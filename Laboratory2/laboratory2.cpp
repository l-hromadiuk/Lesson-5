
#include <iostream>
#include "lab2.h"
using namespace std;
void mainMenu() {
	setlocale(LC_ALL, "Ukrainian_Ukraine.1251");
	cout << "2.��������� ��� ���� �����. ���������� ������� �� ������������� ���������� �������  ������ ���"<<endl;
	cout << "14.���� ������� ������������. ������� ������� ����� ����." << endl;
}
int main() {
	mainMenu();
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 2:  lab2_2(); break;
	case 14:  lab2_14(); break;


	default: cout << "An error occured "; break;
	}
	return 0;
}