#include <iostream>
#include "libSwitch.h"

using namespace std;
void mainMenu() {
	setlocale(LC_ALL, "Ukrainian_Ukraine.1251");
	cout << "1. ���� ����� ����� � ��������� 1�7. ������� ������ � �������� ��� �����u" << endl;
	cout << "3.���� ��� �����. ������� ������� �� ���. " << endl;
	cout << "4.��� ����� ������ .���������� ���������� ���� � ���� ������ ��� ������ -������� ����. " << endl;
	cout << "15.������ � ������������ ��������� ���� ��������� ������: 1 � ����,2 � �����, 3 � �����, 4 � �����.������� �������� ��������������� ����� " << endl;
	cout << "19.�� ������ ���� ���������� ��� �������� �� ��������� ���������. " << endl;
	cout << "20.������� ���� �������, ��������������� ������� ����.  " << endl;


}
int main() {
	mainMenu();
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:  switch_1(); break;
	case 3:  switch_3(); break;
	case 4: switch_4(); break;
	case 15:  switch_15(); break;
	case 19:switch_19(); break;
	case 20:  switch_20(); break;
	
	default: cout << "An error occured "; break;
	}
	return 0;
}
