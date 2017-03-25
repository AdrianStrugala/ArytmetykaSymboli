#ifndef STATYSTYKA_H
#define STATYSTYKA_H

/*Struktura przechowujaca dane do statystyki*/
struct Statystyka {
  int all;     //Wszystkie wyrazenia
  int good;    //Wyrazenia z poprawnie zapisana skladnia
  int better;  //Wyrazenia z poprawnym wynikiem
  int dod;     //Ilosc operacji dodawania i odejmowania
  int mno;     //Ilosc operacji mnozenia i dzielenia
};

int Znak(char znak);
void Wyswietlstat(Statystyka Stat);
#endif
