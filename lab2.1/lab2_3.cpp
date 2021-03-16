// lab2_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
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
struct matrix {
	row* start = NULL;
	row* finish = NULL;
	/*void push(int index) {
		row* a = new row{ index };
		if (start != nullptr) {
			a->beg = start;
			start-> = a;
			beg = a;
		}
		else {
			start = a;
			end = a;
		}

	}*/
};


void readFromfile(const char* file, const int rank, row* first) {
	FILE* fp = fopen(file, "r+");
	for (int i = 0; i < rank; i++) {
		for (int j = 0; j < rank; j++) {
			int value;
			fread(&value, sizeof(int), 1, fp);
			first[i].push(i, j, value);
		}
	}

	fclose(fp);

}
void print(row* first, const int rank) {
	for (int i = 0; i < rank; i++) {
		element* el = first[i].beg;
		if (!el) {
			cout << "this line consists of zeroes only ";
		}


		while (el != NULL) {

			cout << el->value << ' ';
			el = el->next;
		}
		cout << '\n';
	}
}
void sum(row* a, row* b, const int rank, row* sum) {
	for (int i = 0; i < rank; i++) {
		element* first = a[i].end;
		element* second = b[i].end;
		while (first != NULL && second != NULL) {
			if (first == second) { sum[i].push(i, first->col, 2 * first->value); }
			if (first == NULL) sum[i].push(i, first->col, second->value);
			if (second == NULL) sum[i].push(i, first->col, first->value);
			else {

				sum[i].push(i, first->col, first->value + second->value);
			}
			first = first->prev;
			second = second->prev;

		}
	}
	cout << '\n';
	print(sum, rank);

}
void dobutok(row* a, row* b, const int rank, row* m) {
	for (int i = 0; i < rank; i++) {
		for (int j = 0; j < rank; j++) {
			int result = 0;
			element* first = a[i].end;
		element* second = b[j].end;
		while (first) {

				while (second) {
					result += first->value * second->value;
					
					second = second->prev; 
					break;
				}first = first->prev; 
			}if (result != 0) m[i].push(i, j, result);

		}
	}
	cout << '\n';
	print(m, rank);

}

int main() {

	const int rank = 5;
	row first[rank], second[rank], summ[rank], mul[rank];
	readFromfile("A.txt", rank, first);
	print(first, rank);
	cout << endl;
	readFromfile("B.txt", rank, second);
	print(second, rank);
	sum(first, second, rank, summ);
	dobutok(first, second, rank, mul);
}