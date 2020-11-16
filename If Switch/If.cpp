// If.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include "libIf.h"

using namespace std;
void mainMenu() {
	setlocale(LC_ALL, "Ukrainian_Ukraine.1251");
	cout << "1. Дано целое число. Если оно является положительным, то прибавить к нему 1; в противном случае не изменять его." << endl;
	cout << "6.Даны два числа. Вывести большее из них. " << endl;
	cout << "8.Даны два числа. Вывести вначале большее, а затем меньшее из них. " << endl;
	cout << "12.Даны три числа. Найти наименьшее из них.  " << endl;
	cout << "14.Даны три числа. Вывести наименьшее, а затем наибольшее из чисел.  " << endl;
	cout << "15.Даны три числа. Найти сумму двух наибольших из них.  " << endl;
	cout << "24.Для x найти значение  функции f, при-2·sin(x), если x > 0, 6-x,если x<=0 " << endl;
	cout << "25.Для целого x найти значение  функции f,2·x, если x < –2 или x > 2,-3*x в противном случае .  " << endl;
	cout << "28.Дан номер года (положительное целое число). Определить количестводней дней в этом году " << endl;
	
}
int main() {
	mainMenu();
	int choice ;
	cin >> choice;
	switch (choice)
	{
	case 1:  if_1(); break;
	case 6:  if_6(); break;
	case 8: if_8(); break;
	case 12:  if_12(); break;
	case 14: if_14(); break;
	case 15:  if_15(); break;
	case 24:  if_24(); break;
	case 25: if_25(); break;
	case 28: if_28(); break;
	default: cout << "An error occured "; break;
	} 
	return 0;
}


