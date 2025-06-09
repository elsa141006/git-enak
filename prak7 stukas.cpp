#include <iostream>
using namespace std;

const int MAKS = 100;

class Mahasiswa {
public:
    string nim, nama, prodi, no_telp;

    void input() {
        cout << "Masukkan NIM     : "; cin >> nim;
        cin.ignore(); // Membersihkan buffer
        cout << "Masukkan Nama    : "; getline(cin, nama);
        cout << "Masukkan Prodi   : "; getline(cin, prodi);
        cout << "Masukkan No Telp : "; getline(cin, no_telp);
    }

    void tampil() const {
        cout << "NIM     : " << nim << endl;
        cout << "Nama    : " << nama << endl;
        cout << "Prodi   : " << prodi << endl;
        cout << "No Telp : " << no_telp << endl;
        cout << "---------------------------\n";
    }
};

class ManajemenMahasiswa {
private:
    Mahasiswa data[MAKS];
    int jumlah;

public:
    ManajemenMahasiswa() {
        jumlah = 0;
    }

    void tambahData() {
        if (jumlah >= MAKS) {
            cout << "Data sudah penuh!\n";
            return;
        }
        cout << "Input data mahasiswa ke-" << jumlah + 1 << endl;
        data[jumlah].input();
        jumlah++;
    }

    void tampilkanSemua() const {
        for (int i = 0; i < jumlah; i++) {
            data[i].tampil();
        }
    }

    void urutkanNIM(bool ascending = true) {
        for (int i = 0; i < jumlah - 1; i++) {
            for (int j = 0; j < jumlah - i - 1; j++) {
                bool kondisi = ascending ? (data[j].nim > data[j + 1].nim) : (data[j].nim < data[j + 1].nim);
                if (kondisi) {
                    swap(data[j], data[j + 1]);
                }
            }
        }

        cout << "\nData setelah diurutkan:\n";
        tampilkanSemua();
    }

    void cariNIM(string nim_cari) const {
        bool ditemukan = false;
        for (int i = 0; i < jumlah; i++) {
            if (data[i].nim == nim_cari) {
                cout << "\nData ditemukan:\n";
                data[i].tampil();
                ditemukan = true;
                break;
            }
        }

        if (!ditemukan) {
            cout << "Data dengan NIM " << nim_cari << " tidak ditemukan.\n";
        }
    }
};

int main() {
    ManajemenMahasiswa mm;
    int pilihan;
    string nim_cari;

    do {
        cout << "\n=== Menu Manajemen Mahasiswa ===\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Urutkan Data NIM Ascending\n";
        cout << "4. Urutkan Data NIM Descending\n";
        cout << "5. Cari Mahasiswa berdasarkan NIM\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                mm.tambahData();
                break;
            case 2:
                mm.tampilkanSemua();
                break;
            case 3:
                mm.urutkanNIM(true);
                break;
            case 4:
                mm.urutkanNIM(false);
                break;
            case 5:
                cout << "Masukkan NIM yang dicari: ";
                cin >> nim_cari;
                mm.cariNIM(nim_cari);
                break;
            case 6:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 6);

    return 0;
}

