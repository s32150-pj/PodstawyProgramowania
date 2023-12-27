// Lab6.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string> 
#include <vector>
#include<algorithm>


using namespace std;

bool if_contains(string a) { 

    string Oceny[6] = { "1","2","3","4","5","6" }; 

for (int i = 0; i < 6; i++) {
    if (a == Oceny[i]) { return true; }
}
cout << "Nie ma takiej oceny. Podaj liczbę całkowitą od 1 do 6." << endl;
return false;
}

bool if_contains2(string a) {

    string Uczniowie[6] = { "1","2","3","4" };

    for (int i = 0; i < 4; i++) {
        if (a == Uczniowie[i]) { return true; }
    }
    cout << "Nie przedmiotu o takim numerze. Podaj liczbę całkowitą od 1 do 4." << endl;
    return false;
}

bool check_number(string a) {


    for (int i = 0; i < a.length(); i++) {
        if (isdigit(a[i])) { continue; }
        else { 
            cout << "Podano niewłaściwą wartość. " << endl;
            return false; }
    }

    return true;
}

void zadanie1() {
    string a;
    int b;
    int licznik=0;
    cout << "Zadanie 6.1" << endl << endl;
    cout << "Podaj liczbę naturalną:"<<endl;
    do{
        cin >> a;
    } while (!check_number(a));

    b = stoi(a);

    for (int i = 1; i <= b; i++) {
        if (i % 5 == 0 && i % 3 != 0) { cout << i << endl; licznik += 1; }
    }

    cout << "Jest dokładnie " <<licznik << " liczb naturalnych podzielnych przez 5 i nie podzielnych przez 3, które są nie większe " << b << "." << endl;
}

void zadanie2() {
    string Tablica[6][5];
    
    string Przedmioty[]={ " ","informatyki", "matematyki", "biologii", "polskiego" };
    for (int j = 0; j < 6; j++) {
        cout << endl<<"Podaj imię ucznia numer " << j + 1 << ": " << endl;
        cin >> Tablica[j][0];
        for (int i = 1; i < 5; i++) {
            cout << "Podaj ocenę z  " << Przedmioty[i] << " ucznia o imieniu " << Tablica[j][0] << ": ";
            do {
                cin >> Tablica[j][i];
            } while (!check_number(Tablica[j][i])||(!if_contains(Tablica[j][i])));
        }
    }

    string liczba_pytan,numer_ucznia,numer_przedmiotu;
    int liczba_pytan_int;

    cout << "Podaj liczbę twoich zapytań:" << endl;
    do { cin >> liczba_pytan; } while (!check_number(liczba_pytan));

    liczba_pytan_int = stoi(liczba_pytan);

    for(int i=0;i<liczba_pytan_int;i++){

        cout << "Podaj numer ucznia" << endl;
        do { cin >> numer_ucznia; } while (!if_contains(numer_ucznia));

        cout << "Podaj numer przedmiotu" << endl;
        do { cin >> numer_przedmiotu; } while (!if_contains2(numer_przedmiotu));

        cout << " Ocena ucznia  " << Tablica[stoi(numer_ucznia)-1][0] << " z  " << Przedmioty[stoi(numer_przedmiotu)] << " to " 
            << Tablica[stoi(numer_ucznia)][stoi(numer_przedmiotu)] << "." << endl;
    
    }
}

 void zadanie4() {
     string string_uzytkownika;
     string output;
     string ilosc;
     int ilosc_int;

     cout << "Wprowadz napis, na którym dokonana zostanie konkatenacja:" << endl;
     cin >> string_uzytkownika;
     cout << "Podaj ile razy ma zostać dokonana konkatenacja:" << endl;
     do {
         cin >> ilosc;
     } while (!check_number(ilosc));

     ilosc_int = stoi(ilosc);

     for (int i = 0; i < ilosc_int; i++) {
         if (i > 0) {
             output = output + " " + string_uzytkownika;
         }
         else { output = string_uzytkownika; }
     }

     cout << output;
 }
 void zadanie3() {

    vector<vector<string>> wynik;
     vector<vector<string>> wektor_studenci

     {
         {"72165", "Leo", "Kowal"},
         {"783","Maciej","Demp"},
         {"2600000", "Alicja", "Kolecka"},
         {"15","Katarzyna","Szczaw"},
         {"222","Tomasz","Gajowy"},
     {"455","Justyna","Kojot"}
     };

     vector<int> indeksy;
     cout << endl << endl << "Wektor przed posortowaniem" << endl ;
     for (int i = 0; i < wektor_studenci.size(); i++) 
     {
         cout << endl;
        for (int j = 0; j < wektor_studenci[i].size(); j++)
         {
             cout << " " << wektor_studenci[i][j]; 
        }
     }
   

     for (int i = 0; i < wektor_studenci.size(); i++) {
         indeksy.push_back(stoi(wektor_studenci[i][0]));
     }

     sort(indeksy.begin(), indeksy.end());

     int bufor;
     cout << endl << endl << "Posortowany wektor" << endl ;
     string value;
     for (int i = 0; i < indeksy.size(); i++) { 
         bufor = 0;
         for (int j = 0; j < indeksy.size(); j++) {
          if(stoi(wektor_studenci[j][0])==indeksy[i]){
              bufor = j;
              break;
          }
         }
         wynik.push_back(std::vector<string>());
         for (int j = 0; j < wektor_studenci[i].size(); j++) {
             //value = wektor_studenci[bufor][j];
             wynik[i].push_back(wektor_studenci[bufor][j]);     
         }
        
     }

     for (int i = 0; i < wynik.size(); i++) { cout << endl; for (int j = 0; j < wynik[i].size(); j++) { cout <<" "<< wynik[i][j]; } }
     


     cout << endl << endl;
 }

int main()
{
    setlocale(LC_ALL, "");
    zadanie1();
    zadanie2();
    zadanie3();
    zadanie4();
}

