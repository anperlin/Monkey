/**************************************************************
/* Monkey Library - Author: Angelo Perlin 2018
/* This Librey is under LGPL license
***************************************************************/

#ifndef MONKEY_H_INCLUDED
#define MONKEY_H_INCLUDED

#include <Arduino.h>
#define D0 0
#define D1 1
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define D8 8
#define D9 9
#define D10 10
#define D11 11
#define D12 12
#define D13 13
#define ON 1
#define OFF 0
#define MAXPINS 14
#define MaxTimers 10
#define MaxButton 10
#define _PER 1
#define _TRA 2
#define _OGNI 3
#define _TONOFF 4

#define PONPOFF 0
#define PUSHON 1
#define INTERRUTTORE 1


/*
#define E &&
#define O ||
#define NON !
*/

#define NOMI_TIMER(...) enum nt{ntz=0,##__VA_ARGS__}
#define NOMI_PULSANTI(...) enum np{npz=0,##__VA_ARGS__}

//define initialization procedure
#define INGRESSI(...) \
do{\
    int i, _arr_[] = {__VA_ARGS__};\
    for(i=0; i<sizeof(_arr_)/sizeof(int) ; i++){ \
    pinMode(_arr_[i],INPUT); }\
}while(0)

#define USCITE(...) \
do{\
    int i, _arr_[] = {__VA_ARGS__};\
    for(i=0; i<sizeof(_arr_)/sizeof(int) ; i++){ \
     pinMode(_arr_[i],OUTPUT); }\
     }while(0)

#define MULTISTART(...) \
do{\
    int i, _arr_[] = {__VA_ARGS__};\
    for(i=0; i<sizeof(_arr_)/sizeof(int) ; i++){ \
     START(_arr_[i]); }\
     }while(0)

#define MULTISTOP(...) \
do{\
    int i, _arr_[] = {__VA_ARGS__};\
    for(i=0; i<sizeof(_arr_)/sizeof(int) ; i++){ \
     STOP(_arr_[i]); }\
     }while(0)



#define _RSTOLDSTATE oldState = {{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}}
#define _NUMARGS(...)  (sizeof((int[]){0, ##__VA_ARGS__})/sizeof(int)-1)
#define ACCENDI(...) SetOnOff(1,_NUMARGS(__VA_ARGS__), ##__VA_ARGS__)
#define SPEGNI(...) SetOnOff(0,_NUMARGS(__VA_ARGS__), ##__VA_ARGS__)
#define AZZERA_PIN SetOnOff(0,14,0,1,2,3,4,5,6,7,8,9,10,11,12,13)


#define SONO(X,...) IsONOFF(X,_NUMARGS(__VA_ARGS__),##__VA_ARGS__)
#define ALCUNI(X,...) IsOnOROff(X,_NUMARGS(__VA_ARGS__),##__VA_ARGS__)


#define SE if(
#define ALLORA ){
#define ALTRIMENTI }{
#define FINESE }

#define START(X) if(!tmx[X].started){tmx[X].started=true;tmx[X].initialized=false;};
#define STOP(X) tmx[X].timeA=0;tmx[X].ripristinaPins();tmx[X].started=false;tmx[X].initialized=false;
#define LAMP(A,B,C) TIMER(A,B,C)
#define TONOFF(X,Y) set(X+Y,X,_TONOFF);
#define OGNI(X) set(X,_OGNI);
#define TRA(X) set(X,_TRA);
#define PER(X) set(X,_PER);

#define TIMER(A,B,C)  \
    if(tmx[A].isStartable()){tmx[A].C }; \
    if(tmx[A].doAction){ \
        _RSTOLDSTATE; B ; tmx[A].oldStatePin=oldState; tmx[A].doAction=false;} \
    if(tmx[A].isBlinker() && tmx[A].isToff() && tmx[A].flagBlinkOff){tmx[A].ripristinaPins();tmx[A].flagBlinkOff=false;}   \
    if(tmx[A].Stop()){tmx[A].resetTIMER();};
/*
1 definizione del timer: non è startable, doaction=false non può fare nessuna azione e non è stoppabile.
*/
#define NULLA
#define TIPOPULSANTE(Id,Tipo) btx[Id].tipo=Tipo;
//TIPO=0 PUSH ON PUSH OFF TIPO=1 ONOFF
#define PULSANTE(Id,Expr,AzOn,AzOff) btx[Id].Update(Expr); if(btx[Id].stateChanged){ \
                                          btx[Id].stateChanged=false;\
                                          if(btx[Id].stato){ \
                                          AzOn ; } else {\
                                          AzOff ; } }
//sinonimi
#define ATTIVA(...) ACCENDI(__VA_ARGS__)
#define DISATTIVA(...) SPEGNI(__VA_ARGS__)
#define AVVIATIMER(...) MULTISTART(__VA_ARGS__)
#define FERMATIMER(...) MULTISTOP(__VA_ARGS__)


//define other languages
#define TURNON(...) ACCENDI(__VA_ARGS__)
#define TURNOFF(...) SPEGNI(__VA_ARGS__)
#define BLINK(A,B,C) TIMER(A,B,C)
#define FOR(X) PER(X)
#define IN(X) TRA(X)
#define EVERY(X) OGNI(X)
#define IF if(
#define THEN ){
#define ELSE }{
#define ENDIF }
#define ALL(X,...) SONO(X,__VA_ARGS__)
#define ANY(X,...) ALCUNI(X,__VA_ARGS__)
#define SETOFF AZZERA_PIN
#define DIGITINPUT(...) INGRESSI(__VA_ARGS__)
#define DIGITOUT(...) USCITE(__VA_ARGS__)
#define TIMERS(...) TEMPORIZZATORI(__VA_ARGS__)

//define class,struct and function header


typedef struct
{
    int8_t pinX[MAXPINS];
}   OldPin;
extern OldPin oldState;

class Tempx {
    public:
    long int timeA,timeB; //TIME
    int tipoTempor;
    OldPin oldStatePin;
    bool doAction, started, initialized,flagBlinkOff;

    //bool execFlag, doAction,start,flagBlinkOff,started;


    Tempx();
    bool Stop();
    void set(long int millix, int tipoTimer);
    void set(long int millix,long int tOn, int tipoTimer);
    void resetTIMER();
    void ripristinaPins();
    bool isStartable();
    bool isBlinker();
    bool isToff();

};

class Button{
  public:
  bool stato=false;
  bool released=false;
  bool stateChanged=false;
  int tipo=1;
  button(){};
  void Update(bool statePins);
 };

extern Button btx[MaxButton];
extern Tempx tmx[MaxTimers];
extern void SetOnOff(int statex,int count,... ); //this function set on or off specified pins
extern bool IsONOFF(bool statox, int count,...);
extern bool IsOnOROff(bool statox, int count,...);

#endif // MONKEY_H_INCLUDED
