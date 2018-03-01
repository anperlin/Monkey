
#include <monkey.h>

Tempx::Tempx(){};
    bool Tempx::Stop(){
        if (tipoTempor==_OGNI || tipoTempor==_TONOFF){
            return (millis() >= timeA);
        } else{
            return (!execFlag && (millis() > timeA));}
        }
    void Tempx::set(long int millix, int tipoTimer){
        timeA=millis()+(millix*_MULT);
        tipoTempor=tipoTimer;
        if (tipoTempor==_PER || tipoTempor==_OGNI){doAction=true;}
    }

    void Tempx::set(long int millix,long int tOn, int tipoTimer){
        timeA=millis()+(millix *_MULT);
        timeB=millis()+(tOn *_MULT);
        tipoTempor=tipoTimer;
        if (tipoTempor==_TONOFF){doAction=true;flagBlinkOff=true;}
    };

    void Tempx::resetTIMER(){
        switch(tipoTempor){
            case _PER: execFlag=true;ripristinaPins(); break;
            case _TRA: execFlag=true; doAction=true;break;
            case _OGNI:timeA=0;
            case _TONOFF:timeA=0;
        }
   }
    void Tempx::ripristinaPins()
    {
     for (int pin=0;pin<14;pin++){
            if (oldState.pinX[pin]>-1){
                digitalWrite(pin,oldState.pinX[pin]);
            }
        }
    }
    bool Tempx::isStartable(){
            return (timeA==0 && start);
    }

    bool Tempx::isBlinker(){
            return (tipoTempor==_TONOFF);
    }
    bool Tempx::isToff(){
            return ((millis() >= timeB) && (millis() <= timeA));
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

