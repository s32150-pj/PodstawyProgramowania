// Laboratoria2.cpp : 
//

#include <iostream>


#include <iostream>
#include <windows.h>
#include <string> 
#include <cstring> 

    using namespace std;

    int main(){
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // allow to set colour of text displayed in the console
        setlocale(LC_ALL, "");
        SetConsoleTextAttribute(h, 3);
        cout << "Zadanie 1.1" << endl << endl;
        SetConsoleTextAttribute(h, 7);
        cout << " Grzegorz Łazarczyk " << endl;
        cout << " s32150 " << endl;
        cout << " Polsko-Japońska Akademia Technik Komputerowych " << endl;
        cout << endl;

        //Zadanie 1

        string ilosc_iteracji;
        int suma, ilosc_iteracji_conv;

        boolean condition = false;

        cout << "Proszę podać liczbę n, dla której mam policzyć sumę szeregu." << endl;
        int tabela[1000];

        do {
            cin >> ilosc_iteracji;
            for (int i = 0; i < ilosc_iteracji.length(); i++) {

                if (!isdigit(ilosc_iteracji[i])) {
                    cout << "Podałeś niewłaściwą wartość, wprowadź dodatnią liczbę całkowitą" << endl;
                    break;
                }
                if (i == ilosc_iteracji.length() - 1) { condition = true; };
            }
        } while (condition == false);

        ilosc_iteracji_conv = stoi(ilosc_iteracji);

        for (int i = 1; i <= ilosc_iteracji_conv; i++)
        {
            suma = 0;
            for (int j = 1; j < i; j++)
            {
                cout << j << " + ";
                suma = suma + j;
            }
            cout << i << " = " << suma + i << endl;
            tabela[i] = suma + i;

        }
        suma = 0;
        cout << endl << endl;
        cout << "Suma szeregu wynosi: ";

        for (int i = 1; i <= ilosc_iteracji_conv; i++) {
            if (i == 1) { cout << tabela[i]; }
            else {
                cout << " + " << tabela[i];
            }
            suma = suma + tabela[i];
        }
        cout << " = " << suma<<endl<<endl;

        //Zadanie 2

        cout << endl << endl;
        int a, b;
        string input_a, input_b;
        boolean condition2 = false;
        cout << "Proszę podać dodatnią liczbę całkowitą a: " << endl;


        do {
            cin >> input_a;
            for (int i = 0; i < input_a.length(); i++) {

                if (!isdigit(input_a[i])) {
                    cout << "Podałeś niewłaściwą wartość, wprowadź dodatniź liczbę całkowitą" << endl;
                    break;
                }
                if (i == input_a.length() - 1) { condition2 = true; };
            }
        } while (condition2 == false);

        condition2 = false;

        cout << "Proszę podać drugą dodatnią liczbę całkowitą b: " << endl;

        do {
            cin >> input_b;
            for (int i = 0; i < input_b.length(); i++) {

                if (!isdigit(input_b[i])) {
                    cout << "Podałeś niewłaściwą wartość, wprowadź dodatnią liczbę całkowitą" << endl;
                    break;
                }
                if (i == input_b.length() - 1) { condition2 = true; };
            }
        } while (condition2 == false);
        a = stoi(input_a);
        b = stoi(input_b);

        cout << endl << endl;
        cout << "Pierwsza podana liczba to: " << a << "." << endl;
        cout << "Druga podana liczba to: " << b << "." << endl;

        cout << endl << endl;

        cout << "Wiersz gwiazdek o długości " << a <<"."<< endl << endl;
        for (int i = 0; i < a; i++) { cout << "*"; }

        cout << endl << endl;

        cout << "Kolumna gwiazdek o długości " << b << "." << endl << endl;
        for (int i = 0; i < b; i++) { cout << "*" << endl; }

        cout << endl << endl;

        cout << " Wypełniony prostokąt gwiazdek o wymiarach " << a << " na " << b << "." << endl << endl;

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
        cout << endl << endl;

        cout << "Obramowanie prostokąta gwiazdek o wymiarach " << a << " na " << b << endl << endl;

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if ((i == 0) || (i == (a - 1)) || (j == 0) || (j == (b - 1)))
                {
                    cout << "*";
                }
                else { cout << " "; }
            }
            cout << endl;
        }

        cout << endl << endl;
        cout << "Trójkąt prostokątny równoramienny o przyprostokątnych długości " << a << " z kątem prostym w lewym dolnym rogu."<< endl << endl;

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
        cout << endl << endl;
        cout << "Trójkąt prostokątny równoramienny o przyprostokątnych długości " << a << " z kątem prostym w prawym górnym rogu." << endl << endl;

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                if (j >= i) {
                    cout << "*";
                }
                else { cout << " "; }
            }
            cout << endl;
        }
        cout << endl << endl;

        //Zadanie 3

        int miesiac_conv;
        string miesiac;
        condition2 = false;
        cout << "Proszę podać liczbę całkowitą z przedziału 1-12: " << endl << endl;

        do {
            cin >> miesiac;
            for (int i = 0; i < miesiac.length(); i++) {

                if (!isdigit(miesiac[i])) {
                    cout << "Podałeś niewłaściwą wartość, wprowadz dodatnia liczbę całkowitą z przedziału 1-12." << endl;
                    break;
                }


                if (i == input_a.length() - 1) {
                    miesiac_conv = stoi(miesiac);
                    if ((miesiac_conv >= 1) && (miesiac_conv <= 12)) { condition2 = true; }
                    else { cout << "Liczba poza zakresem. Podaj prawidłową wartość(liczba całkowita z przedziału 1-12)" << endl; break; }
                }
                //if ((i == input_a.length() - 1) && (stoi(miesiac) >= 1) && (stoi(miesiac) <= 12)) { condition2 = true; }
                //else { cout << "Liczba poza zakresem." << endl; break; }
            }
        } while (condition2 == false);

        //miesiac_conv = stoi(miesiac);

        switch (miesiac_conv) {

        case 1: cout << "Styczen" << endl; cout << "Jest pochmurno" << endl; if (miesiac_conv % 2 == 0) { cout << "Ten miesiac ma 31 dni"; }
              else { cout << "Ten miesiac ma 31 dni"; }break;
        case 2:cout << "Luty" << endl; cout << "Jest pochmurno" << endl; cout << "Ten miesiac ma 28 dni"; break;
        case 3:cout << "Marzec" << endl; cout << "Jest pochmurno" << endl; if (miesiac_conv % 2 == 0) { cout << "Ten miesiac ma 31 dni"; }
              else { cout << "Ten miesiac ma 31 dni"; } break;
        case 4:cout << "Kwiecien" << endl; cout << "Jest slonecznie" << endl; if (miesiac_conv % 2 == 0) { cout << "Ten miesiac ma 30 dni"; }
              else { cout << "Ten miesiac ma 31 dni"; }  break;
        case 5:cout << "Maj" << endl; cout << "Jest slonecznie" << endl; if (miesiac_conv % 2 == 0) { cout << "Ten miesiac ma 31 dni"; }
              else { cout << "Ten miesiac ma 31 dni"; } break;
        case 6:cout << "Czerwiec" << endl; cout << "Jest slonecznie" << endl; if (miesiac_conv % 2 == 0) { cout << "Ten miesiac ma 30 dni"; }
              else { cout << "Ten miesiac ma 31 dni"; } break;
        case 7:cout << "Lipiec" << endl;  cout << "Jest slonecznie" << endl; if (miesiac_conv % 2 == 0) { cout << "Ten miesiac ma 31 dni"; }
              else { cout << "Ten miesiac ma 31 dni"; } break;
        case 8:cout << "Sierpien" << endl;  cout << "Jest slonecznie" << endl; if (miesiac_conv % 2 == 0) { cout << "Ten miesiac ma 31 dni"; }
              else { cout << "Ten miesiac ma 31 dni"; } break;
        case 9:cout << "Wrzesien" << endl;  cout << "Jest slonecznie" << endl; if (miesiac_conv % 2 == 0) { cout << "Ten miesiac ma 30 dni"; }
              else { cout << "Ten miesiac ma 31 dni"; } break;
        case 10:cout << "Pazdziernik" << endl; cout << "Jest pochmurno" << endl; if (miesiac_conv % 2 == 0) { cout << "Ten miesiac ma 31 dni"; }
               else { cout << "Ten miesiac ma 31 dni"; } break;
        case 11:cout << "Listopad" << endl; cout << "Jest pochmurno" << endl; if (miesiac_conv % 2 == 0) { cout << "Ten miesiac ma 30 dni"; }
               else { cout << "Ten miesiac ma 31 dni"; }break;
        case 12:cout << "Grudzien" << endl; cout << "Jest pochmurno" << endl; if (miesiac_conv % 2 == 0) { cout << "Ten miesiac ma 31 dni"; }
               else { cout << "Ten miesiac ma 31 dni"; } break;

        }
        cout << endl << endl;
    }
    


