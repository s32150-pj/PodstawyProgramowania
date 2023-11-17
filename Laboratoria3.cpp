// Laboratoria3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <windows.h>
#include <string> 
#include <cstring> 
#include <iomanip> 

using namespace std;

float sprawdz_czy_liczba(char a) {
    
    string liczba1s;
    char liczba = a;
    boolean warunek = false;
    int przecinek = 0;

    
    cout << "Proszę podać liczbę numer "<<liczba<<": " << endl;

    do {
        cin >> liczba1s;
       
        for (int i = 0; i < liczba1s.length(); i++) {
            if(liczba1s.length()==1)
            {
                if (isdigit(liczba1s[i])) { warunek = true; continue; }
                else { cout << "Podano nieprawidłową wartość. Wprowadź liczbę rzeczywistą." << endl; break; }
            }
            if (i == 0) {
                if (isdigit(liczba1s[i]) && (liczba1s[i] != '0')) {
                    
                    if (liczba1s.length() ==1) { warunek = true; }
                    continue; }
                else if (liczba1s[i] = '-') { continue; }
                else {
                    cout << "Podano nieprawidłową wartość. Wprowadź liczbę rzeczywistą." << endl;
            break; } }
            else {
                if (isdigit(liczba1s[i])) {  if (i == (liczba1s.length() - 1)) { warunek = true; }
                 continue; }
                else if (liczba1s[i] == ',' || liczba1s[i] == '.') {
                    if (liczba1s[i] == '.') { liczba1s[i] = ','; continue; }
                    if (przecinek == 0) { przecinek = 1; continue; }
                    else {
                        cout << "Podano nieprawidłową wartość. Wprowadź liczbę rzeczywistą." << endl;
                        
                        przecinek = 0;
                        break;
                    }
                
                }
                else {
                    cout << "Podano nieprawidłową wartość. Wprowadź liczbę rzeczywistą." << endl; break;
                }
            }
            
        }

    } while (warunek != true);

    const char* liczba1s_converted = liczba1s.c_str();
    
  
     return stof(liczba1s_converted);
}
void zadanie1() {
    
 float liczba1, liczba2;
    
 liczba1 = sprawdz_czy_liczba('1');
 liczba2 = sprawdz_czy_liczba('2');

 cout <<endl<<endl<<"Pierwsza podana liczba to: " << fixed << setprecision(2) << liczba1 << endl;
 cout << "Druga podana liczba to: " <<fixed<<setprecision(2)<< liczba2 << endl << endl;

 cout << "Oto wyniki działań dla podanych liczb:" << endl << endl;
 cout << "Różnica: "<< liczba1 << " - " << liczba2 << " = " <<setprecision(2)<< liczba1 - liczba2<<endl;
 cout << "Suma: " << liczba1 << " + " << liczba2 << " = " << liczba1 + liczba2<<endl;
 cout << "Iloczyn: " << liczba1 << " x " << liczba2 << " = " << liczba1 * liczba2<<endl;
 cout << "Iloraz: " << liczba1 << " : " << liczba2 << " = " << liczba1 / liczba2<<endl;

}


void zadanie2() {
    string liczba1s;
    boolean warunek = false;
    int przecinek = 0;


    

    do {
        cout << "Wprowadź kolejny znak:  " << endl;
        cin >> liczba1s;
        if (liczba1s.length() > 1) { cout <<endl<< "Możesz podać tylko jeden znak."<<endl; }
        else {
            if (liczba1s[0] =='t') {
                cout << "Podano znak \"t\". Koniec programu." << endl << endl;
                warunek = true;
            }
            else { cout << endl << "Wprowadzony znak to " << liczba1s[0] << endl; }
                }

        } while (warunek != true);
    

}
void zadanie3() {
    string liczba1s;
    boolean warunek = false;
    float liczba_A,liczba_B,liczba_C;


    cout << endl << "Równanie kwadratowe to równanie postaci ax^2 + bx + c = 0 " << endl<<endl;
    do {
        cout << endl << "Liczba a nie może być 0." << endl;
        liczba_A = sprawdz_czy_liczba('A');
    } while (liczba_A == 0);
    liczba_B = sprawdz_czy_liczba('B');
    liczba_C = sprawdz_czy_liczba('C');

    cout << endl << endl << "Równanie ma postać:" << endl;
    cout << liczba_A << "x^2 + ";
    if (liczba_B > 0) { cout << " + "; }
    cout << liczba_B << "x ";
    if (liczba_C > 0) { cout << " + "; }
    cout << liczba_C << " = 0" << endl;

   
    if ((liczba_B * liczba_B - 4 * liczba_A * liczba_C) > 0) {
        cout << "x1 = " << (-liczba_B + sqrt(liczba_B * liczba_B - 4 * liczba_A * liczba_C)) / (2 * liczba_A)<<endl;
        cout << "x2 = " << (-liczba_B - sqrt(liczba_B * liczba_B - 4 * liczba_A * liczba_C)) / (2 * liczba_A)<<endl;
    }

     else if((liczba_B * liczba_B - 4 * liczba_A * liczba_C) == 0) {
        cout << "x1 = x2 = "<< (-liczba_B + sqrt(liczba_B * liczba_B - 4 * liczba_A * liczba_C)) / (2 * liczba_A)<<endl;
    }
     else { cout << "Brak rozwiązań w zbiorze liczb rzeczywsitych"<<endl; }
}

int podaj_liczbe() {
    string liczba1s;
    char liczba;
    boolean warunek = false;
    int przecinek = 0;


    do {
        cout << "Podaj liczbę calkowitą" << endl;
        cin >> liczba1s;

        for (int i = 0; i < liczba1s.length(); i++) {
            
           
                if (isdigit(liczba1s[i])) {
                    if (i == (liczba1s.length() - 1)) { warunek = true; }
                    continue;
                }
                else {
                   cout << "Podano nieprawidłową wartość. Wprowadź liczbę rzeczywistą." << endl; break;
                
                }
        }
    } while (warunek != true);

    const char* liczba1s_converted = liczba1s.c_str();


    return stoi(liczba1s_converted);
}
int licz_wartosc(int n, int k)
{
    int a = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i) {
        a *= (n - i);
        a /= (i + 1);
    }

    return a;
}
void zadanie4(int n)
{
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            cout << " " << licz_wartosc(i, j);
        cout << endl;
    }
}



int main()
{
    setlocale(LC_ALL, "");   // Allow to display letters with diacritics
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h, 3);
    cout << " ZADANIE 1" << endl << endl;
    
    zadanie1();
    SetConsoleTextAttribute(h, 4);
    cout << " ZADANIE 2" << endl << endl;
    zadanie2();
    
    SetConsoleTextAttribute(h, 5);
    cout << " ZADANIE 3" << endl << endl;
    zadanie3();
   
    SetConsoleTextAttribute(h, 6);
    cout << " ZADANIE 4" << endl << endl;
    zadanie4(podaj_liczbe());
    return 0;
    
   
}

