#include <iostream>
#include <cmath>
#include <string>
#include "lab3.h"
using namespace std;

double pow_1(double a, int n)
{

	if (n == 0) return 1;
	double res = 1;
	while (n > 0) {
		if (n % 2 == 0) {
			n /= 2;
			a *= a;
		}
		else {
			n--;
			res *= a;
		}
	}
	return res;

}
void lab3_2() {


	double a, eps = 0.0001;
	double p;

	cout << "Enter A and n ";
	cin >> a >> p;
	double x = pow(a, 1 / p), xn = a, x_pr;
	for (int i = 0; fabs(x - xn) > eps; i++) {
		x_pr = xn;
		xn = (1 / p) * (x_pr * (p - 1) + a / (pow_1(x_pr, p - 1)));
	}
	cout << "Answer is equal to " << xn;






}
void lab3_16() {
	string f;
	cout << "Enter f(x) =";
	cin.ignore(32767, '\n');
	getline(cin, f);
	
	int s, c, t, ct, x, n(0);
	double period;
	double PI_2 = asin(1.0);
	s = f.find("sin");
	c = f.find("cos");
	t = f.find("tg");
	ct = f.find("ctg");
	x = f.find("x");
	auto k = find_if(f.begin(), f.end(), isdigit);

	if (k != f.end()) { n = atoi(f.c_str() + (k - f.begin())); }
	if (n == 0) { n = 1; }
	if (x == -1 && s != 0 && c != 0 && t != 0 && ct != 0) {
		cout << "f(x) is periodic,but there is no least period" << endl;
	}

	if (s == 0 || c == 0) {
		cout << "f(x) is periodic" << endl;
		period = (4 * PI_2) / n;
		cout << "Period is equil to " << period << endl;
	}

	if (t == 0 || ct == 0) {
		cout << "f(x) is periodic" << endl;
		period = (2 * PI_2) / n;
		cout << "Period is equil to " << period << endl;
	}
	if ((t != 0 && ct != 0) && (s != 0 && c != 0) && (x != -1)) { cout << "f(x) isn't periodic"; }
}