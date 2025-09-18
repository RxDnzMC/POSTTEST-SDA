#include <iostream>
using namespace std;

struct Penerbangan {
    string kode_penerbangan;
    string tujuan;
    string status;
    Penerbangan* next;
};

Penerbangan* head = nullptr;
int counter_jadwal = 0;
string base_kode = "JT-044"; // Dari NIM

// bikin node baru
Penerbangan* buat_node(string tujuan, string status) {
    Penerbangan* baru = new Penerbangan;
    if (counter_jadwal == 0) {
        baru->kode_penerbangan = base_kode;
    } else {
        baru->kode_penerbangan = base_kode + "-" + to_string(counter_jadwal);
    }
    baru->tujuan = tujuan;
    baru->status = status;
    baru->next = nullptr;
    counter_jadwal++;
    return baru;
}

// tambah jadwal di akhir
void tambah_jadwal(string tujuan, string status) {
    Penerbangan* node_baru = buat_node(tujuan, status);

    if (!head) {
        head = node_baru;
        return;
    }

    Penerbangan* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = node_baru;
}

// sisip di posisi khusus (default posisi = digit terakhir NIM + 1 = 5)
void sisip_jadwal(string tujuan, string status) {
    int posisi = 4 + 1; // dari NIM 044 -> 4+1=5
    Penerbangan* node_baru = buat_node(tujuan, status);

    if (posisi <= 1 || !head) {
        node_baru->next = head;
        head = node_baru;
        return;
    }

    Penerbangan* temp = head;
    for (int i = 1; i < posisi-1 && temp->next; i++) {
        temp = temp->next;
    }

    node_baru->next = temp->next;
    temp->next = node_baru;
}

// hapus paling awal
void hapus_awal() {
    if (!head) {
        cout << "Jadwal kosong." << endl;
        return;
    }
    Penerbangan* hapus = head;
    head = head->next;
    delete hapus;
    cout << "Jadwal paling awal berhasil dihapus." << endl;
}

// update status
void update_status(string kode_cari) {
    if (!head) {
        cout << "Tidak ada jadwal." << endl;
        return;
    }
    Penerbangan* temp = head;
    while (temp) {
        if (temp->kode_penerbangan == kode_cari) {
            cout << "Masukkan status baru: ";
            string baru;
            getline(cin >> ws, baru);
            temp->status = baru;
            cout << "Status penerbangan " << kode_cari << " berhasil diperbarui." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Kode penerbangan tidak ditemukan." << endl;
}

// tampilkan semua
void tampilkan() {
    if (!head) {
        cout << "Belum ada jadwal penerbangan." << endl;
        return;
    }
    cout << endl << "=== DAFTAR JADWAL PENERBANGAN ===" << endl;
    Penerbangan* temp = head;
    while (temp) {
        cout << temp->kode_penerbangan << " | "
             << temp->tujuan << " | "
             << temp->status << endl;
        temp = temp->next;
    }
    cout << "=================================" << endl;
}

void hapus_semua() { // hapus semua node untuk menghindari memory leak
    while (head) {
        Penerbangan* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int pilihan;
    while (true) {
        cout << endl << "============================================================" << endl;
        cout << "              ✈ FLIGHT SCHEDULE SYSTEM ✈                   " << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "--------[ Rangga Aditya Rahman  -  2409106044 ]-------------" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << " [1] <=> Tambah Jadwal Penerbangan" << endl;
        cout << " [2] <=> Sisipkan Jadwal Penerbangan (posisi khusus)" << endl;
        cout << " [3] <=> Hapus Jadwal Paling Awal" << endl;
        cout << " [4] <=> Update Status Penerbangan" << endl;
        cout << " [5] <=> Tampilkan Semua Jadwal" << endl;
        cout << " [0] <=> Keluar" << endl;
        cout << "============================================================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 0) break;

        string tujuan, status, kode;
        switch (pilihan) {
            case 1:
                cout << "Tujuan : "; getline(cin >> ws, tujuan);
                cout << "Status : "; getline(cin, status);
                tambah_jadwal(tujuan, status);
                break;
            case 2:
                cout << "Tujuan : "; getline(cin >> ws, tujuan);
                cout << "Status : "; getline(cin, status);
                sisip_jadwal(tujuan, status);
                break;
            case 3:
                hapus_awal();
                break;
            case 4:
                cout << "Masukkan kode penerbangan: ";
                getline(cin >> ws, kode);
                update_status(kode);
                break;
            case 5:
                tampilkan();
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }

    cout << "Program selesai." << endl;
    hapus_semua(); // membersihkan semua node sebelum keluar (bahaya memory leak)
    cin.ignore();
    return 0;
}
