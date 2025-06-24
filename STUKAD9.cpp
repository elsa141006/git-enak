#include <iostream>
using namespace std;

class DataMahasiswa {
private:
    string nim;
    string nama;
    string prodi;
    string nomorTelp;

public:
    void inputData() {
        cout << "Masukkan NIM: ";
        cin >> nim;
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan Prodi: ";
        cin >> prodi;
        cout << "Masukkan Nomor Telp: ";
        cin >> nomorTelp;
    }

    void tampilkanData() {
        cout << "NIM         : " << nim << endl;
        cout << "Nama        : " << nama << endl;
        cout << "Prodi       : " << prodi << endl;
        cout << "Nomor Telp  : " << nomorTelp << endl;
        cout << "--------------------------" << endl;
    }

    string getNim() {
        return nim;
    }
};

void urutkanAscending(DataMahasiswa data[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (data[j].getNim() > data[j + 1].getNim()) {
                DataMahasiswa temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    cout << "\nData setelah diurutkan (Ascending):\n";
    for (int i = 0; i < jumlah; i++) {
        data[i].tampilkanData();
    }
}

void urutkanDescending(DataMahasiswa data[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (data[j].getNim() < data[j + 1].getNim()) {
                DataMahasiswa temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    cout << "\nData setelah diurutkan (Descending):\n";
    for (int i = 0; i < jumlah; i++) {
        data[i].tampilkanData();
    }
}

int main() {
    int MAKS_MHS = 5;
    DataMahasiswa data[MAKS_MHS];
    int jumlahData = 0;
    int pilihan;

    do {
        cout << "\nMenu Pengelolaan Data Mahasiswa\n";
        cout << "1. Input Data\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Urutkan NIM berdasarkan (Ascending)\n";
        cout << "4. Urutkan NIM berdasarkan (Descending)\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (jumlahData < MAKS_MHS) {
                    data[jumlahData].inputData();
                    jumlahData++;
                } else {
                    cout << "Data sudah penuh!" << endl;
                }
                break;

            case 2:
                if (jumlahData == 0) {
                    cout << "Belum ada data." << endl;
                } else {
                    for (int i = 0; i < jumlahData; i++) {
                        data[i].tampilkanData();
                    }
                }
                break;

            case 3:
                if (jumlahData > 0) {
                    urutkanAscending(data, jumlahData);
                } else {
                    cout << "Data masih kosong!" << endl;
                }
                break;

            case 4:
                if (jumlahData > 0) {
                    urutkanDescending(data, jumlahData);
                } else {
                    cout << "Data masih kosong!" << endl;
                }
                break;

            case 5:
                cout << "Terima kasih." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}

