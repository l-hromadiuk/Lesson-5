
#include <iostream>
#include "Struct.h"
using namespace std;

struct aeroflot {
		char dest[10];
		int num;
		char plane[10];

	};
void CrudMenu() {
	cout << "1.Search flight." << endl;
	cout << "2.Delete flight." << endl;
	cout << "3.Add flight." << endl;
	cout << "4.Update flight information." << endl;

}
void CinAeroflot(int n, aeroflot* air)
{
	for (int i = 0; i < n; i++) {
		cout << i+1 << ".";
		cout << "Enter destination: ";
		cin >> air[i].dest;
		while (1)
		{
			
				if (isdigit(*air[i].dest))

				{
					cin.clear();
					cin.ignore(256, '\n');
					cout << "You have entered wrong input" << endl << "Enter destination:";
					cin >> air[i].dest;
				}
				else {
					break;
				}
		}
		cout << "Enter number of flight: ";
		cin >> air[i].num;
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "You have entered wrong input" << endl << "Enter number of flight:";
				cin >> air[i].num;
			}
			if (!cin.fail())
				break;
		}
		cout << "Enter a type of plane: ";
		cin >> air[i].plane;
	}
}
int compare(const void* aeroflot1, const void* aeroflot2) {
	return strcmp((reinterpret_cast<const aeroflot*>(aeroflot1))->dest,
		(reinterpret_cast<const aeroflot*>(aeroflot2))->dest);
}
void Sort(aeroflot* air, int n)
{
	qsort(air, n, sizeof(aeroflot), compare);
	cout << endl;
	cout << "Destinations sorted by alphabet: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Destination: " << air[i].dest << endl;
		cout << "Number of a flight: " << air[i].num << endl;
		cout << "Plane type: " << air[i].plane << endl;
		cout << endl;

	}
}
void PlaneInfo(char  plane[10], int n, aeroflot* air, int& count)
{
	cout << "Destinations and numbers of flights according to entered plane type:" << endl;

	cout << "Enter plane type:";

	cin >> plane;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(air[i].plane, plane) == 0)
		{
			cout << "Destination - " << air[i].dest << endl;
			cout << "Number of flight - " << air[i].num << endl;
			count++;cout << endl;
		}
	}
	if (count == 0)
	{
		cout << "No available flights!";cout << endl;
	}
	
}
void Search(char  dest[10], int n, aeroflot* air, int& count)
{
	count = 0;
	cout << "Enter destination:";

	cin >> dest;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(air[i].dest, dest) == 0)
		{
			cout << "Destination - " << air[i].dest << endl;
			cout << "Number of flight - " << air[i].num << endl;
			cout << "Plane type - " << air[i].plane << endl;
			count++;
		}
	};
	if (count == 0)
		cout << "No available flights!";
}
void Delete(int n,aeroflot* air)
{
	int num,j=0;
	cout << "Enterthe number of  flight,which you want to be deleted:";
	cin >> num;
	cout << endl;
	for (int k = 0; k < n; k++) {
		air[k].dest;
		air[k].num;
		air[k].plane;
		if (air[k].num == num) {
			j = k;
			for (int i = 0; i < n; i++) {
				while (i != j) {
					cout << i + 1 << ".";
					cout << "Destination - " << air[i].dest << endl;
					cout << "Number of flight - " << air[i].num << endl;
					cout << "Plane type - " << air[i].plane << endl;
					cout << endl; break;

			}
			}
		}
	}
	
	
	
}
void Add(int n, aeroflot* air) {
	
		cout << "Enter destination: ";
		cin >> air[n].dest;
		while (1)
		{

			if (isdigit(*air[n].dest))

			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "You have entered wrong input" << endl << "Enter destination:";
				cin >> air[n].dest;
			}
			else {
				break;
			}
		}
		cout << "Enter number of flight: ";
		cin >> air[n].num;
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "You have entered wrong input" << endl << "Enter number of flight:";
				cin >> air[n].num;
			}
			if (!cin.fail())
				break;
		}
		cout << "Enter a type of plane: ";
		cin >> air[n].plane;
		cout << endl;
		cout << endl;
	
	for (int i = 0; i <n+1; i++) {
		cout << i + 1 << ".";
		cout << "Destination - " << air[i].dest << endl;
		cout << "Number of flight - " << air[i].num << endl;
		cout << "Plane type - " << air[i].plane << endl;
		cout << endl;
	}
}
void Update(int n, aeroflot* air) {
	int p;
	cout << "Which flight you want to update according to the list? " << endl;
	cout << "Enter value ";
	cin >> p;
	for (int k = 0; k < n; k++) {
		air[k].dest;
		air[k].num;
		air[k].plane;
		if (k + 1 == p) {
			cout << "What exactly you want to change?" << endl;
			cout << "1.Destination." << endl;
			cout << "2.Number of flight." << endl;
			cout << "3.Plane type." << endl;
			int choice;
			cin >> choice;
			switch (choice) {
			case 1: {cout << "Enter new destination: "; cin >> air[k].dest;
				while (1)
				{

					if (isdigit(*air[k].dest))

					{
						cin.clear();
						cin.ignore(256, '\n');
						cout << "You have entered wrong input" << endl << "Enter destination:";
						cin >> air[k].dest;
					}
					else {
						break;
					}
					cout << endl;
				}break; }
			case 2: {cout << "Enter new flight number: "; cin >> air[k].num;
				while (1)
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(256, '\n');
						cout << "You have entered wrong input" << endl << "Enter number of flight:";
						cin >> air[k].num;
					}
					if (!cin.fail())
						break;
				}
				cout << endl; break;
			}
			case 3: {cout << "Enter new plane type: "; cin >> air[k].plane; cout << endl; break;
			}
			}

		}
		cout << k + 1 << ".";
		cout << "Destination - " << air[k].dest << endl;
		cout << "Number of flight - " << air[k].num << endl;
		cout << "Plane type - " << air[k].plane << endl;
		cout << endl;
	}
}
int main()
{
	
	char dest[10];
	char plane[10];
	aeroflot* air;

	cout << "Enter number of flights: ";
	int n,count(0);
	cin >> n;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "You have entered wrong input" << endl << "Enter number of flight:";
			cin >> n;
		}
		if (!cin.fail())
			break;
	}
	air = new aeroflot[n];
	CinAeroflot(n, air);
	Sort(air, n);
	PlaneInfo(plane, n, air, count);
	CrudMenu();
	int choice,i(0);
	cin >> choice;
	switch (choice)
	{
	case 1: Search(dest, n, air, count); break;
	case 2: Delete(n,air); break;
	case 3: Add(n,air); break;
	case 4: Update(n, air); break;


	default: cout << "An error occured "; break;
	}
	
	
		delete[] air;

	
	
}
