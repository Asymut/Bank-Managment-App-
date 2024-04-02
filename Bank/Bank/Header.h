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
*  konta - struktura kt�ra przechowuje dane z pliku uzytkownicy.txt 
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
*  s_trans - struktura kt�ra przechowuje dane z pliku transakcje.txt 
*  @var s_trans::id
*	zmienna przechowuje identyfikator transakcji
*  @var s_trans::numer
*	zmienna przechowuje numer transakcji w banku
*  @var s_trans::rodzaj
*	zmienna przechowuje typ wykonanej transakcji (wp�ata = "+"/wyp�ata = "-")
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
*  s_data - struktura kt�ra przechowuje roz�o�on� na czynniki dat� transakcji
*  @var s_data::dzien
*	zmienna przechowuje dzie� dla konkretnej daty
*  @var s_data::miesiac
*	zmienna przechowuje miesi�c dla konkretnej daty
*  @var s_data::rok
*	zmienna przechowuje rok dla konkretnej daty
*/
struct s_data { //struktura zawierajaca date 
	int dzien;
	int miesiac;
	int rok;
};

/** @struct s_zakres
*  s_zakres - struktura kt�ra przechowuje zdefiniowany przez u�ytkownika zakres finansowy i datowy do generowania raport�w
*  @var s_zakres::dzien1
*	zmienna przechowuje dzie� dla daty zdefiniowanej jako dolny pr�g 
*  @var s_zakres::miesiac1
*	zmienna przechowuje miesiac dla daty zdefiniowanej jako dolny pr�g 
*  @var s_zakres::rok1
*	zmienna przechowuje rok dla daty zdefiniowanej jako dolny pr�g 
*  @var s_zakres::dzien2
*	zmienna przechowuje dzie� dla daty zdefiniowanej jako g�rny pr�g
*  @var s_zakres::miesiac2
*	zmienna przechowuje miesiac dla daty zdefiniowanej jako g�rny pr�g
*  @var s_zakres::rok2
*	zmienna przechowuje rok dla daty zdefiniowanej jako g�rny pr�g
*  @var s_zakres::p_finan
*	zmienna przechowuje dolny pr�g finansowy 
*  @var s_zakres::k_finan
*	zmienna przechowuje g�rny pr�g finansowy
*/
struct s_zakres {	// struktura zdefiniowanego zakresu do raportow
	int dzien1, miesiac1, rok1, dzien2, miesiac2, rok2;
	double p_finan, k_finan;
};

/**
* Funkcja wczytuje plik u�ytkownicy.txt zawieraj�cy baz� danych u�ytkownik�w banku
* @param baza_danych - plik u�ytkownicy.txt
* @return baza - wektor zawierajcy wektory 
*/
std::vector<std::vector<std::string>> wczytaj_baze(const std::string& baza_danych);

/**
* Funkcja wydobywa z vectora vectorow zawieraj�cego stringi, pojedyncze stringi dla bazy uzytkownikow[kolumna][wiersz]
* @param baza_danych - plik u�ytkownicy.txt
* @return dane - wektor wektor�w dla u�ytkownik�w
*/
std::vector<std::vector<std::string>> wydobycie_danych(const std::string& baza_danych);

/**
* Funkcja wczytuje plik transakcje.txt zawieraj�cy baz� transakcji wykonanych w banku
* @param baza_transakcji - plik transakcje.txt
* @return trans - wektor zawierajcy wektory
*/
std::vector<std::vector<std::string>> wczytaj_transakcje(const std::string& baza_transakcji);

/**
* Funkcja wydobywa z vectora vector�w zawieraj�cego stringi, pojedyncze stringi dla bazy transakcji[kolumna][wiersz]
* @param baza_transakcji - plik transakcje.txt
* @return dane2 - wektor wektor�w dla transkcji
*/
std::vector<std::vector<std::string>> wydobycie_transakcji(const std::string& baza_transakcji);

/**
* Funkcjonalno�� nr1 -  pokazuje baze u�ytkownik�w banku;
* @param uzytkownicy - wektor zawieraj�cy struktury u�ytkownik�w
* @return funkcja nie zwraca �adnej warto�ci
*/
void pokaz_baze(std::vector<konta>& uzytkownicy);

/**
* Funkcjonalno�� nr1 -  pokazuje baze transakcji w banku;
* @param transakcje - wektor zawieraj�cy struktury transakcji
* @return funkcja nie zwraca �adnej warto�ci
*/
void pokaz_transakcje(std::vector<s_trans>& transakcje);

/**
* Funkcja uzupe�nia stuktury danymi z wektora, wektor�w dla struktury u�ytkownik�w.
* @param dane - wektor wektor�w dla u�ytkownik�w
* @param l_linii - liczba linii w pliku uzytkownicy.txt
* @return strukture konta, kt�ra przechowuje dane z pliku uzytkownicy.txt 
*/
std::vector<konta> tworzenie_struktur(std::vector<std::vector<std::string>>& dane, int l_linii);

/**
* Funkcja uzupe�nia stuktury danymi z wektora, wektor�w dla struktury transakcji.
* @param dane2 - wektor wektor�w dla transakcji
* @param l_linii2 - liczba linii w pliku transakcje.txt
* @return strukture s_trans, kt�ra przechowuje dane z pliku transakcje.txt
*/
std::vector<s_trans> tworzenie_struktur2(std::vector<std::vector<std::string>>& dane2, int l_linii2);

/**
* Funkcja zlicza linie z pliku uzytkownicy.txt
* @param dane - wektor wektor�w dla u�ytkownik�w
* @return funkcja zwraca licznik_linii - liczbe linni w pliku uzytkownicy.txt
*/
int licznik_linii(std::vector<std::vector<std::string>>& dane);

/**
* Funkcja zlicza linie z pliku transakcje.txt
* @param dane2 - wektor wektor�w dla transakcji
* @return funkcja zwraca licznik_linii2 - liczbe linni w pliku transakcje.txt
*/
int licznik_linii2(std::vector<std::vector<std::string>>& dane2);

/**
* Funkcja generuje bie��c� dat� i rozpisuj� j� na 3 zmienne (dzie�, miesi�c, rok)
* @param s_data - struktura kt�ra przechowuje roz�o�on� na czynniki dat� transakcji
* @return funkcja zwraca element data, struktury s_data  
*/
s_data f_data(struct s_data);

/**
* Funkcjonalno�� nr3 - sprawd� saldo. Sprawdza saldo o podanym numerze konta
* @param uzytkownicy - wektor zawieraj�cy struktury u�ytkownik�w
* @param l_linii - liczbe linni w pliku uzytkownicy.txt
* @return funkcja nie zwraca �adnej warto�ci
*/
void sprawdz_saldo(std::vector<konta>& uzytkownicy, int l_linii);

/**
* Funkcjonalno�� nr4 - wplata pieniedzy. Wplaca podana kwote na wybrane konto.
* @param uzytkownicy - wektor zawieraj�cy struktury u�ytkownik�w
* @param transakcje - wektor zawieraj�cy struktury transakcji
* @param data - element struktury s_data, zawieraj�ca struktur� z bie��c� dat�
* @return funkcja nie zwraca �adnej warto�ci
*/
void wplata(std::vector<konta>& uzytkownicy, std::vector<s_trans>& transakcje, s_data data);

/**
* Funkcjonalno�� nr5 - wyp�ata pieni�dzy. Wyp�aca podan� kwot� z wybranego konto.
* @param uzytkownicy - wektor zawieraj�cy struktury u�ytkownik�w
* @param transakcje - wektor zawieraj�cy struktury transakcji
* @param data - element struktury s_data, zawieraj�ca struktur� z bie��c� dat�
* @return funkcja nie zwraca �adnej warto�ci
*/
void wyplata(std::vector<konta>& uzytkownicy, std::vector<s_trans>& transakcje, s_data data);

/**
* Funkcjonalno�� nr6 - przelew, wykonanie przelewu z jednego konta na drugie.
* @param uzytkownicy - wektor zawieraj�cy struktury u�ytkownik�w
* @param transakcje - wektor zawieraj�cy struktury transakcji
* @param data - element struktury s_data, zawieraj�ca struktur� z bie��c� dat�
* @return funkcja nie zwraca �adnej warto�ci
*/
void przelew(std::vector<konta>& uzytkownicy, std::vector<s_trans>& transakcje, s_data data);

/**
* Funkcjonalno�� nr7 - umo�liwia cofni�cie ostatniej transakcji 
* @param uzytkownicy - wektor zawieraj�cy struktury u�ytkownik�w
* @param transakcje - wektor zawieraj�cy struktury transakcji
* @param last - zmienna znakowa, zapisuj�ca informacj� o tym jak� transakcja by�a ostatnio wykonana - (wp�ata/wyp�ata/przelew)
* @return funkcja nie zwraca �adnej warto�ci
*/
void zwrot(std::vector<konta>& uzytkownicy, std::vector<s_trans>& transakcje, char& last);

/**
* Funkcja pobiera od u�ytkownika i zapisuje zakres finansowy i datowy do generownaia raport�w.
* @param funkcja nie przyjmuje �adnych parametr�w
* @return funkcja zwraca zakres - element struktury s_zakres przechowuj�cy bie��cy zakres dla aktualnie generowanego raportu
*/
s_zakres f_zakres();

/**
* Funkcjonalno�� nr8 - umo�liwia generowanie posortowanych, wedle preferencji raport�w 
* @param uzytkownicy - wektor zawieraj�cy struktury u�ytkownik�w
* @param transakcje - wektor zawieraj�cy struktury transakcji
* @return funkcja nie zwraca �adnej warto�ci
*/
void gen_raport(std::vector<konta> uzytkownicy, std::vector<s_trans> transakcje);

/**
* Funckja sprawdza zadeklarowany zakres dat i weryfikuje czy dana data ma sie wlicza� do raportu, czy nie. 
* @param transakcje - wektor zawieraj�cy struktury transakcji
* @param zakres - element struktury s_zakres przechowuj�cy bie��cy zakres dla aktualnie generowanego raportu 
* @param licznik - zmienna s�u��ca do przekazania funkcji, kt�ra transakcja jest sprawdzana z funkcji generuj�cej raporty
* @return funkcja zwraca true je�li ma si� liczy� do raportu lub false je�li nie ma si� liczy�
*/
bool zakres_dat(std::vector<s_trans>& transakcje, s_zakres zakres, int& licznik);

/**
* Funkcja zapisuje zawarto�ci wektor�w do plik�w na zako�czenie programu
* @param transakcje - wektor zawieraj�cy struktury transakcji
* @param uzytkownicy - wektor zawieraj�cy struktury u�ytkownik�w
* @return funkcja nie zwraca �adnej warto�ci
*/
void zapis_struktury(std::vector<konta>& uzytkownicy, std::vector<s_trans>& transakcje);

/**
* Funkcjonalno�� nr 9 - wyj�cie z aplikacjii i za�adowanie plik�w.
* @param re_menu - kiedy re_menu=true powt�rz menu, kiedy re_menu=false zako�cz program
* @return funkcja zwraca re_menu - true albo false 
*/
bool wyjscie(bool& re_menu);
#endif