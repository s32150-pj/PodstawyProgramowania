// Lab4.cpp : 

#include <iostream>
#include <string> 
#include<algorithm>
#include<iomanip>
#include <windows.h>


using namespace std;

bool check_imput_int(string test_value) {
	bool logic_value = false;
	for (int i = 0; i < test_value.length(); i++)
	{
		if (isdigit(test_value[i])) { 
			if (i == test_value.length() - 1) { logic_value = true; }
			continue; }
		else {
			cout << "You entered wrong value. PLease enter positive integer value." << endl;
			logic_value = false;
			break;
			}
	}
	return logic_value;
}

bool check_imput_float(string &test_value) {
	bool logic_value = false;
	int comma_counter = 0;

	for (int i = 0; i < test_value.length(); i++)
	{
		if (isdigit(test_value[i])) {
			if (i == test_value.length() - 1) { logic_value = true; }
			continue;
		}
		else {
			if (i == 0 && test_value[i] == '-')continue;
			if ( (test_value[i] == '.' || test_value[i] == ',') && comma_counter == 0 && (i<test_value.length()-1) && i>0 )
			{
				comma_counter = 1;
				test_value[i] = '.';
				continue;
			}		
			cout << "You entered wrong value. PLease enter real number." << endl;
			logic_value = false;
			break;
		}
	}
	return logic_value;
}

void zadanie1() {

	int array_size;
	string test_value;
	string* test_value_pointer = &test_value;
	
	cout << "Please, enter how many numbers Your array will contain: " << endl;
	do {
		cin >> test_value;
	} while (check_imput_int(test_value) == false);

	array_size = stoi(test_value);
	float* table = new float[array_size];
	float max_value;

	for (int i = 0; i < array_size; i++)
	{
		cout << endl << "Enter value number " << i + 1 <<"."<< endl;
		do {
			cin >> test_value;
		}while(check_imput_float(test_value)==false);
		table[i] = stod(test_value);
		
	}

	max_value = table[0];
	cout << endl<< endl;
	
	cout << "[ ";
	for (int i = 0; i < array_size; i++) {
		if (table[i] > max_value) { max_value = table[i]; }
			if (i < array_size - 1)
			{
				cout << table[i] << ", ";
			}
			else { cout << table[i]; }
		
	}
	cout<< " ]" << endl << endl;

	cout << "The largest number in your array is: " << max_value << "."<<endl;

	delete[] table;

}
void zadanie2() {

	int array_size;
	string test_value;
	string* test_value_pointer = &test_value;

	cout << "Please, enter how many numbers Your array will contain:  " << endl;
	do {
		cin >> test_value;
	} while (check_imput_int(test_value) == false);

	array_size = stoi(test_value);
	int* table = new int[array_size];
	int max_value;

	for (int i = 0; i < array_size; i++)
	{
		cout << endl << "Enter value number " << i + 1 << "." << endl;
		do {
			cin >> test_value;
		} while (check_imput_int(test_value) == false);
		table[i] = stoi(test_value);
	}
	cout << endl << endl;
	int value_max = table[0];
	int count_value_max = 0;
	int value_check;
	int value_check_count;
	bool alert=false;
	
	for (int j = 0; j < array_size; j++) {
		//value_check = table[j];
		value_check_count = 0;
		for (int i = j; i < array_size; i++) {

			if (table[i] == table[j]) { value_check_count++; }

		}
		if (value_check_count == count_value_max) { alert = true; }
		if (value_check_count > count_value_max) {
			value_max = table[j]; count_value_max = value_check_count; alert = false;
		}
		
	}
	if (alert == false) {
		cout << "The number that occurs in Your table most often is: " << value_max << "." << endl;
		cout << "It occurs " << count_value_max << " times." << endl;
	}
	else { cout << "At least two numbers occurs equaly often in your array. And they occur more often than others." << endl; }
	delete[] table;
}

void zadanie3() {

	int table[10][10];

	for (int i = 0; i < 10; i++) {
		
		table[i][0] = i;
		table[i][1] = i + i;
		table[i][2] = pow(i, 2);
		table[i][3] = i + 3; 
		table[i][4] = i - 4;
		for (int j = 5; j < 10; j++) { table[i][j] = 0; }	
	}

	for(int i = 0; i< 10 ; i++){
		for (int j = 0; j < 10; j++) {
			cout << setw(3)<<table[i][j];
		}cout << endl<<endl;
	}
}

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 

	SetConsoleTextAttribute(h, 3);
	zadanie1();
	cout << endl;
	SetConsoleTextAttribute(h, 4);
	zadanie2();
	cout << endl;
	SetConsoleTextAttribute(h, 5);
	zadanie3();

}

