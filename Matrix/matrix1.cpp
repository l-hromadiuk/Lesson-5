#include <iostream>
#include "matrix.h"
using namespace std;
void matrix_1() {
	const int  m = 3;
	const int  n = 4;
	int matrix[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 2 * i - j;
			if (matrix[i][j] > 0) {
				cout << matrix[i][j] << "\t";
				;
			}
			else { cout << "-" << "\t"; }
		}cout << endl;
	}
}
void matrix_2() {
	int  m = 0, n;
	cout << "Enter m & n : ";
	cin >> m >> n;
	int count = m;
	int** pmatrix = new int* [m];


	for (int i = 0; i < m; i++) {
		pmatrix[i] = new int[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			pmatrix[i][j] = i - 2 * j;
			cout << pmatrix[i][j] << "\t";

			if (pmatrix[i][j] == 0) { count--; }

		} cout << endl;
	}
	cout << count;


	for (int i = 0; i < m; i++)
	{
		delete[] pmatrix[i];

	}
	delete[]pmatrix;


}