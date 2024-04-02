/**
* @file funkcje.cpp
* Plik zawierajacy definicje funkji(ciala) projektu Bank
*/

#include "Header.h"

//using namespace std;
std::vector<std::vector<std::string>> wczytaj_baze(const std::string& baza_danych)
{
	std::vector<std::vector<std::string>> baza;
	std::ifstream plik(baza_danych);

	if (!plik) {
		std::cerr << "Plik uzytkownicy.txt nie istnieje" << std::endl;
		return baza;
	}

	std::string linia;

	return baza;
}

std::vector<std::vector<std::string>> wydobycie_danych(const std::string& baza_danych)
{
	std::vector<std::vector<std::string>> dane;
	std::string linia;

	std::ifstream plik(baza_danych);
	if (!plik) {
			std::cerr << "Plik uzytkownicy.txt nie istnieje" << std::endl;
		return dane;
	}

	while (std::getline(plik, linia))
	{
		std::vector<std::string> wiersz;
		std::istringstream iss(linia);
		std::string pole;
		while (iss >> pole)
		{
			wiersz.push_back(pole);

		}
		dane.push_back(wiersz);
	}
	return dane;
}

std::vector<std::vector<std::string>> wczytaj_transakcje(const std::string& baza_transakcji)
{
	std::vector<std::vector<std::string>> trans;
	std::ifstream plik(baza_transakcji);

	if (!plik) {
		std::cerr << "Plik transakcje.txt nie istnieje" << std::endl;
		return trans;
	}

	std::string linia;

	return trans;
}

std::vector<std::vector<std::string>> wydobycie_transakcji(const std::string& baza_transakcji) {

	std::vector<std::vector<std::string>> dane2;
	std::string linia;


	std::ifstream plik(baza_transakcji);
	if (!plik) {
		std::cerr << "Plik transakcje.txt nie istnieje" << std::endl; // Plik nie móg³ zostaæ otwarty - zwróæ pusty wektor
		return dane2;
	}

	while (std::getline(plik, linia))
	{
		std::vector<std::string> wiersz;
		std::istringstream iss(linia);
		std::string pole;
		while (iss >> pole)
		{
			wiersz.push_back(pole);

		}
		dane2.push_back(wiersz);
	}
	return dane2;
}

void pokaz_baze(std::vector<konta>& uzytkownicy)
{
	std::cout << "----------------<>----------------" << std::endl;
	std::cout << "Baza danych klientow banku ALterra" << std::endl;

	std::cout << "id  nr_konta_bankowego             imie      drugie_imie nazwisko      adres           miasto      kod_pocz pesel         nr_tele     debet    saldo " << std::endl;
	for (int i = 0; i < uzytkownicy.size(); i++) {

		if (uzytkownicy[i].id < 10) {
			std::cout << "0" << uzytkownicy[i].id << "  ";
		}
		else {
			std::cout << uzytkownicy[i].id << "  ";
		}
		std::cout << uzytkownicy[i].nr_konta << "   ";
		std::cout << std::left << std::setw(10) << uzytkownicy[i].imie;
		std::cout << std::left << std::setw(12) << uzytkownicy[i].drugie_imie;
		std::cout << std::left << std::setw(14) << uzytkownicy[i].nazwisko;
		std::cout << std::left << std::setw(16) << uzytkownicy[i].adres;
		std::cout << std::left << std::setw(12) << uzytkownicy[i].miasto;
		std::cout << std::left << uzytkownicy[i].kod_pocztowy << "   ";
		std::cout << uzytkownicy[i].pesel << "   ";
		std::cout << uzytkownicy[i].nr_telefonu << "   ";
		std::cout << std::left << std::setw(6) << uzytkownicy[i].debet << "   ";
		std::cout << std::left << std::setw(12) << uzytkownicy[i].saldo << "   " << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
}

void pokaz_transakcje(std::vector<s_trans>& transakcje)
{
	std::cout << "--------------------<>--------------------" << std::endl;
	std::cout << "Zestawienie wszystkich transakcji w banku:" << std::endl;

	std::cout << "id   nr_trans  data             kwota          rodzaj    konto" << std::endl;
	for (int i = 1; i < transakcje.size(); i++) {

		if (transakcje[i].id < 10) {
			std::cout << "0" << transakcje[i].id << "   ";
		}
		else {
			std::cout << transakcje[i].id << "   ";
		}
		std::cout << transakcje[i].numer << "       ";
		std::cout << transakcje[i].data << "       ";
		std::cout << std::setw(12) << transakcje[i].kwota << "     ";
		std::cout << std::left << std::setw(3) << transakcje[i].rodzaj << "     ";
		std::cout << transakcje[i].konto << "   " << std::endl;

	}
	std::cout << "------------------------------------------" << std::endl;
}

int licznik_linii(std::vector<std::vector<std::string>>& dane) {

	int l_linii = 0;
	std::ifstream plik("pliki_txt/uzytkownicy.txt");
	std::string linia;

	while (std::getline(plik, linia)) {
		l_linii++;
	}

	return l_linii;
};

int licznik_linii2(std::vector<std::vector<std::string>>& dane2) {

	int l_linii2 = 0;
	std::ifstream plik("pliki_txt/transakcje.txt");
	std::string linia;

	while (std::getline(plik, linia)) {
		l_linii2++;
	}

	return l_linii2;
};

s_data f_data(struct s_data) {
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	tm local;
	localtime_s(&local, &now_c);
	s_data data;
	data.dzien = local.tm_mday;
	data.miesiac = local.tm_mon + 1;
	data.rok = local.tm_year + 1900;
	return data;
}

std::vector<konta> tworzenie_struktur(std::vector<std::vector<std::string>>& dane, int l_linii)
{

	std::vector<konta> uzytkownicy;

	for (int i = 1; i < l_linii; i++) {

		konta klient;
		klient.id = std::stoi(dane[i][0]); // stoi - rzutowanie stringa na inta
		klient.nr_konta = dane[i][1];
		klient.imie = dane[i][2];
		klient.drugie_imie = dane[i][3];
		klient.nazwisko = dane[i][4];
		klient.adres = dane[i][5];
		klient.miasto = dane[i][6];
		klient.kod_pocztowy = dane[i][7];
		klient.pesel = dane[i][8];
		klient.nr_telefonu = dane[i][9];
		klient.debet = std::stod(dane[i][10]); // stod - rzutowanie stringa na double
		klient.saldo = std::stod(dane[i][11]);
		uzytkownicy.push_back(klient);

	};

	return uzytkownicy;
}

std::vector<s_trans> tworzenie_struktur2(std::vector<std::vector<std::string>>& dane2, int l_linii2) {

	std::vector<s_trans> transakcje;

	for (int i = 1; i < l_linii2; i++) {

		s_trans operacja;
		operacja.id = std::stoi(dane2[i][0]);
		operacja.numer = std::stoi(dane2[i][1]);
		operacja.data = dane2[i][2];
		operacja.kwota = std::stod(dane2[i][3]);
		operacja.rodzaj = dane2[i][4];
		operacja.konto = dane2[i][5];

		transakcje.push_back(operacja);
	}

	return transakcje;
}

void sprawdz_saldo(std::vector<konta>& uzytkownicy, int l_linii) {

	std::string numer;
	std::cout << "Podaj numer konta:" << std::endl;
	std::cin >> numer;
	bool brak = 0;

	for (int i = 0; i < uzytkownicy.size(); i++) {

		if (numer == uzytkownicy[i].nr_konta) {
			std::cout << "STAN KONTA:  " << uzytkownicy[i].saldo << std::endl;
			brak = 1;
		}

	}

	if (brak == 0)
		std::cout << "Brak konta o podanym numerze w bazie danych." << std::endl;

}

void wplata(std::vector<konta>& uzytkownicy, std::vector<s_trans>& transakcje, s_data data) {

	double kwota = 0;
	std::string numer;
	int kontrola = 1;
	bool brak = 0;
	std::string ddata = std::to_string(data.dzien);
	std::string mdata = std::to_string(data.miesiac);
	std::string rdata = std::to_string(data.rok);

	do {

		std::cout << "Podaj kwote wplaty:" << std::endl;
		std::cin >> kwota;
		
		if (std::cin.fail()) {
		std::cerr << "Podano nieprawidlowe dane wejsciowe (nie jest to liczba)" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (kwota <= 0) {
			std::cout << "Kwota do wplacenia nie moze byc ujemna, badz rowna 0;" << std::endl;
		}
		
	} while (kwota <= 0);


	std::cout << "Podaj numer konta na ktory chcesz wplacic: " << std::endl;
	std::cin >> numer;

	
	for (int i = 0; i < uzytkownicy.size(); i++) {

		if (numer == uzytkownicy[i].nr_konta) {


			uzytkownicy[i].saldo = uzytkownicy[i].saldo + kwota;
			std::cout << "dokonano wplaty " << kwota << "zl, na konto: " << numer << std::endl;
			std::cout << "Saldo: " << uzytkownicy[i].saldo << std::endl;

			s_trans operacja;
			operacja.id = transakcje.back().id + 1;
			operacja.numer = transakcje.back().numer + 1;
			operacja.data = "0" + ddata + ".0" + mdata + "." + rdata;
			operacja.kwota = kwota;
			operacja.rodzaj = "+";
			operacja.konto = numer;
			transakcje.push_back(operacja);

			brak = 1;
		}

	}


	if (brak == 0)
		std::cout << "Brak konta o podanym numerze w bazie danych." << std::endl;

}

void wyplata(std::vector<konta>& uzytkownicy, std::vector<s_trans>& transakcje, s_data data) {

	double kwota;
	std::string numer;
	double debet;
	bool brak = 0;
	std::string ddata = std::to_string(data.dzien);
	std::string mdata = std::to_string(data.miesiac);
	std::string rdata = std::to_string(data.rok);


	do {

		std::cout << "Podaj kwote do wyplaty:" << std::endl;
		std::cin >> kwota;
		if (std::cin.fail()) {
			std::cerr << "Podano nieprawidlowe dane wejsciowe (nie jest to liczba)" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (kwota <= 0) {
			std::cout << "Kwota do wyplacenia nie moze byc ujemna, badz rowna 0;" << std::endl;
		}
	} while (kwota <= 0);

	std::cout << "Podaj numer konta z ktorego chcesz wyplacic: " << std::endl;
	std::cin >> numer;

	for (int i = 0; i < uzytkownicy.size(); i++) {

		if (numer == uzytkownicy[i].nr_konta) {

			debet = uzytkownicy[i].debet;

			if (uzytkownicy[i].saldo + uzytkownicy[i].debet < kwota) {
				std::cout << "Brak wystarczajacych srodkow na koncie (uwzgledniajac potencjalny debet)." << std::endl;
			}

			else {
				uzytkownicy[i].saldo = uzytkownicy[i].saldo - kwota;
				std::cout << "dokonano wyplaty " << kwota << "zl, z konta: " << numer << std::endl;
				std::cout << "Saldo: " << uzytkownicy[i].saldo << std::endl;



				s_trans operacja;
				operacja.id = transakcje.back().id + 1;
				operacja.numer = transakcje.back().numer + 1;
				operacja.data = "0" + ddata + ".0" + mdata + "." + rdata;
				operacja.kwota = kwota;
				operacja.rodzaj = "-";
				operacja.konto = numer;
				transakcje.push_back(operacja);

			}


			brak = 1;
		}

	}

	if (brak == 0)
		std::cout << "Brak konta o podanym numerze w bazie danych." << std::endl;


}

void przelew(std::vector<konta>& uzytkownicy, std::vector<s_trans>& transakcje, s_data data) {

	double kwota = 0.0;
	std::string numer1;
	std::string numer2;
	double debet;
	bool brak = 0;
	std::string ddata = std::to_string(data.dzien);
	std::string mdata = std::to_string(data.miesiac);
	std::string rdata = std::to_string(data.rok);

	do {
		std::cout << "Podaj kwote przelewu:" << std::endl;
		std::cin >> kwota;
		if (std::cin.fail()) {
			std::cerr << "Podano nieprawidlowe dane wejsciowe (nie jest to liczba)" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (kwota <= 0)
			std::cout << "Kwota przelewu musi byc dodatnia." << std::endl;
	} while (kwota <= 0);

	std::cout << "Podaj numer konta nadawcy przelewu: " << std::endl;
	std::cin >> numer1;

	for (int i = 0; i < uzytkownicy.size(); i++) {

		if (numer1 == uzytkownicy[i].nr_konta) {

			debet = uzytkownicy[i].debet;
			if (uzytkownicy[i].saldo + uzytkownicy[i].debet < kwota) {
				std::cout << "Brak wystarczajacych srodkow na koncie, aby wykonac przelew (uwzgledniajac potencjalny debet)." << std::endl;
				brak = 1;
				break;
			}
			else
				std::cout << "Podaj numer konta odbiorcy przelewu: " << std::endl;
			std::cin >> numer2;
			for (int j = 0; j < uzytkownicy.size(); j++) {

				if (numer2 == uzytkownicy[j].nr_konta) {

					uzytkownicy[i].saldo = uzytkownicy[i].saldo - kwota;
					uzytkownicy[j].saldo = uzytkownicy[j].saldo + kwota;

					std::cout << kwota << " zl zostalo przelane na konto: " << numer2 << ";" << std::endl;

					s_trans operacja;
					operacja.id = transakcje.back().id + 1;
					operacja.numer = transakcje.back().numer + 1;
					operacja.data = "0" + ddata + ".0" + mdata + "." + rdata;
					operacja.kwota = kwota;
					operacja.rodzaj = "-";
					operacja.konto = numer1;
					transakcje.push_back(operacja);

					operacja.id = transakcje.back().id + 1;
					operacja.numer = transakcje.back().numer + 1;
					operacja.data = "0" + ddata + ".0" + mdata + "." + rdata;
					operacja.kwota = kwota;
					operacja.rodzaj = "+";
					operacja.konto = numer2;
					transakcje.push_back(operacja);




				}
				

			}

			brak = 1;

		}
		



	}


	if (brak == 0)
		std::cout << "Brak konta o podanym numerze w bazie danych." << std::endl;


}

void zwrot(std::vector<konta>& uzytkownicy, std::vector<s_trans>& transakcje, char& last) {

	int again = 0;
	char potw;
	std::cout << "Czy na pewno chcesz dokonac zwrotu ostatniej transakcji?" << std::endl;
	std::cout << "T - tak/ N - nie" << std::endl;

	std::cin >> potw;
	if ((potw == 'T') or (potw == 't')) {

		if (last == '+') {
			if (transakcje.back().rodzaj == "+")
			{
				double kwota = transakcje.back().kwota;
				std::string numer = transakcje.back().konto;

				for (int i = 0; i < uzytkownicy.size(); i++) {

					if (numer == uzytkownicy[i].nr_konta) {
						uzytkownicy[i].saldo = uzytkownicy[i].saldo - kwota;
						std::cout << "Pozytywnie cofnieto transakcje o nr: " << transakcje.back().numer << std::endl;
						transakcje.pop_back(); // metoda usuniecia zaw ostat adresu wektora

					}
				}

			}
		}
		else if (last == '-') {
			if (transakcje.back().rodzaj == "-")
			{
				double kwota = transakcje.back().kwota;
				std::string numer = transakcje.back().konto;

				for (int i = 0; i < uzytkownicy.size(); i++) {

					if (numer == uzytkownicy[i].nr_konta) {

						uzytkownicy[i].saldo = uzytkownicy[i].saldo + kwota;
						std::cout << "Pozytywnie cofnieto transakcje o nr: " << transakcje.back().numer << std::endl;
						transakcje.pop_back(); // metoda usuniecia zaw ostat adresu wektora

					}
				}
			}
		}
		else if (last == 'p') {

			double kwota = transakcje.back().kwota;
			std::string numer1 = transakcje.back().konto;
			std::string numer2 = transakcje[transakcje.size() - 2].konto; // numer2 = rozmiar wektora transakce z elementem nr konta pomniejszony o dwa co daje przedostatni rekord wektora. 

			for (int i = 0; i < uzytkownicy.size(); i++) {

				if (numer1 == uzytkownicy[i].nr_konta) {

					uzytkownicy[i].saldo = uzytkownicy[i].saldo - kwota;
					transakcje.pop_back(); // metoda usuniecia zaw ostat adresu wektora
				}
				if (numer2 == uzytkownicy[i].nr_konta) {

					uzytkownicy[i].saldo = uzytkownicy[i].saldo + kwota;
					transakcje.pop_back(); // metoda usuniecia zaw ostat adresu wektora (w tym wypadku przedostat jest ostat)
					std::cout << "Pozytywnie cofnieto ostatni wykonany przelew" << std::endl;
				}

			}


		}
		else
			std::cout << "Nie ma ostatniej operacji w bazie. Ostatnia operacja moze ulec cofnieciu do chwili wylogowania sie z systemu.";

	}
	else if ((potw == 'N') or (potw == 'n')) {
		std::cout << "Anulowano cofniecie ostatniej transakcji" << std::endl;
	}
	else {
		std::cerr << "Nie udzielono wlasciwej odpowiedzi" << std::endl;
	}



}

s_zakres f_zakres() {

	s_zakres zakres;
	char kropa = 'a';

	std::cout << "Podaj date poczatku zakresu (dd.mm.rrrr): " << std::endl;
	std::cin >> zakres.dzien1 >> kropa >> zakres.miesiac1 >> kropa >> zakres.rok1;

	std::cout << "Podaj date konca zakresu (dd.mm.rrrr): " << std::endl;
	std::cin >> zakres.dzien2 >> kropa >> zakres.miesiac2 >> kropa >> zakres.rok2;

	std::cout << "Podaj dolny prog finansowy dla raportu: " << std::endl;
	std::cin >> zakres.p_finan;

	std::cout << "Podaj gorny prog finansowy dla raportu: " << std::endl;
	std::cin >> zakres.k_finan;


	return zakres;
}

bool zakres_dat(std::vector<s_trans>& transakcje, s_zakres zakres, int &licznik) {

		int i_dzien, i_miesiac, i_rok;
		sscanf_s(transakcje[licznik].data.c_str(), "%d.%d.%d", &i_dzien, &i_miesiac, &i_rok);
		//Argument date.c_str() jest wskaŸnikiem do tablicy znaków zawieraj¹cej wartoœæ transakcje[1].data. Formatowanie "%d.%d.%d" oznacza, ¿e funkcja sscanf powinna wczytaæ trzy liczby ca³kowite oddzielone kropkami i zapisaæ je w trzech zmiennych.

		if (i_rok >= zakres.rok1 && i_rok <= zakres.rok2) {
			if (i_rok > zakres.rok1 && i_rok < zakres.rok2) {
				return true;
			}
			else {
				if (i_miesiac >= zakres.miesiac1 && i_miesiac <= zakres.miesiac2) {
					if (i_miesiac > zakres.miesiac1 && i_miesiac < zakres.miesiac2) {
						return true;
					}
					else {
						if (i_dzien >= zakres.dzien1 && i_dzien <= zakres.dzien2) {
							return true;
						}
						else {
							return false;
						}
					}
				}
				else {
					return false;
				}
			}
		}
		else {
			return false;
		}
}

void gen_raport(std::vector<konta> uzytkownicy, std::vector<s_trans> transakcje) {

	std::cout << "Witaj! Podprogram sluzacy do generowania raportow!" << std::endl;
	std::cout << "------------------------<>------------------------" << std::endl;
	std::cout << "Jakiego raportu potrzebujesz: " << std::endl;
	std::cout << "-------------<>-------------" << std::endl;

	int operacja = 0;
	std::cout << "1. Wyciag z konta za okreslony czas;" << std::endl;
	std::cout << "2. Raport wykonanych w banku operacji;" << std::endl;
	std::cout << "3. Raport uzytkownikow, ktorzy maja debet na koncie;" << std::endl;
	std::cout << "4. Wykrywanie podejrzanych ciagow transakcji;" << std::endl;

	std::cin >> operacja;

	switch (operacja) {
	case 1: {

		std::string numer;
		int ilosc = 0;
		double obrot = 0;
		bool brak = 0;

		std::cout << "Podaj numer konta dla ktorego chcesz wygenerowac wyciag: " << std::endl;
		std::cin >> numer;

		s_zakres zakres = f_zakres();

		for (int i = 0; i < uzytkownicy.size(); i++) {
			if (numer == uzytkownicy[i].nr_konta) {




				std::cout << "Spersonalizowany raport transakcji dla konta " << numer << ":" << std::endl;
				std::cout << "------------------------------------<>------------------------------------" << std::endl;

				std::cout << "id   data         numer" << std::setw(30) << "kwota     rodzaj" << std::endl;;


				for (int i = 1; i < transakcje.size(); i++) {
					if (transakcje[i].konto == numer) {
						if ((transakcje[i].kwota >= zakres.p_finan) and (transakcje[i].kwota <= zakres.k_finan) and (zakres_dat(transakcje, zakres, i))){

							if (transakcje[i].id < 10) {
								std::cout << "0" << transakcje[i].id << "   ";
							}
							else {
								std::cout << transakcje[i].id << "   ";
							}
								std::cout << transakcje[i].data << "   ";
								std::cout << transakcje[i].numer << "   ";
								std::cout << std::setw(16) << transakcje[i].kwota << "       ";
								obrot = obrot + transakcje[i].kwota;
								std::cout << transakcje[i].rodzaj << "     " << std::endl;
								ilosc++;

							if (ilosc == 0) {
								std::cout << "Brak transakcji dla tego uzytkownika we wskazaym okresie" << std::endl;
								break;
							}

						}

					}

				}

				std::cout << "Podsumowanie dla " << numer << ":" << std::endl;
				std::cout << "Laczna liczba transakcji: " << ilosc << std::endl;
				std::cout << "Laczny obrot na koncie: " << obrot << std::endl;
				std::cout << "------------------------------------------" << std::endl;
				brak = 1;
			}
		}
		if (brak == 0)
			std::cout << "Brak konta o podanym numerze w bazie danych." << std::endl;


		break;
	}
	case 2: {

		std::string numer;
		int ilosc = 0, sortowanie = 0;
		double obrot = 0;
		bool brak = 0;

		s_zakres zakres = f_zakres();

		std::cout << "Jak posortowac uzytkownikow? " << std::endl;
		std::cout << "1. Sortowanie wedlug daty transakcji;" << std::endl;
		std::cout << "2. Sortowanie wedlug kwoty transakcji;" << std::endl;
		std::cout << "3. Sortowanie wedlug numerow kont;" << std::endl;
		std::cin >> sortowanie;

		if (sortowanie == 1) {
			sort(transakcje.begin(), transakcje.end(), [](const s_trans a, const s_trans b) {
				return a.data < b.data;
				});
		}
		else if (sortowanie == 2) {
			sort(transakcje.begin(), transakcje.end(), [](const s_trans a, const s_trans b) {
				return a.kwota < b.kwota;
				});
		}
		else if (sortowanie == 3) {
			sort(transakcje.begin(), transakcje.end(), [](const s_trans a, const s_trans b) {
				return a.konto < b.konto;
				});
		}
		else {
			std::cout << "Nieznana opcja sortowania" << std::endl;
			break;
		}

		std::cout << "Spersonalizowany raport transakcji w banku Altera: " << std::endl;
		std::cout << "------------------------<>------------------------" << std::endl;
		std::cout << "id   nr_trans  data             kwota          rodzaj    konto" << std::endl;
		for (int i = 1; i < transakcje.size(); i++) {

			if ((transakcje[i].kwota >= zakres.p_finan) and (transakcje[i].kwota <= zakres.k_finan) and (zakres_dat(transakcje, zakres, i))) {

				if (transakcje[i].id < 10) {
					std::cout << "0" << transakcje[i].id << "   ";
				}
				else {
					std::cout << transakcje[i].id << "   ";
				}
				std::cout << transakcje[i].numer << "       ";
				std::cout << transakcje[i].data << "       ";
				std::cout << std::setw(12) << transakcje[i].kwota << "     ";
				obrot = obrot + transakcje[i].kwota;
				std::cout << std::left << std::setw(3) << transakcje[i].rodzaj << "     ";
				std::cout << transakcje[i].konto << std::endl;
				ilosc++;
			}
			else if (ilosc == 0) {
				std::cout << "Brak transakcji w banku we wskazaym okresie" << std::endl;
				break;
			}

			brak = 1;
		}
		if (brak == 1) {
			std::cout << "Podsumowanie:" << std::endl;
			std::cout << "Laczna liczba transakcji: " << ilosc << std::endl;
			std::cout << "Laczny obrot transakcji: " << obrot << std::endl;
			std::cout << "------------------------------------------" << std::endl;
		}

		if (brak == 0)
			std::cout << "Brak transakcji w bazie dla podanych wytycznych." << std::endl;

		break;
	}
	case 3: {

		int sortowanie = 0;
		bool brak = 0;

		std::cout << "Jak posortowac uzytkownikow? " << std::endl;
		std::cout << "1. Sortowanie wedlug nazwisk;" << std::endl;
		std::cout << "2. Sortowanie wedlug numerow kont;" << std::endl;
		std::cin >> sortowanie;

		if (sortowanie == 1) {
			sort(uzytkownicy.begin(), uzytkownicy.end(), [](const konta a, const konta b) {
				return a.nazwisko < b.nazwisko;
				});
		}
		else if (sortowanie == 2) {
			sort(uzytkownicy.begin(), uzytkownicy.end(), [](const konta a, const konta b) {
				return a.nr_konta < b.nr_konta;
				});
		}
		else {
			std::cout << "Nieznana opcja sortowania" << std::endl;
			break;
		}

		std::cout << "Raport uzytkownikow z debetem na koncie: " << std::endl;

		std::cout << "id  nr_konta_bankowego             imie        nazwisko      pesel       dost_debet    saldo " << std::endl;
		for (int i = 1; i < uzytkownicy.size(); i++) {

			if (uzytkownicy[i].saldo < 0) {
				std::cout << uzytkownicy[i].id << "   ";
				std::cout << uzytkownicy[i].nr_konta << "   ";
				std::cout << std::left << std::setw(12) << uzytkownicy[i].imie;
				std::cout << std::left << std::setw(14) << uzytkownicy[i].nazwisko;
				std::cout << std::left << std::setw(12) << uzytkownicy[i].pesel << "      ";
				std::cout << std::setw(10) << uzytkownicy[i].debet << " ";
				std::cout << std::setw(10) << uzytkownicy[i].saldo << std::endl;

				brak = 1;
			}
		}
		if (brak == 0) {
			std::cout << "----------------------------------------" << std::endl;
			std::cout << "Brak uzytkownikow z ujemnym stanem konta" << std::endl;
		}

		break;
	}
	case 4: {
		bool brak = 0;
		std::vector<s_trans> podejrzane_ciagi;

		std::cout << "Raport podejrzanych ciagow transakcji w bazie: " << std::endl;
		std::cout << "----------------------<>----------------------" << std::endl;

		for (int i = 1; i < transakcje.size(); i++) {
			podejrzane_ciagi.clear();
			for (int j = i; j < transakcje.size() - 1; j++) {
				if (transakcje[j].kwota >= transakcje[j + 1].kwota) {
					podejrzane_ciagi.push_back(transakcje[j + 1]);
				}
				else {
					break;
				}
			}

			if (podejrzane_ciagi.size() >= 3) {
				for (int k = 1; k < podejrzane_ciagi.size(); k++) {
					if (podejrzane_ciagi[k].kwota == transakcje[i].kwota and podejrzane_ciagi[k].konto == transakcje[i].konto) {
						brak = 1;
						std::cout << "Ciagi: " << std::endl;
						std::cout << "   nr_trans  data     rodzaj              konto            kwota" << std::endl;
						for (int m = i; m <= i + podejrzane_ciagi.size(); m++) {
							std::cout << m + 1 << ".  " << transakcje[m].numer << "  "
								<< transakcje[m].data << "    " << transakcje[m].rodzaj
								<< "   " << transakcje[m].konto << "   " << transakcje[m].kwota << std::endl;
						}
						break;
					}
				}
			}
		}

		if (brak == 0) {
			std::cout << "Brak podejrzanych ciagow transakcji." << std::endl;
		}
	}
	}


}

void zapis_struktury(std::vector<konta>& uzytkownicy, std::vector<s_trans>& transakcje) {

	std::ofstream plik1("pliki_txt/uzytkownicy.txt");
	if (plik1.is_open()) {
		plik1 << "/ nr_konta_bankowego imie drugie_imie nazwisko adres miasto kod_pocztowy pesel nr_telefonu debet saldo" << std::endl;
		for (const auto& x : uzytkownicy) {
			plik1 << x.id << " " << x.nr_konta << " " << x.imie << " " << x.drugie_imie << " " << x.nazwisko
				<< " " << x.adres << " " << x.miasto << " " << x.kod_pocztowy << " " << x.pesel << " "
				<< x.nr_telefonu << " " << x.debet << " " << x.saldo << std::endl;
		}
		plik1.close();
	}

	std::ofstream plik2("pliki_txt/transakcje.txt");
	if (plik2.is_open()) {
		plik2 << "id  nr_trans data		 kwota  rodzaj  konto" << std::endl;
		for (const auto& x : transakcje) {
			plik2 << x.id << " " << x.numer << " " << x.data << " " << x.kwota << " " << x.rodzaj << " " << x.konto << std::endl;
		}
		plik2.close();
	}


}

bool wyjscie(bool& re_menu) {

	re_menu = 0;
	std::cout << "Do zobaczenia niebawem! (:" << std::endl;
	return re_menu;
}

