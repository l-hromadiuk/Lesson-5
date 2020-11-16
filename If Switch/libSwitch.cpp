#include <iostream>
#include "libSwitch.h"
using namespace std;
void switch_1() {

	int x;

	cout << "Enter a number of a day: ";
	cin >> x;

	switch (x)
	{
	case 1: cout << "Monday"; break;
	case 2:  cout << "Tuesday"; break;
	case 3:   cout << "Wednesday"; break;
	case 4:   cout << "Thurthday"; break;
	case 5:  cout << "Friday"; break;
	case 6:   cout << "Saturday"; break;
	case 7:   cout << "Sunday"; break;
	default: cout << "An error occured "; break;
	}


}
void switch_3() {

	cout << "Enter month (1-12) ";
	int x;
	cin >> x;
	switch (x) {
	case 12:
	case 1:
	case 2: cout << "Зима"; break;
	case 3:
	case 4:
	case 5: cout << "Весна"; break;
	case 6:
	case 7:
	case 8: cout << "Лето"; break;
	case 9:
	case 10:
	case 11: cout << "Осень"; break;
	default: cout << "An error occured"; break;
	}


}
void switch_4() {

	cout << "Enter month (1-12): ";
	int x;
	cin >> x;
	cout << "Number of days is ";
	switch (x) {
	case 1:  cout << "31"; break;
	case 2:cout << "28"; break;
	case 3:   cout << "31"; break;
	case 4:cout << "30"; break;
	case 5:   cout << "31"; break;
	case 6:cout << "30"; break;
	case 7:   cout << "31"; break;
	case 8:cout << "31"; break;
	case 9:   cout << "30"; break;
	case 10:cout << "31"; break;
	case 11:  cout << "30"; break;
	case 12:cout << "31"; break;
	default: cout << "An error occured "; break;

	}


}
void switch_15() {

	cout << "Enter type(масть) of card(1-4) : ";
	int x, y;
	cin >> x;
	cout << "Enter a number(достоинство) of card(6-14) ";
	cin >> y;
	switch (y) {
	case 6:cout << "шестёрка" << " "; break;
	case 7:   cout << "семёрка" << " "; break;
	case 8:cout << "восьмёрка" << " "; break;
	case 9:   cout << "девятка" << " "; break;
	case 10:cout << "десятка" << " "; break;
	case 11:  cout << "валет" << " "; break;
	case 12:cout << "дама" << " "; break;
	case 13:  cout << "король" << " "; break;
	case 14:cout << "туз" << " "; break;
	default: cout << "An error occured "; break;
	}
	switch (x) {
	case 1:  cout << "пик"; break;
	case 2:cout << "треф"; break;
	case 3:   cout << "бубен"; break;
	case 4:cout << "червей"; break;
	default: cout << "An error occured "; break;

	}


}
void switch_19() {

	int x;

	cout << "Enter a year: ";
	cin >> x;

	switch (x % 10)
	{
	case 0:
	case 1:  cout << "Бел."; break;
	case 2:
	case 3:   cout << "Чёрн."; break;
	case 4:
	case 5:   cout << "Зелён."; break;
	case 6:
	case 7:   cout << "Красн."; break;
	case 8:
	case 9:   cout << "Жёлт."; break;

	default: cout << "An error occured "; break;
	}
	switch (x % 12) {
	case 0:cout << "Обезьяна"; break;
	case 1:  cout << "Курица"; break;
	case 2:cout << "Собака"; break;
	case 3:   cout << "Свинья"; break;
	case 4:cout << "Крысы"; break;
	case 5:   cout << "Коровы"; break;
	case 6:cout << "Тигр"; break;
	case 7:   cout << "Заец"; break;
	case 8:cout << "Дракон"; break;
	case 9:   cout << "Змея"; break;
	case 10:cout << "Лошадь"; break;
	case 11:  cout << "Овца"; break;
	default: cout << "An error occured "; break;

	}
}
void switch_20() {

	int x, y;

	cout << "Enter day and month : ";
	cin >> x >> y;;

	switch (y)
	{
	case 1: if (x <= 19) cout << "Козерог";
		  else cout << "Водолей"; break;
	case 2: if (x <= 18) cout << "Водолей"; else  cout << "Рыбы"; break;
	case 3: if (x <= 20) cout << "Рыбы"; else  cout << "Овен"; break;
	case 4: if (x <= 19) cout << "Овен"; else cout << "Телец"; break;
	case 5:  if (x <= 20) cout << "Телец"; else cout << "Близнецы"; break;
	case 6: if (x <= 21) cout << "Близнецы"; else   cout << "Рак"; break;
	case 7: if (x <= 22) cout << "Рак"; else  cout << "Лев"; break;
	case 8: if (x <= 22) cout << "Лев"; else  cout << "Дева"; break;
	case 9:  if (x <= 22) cout << "Дева"; else  cout << "Весы"; break;
	case 10: if (x <= 22) cout << "Весы"; else cout << "Скорпион"; break;
	case 11: if (x <= 22) cout << "Скорпион"; else cout << "Стрелец"; break;
	case 12: if (x <= 21) cout << "Стрелец"; else  cout << "Козерог"; break;

	default: cout << "An error occured "; break;
	}
}