#include <iostream>
#include <conio.h>
#include <iomanip>
#include <math.h>
using namespace std;

const int MAX_SIZE = 10;

void gaussianElimination(double arr[MAX_SIZE][MAX_SIZE+1], int n);

void gaussianElimination(double arr[MAX_SIZE][MAX_SIZE+1], int n) {
    // Lakukan eliminasi Gauss
    for (int i = 0; i < n; i++) {
        // Temukan baris dengan elemen terbesar di kolom i
        int max_row = i;
        for (int j = i+1; j < n; j++) {
            if (abs(arr[j][i]) > abs(arr[max_row][i])) {
                max_row = j;
            }
        }

        // Tukar baris maksimum dengan baris i
        for (int j = i; j <= n; j++) {
            double temp = arr[i][j];
            arr[i][j] = arr[max_row][j];
            arr[max_row][j] = temp;
        }

        // Buat elemen diagonal menjadi 1 dan elemen di bawahnya menjadi 0
        for (int j = i+1; j < n; j++) {
            double factor = arr[j][i] / arr[i][i];
            for (int k = i; k <= n; k++) {
                arr[j][k] -= factor * arr[i][k];
            }
        }
    }

    // Lakukan substitusi mundur untuk mencari solusi
    for (int i = n-1; i >= 0; i--) {
        for (int j = i+1; j < n; j++) {
            arr[i][n] -= arr[j][n] * arr[i][j];
        }
        arr[i][n] /= arr[i][i];
    }
}

int main() {
    int n;

    cout << "Masukkan jumlah persamaan: ";
    cin >> n;

    double arr[MAX_SIZE][MAX_SIZE+1];

    cout << "Masukkan koefisien dan konstanta persamaan: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    gaussianElimination(arr, n);

    cout << "Solusi sistem persamaan linear: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i+1 << " = " << fixed << setprecision(3) << arr[i][n] << endl;
    }

    getch();
}

