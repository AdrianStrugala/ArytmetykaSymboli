#include <iostream>
#include <cstring>
#include "WyrazenieAlgeb.h"
#include "Statystyka.h"
#include "Symbol.h"

using namespace std;
Wyrazenie Algeb;          //Zmienna, w ktorej zapisywane sa elementy wyrazenia
Statystyka Stat;          //Zmienna do ktorej zapisywane sa elementy statystyki

/*Przeciazenia opratora >> dla zmiennej typu Symbol*/
istream& operator >> (istream& Strm, Symbol& Sym){
  char Ch ='x';
  char const *SymChars = "eabcd", *pSymCh;
  Symbol SymTab[]={e,a,b,c,d};
  if(Strm.fail())return Strm;
  Strm>>Ch;
  //W przypadku poprawnego czytania zmienna przyjmuje wartosc z tablicy symboli
  if((pSymCh=strchr(SymChars,Ch))){Sym=SymTab[pSymCh-SymChars];}
  //W przeciwnym wypadku zmienna przyjmuje wartosc "z"
  else {Sym=(Symbol)6;}
  return Strm;
}
/*Przeciazenie opratora >> dla zmiennej typu Wyrazenie*/
istream& operator >> (istream& Strm, Wyrazenie& Algeb){
  cin>>Algeb.x>> Algeb.znak >> Algeb.y >> Algeb.znakr >> Algeb.wynik;
  return Strm;
}
/*Definicja operatora << dla zmiennej typu symbol*/
ostream & operator << (ostream & StrmWy, Symbol Arg){ 
  return StrmWy <<"eabcd"[Arg];
}
/*Definicja operatora << dla zmiennej typu Wyrazenie*/
ostream & operator << (ostream & StrmWy, Wyrazenie Algeb){
  cout<<Algeb.x<<Algeb.znak<<Algeb.y<<Algeb.znakr<<Algeb.wynik;
  return StrmWy;
}

int main(){
 
  cout << "Start sprawdzianu testu arytmetyki symboli" << endl<<"Wpisz jedno z czterech podstawowych dzialan operujac na literach od a do e"<<endl;
  while(cin>>Algeb){           //Dopoki nie nastapil EOT
    Stat.all++;                //Liczba wszystkich wyrazen ++
    if(Analiza(Algeb)==0){     //Analiza poprawnosci skladni
      Stat.good++;             //Liczba wyrazen z poprawna skladnia ++
      if(Znak(Algeb.znak)==0)  //Sprawdzanie znaku opracji 
	Stat.dod++;            //Jesli dodawanie lub odejmowanie
      else
	Stat.mno++;            //Jesli mnozenie lub dzielenie
      if((Symbol)Analiza2(Algeb)==Algeb.wynik){ //Analiza poprawnosci wyniku
	Stat.better++;         //Liczba wyrazen z poprawnym wynikiem ++  
	cout << "Wczytano wyrazenie: "<<Algeb<<". Wynik poprawny"<<endl;
      }
      else{
	cout << "Wczytano wyrazenie: " <<Algeb<<". Poprawny wynik to: "<<(Symbol)Analiza2(Algeb)<<endl;
      }
    }
  }                              //Koniec petli while
  Wyswietlstat(Stat);            //Wyswietlenie statystyki
}

