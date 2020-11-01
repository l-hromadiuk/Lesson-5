// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "matrix.h"
using namespace std;
void mainMenu() {
	setlocale(LC_ALL, "Ukrainian_Ukraine.1251");
	cout << "100. Вывести все положительные елементы; Статична матриця" << endl;
	cout << "0.Вывести количество строк, не содержащих ни одного нулевого элемента; Динамічна матриця. " << endl;
	cout << "1.Сформировать целочисленную матрицу размера M × N, у которой все элементы I- oй строки имеют значение 10·I" << endl;
	cout << "7.Дана матрица размера M × N и целое число K (1 ≤ K ≤ M). Вывестиэлементы K - й строки данной матрицы." << endl;
	cout << "8.Дана матрица размера M × N и целое число K (1 ≤ K ≤N ). Вывестиэлементы K - й столбца данной матрицы." << endl;
	cout << "10.Дана матрица размера M × N. Вывести ее элементы, расположенные в столбцах с нечетными номерами" << endl;
	cout << "17.Дана матрица размера M × N и целое число K (1 ≤ K ≤ M). Найти сумму и произведение элементов K - й строки матрицы." << endl;
	cout << "18.Дана матрица размера M × N и целое число K (1 ≤ K ≤ M). Найти сумму и произведение элементов K -го столбца матрицы." << endl;
	cout << "20.Дана матрица размера M × N.Для каждого столбца матрицы найти произведение его элементов." << endl;
	}

int main() {
	mainMenu();
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 100:  matrix_01(); break;
	case 0:  matrix_02(); break;
	case 1:	 matrix_1(); break;
	case 7:	 matrix_7(); break;
	case 8:	 matrix_8(); break;
	case 10: matrix_10(); break;
	case 17: matrix_17(); break;
	case 18: matrix_18(); break;
	case 20: matrix_20(); break;
	

	default: cout << "An error occured "; break;
	}
	return 0;
}