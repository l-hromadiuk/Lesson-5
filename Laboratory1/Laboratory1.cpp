

#include <iostream>
#include "lab1.h"
using namespace std;
void mainMenu() {
	setlocale(LC_ALL, "Ukrainian_Ukraine.1251");
	cout << "2.������ �i���i������ ����i�i��� �� ��������� ���� �� �����i ��������." << endl;
	cout << "10.�����i���� �� � ������� ����� ������ ���������. " << endl;
	


}
int main() {
	mainMenu();
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 2:  lab1_2(); break;
	case 10:  lab1_10(); break;
	

	default: cout << "An error occured "; break;
	}
	return 0;
}