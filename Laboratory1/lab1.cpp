#include <iostream>
#include "lab1.h"

using namespace std;
unsigned long long  int factorial(unsigned long long int a) {
    if (a < 0) { return 0; }
   
	if (a == 0) { return 1; }
	else { return a * factorial(a - 1); }
}
void lab1_2() {

	 unsigned long long  int n, k, C;
	cout << "Enter n (n>=0) ";
	cin >> n;
	cout << "Enter k (0<=k<=n) ";
	cin >> k;


    
    if (n >= k) {
        C = ((factorial(n)) / ((factorial(k)) * (factorial(n - k))));
		cout << "C = " << C << endl;
	}
	else { cout << "An error occured"; }
	int d = 2;
	cout << "C = ";
	while (d <= C) {
        
		while (C % d == 0) {
           
			cout << d; C /= d; cout << "*";
		}
		d++;

	}
   
        cout << "1";
    
	}
int maxDivider(int a, int d)/*перевірка чи числа взаємнопрості*/
{


    while (a > 0 && d > 0) {

        while (a != d) {
            if (a > d) {
                a -= d;
            }
            else {
                d -= a;
            }

        }
        return d;
    }

}
long binpow(long q, long w, long e) {
    long res = 1;
    while (w != 0) {
        if (w % 2 == 1) {
            res *= q;
            res %= e;
        }
        q *= (q % e);
        q %= e;
        w /= 2;
    }
    return res % e;
}
void lab1_10() {
    
    
    
       
        long b, n, p;
        setlocale(LC_ALL, "Ukrainian_Ukraine.1251");
        cout << "Уведiть число,яке необхiдно перевiрити(n>0) ";
        cin >> n;
        cout << "Уведiть число,взаємнопросте з n ";
        cin >> b;
        int c = maxDivider(b, n);
        while (c != 1) {
            cout << "Уведене b не є взаємопростим з заданим числом n" << endl;
            cout << "Уведiть число,взаємно просте з n ";
            cin >> b;
            if (maxDivider(b, n) == 1) break;
        }
        p = n - 1;


        if (binpow(b, p, n) == 1) {
            cout << n << "-число Кармайкла";
        }
        else {
            cout << n << "-не число Кармайкла";




        }
    }
