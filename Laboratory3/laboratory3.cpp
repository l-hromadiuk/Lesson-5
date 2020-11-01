#include <iostream>
#include "lab3.h"
using namespace std;
void mainMenu() {
	setlocale(LC_ALL, "Ukrainian_Ukraine.1251");
	cout << "2.Реалізувати чисельне обчислення кореня n-того стeпеня." << endl;
	cout << "16.Дано функцію f(x). Визначити, чи є вона періодичною, якщо так – визначити період." << endl;
}
int main() {
	mainMenu();
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 2:  lab3_2(); break;



	default: cout << "An error occured "; break;
	}
	return 0;
}