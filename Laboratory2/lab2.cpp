#include <iostream>
#include <cmath> 
#include "lab2.h"
using namespace std;
double findCentreX(double x1, double x2, double x3) {
	double x_mid, x_cent;
	x_mid = (x1 + x3) / 2;
	x_cent = (x2 + 2 * x_mid) / 3;
	return x_cent;
}

double findCentreY(double y1, double y2, double y3) {
	double y_mid, y_cent;
	y_mid = (y1 + y3) / 2;
	y_cent = (y2 + 2 * y_mid) / 3;
	return y_cent;
}
void rotationScaling(double x1, double x2, double x3, double y1, double y2, double y3, double x_cent, double y_cent) {
	double angle, x1_new, x2_new, x3_new, y1_new, y2_new, y3_new, sfactor;
	double PI_2 = asin(1.0);
	cout << "Enter angle (in degrees) : ";
	cin >> angle;
	cout << "Enter scaling factor : ";
	cin >> sfactor;
	angle = (angle * PI_2 / 90);
	cout << "After rotation & sсaling: " << endl;
	x1_new = x_cent + (x1 - x_cent) * cos(angle) - (y1 - y_cent) * sin(angle);
	x2_new = x_cent + (x2 - x_cent) * cos(angle) - (y2 - y_cent) * sin(angle);
	x3_new = x_cent + (x3 - x_cent) * cos(angle) - (y3 - y_cent) * sin(angle);
	y1_new = y_cent + (y1 - y_cent) * cos(angle) + (x1 - x_cent) * sin(angle);
	y2_new = y_cent + (y2 - y_cent) * cos(angle) + (x2 - x_cent) * sin(angle);
	y3_new = y_cent + (y3 - y_cent) * cos(angle) + (x3 - x_cent) * sin(angle);
	x1_new = x_cent + (x1_new - x_cent) * sfactor;
	x2_new = x_cent + (x2_new - x_cent) * sfactor;
	x3_new = x_cent + (x3_new - x_cent) * sfactor;
	y1_new = y_cent + (y1_new - y_cent) * sfactor;
	y2_new = y_cent + (y2_new - y_cent) * sfactor;
	y3_new = y_cent + (y3_new - y_cent) * sfactor;
	cout << "(" << x1_new << ";" << y1_new << ")" << endl;
	cout << "(" << x2_new << ";" << y2_new << ")" << endl;
	cout << "(" << x3_new << ";" << y3_new << ")" << endl;
}
void lab2_2() {
	double x1, x2, x3, x_cent, y1, y2, y3, y_cent;
	cout << "Enter first vertex ";
	cin >> x1 >> y1;
	cout << "Enter second vertex ";
	cin >> x2 >> y2;
	cout << "Enter third vertex ";
	cin >> x3 >> y3;
	x_cent = findCentreX(x1, x2, x3);
	y_cent = findCentreY(y1, y2, y3);
	cout << "Centre(" << x_cent << ";" << y_cent << ")" << endl;
	rotationScaling(x1, x2, x3, y1, y2, y3, x_cent, y_cent);

}
//Вважатимемо,що навколо заданого багатокутника однозначно можна описати коло//
void lab2_14() {
	int num;
	cout << "Enter number of sides ";
	cin >> num;
	double* x = new double[num];
	double* y = new double[num];
	for (int i = 1; i <= num; i++) {
		cout << "Enter vetrix ";
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= num; i++)
	{
		cout << "(" << x[i] << ";" << y[i] << ")" << endl;
	}
	double d1, d2, y_cent, x_cent, radius;
	d1 = -((x[2] - x[1]) * ((x[1] + x[2]) / 2)) - ((y[2] - y[1]) * ((y[1] + y[2]) / 2));
	d2 = -((x[3] - x[2]) * ((x[3] + x[2]) / 2)) - ((y[3] - y[2]) * ((y[3] + y[2]) / 2));
	y_cent = ((d2 * (x[2] - x[1])) - (d1 * (x[3] - x[2]))) / (((y[2] - y[1]) * (x[3] - x[2])) - ((y[3] - y[2]) * (x[2] - x[1])));
	x_cent = (-d1 - (y_cent * (y[2] - y[1]))) / (x[2] - x[1]);
	cout << "Centre of circle (" << x_cent << ";" << y_cent << ")" << endl;
	radius = sqrt((pow((x[1] - x_cent), 2)) + (pow((y[1] - y_cent), 2)));
	cout << "R = " << radius << endl;
}