#include <iostream>
#include "libIf.h"

using namespace std;
void if_1() {
	int x;
	cout << "Enter a number ";
	cin >> x;

	if (x > 0)cout << ++x;
	else cout << x;
}
void if_6() {

	int x, y;
	cout << "Enter 2 numbers ";
	cin >> x >> y;

	if (x > y)cout << x;
	else cout << y;
}
void if_8() {

	int x, y;
	cout << "Enter 2 numbers ";
	cin >> x >> y;

	if (x > y) cout << x << " " << y;
	else cout << y << " " << x;
}
int findMin(int p, int d) {
	if (p <= d) return p;
	else return d;
}
void if_12() {

	int a, b, c;

	cout << "Enter 3 numbers ";
	cin >> a >> b >> c;;
	int Min = findMin(a, (findMin(b, c)));
	cout << "The least number is equal to " << Min;

}
int findMax(int k, int f) {
	if (k >= f) return k;
	else return f;
}
void if_14() {

	int a, b, c;

	cout << "Enter 3 numbers ";
	cin >> a >> b >> c;;
	int Min = findMin(a, (findMin(b, c)));
	int Max = findMax(a, (findMax(b, c)));
	cout << "The least number is  " << Min << endl;;
	cout << "The biggest number is  " << Max;

}
void if_15() {

	int a, b, c;

	cout << "Enter 3 numbers ";
	cin >> a >> b >> c;;
	int Max = findMax(a, (findMax(b, c)));
	int Max2=0;
	if (a == Max) { Max2 = findMax(b, c); }
	if (b == Max) { Max2 = findMax(a, c); }
	if (c == Max) { Max2 = findMax(b, a); }
	cout << "Sum of 2 biggest = " << Max + Max2 << endl;;


}
void if_24() {

	int x, y;

	cout << "Enter x: ";
	cin >> x;

	if (x > 0) { y = 2 * sin(x); }
	else { y = 6 - x; }

	cout << "y = " << y << endl;;


}
void if_25() {

	int x, y;

	cout << "Enter x: ";
	cin >> x;

	if (x < -2 || x>2) { y = 2 * x; }
	else { y = -3 * x; }

	cout << "y = " << y << endl;;


}
void if_28() {

	int x;
	cout << "Enter a year ";
	cin >> x;
	if (x % 4 == 0) {
		if (x % 100 == 0 && x % 400 != 0) { cout << "A number of days is equal to 365 "; }
		else cout << "A number of days is equal to 366 ";
	}
	else cout << "A number of days is equal to 365 ";


}