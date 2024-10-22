#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;

int** new_arr(int rows, int cols, int low, int high) {
    int** a = new int*[rows];
    for (int i = 0; i != rows; i++) {
        a[i] = new int[cols];
    }
    for (int i = 0; i != rows; i++) {
        for (int j = 0; j != cols; j++) {
            a[i][j] = low + rand() % (high - low + 1);
        }
    }
    return a;
}

void print_arr(int** a, int rows, int cols) {
    for (int i = 0; i != rows; i++) {
        cout << "{";
        for (int j = 0; j != cols; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << setw(4) << "}" << endl;
    }
    cout << endl;
}

void Calc(int** a, int rows, int cols, int& S, int& amount) {
    for (int i = 0; i != rows; i++) {
        for (int j = 0; j != cols; j++) {
            if ( !(a[i][j] % 2 != 0 && (i+j) % 7 == 0) ) {
                amount++;
                S += a[i][j];
                a[i][j] = 0;
            }
        }
    }
}

void Change(int** a, int rows, int cols) {
    int tmp;
    for (int i = 0; i != rows-1; i++) {
        for (int j = 0; j != rows - i - 1; j++) {
            if ((a[j][0] > a[j + 1][0]) || 
                (a[j][0] == a[j + 1][0] && a[j][1] < a[j + 1][1]) || 
                (a[j][0] == a[j + 1][0] && a[j][1] == a[j + 1][1] && a[j][2] < a[j + 1][2])) {
                for (int index = 0; index != cols; index++) {
                    tmp = a[j][index];
                    a[j][index] = a[j+1][index];
                    a[j+1][index] = tmp;
                }
            }

        }
    }
}

int main()
{
    srand(time(NULL));

    int low = 9, high = 61;
    int rows = 7, cols = 6;
    int S = 0, amount = 0;

    int** a = new_arr(rows, cols, low, high);
    print_arr(a, rows, cols);
    Change(a, rows, cols);
    print_arr(a, rows, cols);
    Calc(a, rows, cols, S, amount);
    cout << "Amount = " << amount << endl;
    cout << "S = " << S << endl;
    print_arr(a, rows, cols);

    for (int i = 0; i != rows; i++) {
        delete[] a[i];
    }
    delete[] a;
}