// Lab5.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool sprawdz_wartosc_int(string a) {

	for (int i = 0; i < a.length(); i++) {
	if(isdigit(a[i])){continue;}
	else { cout << "Podana wartość jest nieprawidłowa. Podaj lczbę całkowitą." << endl; return false; }
	}
	return true;
}
void zadanie2() {

	int rozmiar_tablicy;
	string test_value;
	string* test_value_pointer = &test_value;
	string a;

	cout << "Ile wartosci ma zawierać tablica? " << endl;
	do {
		cin >> test_value;
	} while (sprawdz_wartosc_int(test_value) == false);

	int pomocnicza_wartosc = 0;

	rozmiar_tablicy = stoi(test_value);
	if (rozmiar_tablicy % 2 == 1) { rozmiar_tablicy = rozmiar_tablicy + 1; pomocnicza_wartosc = 1; }
	int* table = new int[rozmiar_tablicy];
	
	if (pomocnicza_wartosc == 0) {
		for (int i = 0; i < rozmiar_tablicy;i++) {
			cout << "Podaj liczbę całkowitą: " << endl;

			do { cin >> a; } while (!sprawdz_wartosc_int(a));
			table[i] = stoi(a);
		}
	
	}
	else {
	
		for (int i = 0; i < rozmiar_tablicy-1;i++) {
			cout << "Podaj liczbę całkowitą: " << endl;
			
			do { cin >> a; } while (!sprawdz_wartosc_int(a));
			table[i] = stoi(a);
		}
		table[rozmiar_tablicy-1] = 0;
	}
	cout << endl;

	for (int i = 0; i < (rozmiar_tablicy / 2); i++)
	{
		cout << table[i] << "    |     " << table[(rozmiar_tablicy / 2)+i] << endl;
	}

	int bufor;
	for (int i = 0; i < (rozmiar_tablicy / 2); i++)
	{
		bufor = table[i];
		table[i] = table[(rozmiar_tablicy / 2) + i];
		table[(rozmiar_tablicy / 2) + i] = bufor;

	}
	cout << endl << endl;
	for (int i = 0; i < (rozmiar_tablicy / 2); i++)
	{
		cout << table[i] << "    |     " << table[(rozmiar_tablicy / 2) + i] << endl;
	}

}
void zadanie1() {

	cout << "Podaj liczbę elementów wektora: " << endl;
	bool logic_variable = false;
	string liczba_elementow;
	vector <string> wektor;

	do {
		cin >> liczba_elementow;
		logic_variable = sprawdz_wartosc_int(liczba_elementow);

	} while (logic_variable!=true);

	logic_variable = false;
	string a;
	int liczba_elemetow_int = stoi(liczba_elementow);

	for (int i = 0; i < liczba_elemetow_int; i++) {
		cout << "Podaj liczbę calkowita" << endl;
		do {
			cin >> a;
			logic_variable = sprawdz_wartosc_int(a);

		} while (logic_variable != true);
		wektor.push_back(a);
		logic_variable = false;
	}

	int najwieksza_wartosc = stoi(wektor[0]);
	int index_najwieksza_wartosc = 0;


	for (int i = 1; i < liczba_elemetow_int; i++) {
	
		if (stoi(wektor[i]) > najwieksza_wartosc) {
			najwieksza_wartosc = stoi(wektor[i]);
			index_najwieksza_wartosc = i;
		}
	}

	cout << "Najwieksza wartosc to " << najwieksza_wartosc << endl;
	cout << "Numer indeksu: " << index_najwieksza_wartosc << endl << endl;
}

int main()
{
	setlocale(LC_ALL, "");
	cout << endl << endl << "Zadanie 5.1" << endl << endl;
	zadanie1();

	cout << endl << endl << "Zadanie 5.2" << endl << endl;
	zadanie2();
}


