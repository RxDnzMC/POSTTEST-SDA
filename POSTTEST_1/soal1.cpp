#include <iostream>
using namespace std;

void balik_array(int *arr, int n) {
    int *awal = arr;
    int *akhir = arr + n - 1;

    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    const int N = 7;
    int arr[N] = {2, 3, 5, 7, 11, 13, 17}; // bilangan prima

    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
    cout << endl;

    balik_array(arr, N);

    cout << "Array sesudah dibalik: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
    cout << endl;

    cin.ignore();
    cout << "\nTekan Enter untuk keluar...";
    cin.get();

    return 0;
}
