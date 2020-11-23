

#include <iostream>
using namespace std;
void coutMatrix(int n, int** a)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << '\t';
        cout << endl;
    }
    for (int i = 0; i < n; ++i)
        delete a[i];

    delete[] a;
   
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << endl;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    int k, l;
    if (n % 2 == 1) {
        k = (n - 1) / 2;
    }
    else {
        k = n / 2 - 1;
    }
    l = n / 2;
    int num(0), x(0);

    a[k][l] = ++num;
    while (k < n && l < n)
    {
        ++x;
        for (int b = 0; b < x; b++)
        {
            if (k + 1 < n) {
                a[++k][l] = ++num;

            }
            else {
                coutMatrix(n, a);
                return 0;
            };

        }
        for (int b = 0; b < x; ++b)
            a[k][--l] = ++num;
        ++x;
        for (int b = 0; b < x; ++b)
        {
            if (k - 1 >= 0) {
                a[--k][l] = ++num;


            }
            else {
                coutMatrix(n, a);  return 0;
            }

        }

         for (int b = 0; b < x; ++b) {
              a[k][++l] = ++num;
          }
      }

      coutMatrix(n, a);

      return 0;
    }


