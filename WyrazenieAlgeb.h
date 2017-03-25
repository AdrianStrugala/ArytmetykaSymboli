#ifndef WYRAZENIEALGEB_H
#define WYRAZENIEALGEB_H
#include "Symbol.h"

/*Struktura przechowujaca wczytane wyrazenie algebraiczne*/
struct Wyrazenie{
  Symbol x;     //Pierwszy argument 
  char znak;    //Znak dzialania
  Symbol y;     //Drugi argument
  char znakr;   //Znak rownosci
  Symbol wynik; //Wynik
};

int Analiza(Wyrazenie Algeb);
int Analiza2(Wyrazenie Algeb);
Symbol Dodaj(Symbol Arg1, Symbol Arg2);
Symbol Odejmuj(Symbol Arg1, Symbol Arg2);
Symbol Mnoz(Symbol Arg1, Symbol Arg2);
Symbol Dziel(Symbol Arg1, Symbol Arg2);
Symbol operator + (Symbol Arg1, Symbol Arg2);
Symbol operator + (Symbol Arg);
Symbol operator - (Symbol Arg1, Symbol Arg2);
Symbol operator - (Symbol Arg);
Symbol operator * (Symbol Arg1, Symbol Arg2);
Symbol operator / (Symbol Arg1, Symbol Arg2);

#endif
