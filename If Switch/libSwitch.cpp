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
	case 2: cout << "����"; break;
	case 3:
	case 4:
	case 5: cout << "�����"; break;
	case 6:
	case 7:
	case 8: cout << "����"; break;
	case 9:
	case 10:
	case 11: cout << "�����"; break;
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

	cout << "Enter type(�����) of card(1-4) : ";
	int x, y;
	cin >> x;
	cout << "Enter a number(�����������) of card(6-14) ";
	cin >> y;
	switch (y) {
	case 6:cout << "�������" << " "; break;
	case 7:   cout << "������" << " "; break;
	case 8:cout << "��������" << " "; break;
	case 9:   cout << "�������" << " "; break;
	case 10:cout << "�������" << " "; break;
	case 11:  cout << "�����" << " "; break;
	case 12:cout << "����" << " "; break;
	case 13:  cout << "������" << " "; break;
	case 14:cout << "���" << " "; break;
	default: cout << "An error occured "; break;
	}
	switch (x) {
	case 1:  cout << "���"; break;
	case 2:cout << "����"; break;
	case 3:   cout << "�����"; break;
	case 4:cout << "������"; break;
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
	case 1:  cout << "���."; break;
	case 2:
	case 3:   cout << "׸��."; break;
	case 4:
	case 5:   cout << "����."; break;
	case 6:
	case 7:   cout << "�����."; break;
	case 8:
	case 9:   cout << "Ƹ��."; break;

	default: cout << "An error occured "; break;
	}
	switch (x % 12) {
	case 0:cout << "��������"; break;
	case 1:  cout << "������"; break;
	case 2:cout << "������"; break;
	case 3:   cout << "������"; break;
	case 4:cout << "�����"; break;
	case 5:   cout << "������"; break;
	case 6:cout << "����"; break;
	case 7:   cout << "����"; break;
	case 8:cout << "������"; break;
	case 9:   cout << "����"; break;
	case 10:cout << "������"; break;
	case 11:  cout << "����"; break;
	default: cout << "An error occured "; break;

	}
}
void switch_20() {

	int x, y;

	cout << "Enter day and month : ";
	cin >> x >> y;;

	switch (y)
	{
	case 1: if (x <= 19) cout << "�������";
		  else cout << "�������"; break;
	case 2: if (x <= 18) cout << "�������"; else  cout << "����"; break;
	case 3: if (x <= 20) cout << "����"; else  cout << "����"; break;
	case 4: if (x <= 19) cout << "����"; else cout << "�����"; break;
	case 5:  if (x <= 20) cout << "�����"; else cout << "��������"; break;
	case 6: if (x <= 21) cout << "��������"; else   cout << "���"; break;
	case 7: if (x <= 22) cout << "���"; else  cout << "���"; break;
	case 8: if (x <= 22) cout << "���"; else  cout << "����"; break;
	case 9:  if (x <= 22) cout << "����"; else  cout << "����"; break;
	case 10: if (x <= 22) cout << "����"; else cout << "��������"; break;
	case 11: if (x <= 22) cout << "��������"; else cout << "�������"; break;
	case 12: if (x <= 21) cout << "�������"; else  cout << "�������"; break;

	default: cout << "An error occured "; break;
	}
}