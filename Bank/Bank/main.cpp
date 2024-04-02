/**
* @file main.cpp
* Plik g³ówny projektu Bank
*/

#include "Header.h"

int main(int argc, char* argv[])
{
	std::cout << "Witaj w centrali banku Altera!" << std::endl;
	std::cout << "--------------<>--------------" << std::endl;


	const std::string baza_danych("pliki_txt/uzytkownicy.txt");
	std::vector<std::vector<std::string>> baza = wczytaj_baze(baza_danych);

	const std::string baza_transakcji("pliki_txt/transakcje.txt");
	std::vector<std::vector<std::string>> trans = wczytaj_transakcje(baza_transakcji);

	std::vector<std::vector<std::string>> dane = wydobycie_danych(baza_danych);
	std::vector<std::vector<std::string>> dane2 = wydobycie_transakcji(baza_transakcji);

	int l_linii = licznik_linii(dane); // tw zmienna zawierajaca liczbe linii bazy uzytkownikow	
	int l_linii2 = licznik_linii2(dane2); // tw zmienna zawierajaca liczbe linii bazy transakcji

	s_data data = f_data(s_data());
	std::vector<konta> uzytkownicy = tworzenie_struktur(dane, l_linii);
	std::vector<s_trans> transakcje = tworzenie_struktur2(dane2, l_linii2);

	bool re_menu = 1;
	char last;
	do {
		while (re_menu) {
			int operacja;

			std::cout << " Jaka operacje chcesz wykonac: " << std::endl;
			std::cout << "--------------<>--------------" << std::endl;
			std::cout << " 1. Pokaz baze danych klientow; " << std::endl;
			std::cout << " 2. Pokaz zestawienie transakcji w banku; " << std::endl;
			std::cout << " 3. Sprawdz saldo konta; " << std::endl;
			std::cout << " 4. Wplata pieniedzy; " << std::endl;
			std::cout << " 5. Wyplata pieniedzy; " << std::endl;
			std::cout << " 6. Dokonanie przelewu; " << std::endl;
			std::cout << " 7. Cofniecie transakcji; " << std::endl;
			std::cout << " 8. Generowanie raportow; " << std::endl;
			std::cout << " 9. Wyjscie." << std::endl;
			std::cin >> operacja;

			if ((operacja >= 1) and (operacja <= 9)) {
				switch (operacja)
				{
				case 1: pokaz_baze(uzytkownicy);
					break;
				case 2: pokaz_transakcje(transakcje);
					break;
				case 3: sprawdz_saldo(uzytkownicy, l_linii);
					break;
				case 4:  last = '+'; wplata(uzytkownicy, transakcje, data);
					break;
				case 5:	 last = '-'; wyplata(uzytkownicy, transakcje, data);
					break;
				case 6:  last = 'p'; przelew(uzytkownicy, transakcje, data);
					break;
				case 7: zwrot(uzytkownicy, transakcje, last);
					break;
				case 8: gen_raport(uzytkownicy, transakcje);
					break;
				case 9: zapis_struktury(uzytkownicy, transakcje), wyjscie(re_menu);
					break;
				default: std::cout << "Nie ma takiej opcji w menu!";
				}
				getchar(); getchar();// umozliwia wstrzymanie wyniku i wznowienie petli po nacisnieciu enter (funkcja czeka na enter)
				system("cls");
			}
			else if (std::cin.fail()) {
				std::cerr << "Podano nieprawidlowe dane wejsciowe (nie jest to liczba)" << std::endl;
				std::cin.clear();											//  cin.clear() usuwa flage bledu wejscia - to co zwrocila funkcja cin.fail
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	//ignoruje niepoprane danye wejsciowe - umozliwia ponowne dzialanie menu w petli i zapytanie o wartosc operacji
			}
			else if ((operacja < 1) or (operacja > 9))
				std::cerr << "To nie jest liczba z przedzialu <1;9>! Bledne dane!" << std::endl; // jesli nie jest system walidacji "cerr" wyswietli komunikat 
		}


	} while (true);
	std::cout << "------------------------------------------" << std::endl;
	return 0;
}
