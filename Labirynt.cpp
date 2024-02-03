// Autor: Grzegorz Łazarczyk
// Indeks: s32150
// PJWSTK projekt Podstawy Programowania

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <thread>

void wyswietlMenu();
void wyswietlDuzaPlansza(int a);
void wyswietlMalaPlansza(int a);
void grajMala();

char malaPlansza[10][20];
char duzaPlansza[27][55];
int X = 1;
int Y = 1;

using namespace std;

//Sprawdza czy wprowadzona przez użytkownika wartość jest poprawna
bool sprawdzWyborRuch(string wybor) {

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    string tablica_wybor[] = { "l","p","d","g","q"};

    for (int i = 0; i < sizeof(tablica_wybor) / sizeof(tablica_wybor[0]); i++) {
        if (tablica_wybor[i] == wybor) {
            return true;
        }
    }
    printf("\033[A\33[2K\r");
    SetConsoleTextAttribute(h, 4);
    cout << "Podano niewłaściwą wartość";
    Sleep(1000);
    printf("\33[2K\r");
    SetConsoleTextAttribute(h, 7);
    return false;
}
// wyswietal informacje o wygrenej i ilosci ruchow ktorych potrzebował użytkownik
void wynik(int y) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    string x;
    X = 1;
    Y = 1;
    system("CLS");
    cout << endl << endl;
    cout << "     BRAWO!!! Udało Ci się przejść labirynt."<< endl;
    cout << "       Potrzebowałeś na to " << y << " posunięć." << endl;

    SetConsoleTextAttribute(h, 6); cout << endl << endl << " q - "; SetConsoleTextAttribute(h, 14); cout << "wróć" << endl;

    do {
        cin >> x;
        printf("\033[A\33[2K\r");   //kasuje i wraca na początek lin
    } while (x != "q");

    system("CLS");
    wyswietlMenu();
}

void grajMala() {

    int licznikPosunienc = 0;
    string ruch;
    bool warunek = true;
    
    do {
        do { cin >> ruch; } while (!sprawdzWyborRuch(ruch));
        if (ruch == "p") {
            if (malaPlansza[X][Y + 1] == ' ')
            {
                malaPlansza[X][Y] = '.';
                malaPlansza[X][Y + 1] = '$';
                Y = Y + 1;
                system("CLS");
                licznikPosunienc++;
                wyswietlMalaPlansza(2);
            }
            else if (malaPlansza[X][Y + 1] == '@')
            {
                cout << "Hura!!! Wygrałeś!!!" << endl;
                X = 1;
                Y = 1;
                licznikPosunienc++;
                warunek = false;
                wynik(licznikPosunienc);
            }
            else if (malaPlansza[X][Y + 1] == '.')
            {
                malaPlansza[X][Y] = '.';
                malaPlansza[X][Y + 1] = '$';
                Y = Y + 1;
                system("CLS");
                licznikPosunienc++;
                wyswietlMalaPlansza(2);
            }
            else {
                printf("\033[A\33[2K\r");
                cout << "Brak przejścia." << endl;
                Sleep(1000);
                printf("\033[A\33[2K\r");
            }
        }
        else if (ruch == "l") {
            if (malaPlansza[X][Y - 1] == ' ')
            {
                malaPlansza[X][Y] = '.';
                malaPlansza[X][Y - 1] = '$';
                Y = Y - 1;
                system("CLS");
                licznikPosunienc++;
                wyswietlMalaPlansza(2);
            }
            else if (malaPlansza[X][Y - 1] == '@')
            {
                cout << "Hura!!! Wygrałeś!!!" << endl;
                X = 1;
                Y = 1;
                licznikPosunienc++;
                warunek = false;
                wynik(licznikPosunienc);
            }
            else if (malaPlansza[X][Y - 1] == '.')
            {
                malaPlansza[X][Y] = '.';
                malaPlansza[X][Y - 1] = '$';
                Y = Y - 1;
                system("CLS");
                licznikPosunienc++;
                wyswietlMalaPlansza(2);
            }
            else {
                printf("\033[A\33[2K\r");
                cout << "Brak przejścia." << endl;
                Sleep(1000);
                printf("\033[A\33[2K\r");
            }
        }
        else if (ruch == "g") {
            if (malaPlansza[X - 1][Y] == ' ')
            {
                malaPlansza[X][Y] = '.';
                malaPlansza[X - 1][Y] = '$';
                X = X - 1;
                system("CLS");
                licznikPosunienc++;
                wyswietlMalaPlansza(2);
            }
            else if (malaPlansza[X - 1][Y] == '@')
            {
                cout << "Hura!!! Wygrałeś!!!" << endl;
                X = 1;
                Y = 1;
                warunek = false;
                wynik(licznikPosunienc);
            }
            else if (malaPlansza[X - 1][Y] == '.')
            {
                malaPlansza[X][Y] = '.';
                malaPlansza[X - 1][Y] = '$';
                X = X - 1;
                system("CLS");
                licznikPosunienc++;
                wyswietlMalaPlansza(2);
            }
            else {
                printf("\033[A\33[2K\r");
                cout << "Brak przejścia." << endl;
                Sleep(1000);
                printf("\033[A\33[2K\r");
            }
        }
        else if (ruch == "d") {
            if (malaPlansza[X + 1][Y] == ' ')
            {
                malaPlansza[X][Y] = '.';
                malaPlansza[X + 1][Y] = '$';
                X = X + 1;
                system("CLS");
                licznikPosunienc++;
                wyswietlMalaPlansza(2);
            }
            else if (malaPlansza[X + 1][Y] == '@')
            {
                cout << "Hura!!! Wygrałeś!!!" << endl;
                X = 1;
                Y = 1;
                licznikPosunienc++;
                warunek = false;
                wynik(licznikPosunienc);
            }
            else if (malaPlansza[X + 1][Y] == '.')
            {
                malaPlansza[X][Y] = '.';
                malaPlansza[X + 1][Y] = '$';
                X = X + 1;
                system("CLS");
                licznikPosunienc++;
                wyswietlMalaPlansza(2);
            }
            else {
                printf("\033[A\33[2K\r");
                cout << "Brak przejścia." << endl;
                Sleep(1000);
                printf("\033[A\33[2K\r");
            }
        }
        else if (ruch == "q") { 
            warunek = false; 
            X = 1;
            Y = 1;
            system("CLS");
            licznikPosunienc = 0;
            wyswietlMenu();
            break;
         }
    } while (warunek);
}
void grajDuza() {
    
    string ruch;
    bool warunek = true;
    int licznikPosunienc = 0;

    do {
        do { cin >> ruch; } while (!sprawdzWyborRuch(ruch));

        if (ruch == "p") {
            if (duzaPlansza[X][Y + 1] == ' ')
            {
                duzaPlansza[X][Y] = '.';
                duzaPlansza[X][Y + 1] = '$';
                Y = Y + 1;
                system("CLS");
                licznikPosunienc++;
                wyswietlDuzaPlansza(2);
            }
            else if (duzaPlansza[X][Y + 1] == '@')
            {
                cout << "Hura!!! Wygrałeś!!!" << endl;
                X = 1;
                Y = 1;
                licznikPosunienc++;
                warunek = false;
                wynik(licznikPosunienc);
            }
            else if (duzaPlansza[X][Y + 1] == '.')
            {
                duzaPlansza[X][Y] = '.';
                duzaPlansza[X][Y + 1] = '$';
                Y = Y + 1;
                system("CLS");
                licznikPosunienc++;
                wyswietlDuzaPlansza(2);
            }
            else {
                printf("\033[A\33[2K\r");
                cout << "Brak przejścia." << endl;
                Sleep(1000);
                printf("\033[A\33[2K\r");
            }
        }
        else if (ruch == "l") {
            if (duzaPlansza[X][Y - 1] == ' ')
            {
                duzaPlansza[X][Y] = '.';
                duzaPlansza[X][Y - 1] = '$';
                Y = Y - 1;
                system("CLS");
                licznikPosunienc++;
                wyswietlDuzaPlansza(2);
            }
            else if (duzaPlansza[X][Y - 1] == '@')
            {
                cout << "Hura!!! Wygrałeś!!!" << endl;
                X = 1;
                Y = 1;
                licznikPosunienc++;
                warunek = false;
                wynik(licznikPosunienc);
            }
            else if (duzaPlansza[X][Y - 1] == '.')
            {
                duzaPlansza[X][Y] = '.';
                duzaPlansza[X][Y - 1] = '$';
                Y = Y - 1;
                system("CLS");
                licznikPosunienc++;
                wyswietlDuzaPlansza(2);
            }
            else {
                printf("\033[A\33[2K\r");
                cout << "Brak przejścia." << endl;
                Sleep(1000);
                printf("\033[A\33[2K\r");
            }
        }
        else if (ruch == "g") {
            if (duzaPlansza[X - 1][Y] == ' ')
            {
                duzaPlansza[X][Y] = '.';
                duzaPlansza[X - 1][Y] = '$';
                X = X - 1;
                system("CLS");
                licznikPosunienc++;
                wyswietlDuzaPlansza(2);
            }
            else if (duzaPlansza[X - 1][Y] == '@')
            {
                cout << "Hura!!! Wygrałeś!!!" << endl;
                X = 1;
                Y = 1;
                warunek = false;
                wynik(licznikPosunienc);
            }
            else if (duzaPlansza[X-1][Y] == '.')
            {
                duzaPlansza[X][Y] = '.';
                duzaPlansza[X-1][Y] = '$';
                X = X - 1;
                system("CLS");
                licznikPosunienc++;
                wyswietlDuzaPlansza(2);
            }
            else {
                printf("\033[A\33[2K\r");
                cout << "Brak przejścia." << endl;
                Sleep(1000);
                printf("\033[A\33[2K\r");
            }
        }
        else if (ruch == "d") {
            if (duzaPlansza[X + 1][Y] == ' ')
            {
                duzaPlansza[X][Y] = '.';
                duzaPlansza[X + 1][Y] = '$';
                X = X + 1;
                system("CLS");
                licznikPosunienc++;
                wyswietlDuzaPlansza(2);
            }
            else if (duzaPlansza[X + 1][Y] == '@')
            {
                cout << "Hura!!! Wygrałeś!!!" << endl;
                X = 1;
                Y = 1;
                licznikPosunienc++;
                warunek = false;
                wynik(licznikPosunienc);
            }
            else if (duzaPlansza[X+1][Y] == '.')
            {
                duzaPlansza[X][Y] = '.';
                duzaPlansza[X+1][Y] = '$';
                X = X + 1;
                system("CLS");
                licznikPosunienc++;
                wyswietlDuzaPlansza(2);
            }
            else {
                printf("\033[A\33[2K\r");
                cout << "Brak przejścia." << endl;
                Sleep(1000);
                printf("\033[A\33[2K\r");
            }
        }
        else if (ruch == "q") {
            warunek = false; 
            X = 1;
            Y = 1;
            system("CLS");
            licznikPosunienc = 0;
            wyswietlMenu(); 
            break;
}
    } while (warunek);
}

void wyswietlDuzaPlansza(int a) {

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 55; j++) {
            if (duzaPlansza[i][j] == '#') {
                SetConsoleTextAttribute(h, 17);
                cout << duzaPlansza[i][j];
            }
            else if (duzaPlansza[i][j] == '$') {
                SetConsoleTextAttribute(h, 170);
                cout << duzaPlansza[i][j];
            }
            else if (duzaPlansza[i][j] == '@') {
                SetConsoleTextAttribute(h, 204);
                cout << duzaPlansza[i][j];
            }
            else if (duzaPlansza[i][j] == '.') {
                SetConsoleTextAttribute(h, 85);
                cout << duzaPlansza[i][j];
            }
            else {
                SetConsoleTextAttribute(h, 119);
                cout << duzaPlansza[i][j];
            }
            SetConsoleTextAttribute(h, 2);
        }
        cout << endl;
    }
    if (a == 1) {
        grajDuza();
    }
}

void wyswietlMalaPlansza(int a) {
   
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            if (malaPlansza[i][j] == '#') {
                SetConsoleTextAttribute(h, 17);
                cout << malaPlansza[i][j];
            }
            else if (malaPlansza[i][j] == '$') {
                SetConsoleTextAttribute(h, 170);
                cout << malaPlansza[i][j];
            }
            else if (malaPlansza[i][j] == '@') {
                SetConsoleTextAttribute(h, 204);
                cout << malaPlansza[i][j];
            }
            else if (malaPlansza[i][j] == '.') {
                SetConsoleTextAttribute(h, 85);
                cout << malaPlansza[i][j];
            }
            else {
                SetConsoleTextAttribute(h, 119);
                cout << malaPlansza[i][j];
            }
            SetConsoleTextAttribute(h, 2);
        }
        cout << endl;
    }
    if (a == 1) {
        grajMala();  
    }
    }
    
void wczytajDuzaPlansza() {

    string a;
    int line_counter = 0;
    ifstream in;
    in.open("C:\\Users\\Admin\\OneDrive\\Pulpit\\duzaPlansza.txt");
 

    if (in.fail()) { cout << "Plik nie został otwarty poprawnie." << endl; }
    else{
        while (in) {
            getline(in, a);
            for (int i = 0; i < 55; i++) {
                duzaPlansza[line_counter][i] = a[i];
            }
            line_counter++;
        }
        in.close();
        wyswietlDuzaPlansza(1);
        }  
}

void wczytajMalaPlansza() {
    string a;
    int line_counter = 0;
    ifstream in;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    in.open("C:\\Users\\Admin\\OneDrive\\Pulpit\\malaPlansza.txt");
    //in.open(("C:\\Users\\Admin\\OneDrive\\Pulpit\\Labirynt\\malaPlansza.txt"));

    if (in.fail()) { cout << "Plik nie został otwarty poprawnie." << endl; }
    else {
        while (in) {
            getline(in, a);
            for (int i = 0; i < 20; i++) {
                malaPlansza[line_counter][i] = a[i];
            }
            line_counter++;
        }
        in.close();
        wyswietlMalaPlansza(1);
    }
}

bool sprawdzWyborMenu(string wybor) {

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    string tablica_wybor[] = { "1","2","3","4" };

    for (int i = 0; i < sizeof(tablica_wybor) / sizeof(tablica_wybor[0]); i++) {
        if (tablica_wybor[i] == wybor) { 
            return true; }
    }

    printf("\033[A\33[2K\r");
    SetConsoleTextAttribute(h, 4);
    cout << "Podano niewłaściwą wartość";
    Sleep(1000);
    printf("\33[2K\r");
    SetConsoleTextAttribute(h, 7);
    
    return false;
}

bool sprawdzWyborPoziom(string wybor) {

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    string tablica_wybor[] = { "1","2","3"};

    for (int i = 0; i < sizeof(tablica_wybor) / sizeof(tablica_wybor[0]); i++) {
        if (tablica_wybor[i] == wybor) {
            return true;
        }
    }
    printf("\033[A\33[2K\r");
    SetConsoleTextAttribute(h, 4);
    cout << "Podano niewłaściwą wartość";
    Sleep(1000);
    printf("\33[2K\r");
    SetConsoleTextAttribute(h, 7);

    return false;
}
void wybierzPlansze() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    string wybor;
    int wybor_int;
    
    SetConsoleTextAttribute(h, 6); cout << endl << "          WYBIERZ POZIOM           " << endl << endl;
    SetConsoleTextAttribute(h, 6); cout << " 1."; SetConsoleTextAttribute(h, 14); cout << " ŁATWY " << endl << endl;
    SetConsoleTextAttribute(h, 6); cout << " 2."; SetConsoleTextAttribute(h, 14); cout << " TRUDNY " << endl << endl;
    SetConsoleTextAttribute(h, 6); cout << " 3."; SetConsoleTextAttribute(h, 14); cout << " POWRÓT " << endl << endl;
    
    SetConsoleTextAttribute(h, 7); cout << "Wybierz liczbę całkowitą od 1 do 3." << endl << endl;

    do { cin >> wybor; } while (!sprawdzWyborPoziom(wybor));
    wybor_int = stoi(wybor);

    switch (wybor_int) {
    case 1: system("CLS"); wczytajMalaPlansza(); break;
    case 2: system("CLS"); wczytajDuzaPlansza(); break;
    case 3: system("CLS"); wyswietlMenu(); break;
    }
}

void pomoc() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    string x;

    SetConsoleTextAttribute(h, 6);
    cout << "Gra w Labirynt." << endl<< endl ;
    SetConsoleTextAttribute(h, 14);
    cout << "Celem gry jest przedostanie się gracza reprezentowanego przez zielony prostokąt" << endl;
    cout << "do wyjścia z labiryntu, którym jest różowy prostokąt, w jak najmnniejszej ilości ruchów." << endl << endl;
    SetConsoleTextAttribute(h, 6);
    cout << "    Sposób poruszania :" << endl << endl;

    cout << " l - "; SetConsoleTextAttribute(h, 14); cout<< "ruch  w lewo" << endl;
    SetConsoleTextAttribute(h, 6); cout << " p - "; SetConsoleTextAttribute(h, 14); cout<< "ruch  w prawo" << endl;
    SetConsoleTextAttribute(h, 6); cout << " g - "; SetConsoleTextAttribute(h, 14); cout<< "ruch  w górę" << endl;
    SetConsoleTextAttribute(h, 6); cout << " d - "; SetConsoleTextAttribute(h, 14); cout<< "ruch  w dół" << endl;
    
    SetConsoleTextAttribute(h, 6); cout <<endl<<endl<< " q - "; SetConsoleTextAttribute(h, 14); cout << "wróć" << endl;

    do { cin >> x;
    printf("\033[A\33[2K\r");
    } while (x != "q");

    system("CLS");
    wyswietlMenu();
}
void ranking() {}


void wyjscie(){

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 6);
    cout << endl << "   DZIĘKUJĘ ZA GRĘ !!!   ZAPRASZAM PONOWNIE  :)  " << endl << endl<< endl;
    SetConsoleTextAttribute(h, 7);
}

void wyswietlMenu() {
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1000, 600, TRUE);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    string wybor;
    int wybor_int;

    SetConsoleTextAttribute(h, 6); cout << endl << "          MENU           " << endl<<endl;
    SetConsoleTextAttribute(h, 6); cout << " 1."; SetConsoleTextAttribute(h, 14); cout << " ROZPOCZNIJ GRĘ " << endl << endl;
    SetConsoleTextAttribute(h, 6); cout << " 2."; SetConsoleTextAttribute(h, 14); cout << " RANKING " << endl << endl;
    SetConsoleTextAttribute(h, 6); cout << " 3."; SetConsoleTextAttribute(h, 14); cout << " POMOC " << endl << endl;
    SetConsoleTextAttribute(h, 6); cout << " 4."; SetConsoleTextAttribute(h, 14); cout << " WYJŚCIE " << endl << endl;

    SetConsoleTextAttribute(h, 7); cout << "Wybierz liczbę całkowitą od 1 do 4." << endl << endl;

    do { cin >> wybor; } while (!sprawdzWyborMenu(wybor));
    wybor_int = stoi(wybor);

    switch (wybor_int) {
    case 1: system("CLS"); wybierzPlansze(); break;
    case 2: system("CLS"); ranking(); break;
    case 3: system("CLS"); pomoc(); break;
    case 4: system("CLS"); wyjscie(); break;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    wyswietlMenu();
}

