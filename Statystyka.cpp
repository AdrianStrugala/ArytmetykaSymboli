#include <iostream>
#include "Statystyka.h"
using namespace std;

/*Funkcja badajaca znak operacji
PRE: Poprawnie wczytane wyrazenie
POST: Funkcja zwraca wartosc 0 w przypadku operacji mnozenia i dzielenia i wartosc 0 w przypadku operacji dodawania i odejmowania*/
int Znak(char znak){
  int mno=0;
  if (znak!='+' && znak!='-')
    mno=1;
  return mno;
}

/*Funkcja wyswietlajaca elementy statystyki na wyjsciu cout
PRE: Brak
POST: Brak*/
void Wyswietlstat(Statystyka Stat){
  cout <<endl<<"Statystyka:"<<endl<<"Ilosc wszystkich wyrazen: "<<Stat.all<<endl<<"Ilosc poprawnie zapisanych wyrazen: "<<Stat.good<<endl<<"Ilosc wyrazen z poprawnym wynikiem: "<<Stat.better<<endl<<"Procentowo ilosc poprawnych wynikow: ";
  if(Stat.good!=0)
      cout<<(float)Stat.better*100/(float)Stat.good<<"%";
  else 
    cout<<"0";
cout<<endl<<"Ilosc operacji odejmowania i dodawania: "<<Stat.dod<<endl<<"Ilosc operacji mnozenia i dzielenia: "<<Stat.mno<<endl;
}
