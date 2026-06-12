#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Skin {
	string nazwa;
	string jakosc;
	float cena;
	bool stattrak;
};

Skin inwentarz[100];
int ilosc = 0;
const string plik = "ekwipunek.txt";

void wczytaj() {
	ifstream wejscie(plik);
	if (!wejscie.is_open()) return;

	ilosc = 0;
	string nazwa, jakosc, cena_tmp, st_tmp;
	while (getline(wejscie, nazwa) && getline(wejscie, jakosc) && getline(wejscie, cena_tmp) && getline(wejscie, st_tmp)) {
		if (ilosc < 100) {
			inwentarz[ilosc].nazwa = nazwa;
			inwentarz[ilosc].jakosc = jakosc;
			inwentarz[ilosc].cena = stof(cena_tmp);
			inwentarz[ilosc].stattrak = (st_tmp == "1");
			ilosc++;
		}
	}
	wejscie.close();
}

void zapisz() {
	ofstream wyjscie(plik);
	for (int i = 0; i < ilosc; i++) {
		wyjscie << inwentarz[i].nazwa << "\n"
			<< inwentarz[i].jakosc << "\n"
			<< inwentarz[i].cena << "\n"
			<< inwentarz[i].stattrak << "\n";
	}
	wyjscie.close();
}

void wyswietl() {
	if (ilosc == 0) {
		cout << "Ekwipunek jest pusty. \n";
		return;
	}
	float suma = 0;
	cout << "\n --- Ekwipunek --- \n";
	for (int i = 0; i < ilosc; i++) {
		cout << "[" << i << "]" << inwentarz[i].nazwa
			<< " | " << inwentarz[i].jakosc
			<< " | " << inwentarz[i].cena << " PLN";
		if (inwentarz[i].stattrak) {
			cout << " | Stattrak ";
		}
		cout << "\n";
		suma = suma + inwentarz[i].cena;
	}
	cout << "---------------\n";
	cout << "Laczna wartosc: " << suma << "PLN \n";
}

void dodaj() {
	if (ilosc >= 100) {
		cout << "Brak miejsca \n";
		return;
	}
	cout << "Nazwa skina (np. AK-47 Redline): ";
	getline(cin, inwentarz[ilosc].nazwa);

	cout << "Jakosc (np. Field-Tested): ";
	getline(cin, inwentarz[ilosc].jakosc);

	cout << "Cena: ";
	cin >> inwentarz[ilosc].cena;

	cout << "Stattrak (Tak = 1, Nie = 0): ";
	cin >> inwentarz[ilosc].stattrak;

	ilosc++;
	cout << "Dodano! \n";
}

void szukaj() {
	cout << "Szukaj: ";
	string fraza;
	getline(cin, fraza);

	bool znaleziono = false;
	for (int i = 0; i < ilosc; i++) {
		if (inwentarz[i].nazwa.find(fraza) != string::npos) {
			cout << "[" << i << "]" << inwentarz[i].nazwa
				<< "|" << inwentarz[i].jakosc
				<< "|" << inwentarz[i].cena << " PLN";
			if (inwentarz[i].stattrak) {
				cout << " | Stattrak ";
			}
			cout << "\n";
			znaleziono = true;
		}
	}
	if (!znaleziono) {
		cout << "Nie znaleziono. \n";
	}
}

void usun() {
	wyswietl();
	if (ilosc == 0) {
		return;
	}

	cout << "\n Podaj ID do usuniecia: ";
	int id;
	cin >> id;

	if (id >= 0 && id < ilosc) {
		for (int i = id; i < ilosc - 1; i++) {
			inwentarz[i] = inwentarz[i + 1];
		}
		ilosc--;
		cout << "Usunieto \n";
	}
	else {
		cout << "Nieprawidlowe ID \n";
	}
}

void sortowaniePoCenie() {
	for (int i = 0; i < ilosc - 1; i++) {
		for (int j = 0; j < ilosc - i - 1; j++) {
			if (inwentarz[j].cena > inwentarz[j + 1].cena) {
				Skin temp = inwentarz[j];
				inwentarz[j] = inwentarz[j + 1];
				inwentarz[j + 1] = temp;
			}
		}
	}
	cout << "Posortowano po cenie \n";
}

int main() {
	wczytaj();
	int wybor = 0;

	do {
		cout << "\n=== MENEDZER SKINOW ===\n";
		cout << "1. Wyswietl ekwipunek \n";
		cout << "2. Dodaj skina \n";
		cout << "3. Usun skina \n";
		cout << "4. Szukaj \n";
		cout << "5. Sortowanie po cenie \n";
		cout << "0. Zapisz i wyjdz \n";
		cout << "Wybierz: ";
		cin >> wybor;
		cin.ignore();

		switch (wybor) {
			case 1: wyswietl(); break;
			case 2: dodaj(); break;
			case 3: usun(); break;
			case 4: szukaj(); break;
			case 5: sortowaniePoCenie(); break;
			case 0: zapisz(); cout << "Zapisano \n"; break;
			default: cout << "Nie wybrales dobrze \n";
		}
	} while (wybor != 0);

	return 0;
}