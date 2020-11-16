#include <iostream>
#include "MenuFunc.h"
using namespace std;
void rectangular() {
	for (int j = 5; j > 0; j--) {
		cout << "*" << " ";

	}
	cout << "\n";
	for (int i = 2; i > 0; i--) {
		cout << "*" << " " << " " << " " << " " << " " << " " << " " << "*" << "\n";
	}
	for (int j = 5; j > 0; j--) {
		cout << "*" << " ";
	}
	cout << "\n";

}
void rightTriangle() {
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == 0 || i == j || i == 4)
            {
                cout << "*";
            }
            else
            {
                cout << ' ';
            }

        }

        cout << "\n";
    }

}
void equalTriangle() {
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j == 4 - i || j == 4 + i || i == 4)
			{
				cout << "*";
			}
			else
			{
				cout << ' ';
			};

		}

		cout << "\n";
	}

}
void rhomb() {
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (i == 0 && j > 5 && j < 11) { cout << "*"; }
			if (i == 4 && j > 1 && j < 7) { cout << "*"; }
			if (j == 4 - i || j == 14 - i && i != 0 && i != 4)
			{
				cout << "*";
			}
			else
			{
				cout << ' ';
			};

		}

		cout << "\n";
	}

}