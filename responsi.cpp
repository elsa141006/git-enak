#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Barang {
    string nama;
    int harga;
};

class Supermarket {
private:
    vector<Barang> daftarBarang;
    int totalPelanggan;
    int totalPemasukan;

public:
    Supermarket() {
        totalPelanggan = 0;
        totalPemasukan = 0;
        bacaDataBarang();
    }

    void login() {
        string user, pass;
        cout << "Username: "; cin >> user;
        cout << "Password (NIM): "; cin >> pass;
        if(user != "admin" || pass != "12345678") {
            cout << "Login gagal.\n";
            exit(0);
        }
    }

    void bacaDataBarang() {
        ifstream file("barang.txt");
        Barang b;
        while(file >> b.nama >> b.harga) {
            daftarBarang.push_back(b);
        }
        file.close();
    }

    void tampilkanBarang() {
        cout << "\nDaftar Barang:\n";
        for(int i = 0; i < daftarBarang.size(); i++) {
            cout << i+1 << ". " << daftarBarang[i].nama << " - Rp" << daftarBarang[i].harga << endl;
        }
    }

    void hapusBarang() {
        int index;
        tampilkanBarang();
        cout << "Masukkan nomor barang yang ingin dihapus: ";
        cin >> index;
        if(index >= 1 && index <= daftarBarang.size()) {
            daftarBarang.erase(daftarBarang.begin() + index - 1);
            cout << "Barang dihapus.\n";
        } else {
            cout << "Indeks tidak valid.\n";
        }
    }

    void kasir() {
        vector<int> jumlahBeli(daftarBarang.size(), 0);
        char lagi;
        do {
            tampilkanBarang();
            int kode, qty;
            cout << "Pilih barang (nomor): ";
            cin >> kode;
            cout << "Jumlah: ";
            cin >> qty;
            if(kode >= 1 && kode <= daftarBarang.size())
                jumlahBeli[kode - 1] += qty;
            else
                cout << "Kode salah.\n";
            cout << "Tambah barang lagi? (y/n): ";
            cin >> lagi;
        } while(lagi == 'y');

        // Hitung total
        int total = 0;
        ofstream struk("struk.txt");
        struk << "=== STRUK PEMBELIAN ===\n";
        for(int i = 0; i < jumlahBeli.size(); i++) {
            if(jumlahBeli[i] > 0) {
                int subtotal = daftarBarang[i].harga * jumlahBeli[i];
                struk << daftarBarang[i].nama << " x " << jumlahBeli[i] << " = Rp" << subtotal << endl;
                total += subtotal;
            }
        }

        // Potongan jika >100000
        if(total > 100000) {
            int diskon = total * 15 / 100;
            total -= diskon;
            struk << "Diskon 15% = -Rp" << diskon << endl;
        }

        struk << "Total Bayar = Rp" << total << endl;
        struk.close();

        cout << "Struk telah dicetak ke struk.txt\n";

        totalPelanggan++;
        totalPemasukan += total;
    }

    void laporan() {
        ofstream file("laporan.txt");
        file << "=== LAPORAN SUPERMARKET ===\n";
        file << "Jumlah Pelanggan: " << totalPelanggan << endl;
        file << "Total Pemasukan: Rp" << totalPemasukan << endl;
        file.close();
        cout << "Laporan tersimpan di laporan.txt\n";
    }

    void menu() {
        int pilihan;
        do {
            cout << "\n--- Menu Supermarket ---\n";
            cout << "1. Tampilkan Barang\n";
            cout << "2. Hapus Barang\n";
            cout << "3. Kasir (Transaksi)\n";
            cout << "4. Laporan\n";
            cout << "5. Keluar\n";
            cout << "Pilihan: ";
            cin >> pilihan;
            switch(pilihan) {
                case 1: tampilkanBarang(); break;
                case 2: hapusBarang(); break;
                case 3: kasir(); break;
                case 4: laporan(); break;
                case 5: cout << "Keluar...\n"; break;
                default: cout << "Pilihan salah\n";
            }
        } while(pilihan != 5);
    }
};

int main() {
    Supermarket toko;
    toko.login();
    toko.menu();
    return 0;
}

