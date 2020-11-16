// Menu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include "MenuFunc.h"
using namespace std;

int menu() {
	int key = 0;
	int code;

	setlocale(LC_ALL, "Ukrainian_Ukraine.1251");
	do {
		system("cls");
		key = (key + 5) % 5;
		
		if (key == 1) cout << "-> Надрукувати прямокутник." << endl;
		else  cout << "  Надрукувати прямокутник." << endl;
		if (key == 2) cout << "-> Надрукувати прямокутний трикутник." << endl;
		else  cout << "  Надрукувати прямокутний трикутник." << endl;
		if (key == 3) cout << "-> Надрукувати рівносторонній трикутник." << endl;
		else  cout << "  Надрукувати рівносторонній трикутник." << endl;
		if (key == 4) cout << "-> Надрукувати ромб." << endl;
		else  cout << "  Надрукувати ромб." << endl;
		if (key == 0) cout << "-> Вийти" << endl;
		else  cout << "  Вийти" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
int main()
{
	setlocale(LC_ALL, "Ukrainian_Ukraine.1251");
	while (true) {
		int answer = menu();
		switch (answer)
		{
		case 0:  break;
		case 1: rectangular(); break;
		case 2: rightTriangle(); break;
		case 3: equalTriangle(); break;
		case 4: rhomb(); 
			return 0;
		}
		system("pause");
		if (answer == 0) break;
	}
	return 0;
}

