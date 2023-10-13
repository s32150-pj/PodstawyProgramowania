//Podstawy Programowania
// LAB1
// S32150
// Grzegorz Łazarczyk 

#include <iostream>
#include <windows.h>
#include <string> 
#include <cstring> 

using namespace std;

int main()
{
    setlocale(LC_ALL, "");   // Allow to display letters with diacritics
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // allow to set colour of text displayed in the console

 // Zadanie 1.1

    SetConsoleTextAttribute(h, 3);
    cout << "Zadanie 1.1"<< endl<<endl;
    SetConsoleTextAttribute(h, 7);
    cout << " Grzegorz Łazarczyk " << endl;
    cout << " s32150 " << endl;
    cout << " Polsko-Japońska Akademia Technik Komputerowych " << endl;
    cout << endl;

 //Zadanie 1.2 v.1

    int number1 = 10;

    SetConsoleTextAttribute(h, 3);
    cout << "Zadanie 1.2 v.1" << endl << endl;
    SetConsoleTextAttribute(h, 7);
    SetConsoleTextAttribute(h, 6);
    if (number1 == 0) { cout << "Given number is equal to 0." << endl<< endl; }
    else if (number1 < 0) { cout << "Given number is negative.["<< number1<<"]" << endl << endl; }
    else if (number1 > 0) { cout << "Given number is positive.["<< number1 << "]" << endl<< endl; }

 //Zadanie 1.2 v.2

    int number2;
    string user_input;
    boolean loop_condition = false;

    SetConsoleTextAttribute(h, 3);
    cout << "Zadanie 1.2 v.2" << endl << endl;
    SetConsoleTextAttribute(h, 7);

    SetConsoleTextAttribute(h, 4);
    cout << "Please, enter a number and I will tell You if it is negative, positive or 0: "<< endl;
    SetConsoleTextAttribute(h, 7);
    do {
        
        cin >> user_input;
 
        for (int i = 0; i < user_input.length(); i++) {
            
             if ( isdigit(user_input[i]) == false)
                {
                 if (i==0 && user_input[i] == '-' && user_input.length()>1) { continue; }
                 else {
                     SetConsoleTextAttribute(h, 4);
                     cout << "You entered wrong value. Please enter an integer. " << endl;
                     SetConsoleTextAttribute(h, 7);
                     break;
                 }
                }
             if (i == user_input.length() - 1) {
                 loop_condition = true;
                 number2 = stoi(user_input);
                 SetConsoleTextAttribute(h, 6);
                 if (number2 == 0) { cout << "Given number is equal to 0." << endl << endl;}
                 else if (number2 < 0) { cout << "Given number is negative.[" << number2 << "]" << endl << endl;}
                 else if (number2 > 0) { cout << "Given number is positive.[" << number2 << "]" << endl << endl;}
                 SetConsoleTextAttribute(h, 7);
                  }
        }
    } while (loop_condition == false);

 //Zadanie 1.3 v.1

    int number4 = 10;

    SetConsoleTextAttribute(h, 3);
    cout << "Zadanie 1.3 v.1" << endl << endl;
    SetConsoleTextAttribute(h, 7);
    SetConsoleTextAttribute(h, 6);
    if (number4%2 == 0 ) { cout << "Given number is even.[" << number4 << "]" << endl << endl;}
    else if (number4 % 2 == 1) { cout << "Given number is odd.[" << number4 << "]" << endl << endl;}
    else  { cout << "It is 0." << endl << endl; }

 //Zadanie 1.3 v.2

    int number3;
    string user_input2;
    boolean loop_condition2 = false;

    SetConsoleTextAttribute(h, 3);
    cout << "Zadanie 1.3 v.2" << endl << endl;
    SetConsoleTextAttribute(h, 7);

    SetConsoleTextAttribute(h, 4);
    cout << "Please, enter an integer and I will tell You if it is even,odd or is it 0: " << endl;
    SetConsoleTextAttribute(h, 7);
    do {

        cin >> user_input2;

        for (int i = 0; i < user_input2.length(); i++) {

            if (isdigit(user_input2[i]) == false)
            {
                if (i == 0 && user_input2[i] == '-' && user_input2.length() > 1) { continue; }
                else {
                    SetConsoleTextAttribute(h, 4);
                    cout << "You entered wrong value. Please enter an integer. " << endl;
                    SetConsoleTextAttribute(h, 7);
                    break;
                }
            }
            if (i == user_input2.length() - 1) {
                loop_condition2 = true;
                number3 = stoi(user_input2);
                SetConsoleTextAttribute(h, 6);
                if (number3 == 0){ cout << "It is 0." << endl << endl; }
                else if (number3 % 2 == 0) { cout << "Given number is even.[" << number3 << "]" << endl << endl;}
                else if (abs(number3 % 2) == 1) { cout << "Given number is odd.[" << number3 << "]" << endl << endl;}
                SetConsoleTextAttribute(h, 7);
            }
        }
    } while (loop_condition2 == false);

 //Zadanie 1.4

    string numbers[3];
    int comma_counter = 0;
    boolean loop_condition3 = false;

    for (int i = 0; i < 3; i++)
    {
        SetConsoleTextAttribute(h, 4);
        cout << "Enter " << i + 1 << " number."<< endl;
        SetConsoleTextAttribute(h, 7);
       
        do {
            comma_counter = 0;
            loop_condition3 = false;
            cin >> numbers[i];

            for (int j = 0; j < numbers[i].length(); j++) {

                if (isdigit(numbers[i][j]) == false)
                {
                    if (j == 0 && numbers[i][j] == '-' && numbers[i].length() > 1) { continue; }
                    else if (j != 0 && (numbers[i][j] == '.' || numbers[i][j] == ',') && comma_counter == 0) { 
                    comma_counter = 1;
                    numbers[i][j] = ',';
                    continue;
                    }
                    else {
                        SetConsoleTextAttribute(h, 4);
                        cout << "Wrong input. Please enter a number. " << endl;
                        SetConsoleTextAttribute(h, 7);
                        break;
                    }
                }
                if (j == numbers[i].length() - 1) {loop_condition3 = true; }
            }
        } while (loop_condition3 == false);
    }

    double numbers_converted[3];
   
    const char* number1_string = numbers[0].c_str();
    const char* number2_string = numbers[1].c_str();
    const char* number3_string = numbers[2].c_str();
    
    numbers_converted[0] = stod(number1_string);
    numbers_converted[1] = stod(number2_string);
    numbers_converted[2] = stod(number3_string);

 // Version 1

    cout << endl << " Version 1: " << endl;

    if (numbers_converted[0] >= numbers_converted[1]) {
        if (numbers_converted[0] >= numbers_converted[2])
        {
            cout << "The largest number is: " << numbers_converted[0]<< endl;
        }
        else { cout << "The largest number is: " << numbers_converted[2] << endl; }
    }
    else {
        if (numbers_converted[1] >= numbers_converted[2])
        {
            cout << "The largest number is: " << numbers_converted[1] << endl;
            
        }
        else { cout << "The largest number is: " << numbers_converted[2] << endl; }
    }
 // Version 2

    cout << endl << " Version 2: " << endl;

    if(numbers_converted[0]>=numbers_converted[1] && numbers_converted[0] >= numbers_converted[2])
    {
        cout << "The largest numbers is: " << numbers_converted[0] << endl;
    }

    else if (numbers_converted[1] >= numbers_converted[0] && numbers_converted[1] >= numbers_converted[2])
    {
        cout << "The largest numbers is: " << numbers_converted[1] << endl;
    }
    else 
    {
        cout << "The largest numbers is: " << numbers_converted[2] << endl;
    }

 // Version 3
    cout << endl << " Version 3: " << endl;
    cout << "The largest numbers is: " << max(max(numbers_converted[0], numbers_converted[1]), numbers_converted[2]) << endl;
}

