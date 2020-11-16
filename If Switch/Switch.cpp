#include <iostream>
#include "libSwitch.h"

using namespace std;
void mainMenu() {
	setlocale(LC_ALL, "Ukrainian_Ukraine.1251");
	cout << "1. Дано целое число в диапазоне 1–7. Вывести строку — название дня неделu" << endl;
	cout << "3.Даны два числа. Вывести большее из них. " << endl;
	cout << "4.Дан номер месяца .Определить количество дней в этом месяце для невисо -косного года. " << endl;
	cout << "15.Мастям и достоинствам игральных карт присвоены номера: 1 — пики,2 — трефы, 3 — бубны, 4 — червы.Вывести название соответствующей карты " << endl;
	cout << "19.По номеру года определить его название за восточным календарём. " << endl;
	cout << "20.Вывести знак Зодиака, соответствующий заданой дате.  " << endl;


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
