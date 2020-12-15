#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
using namespace std;
struct scan_info
{
	char model[25]; // модель
	int price; //ціна
	double x_size; //горизонтальна область
	double y_size; //вертикальна область сканування
	int grey;//градация серого
	
};
void sortPrice(scan_info  scan[],int&n)
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n -i - 1; j++)
		{
			if (scan[j].price > scan[j + 1].price) {
				scan_info temp = scan[j];
				scan[j] = scan[j + 1];
				scan[j + 1] = temp;
			}
		}
}
void sortGrey(scan_info  scan[], int& n)
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n - i - 1; j++)
		{
			if (scan[j].grey > scan[j + 1].grey) {
				scan_info temp = scan[j];
				scan[j] = scan[j + 1];
				scan[j + 1] = temp;
			}
		}
}
void saveToFile(scan_info* a,int& n)
{
	ofstream note_file("scan.dat");
	note_file.write((char*)&n , sizeof(int));
	for (size_t i = 0; i < n; i++) {
		note_file.write((char*)&a[i], sizeof(scan_info));
	}
}
void read(scan_info* a,int& n)
{
	ifstream note_file("scan.dat");
	note_file.read((char*)&n, sizeof(int));
	for (size_t i = 0; i < n; i++) {
		note_file.read((char*)&a[i], sizeof(scan_info));
	}
}
void printScaners(scan_info* a,int &n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << "model " << a[i].model << endl;
		cout <<"price "<< a[i].price<<endl;
		cout << "horizontal area " << a[i].x_size << endl;
		cout << "vertikal area " << a[i].y_size << endl;
		cout << "grey " << a[i].grey << endl;
		cout << endl;
	}
}
void mainMenu() {
	cout << "1.Sort by price"<<endl;
	cout << "2.Sort by grey"<<endl;
	;
}
int main()
{
	int n;
	cin >> n;
	scan_info* a;
	a = new scan_info[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter model ";
		cin >> a[i].model;
		cout << "Enter price ";
		cin >> a[i].price;
		cout << "Enter horizontal area ";
		cin >> a[i].x_size;
		cout << "Enter vertikal area ";
		cin >> a[i].y_size;
		cout << "Enter grey ";
		cin >> a[i].grey;
		cout << endl;
		saveToFile(&a[i], n);

	}
	int choice;
	mainMenu();
	cin >> choice;
	switch (choice) {
	case 1:sortPrice(a, n); break;
	case 2:sortGrey(a, n); break;
	}
	 printScaners(a, n);   
	 saveToFile(a, n);

	 cout << "Read from file" << endl;
	 read(a, n);
	 printScaners(a, n);
}