// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "matrix.h"
using namespace std;
void mainMenu() {
	setlocale(LC_ALL, "Ukrainian_Ukraine.1251");
	cout << "1. ������� ��� ������������� ��������; �������� �������" << endl;
	cout << "2.������� ���������� �����, �� ���������� �� ������ �������� ��������; �������� �������. " << endl;



}
int main() {
	mainMenu();
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:  matrix_1(); break;
	case 2:  matrix_2(); break;


	default: cout << "An error occured "; break;
	}
	return 0;
}