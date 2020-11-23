#include <iostream>
using namespace std;
int main()
{
	const int n = 20;
	char a[n];
	char b[n];
	int max(0), m, k, x, ind(0);
	cout << " Enter 2 strings:"<<endl;
	cin >> a >> b;
	for ( int i = 0; i <strlen(a); i++) {
		for (int j = 0; j < strlen(b); j++) {
			if (a[i] == b[j]) {
				m = j; k = i;
				x = 0;
				while (a[k] == b[m]) {
					++x;
					if (x > max) {
						max = x;
						ind = k;
					}
					m++;
					k++;
				}
			}
		}
	}
	for ( int i = ind - max+1; i <= ind; i++)
	{
		cout << a[i];
	}
	return 0;
}


