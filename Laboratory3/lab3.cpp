#include <iostream>
#include <cmath>
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