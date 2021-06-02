// laba6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;
const int RANK = 5;
struct element {
	int row;
	int col;
	int value;
	element* next = NULL;
	element* prev = NULL;
};
struct row {
	int index;
	element* beg = NULL;
	element* end = NULL;

	void push(int index, int col, int value) {
		element* a = new element{ index,col,value };
		if (beg != nullptr) {
			a->next = beg;
			beg->prev = a;
			beg = a;
		}
		else {
			beg = a;
			end = a;
		}

	}

};

void readFromfile( const int rank, row* first, row* first_col) {

	ifstream fin("A.txt");
			for (int i = 0; i < rank; i++) {
			for (int j = 0; j < rank; j++) {
				int value;
				if (fin.is_open()) {

					fin >> value;

					first[i].push(i, j, value);
					first_col[j].push(i, j, value);
				}

			}
		}
	
}

	


void print(row* first, const int rank) {
	for (int i = 0; i < rank; i++) {
		element* el = first[i].end;
		
		while (el != NULL) {

			cout << el->value << ' ';
			el = el->prev;
		}
		cout << '\n';
	}
}
int** Swap(row* a) {
	
	int** mtrx = new int* [RANK];
	for (int i = 0; i < RANK; i++)
	{
		element* row = a[i].end;
		mtrx[i] = new int[RANK];
		for (int j = 0; j < RANK; j++)
		{
			mtrx[i][j] = row->value;
			
			row = row->prev;
		}


	}
	return mtrx;
}
/*int determinant(int** a, int n) { 
	if (n == 1)
		return a[0][0];
	else if (n == 2)
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	else {
		int d = 0;
		for (int k = 0; k < n; k++) {
			int** m = new int* [n - 1];
			for (int i = 0; i < n - 1; i++) {
				m[i] = new int[n - 1];
			}
			for (int i = 1; i < n; i++) {
				int t = 0;
				for (int j = 0; j < n; j++) {
					if (j == k)
						continue;
					m[i - 1][t] = a[i][j];
					t++;
				}
			}
			d += pow(-1, k + 2) * a[0][k] * determinant(m, n - 1);
		}
	}
}
/*int determinant(row* first,const int rank) {
	double det = 0;

	row temp[RANK];
	int n = rank;
	
	for (int i = 0; i < rank; i++) {
		for (int j = 0; j < rank; j++) {
			element* row = first[i].end;
			element* col = first[j+1].beg;
			element* el1 = first[0].end;
			///element** k;
			//k = new element * [i];
			
				if (n == 1) return el1->value;
				else if (n == 2) if (col->next) {
					return det = 12;
				} //((row->value) * (col->value) - (row->prev->value) * (col->next->value)); }
				//else { n - 1; }

						
			else {
				for (int x = 0; x < n; x++) {
					int subi = 0;
					for (int i = 1; i < n; i++) {
						int subj = 0;
						for (int j = 0; j < n; j++) {
							if (j == x)
								continue;
							element* r = temp[subi].end;
							r=row;

							subj++;
						}
						subi++;
					}
					det = det + (pow(-1, x) * el1[x].value * determinant(temp, n - 1));
				}
			}
			return det;







		}




	}
}*/
void getMatrixWithoutRowAndCol(int** matrix, int size, int row, int col, int** newMatrix) {
	int offsetRow = 0;
	int offsetCol = 0;
	for (int i = 0; i < size - 1; i++) {
		if (i == row) {
			offsetRow = 1;
		}

		offsetCol = 0;
		for (int j = 0; j < size - 1; j++) {
			if (j == col) {
				offsetCol = 1;
			}

			newMatrix[i][j] = matrix[i + offsetRow][j + offsetCol];
		}
	}
}
int determinant (int** matrix, int size) {
	int det = 0;
	int degree = 1;

	if (size == 1) {
		return matrix[0][0];
	}
	if (size == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}

	int** newMatrix = new int* [size - 1];
	for (int i = 0; i < size - 1; i++) {
		newMatrix[i] = new int[size - 1];
	}
	for (int j = 0; j < size; j++) {
		getMatrixWithoutRowAndCol(matrix, size, 0, j, newMatrix);
		det = det + (degree * matrix[0][j] * determinant(newMatrix, size - 1));
		degree = -degree;
	}
	for (int i = 0; i < size - 1; i++) {
		delete[] newMatrix[i];
	}
	delete[] newMatrix;

	return det;
}

int main()
{
	const int rank = 5;
	
	row first[rank], first_col [rank] ;
	readFromfile( rank, first, first_col);
	print(first, rank);
	cout<<endl<<determinant(Swap(first), rank);
}

