#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    int matriks[N][N];

    cout << "Input matriks 3x3:" << endl;
    for (int i = 0; i < N; i++) { // menginput elemen matriks
        for (int j = 0; j < N; j++) {
            cin >> matriks[i][j];
        }
    }

    cout << endl << "Matriks 3x3:" << endl;
    for (int i = 0; i < N; i++) { // Menampilkan matriks 3x3
        for (int j = 0; j < N; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    int jumlah = 0;
    cout << "Proses penjumlahan elemen baris genap: ";
    for (int i = 0; i < N; i += 2) { // baris genap: 0, 2
        for (int j = 0; j < N; j++) {
            jumlah += matriks[i][j];
            cout << jumlah << " -> ";
        }
    }

    cout << endl << "Jumlah elemen baris genap = " << jumlah << endl;

    cin.ignore(); 
    cout << "\nTekan Enter untuk keluar...";
    cin.get();

    return 0;
}
