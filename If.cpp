// If.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include "libIf.h"

using namespace std;
void mainMenu() {
	setlocale(LC_ALL, "Ukrainian_Ukraine.1251");
	cout << "1. ���� ����� �����. ���� ��� �������� �������������, �� ��������� � ���� 1; � ��������� ������ �� �������� ���." << endl;
	cout << "6.���� ��� �����. ������� ������� �� ���. " << endl;
	cout << "8.���� ��� �����. ������� ������� �������, � ����� ������� �� ���. " << endl;
	cout << "12.���� ��� �����. ����� ���������� �� ���.  " << endl;
	cout << "14.���� ��� �����. ������� ����������, � ����� ���������� �� �����.  " << endl;
	cout << "15.���� ��� �����. ����� ����� ���� ���������� �� ���.  " << endl;
	cout << "24.��� x ����� ��������  ������� f, ���-2�sin(x), ���� x > 0, 6-x,���� x<=0 " << endl;
	cout << "25.��� ������ x ����� ��������  ������� f,2�x, ���� x < �2 ��� x > 2,-3*x � ��������� ������ .  " << endl;
	cout << "28.��� ����� ���� (������������� ����� �����). ���������� �������������� ���� � ���� ���� " << endl;
	
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


