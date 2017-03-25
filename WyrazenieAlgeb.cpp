#include <iostream>
#include "WyrazenieAlgeb.h"

using namespace std;

/*Funkcja analizujaca skladnie wczytanego wyrazenia
PRE: Poprawnie wczytane wyrazenie
POST: Funkcja zwraca 0 w przypadku braku bledu skladni i 1 w przypadku bledu*/
int Analiza(Wyrazenie Algeb){
  int OK=0;
  if(Algeb.x==6){       //Czy argument 1. jest "z"?
    cerr<<"Blad skladni. Nieprawidlowy pierwszy argument"<<endl;
    OK=1;
  }
  //Czy znak dzialania jest dozwolony?
  if (Algeb.znak!='*'&& Algeb.znak!='/'&& Algeb.znak!='+'&& Algeb.znak!='-'){
    cerr<<"Blad skladni. Nieprawidlowy znak dzialania"<<endl;
    OK= 1;
  }
  if(Algeb.y==6){       //Czy argument 2. jest "z"?
    cerr<<"Blad skladni. Nieprawidlowy drugi argument"<<endl;
    OK=1;
  }
  if(Algeb.znakr!='='){ //Czy wystepuje na swoim miejscu znak "="? 
    cerr<<"Blad skladni. Brak znaku rownosci"<<endl;
    OK=1;
  }
  if(Algeb.wynik==6){   //Czy wynik jest "z"?
    cerr<<"Blad skladni. Nieprawidlowy wynik"<<endl;
    OK=1;
  }
  //Czy dzielenie przez 0?
  if(Algeb.znak=='/' && Algeb.y==0){ 
    cerr<<"Kto dzieli przez zero ten traci szacunek bo to jest niewykonalny rachunek."<<endl;
    OK=1;
  }
    return OK;
}

/*Funkcja analizuje wyrazneie pod wzgledem poprawnosci obliczen
PRE: Poprawnie wczytane wyrazenie
POST: Funkcja zwraca Symbol z poprawnym wynikiem wczytanego dzialania*/
int Analiza2(Wyrazenie Algeb){
  Symbol pop;
  if(Algeb.znak=='*')
    pop=Mnoz(Algeb.x,Algeb.y);
  if(Algeb.znak=='+')
    pop=Algeb.x+Algeb.y;
  if(Algeb.znak=='-')
    pop=Algeb.x-Algeb.y;
  if(Algeb.znak=='/')
    pop=Algeb.x/Algeb.y;
  return pop;
}

/* Zdefiniowana tabliczka dodawania*/
Symbol TabliczkaDzialania[5][5]={{e,a,b,c,d},{a,b,c,d,e},{b,c,d,e,a},{c,d,e,a,b},{d,e,a,b,c}};

/*Zdefiniowana tabliczka mnozenia*/
Symbol TabliczkaMnozenia[5][5]={{e,e,e,e,e},{e,a,b,c,d},{e,b,d,a,c},{e,c,a,d,b},{e,d,c,b,a}};

/*
  Definicja funkcji: Dodaj, OdwrotnyDodawania, Odejmij, Mnoz, OdwrotnyMnozenia, Dziel.
*/

/*PRE: poprawnie wczytane argumenty
  POST: funkcja zwraca sume argumentow*/
Symbol Dodaj(Symbol Arg1, Symbol Arg2){
  return TabliczkaDzialania[Arg1][Arg2];
}

/*Zdefiniowana tabliczka elementow odwrotych wzgledem dodawania*/
Symbol OdwrotnyDodawania[]={e,d,c,b,a};

/*PRE: poprawnie wczytane argumenty
  POST: funkcja zwraca roznice argumentow*/
Symbol Odejmuj(Symbol Arg1, Symbol Arg2){
  return TabliczkaDzialania[Arg1][OdwrotnyDodawania[Arg2]];
}

/*PRE: poprawnie wczytane argumenty
  POST: funkcja zwraca iloczyn argumentow*/
Symbol Mnoz(Symbol Arg1, Symbol Arg2){
  return TabliczkaMnozenia[Arg1][Arg2];
}
/*Zdefiniowana tablica elementow odwrotnych wzgledem mnozenia*/
Symbol OdwrotnyMnozenia[]={e,a,c,b,d};

/*PRE: poprawnie wczytane argumenty
  POST: funkcja zwraca iloraz argumentow*/
Symbol Dziel(Symbol Arg1, Symbol Arg2){
  return TabliczkaMnozenia[Arg1][OdwrotnyMnozenia[Arg2]];
}
/*
  Definicja przeciążeń operatorów
*/

/*PRE: poprawnie wczytane argumenty
  POST: funkcja zwraca sume argumentow*/
Symbol operator + (Symbol Arg1, Symbol Arg2){
  return TabliczkaDzialania[Arg1][Arg2];
}
/*Funkcja zwraca argument z pominieciem znau + */
Symbol operator + (Symbol Arg){
  return Arg;
}

/*PRE: poprawnie wczytane argumenty
  POST: funkcja zwraca roznice argumentow*/
Symbol operator - (Symbol Arg1, Symbol Arg2){
  return TabliczkaDzialania[Arg1][OdwrotnyDodawania[Arg2]];
}
/* Funkcja zwraca argument odwrotny wzgledem dodawania*/
Symbol operator - (Symbol Arg){
  return OdwrotnyDodawania[Arg];
}

/*PRE: poprawnie wczytane argumenty
  POST: funkcja zwraca iloczyn argumentow*/
Symbol operator * (Symbol Arg1, Symbol Arg2){
  return TabliczkaMnozenia[Arg1][Arg2];
}

/*PRE: poprawnie wczytane argumenty
  POST: funkcja zwraca iloraz argumentow*/
Symbol operator / (Symbol Arg1, Symbol Arg2){
  return TabliczkaMnozenia[Arg1][OdwrotnyMnozenia[Arg2]];
}
