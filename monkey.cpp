#include <monkey.h>
OldPin oldState;
Tempx tmx[MaxTimers];
Button btx[MaxButton];

Tempx::Tempx(){
        timeA=0;
        timeB=0;
        started=false;
        doAction=false;
        initialized=false;
};
    bool Tempx::Stop(){
        //the timer is stoppable if is running.
        bool stp=false;
        if (started){
            stp= (millis() >= timeA);
        }
        return stp;
    }
    void Tempx::set(long int millix, int tipoTimer){
        timeA=millis()+ millix ;
        tipoTempor=tipoTimer;
        initialized=true;
        if (tipoTempor==_PER || tipoTempor==_OGNI){doAction=true;} //if temporization is _PER or _OGNI it start immediatly setting doAction to true
    }

    void Tempx::set(long int millix,long int tOn, int tipoTimer){
        timeA=millis()+ millix;
        timeB=millis()+ tOn;
        tipoTempor=tipoTimer;
         initialized=true;
        if (tipoTempor==_TONOFF){doAction=true;flagBlinkOff=true;}
    };

    void Tempx::resetTIMER(){
        switch(tipoTempor){
            case _PER:  ripristinaPins();
                        started=false;
                        initialized=true;
                        break;
            case _TRA:  doAction=true;
                        started=false;
                        initialized=false;
                        break;
            case _OGNI: initialized=false;
                        started=true;
                        break;
            case _TONOFF:initialized=false;
                        started=true;
                       timeA=0; break;
         }

   }
    void Tempx::ripristinaPins()
    {
     for (int pin=0;pin<14;pin++){
            if (oldStatePin.pinX[pin]>-1){
                digitalWrite(pin,oldStatePin.pinX[pin]);
            }
        }
    }
    bool Tempx::isStartable(){
            return (started && !initialized); //return true if the timer is running else return true if the timer is stopped
    }

    bool Tempx::isBlinker(){
            return (tipoTempor==_TONOFF);
    }
    bool Tempx::isToff(){
            return ((millis() >= timeB) && (millis() <= timeA));
    }

   void Button::Update(bool statePins){
    if (tipo==0){
      if (statePins && !released) {
        stato=!stato;
        released=true;
        stateChanged=true;}

      if (!statePins && released){
        released=false; stateChanged=true;}
    }

    if (tipo==1){
       if (statePins && !released) {
        stato=statePins;
        released=true;
        stateChanged=true;}

      if (!statePins && released){
        released=false; stato=statePins;
        stateChanged=true;}
      }
      }
//---
void SetOnOff(int statex,int count,... ){

     va_list ap;
     int i,pin;
     va_start (ap, count);
     for (i = 0; i < count; i++){
        pin= va_arg (ap, int);
        oldState.pinX[pin]=digitalRead(pin);
        digitalWrite(pin,statex);
     }
     va_end (ap);
}

bool IsONOFF(bool statox, int count,...){
     va_list ap;
     int i,pin;
     int stato;
     bool result=true;
     va_start (ap, count);
     for (i = 0; i < count; i++){
        pin= va_arg (ap, int);
        stato=digitalRead(pin);
        result=result && ((stato && statox)||(!(stato || statox)));
     }
     va_end (ap);
     return result;
}

bool IsOnOROff(bool statox, int count,...){
     va_list ap;
     int i=1,pin;
     int stato;
     bool result=false;
     va_start (ap, count);
     do{
        pin= va_arg (ap, int);
        stato=digitalRead(pin);
        result=result || ((!stato && !statox) ||(stato && statox));
        i++;
    }while(!result && i<=count);
     va_end (ap);
     return result;

}

