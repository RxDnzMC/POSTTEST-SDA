#include <iostream>
using namespace std;

struct Mahasiswa { // Struct data mahasiswa
    string nama;
    string nim;
    double ipk;
};

void bubbleSort(Mahasiswa arr[], int n) { // Fungsi Sorting Ipk
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].ipk > arr[j+1].ipk) { // Tukar Posisi  
                Mahasiswa temp = arr[j]; 
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    const int N = 4;
    Mahasiswa mhs[N];

    cout << "Input data mahasiswa:" << endl; // Input data mahasiswa
    for (int i = 0; i < N; i++) {
        cout << "Mahasiswa " << i+1 << endl;
        cout << "Nama : "; 
        cin >> mhs[i].nama;
        cout << "NIM  : "; 
        cin >> mhs[i].nim;
        cout << "IPK  : "; 
        cin >> mhs[i].ipk;
        cout << endl;
    }

    // Urutkan IPK ascending
    bubbleSort(mhs, N);

    cout << "Data setelah diurutkan berdasarkan IPK (ascending):" << endl;
    cout << "Nama | NIM | IPK" << endl;
    cout << "---------------------" << endl;
    for (int i = 0; i < N; i++) { // Tampilkan data mahasiswa
        cout << mhs[i].nama << " | " << mhs[i].nim << " | " << mhs[i].ipk << endl;
    }

    cin.ignore();
    cout << "\nTekan Enter untuk keluar...";
    cin.get();

    return 0;
}
