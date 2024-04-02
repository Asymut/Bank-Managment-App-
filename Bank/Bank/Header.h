//#pragma once
/**
* @file Header.h
* Plik zawierajacy deklaracje funkji(naglowki) projektu Bank
*/

#ifndef Header_h
#define Header_h
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>  // biblioteka dla stringstream   
#include <iomanip>
#include <ctime>
#include <chrono>
#include <cstdio> // biblioteka zawiera funkcje sscanf - umozliwia rozlozenie daty w stringu na poszczegolne skladowe w intach. - raporty
#include <algorithm> // biblioteka dla sortowania danych

/** @struct konta
*  konta - struktura która przechowuje dane z pliku uzytkownicy.txt 
*  @var konta::id
*	zmienna przechowuje identyfikator konta
*  @var konta::imie
* 	zmienna przechowuje imie klienta
*  @var konta::drugie_imie
*	zmienna przechowuje drugie imie klienta
*  @var konta::nazwisko
*   zmienna przechowuje nazwisko klienta
*  @var konta::adres
*   zmienna przechowuje adres klienta
*  @var konta::miasto 
*	zmienna przechowuje miasto zamieszkania klienta
*  @var konta::kod_pocztowy
*	zmienna przechowuje kod pocztowy klienta
*  @var konta::nr_konta
*	zmienna przechowuje numer konta klienta
*  @var konta::pesel
*	zmienna przechowuje pesel klienta
*  @var konta::nr_telefonu
*	zmienna przechowuje numer telefonu klienta
*  @var konta::saldo
*	zmienna przechowuje saldo konta klienta
*  @var konta::debet
*	zmienna przechowuje maksymalny debet na koncie klienta
*/
struct konta { 

	int id;
	std::string imie, drugie_imie, nazwisko, adres, miasto, kod_pocztowy;
	std::string nr_konta, pesel, nr_telefonu;
	double saldo, debet;
};

/** @struct s_trans
*  s_trans - struktura która przechowuje dane z pliku transakcje.txt 
*  @var s_trans::id
*	zmienna przechowuje identyfikator transakcji
*  @var s_trans::numer
*	zmienna przechowuje numer transakcji w banku
*  @var s_trans::rodzaj
*	zmienna przechowuje typ wykonanej transakcji (wp³ata = "+"/wyp³ata = "-")
*  @var s_trans::konto
*	zmienna przechowuje numer konta klienta
*  @var s_trans::data
*	zmienna przechowuje date wykonania transakcji
*  @var s_trans::kwota
*	zmienna przechowuje kwote wykonanej transakcji
*/
struct s_trans { 
	int id, numer;
	std::string rodzaj, konto, data;
	double kwota;
};

/** @struct s_data
*  s_data - struktura która przechowuje roz³o¿on¹ na czynniki datê transakcji
*  @var s_data::dzien
*	zmienna przechowuje dzieñ dla konkretnej daty
*  @var s_data::miesiac
*	zmienna przechowuje miesi¹c dla konkretnej daty
*  @var s_data::rok
*	zmienna przechowuje rok dla konkretnej daty
*/
struct s_data { //struktura zawierajaca date 
	int dzien;
	int miesiac;
	int rok;
};

/** @struct s_zakres
*  s_zakres - struktura która przechowuje zdefiniowany przez u¿ytkownika zakres finansowy i datowy do generowania raportów
*  @var s_zakres::dzien1
*	zmienna przechowuje dzieñ dla daty zdefiniowanej jako dolny próg 
*  @var s_zakres::miesiac1
*	zmienna przechowuje miesiac dla daty zdefiniowanej jako dolny próg 
*  @var s_zakres::rok1
*	zmienna przechowuje rok dla daty zdefiniowanej jako dolny próg 
*  @var s_zakres::dzien2
*	zmienna przechowuje dzieñ dla daty zdefiniowanej jako górny próg
*  @var s_zakres::miesiac2
*	zmienna przechowuje miesiac dla daty zdefiniowanej jako górny próg
*  @var s_zakres::rok2
*	zmienna przechowuje rok dla daty zdefiniowanej jako górny próg
*  @var s_zakres::p_finan
*	zmienna przechowuje dolny próg finansowy 
*  @var s_zakres::k_finan
*	zmienna przechowuje górny próg finansowy
*/
struct s_zakres {	// struktura zdefiniowanego zakresu do raportow
	int dzien1, miesiac1, rok1, dzien2, miesiac2, rok2;
	double p_finan, k_finan;
};

/**
* Funkcja wczytuje plik u¿ytkownicy.txt zawieraj¹cy bazê danych u¿ytkowników banku
* @param baza_danych - plik u¿ytkownicy.txt
* @return baza - wektor zawierajcy wektory 
*/
std::vector<std::vector<std::string>> wczytaj_baze(const std::string& baza_danych);

/**
* Funkcja wydobywa z vectora vectorow zawieraj¹cego stringi, pojedyncze stringi dla bazy uzytkownikow[kolumna][wiersz]
* @param baza_danych - plik u¿ytkownicy.txt
* @return dane - wektor wektorów dla u¿ytkowników
*/
std::vector<std::vector<std::string>> wydobycie_danych(const std::string& baza_danych);

/**
* Funkcja wczytuje plik transakcje.txt zawieraj¹cy bazê transakcji wykonanych w banku
* @param baza_transakcji - plik transakcje.txt
* @return trans - wektor zawierajcy wektory
*/
std::vector<std::vector<std::string>> wczytaj_transakcje(const std::string& baza_transakcji);

/**
* Funkcja wydobywa z vectora vectorów zawieraj¹cego stringi, pojedyncze stringi dla bazy transakcji[kolumna][wiersz]
* @param baza_transakcji - plik transakcje.txt
* @return dane2 - wektor wektorów dla transkcji
*/
std::vector<std::vector<std::string>> wydobycie_transakcji(const std::string& baza_transakcji);

/**
* Funkcjonalnoœæ nr1 -  pokazuje baze u¿ytkowników banku;
* @param uzytkownicy - wektor zawieraj¹cy struktury u¿ytkowników
* @return funkcja nie zwraca ¿adnej wartoœci
*/
void pokaz_baze(std::vector<konta>& uzytkownicy);

/**
* Funkcjonalnoœæ nr1 -  pokazuje baze transakcji w banku;
* @param transakcje - wektor zawieraj¹cy struktury transakcji
* @return funkcja nie zwraca ¿adnej wartoœci
*/
void pokaz_transakcje(std::vector<s_trans>& transakcje);

/**
* Funkcja uzupe³nia stuktury danymi z wektora, wektorów dla struktury u¿ytkowników.
* @param dane - wektor wektorów dla u¿ytkowników
* @param l_linii - liczba linii w pliku uzytkownicy.txt
* @return strukture konta, która przechowuje dane z pliku uzytkownicy.txt 
*/
std::vector<konta> tworzenie_struktur(std::vector<std::vector<std::string>>& dane, int l_linii);

/**
* Funkcja uzupe³nia stuktury danymi z wektora, wektorów dla struktury transakcji.
* @param dane2 - wektor wektorów dla transakcji
* @param l_linii2 - liczba linii w pliku transakcje.txt
* @return strukture s_trans, która przechowuje dane z pliku transakcje.txt
*/
std::vector<s_trans> tworzenie_struktur2(std::vector<std::vector<std::string>>& dane2, int l_linii2);

/**
* Funkcja zlicza linie z pliku uzytkownicy.txt
* @param dane - wektor wektorów dla u¿ytkowników
* @return funkcja zwraca licznik_linii - liczbe linni w pliku uzytkownicy.txt
*/
int licznik_linii(std::vector<std::vector<std::string>>& dane);

/**
* Funkcja zlicza linie z pliku transakcje.txt
* @param dane2 - wektor wektorów dla transakcji
* @return funkcja zwraca licznik_linii2 - liczbe linni w pliku transakcje.txt
*/
int licznik_linii2(std::vector<std::vector<std::string>>& dane2);

/**
* Funkcja generuje bie¿¹c¹ datê i rozpisujê j¹ na 3 zmienne (dzieñ, miesi¹c, rok)
* @param s_data - struktura która przechowuje roz³o¿on¹ na czynniki datê transakcji
* @return funkcja zwraca element data, struktury s_data  
*/
s_data f_data(struct s_data);

/**
* Funkcjonalnoœæ nr3 - sprawdŸ saldo. Sprawdza saldo o podanym numerze konta
* @param uzytkownicy - wektor zawieraj¹cy struktury u¿ytkowników
* @param l_linii - liczbe linni w pliku uzytkownicy.txt
* @return funkcja nie zwraca ¿adnej wartoœci
*/
void sprawdz_saldo(std::vector<konta>& uzytkownicy, int l_linii);

/**
* Funkcjonalnoœæ nr4 - wplata pieniedzy. Wplaca podana kwote na wybrane konto.
* @param uzytkownicy - wektor zawieraj¹cy struktury u¿ytkowników
* @param transakcje - wektor zawieraj¹cy struktury transakcji
* @param data - element struktury s_data, zawieraj¹ca strukturê z bie¿¹c¹ dat¹
* @return funkcja nie zwraca ¿adnej wartoœci
*/
void wplata(std::vector<konta>& uzytkownicy, std::vector<s_trans>& transakcje, s_data data);

/**
* Funkcjonalnoœæ nr5 - wyp³ata pieniêdzy. Wyp³aca podan¹ kwotê z wybranego konto.
* @param uzytkownicy - wektor zawieraj¹cy struktury u¿ytkowników
* @param transakcje - wektor zawieraj¹cy struktury transakcji
* @param data - element struktury s_data, zawieraj¹ca strukturê z bie¿¹c¹ dat¹
* @return funkcja nie zwraca ¿adnej wartoœci
*/
void wyplata(std::vector<konta>& uzytkownicy, std::vector<s_trans>& transakcje, s_data data);

/**
* Funkcjonalnoœæ nr6 - przelew, wykonanie przelewu z jednego konta na drugie.
* @param uzytkownicy - wektor zawieraj¹cy struktury u¿ytkowników
* @param transakcje - wektor zawieraj¹cy struktury transakcji
* @param data - element struktury s_data, zawieraj¹ca strukturê z bie¿¹c¹ dat¹
* @return funkcja nie zwraca ¿adnej wartoœci
*/
void przelew(std::vector<konta>& uzytkownicy, std::vector<s_trans>& transakcje, s_data data);

/**
* Funkcjonalnoœæ nr7 - umo¿liwia cofniêcie ostatniej transakcji 
* @param uzytkownicy - wektor zawieraj¹cy struktury u¿ytkowników
* @param transakcje - wektor zawieraj¹cy struktury transakcji
* @param last - zmienna znakowa, zapisuj¹ca informacjê o tym jak¹ transakcja by³a ostatnio wykonana - (wp³ata/wyp³ata/przelew)
* @return funkcja nie zwraca ¿adnej wartoœci
*/
void zwrot(std::vector<konta>& uzytkownicy, std::vector<s_trans>& transakcje, char& last);

/**
* Funkcja pobiera od u¿ytkownika i zapisuje zakres finansowy i datowy do generownaia raportów.
* @param funkcja nie przyjmuje ¿adnych parametrów
* @return funkcja zwraca zakres - element struktury s_zakres przechowuj¹cy bie¿¹cy zakres dla aktualnie generowanego raportu
*/
s_zakres f_zakres();

/**
* Funkcjonalnoœæ nr8 - umo¿liwia generowanie posortowanych, wedle preferencji raportów 
* @param uzytkownicy - wektor zawieraj¹cy struktury u¿ytkowników
* @param transakcje - wektor zawieraj¹cy struktury transakcji
* @return funkcja nie zwraca ¿adnej wartoœci
*/
void gen_raport(std::vector<konta> uzytkownicy, std::vector<s_trans> transakcje);

/**
* Funckja sprawdza zadeklarowany zakres dat i weryfikuje czy dana data ma sie wliczaæ do raportu, czy nie. 
* @param transakcje - wektor zawieraj¹cy struktury transakcji
* @param zakres - element struktury s_zakres przechowuj¹cy bie¿¹cy zakres dla aktualnie generowanego raportu 
* @param licznik - zmienna s³u¿¹ca do przekazania funkcji, która transakcja jest sprawdzana z funkcji generuj¹cej raporty
* @return funkcja zwraca true jeœli ma siê liczyæ do raportu lub false jeœli nie ma siê liczyæ
*/
bool zakres_dat(std::vector<s_trans>& transakcje, s_zakres zakres, int& licznik);

/**
* Funkcja zapisuje zawartoœci wektorów do plików na zakoñczenie programu
* @param transakcje - wektor zawieraj¹cy struktury transakcji
* @param uzytkownicy - wektor zawieraj¹cy struktury u¿ytkowników
* @return funkcja nie zwraca ¿adnej wartoœci
*/
void zapis_struktury(std::vector<konta>& uzytkownicy, std::vector<s_trans>& transakcje);

/**
* Funkcjonalnoææ nr 9 - wyjœcie z aplikacjii i za³adowanie plików.
* @param re_menu - kiedy re_menu=true powtórz menu, kiedy re_menu=false zakoñcz program
* @return funkcja zwraca re_menu - true albo false 
*/
bool wyjscie(bool& re_menu);
#endif