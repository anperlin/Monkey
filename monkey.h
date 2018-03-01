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
#define _PER 1
#define _TRA 2
#define _OGNI 3
#define _TONOFF 4



#define _MULT 1

#define TEMPORIZZATORI(...) enum c{nn=0,##__VA_ARGS__}

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

#define START(X) if(!tmx[X].started){tmx[X].start=true;tmx[X].timeA=0;tmx[X].started=true;};
#define LAMP(A,B,C) TIMER(A,B,C)
#define TONOFF(X,Y) set(X+Y,X,_TONOFF);
#define OGNI(X) set(X,_OGNI);
#define TRA(X) set(X,_TRA);
#define PER(X) set(X,_PER);

#define TIMER(A,B,C) \
    if(tmx[A].isStartable()){tmx[A].C }; \
    if(tmx[A].doAction){ \
        _RSTOLDSTATE; B ; tmx[A].oldState= oldState ;tmx[A].doAction=false;} \
    if(tmx[A].isBlinker() && tmx[A].isToff() && tmx[A].flagBlinkOff){tmx[A].ripristinaPins();tmx[A].flagBlinkOff=false;}    \
    if(tmx[A].Stop()){tmx[A].resetTIMER();};


//sinonimi
#define ATTIVA(...) ACCENDI(__VA_ARGS__)
#define DISATTIVA(...) SPEGNI(__VA_ARGS__)
#define AVVIA(...) ACCENDI(__VA_ARGS__)
#define FERMA(...) SPEGNI(__VA_ARGS__)


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
    bool execFlag, doAction,start,flagBlinkOff,started;
    long int timeA,timeB;
    int tipoTempor;
    OldPin oldState;


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

extern Tempx tmx[MaxTimers];
extern void SetOnOff(int statex,int count,... ); //this function set on or off specified pins
extern bool IsONOFF(bool statox, int count,...);
extern bool IsOnOROff(bool statox, int count,...);

#endif // MONKEY_H_INCLUDED
