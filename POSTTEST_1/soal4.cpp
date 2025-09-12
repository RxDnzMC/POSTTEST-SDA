#include <iostream>
using namespace std;

void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;
    cout << "Masukkan nilai pertama: ";
    cin >> x;
    cout << "Masukkan nilai kedua  : ";
    cin >> y;

    cout << endl << "Sebelum ditukar: x = " << x << ", y = " << y << endl;
    tukar(x, y);
    cout << "Sesudah ditukar: x = " << x << ", y = " << y << endl;

    cin.ignore();
    cout << "\nTekan Enter untuk keluar...";   
    cin.get();
    return 0;
}
