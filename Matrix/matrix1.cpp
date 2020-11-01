#include <iostream>
#include "matrix.h"
using namespace std;
void matrix_01() {
	const int  m = 3;
	const int  n = 4;
	int matrix[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 2 * i - j;
			if (matrix[i][j] > 0) {
				cout << matrix[i][j] << "\t";

			}
			else { cout << "-" << "\t"; }
		}cout << endl;
	}
}
void matrix_02() {
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
void matrix_1() {
	const int  m = 3;
	const int  n = 4;
	int matrix[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = i + j;
			if (i == 0) {

				matrix[i][j] = j * 10;
			}	cout << matrix[i][j] << "\t";
		}

		cout << endl;
	}


}
void matrix_7() {
	int  m, n, k;
	cout << "Enter M & N : ";
	cin >> m >> n;
	cout << "Enter K (1 <= K <= M). : ";
	cin >> k;
	int** pmatrix = new int* [m];


	for (int i = 0; i < m; i++) {
		pmatrix[i] = new int[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			pmatrix[i][j] = i - 2 * j;
			if (i == k - 1) {
				cout << pmatrix[i][j] << "\t";
			}



		} cout << endl;
	}



	for (int i = 0; i < m; i++)
	{
		delete[] pmatrix[i];

	}
	delete[]pmatrix;


}
void matrix_8() {
	int  m, n, k;
	cout << "Enter M & N : ";
	cin >> m >> n;
	cout << "Enter K (1 <= K <= N). : ";
	cin >> k;
	int** pmatrix = new int* [m];


	for (int i = 0; i < m; i++) {
		pmatrix[i] = new int[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			pmatrix[i][j] = i - 2 * j;
			if (j == k - 1) {
				cout << pmatrix[i][j] << "\t";
			}



		} cout << endl;
	}



	for (int i = 0; i < m; i++)
	{
		delete[] pmatrix[i];

	}
	delete[]pmatrix;


}
void matrix_10() {
	int  m, n;
	cout << "Enter M & N : ";
	cin >> m >> n;

	int** pmatrix = new int* [m];


	for (int i = 0; i < m; i++) {
		pmatrix[i] = new int[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j += 2) {
			pmatrix[i][j] = i - 2 * j;
			cout << pmatrix[i][j] << "\t";
		} cout << endl;
	}



	for (int i = 0; i < m; i++)
	{
		delete[] pmatrix[i];

	}
	delete[]pmatrix;


}
void matrix_17() {
	int  m, n, k, sum(0), dob(1);
	cout << "Enter M & N : ";
	cin >> m >> n;
	cout << "Enter K(1 <=K <= M). : ";
	cin >> k;
	int** pmatrix = new int* [m];
	for (int i = 0; i < m; i++) {
		pmatrix[i] = new int[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			pmatrix[i][j] = i - 2 * j;
			if (i == k - 1) {
				sum += pmatrix[i][j];
				dob *= pmatrix[i][j];
			}




		}
	}cout << "sum=" << sum << " ; " << "dob=" << dob;



	for (int i = 0; i < m; i++)
	{
		delete[] pmatrix[i];

	}
	delete[]pmatrix;


}
void matrix_18() {
	int  m, n, k, sum(0), dob(1);
	cout << "Enter M & N : ";
	cin >> m >> n;
	cout << "Enter K(1 <=K <= N). : ";
	cin >> k;
	int** pmatrix = new int* [m];
	for (int i = 0; i < m; i++) {
		pmatrix[i] = new int[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			pmatrix[i][j] = i - 2 * j;
			if (j == k - 1) {
				sum += pmatrix[i][j];
				dob *= pmatrix[i][j];
			}




		}
	}cout << "sum=" << sum << " ; " << "dob=" << dob;



	for (int i = 0; i < m; i++)
	{
		delete[] pmatrix[i];

	}
	delete[]pmatrix;


}
void matrix_20() {
	int  m, n, dob(1);
	cout << "Enter M & N : ";
	cin >> m >> n;

	int** pmatrix = new int* [m];
	for (int i = 0; i < m; i++) {
		pmatrix[i] = new int[n];
	}


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			pmatrix[i][j] = i + j;


			cout << pmatrix[i][j] << "\t";
		}cout << endl;
	}
	for (int j = 1; j < n; j++) {
		dob = 1;
		for (int i = 0; i < m; i++) {
			dob *= pmatrix[i][j];
			if (i == m - 1)cout << "dob[" << j << "]=" << dob << endl;

		}
	}

	for (int i = 0; i < m; i++)
	{
		delete[] pmatrix[i];

	}
	delete[]pmatrix;
}