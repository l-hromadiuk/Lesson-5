
#include <iostream>

#include "dArray.h"

using namespace std;
void dyn_21() {
	int n, k, l, sum = 0;
	cout << "Enter size of array: ";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;

	}
	cout << "Enter K & L (K<L): ";
	cin >> k >> l;
	for (int i = 0; i < n; i++)
	{
		arr[i];
		if (i<k || i>l) {
			sum += arr[i];
		}

	}delete[]arr;
}
void dyn_32() {
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]= ";
		cin >> arr[i];

	}

	for (int i = 0; i < n; i++)
	{
		arr[i];
		if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
			cout << i; break;

		}

	}


	delete[] arr;
}
void dyn_47() {
	int n, dif = 0;
	cout << "Enter size of array: ";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]= ";
		cin >> arr[i];

	}

	for (int i = 0; i < n; i++, dif++)
	{
		arr[i];
		for (int q = i - 1; q >= 0; q--)
		{


			if (arr[i] == arr[q]) {
				dif--; break;

			}
		}

	}
	cout << dif;

	delete[] arr;
}
void dyn_52() {
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]= ";
		cin >> arr[i];

	}
	int* arr1 = new int[n];
	for (int i = 0; i < n; i++)
	{
		if (i < 5) {
			arr1[i] = 2 * arr[i];
		}
		else { arr1[i] = 0.5 * arr[i]; }
		cout << "arr1[" << i << "]= " << arr1[i] << endl;
	}




	delete[] arr;
	delete[] arr1;
}
void dyn_63() {
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]= ";
		cin >> arr[i];

	}
	int* arr1 = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "arr1[" << i << "]= ";
		cin >> arr1[i];

	}
	int* arr2 = new int[n * 2];
	int i, j, k;
	i = j = k = 0;
	while (i < n && j < n)
	{
		if (arr[i] < arr1[j]) { arr2[k++] = arr[i++]; }
		else { arr2[k++] = arr1[j++]; }
	}
	while (i < n) arr2[k++] = arr[i++];
	while (j < n) arr2[k++] = arr1[j++];
	for (int i = 0; i < 2 * n; i++)
		cout << "arr2[" << i << "]= " << arr2[i] << endl;





	delete[] arr;
	delete[] arr1;
	delete[] arr2;
}
void dyn_71() {
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]= ";
		cin >> arr[i];

	}
	for (int i = n - 1; i >= 0; i--)

		cout << "arr[" << (n - i - 1) << "]= " << arr[i] << endl;





	delete[] arr;
}
void dyn_80() {
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]= ";
		cin >> arr[i];

	}
	for (int i = 1; i < n; i++) {

		arr[i - 1] = arr[i];
		cout << "arr[" << (i - 1) << "]= " << arr[i - 1] << endl;
	}
	arr[n - 1] = 0;
	cout << "arr[" << (n - 1) << "]= " << arr[n - 1] << endl;




	delete[] arr;
}
void dyn_90() {
	int n, k;
	cout << "Enter size of array: ";
	cin >> n;
	int* arr = new int[n];
	cout << "Enter K (1<=K<=N) ";
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]= ";
		cin >> arr[i];

	}
	for (int i = 0; i < n; i++) {

	 arr[i];
		if (i != k) {
			cout << "arr[" << i << "]= " << arr[i] << endl;
		}
	}

	delete[] arr;
}
void dyn_101() {
	int n, k, i;
	cout << "Enter size of array: ";
	cin >> n;
	int* arr = new int[n];
	cout << "Enter K (1<=K<=N) ";
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]= ";
		cin >> arr[i];

	}
	for (int i = 0; i < k - 1; i++) {

		arr[i]; cout << "arr[" << i << "]= " << arr[i] << endl;
	}
	for (i = k - 1; i < n; i++) {
		if (i == k - 1) {
			arr[k - 1] = 0; cout << "arr[" << i << "]= " << arr[k - 1] << endl;
		}
		arr[i]; cout << "arr[" << i << "]= " << arr[i] << endl;
	}



	delete[] arr;
}
void dyn_12() {
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]= ";
		cin >> arr[i];

	}
	for (int i = 1; i < n; i++) {
		while (i % 2 == 0) {
			cout << "arr[" << i << "]= " << arr[i] << endl; i++;
		}
	}

	delete[] arr;
}