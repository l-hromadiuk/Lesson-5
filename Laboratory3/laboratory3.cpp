#include <iostream>
#include <string>
#include "lab3.h"
using namespace std;
void mainMenu() {
	setlocale(LC_ALL, "Ukrainian_Ukraine.1251");
	cout << "2.Реалiзувати чисельне обчислення кореня n-того стeпеня." << endl;
	cout << "16.Дано функцiю f(x). Визначити, чи є вона перiодичною, якщо так – визначити перiод." << endl;
}
int main() {
	mainMenu();
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 2:  lab3_2(); break;
	case 16:  lab3_16(); break;



	default: cout << "An error occured "; break;
	}
	return 0;
}