#include <iostream>
using namespace std;

const int BIAYA_PER_SKS = 125000;

struct MataKuliah {
    string nama;
    int sks;
};

int inputMatkul(MataKuliah mk[], int total, int index = 0) {
    if (index == total) return 0;

    cout << "Nama mata kuliah ke-" << index + 1 << ": ";
    cin.ignore(); 
    getline(cin, mk[index].nama);
    cout << "Jumlah SKS: ";
    cin >> mk[index].sks;

    return mk[index].sks + inputMatkul(mk, total, index + 1);
}

int main() {
    string nama, nim;
    int jumlahMatkul;

    cout << "Masukkan NIM: ";
    getline(cin, nim);
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Jumlah mata kuliah: ";
    cin >> jumlahMatkul;

    MataKuliah mk[20];
    int totalSKS = inputMatkul(mk, jumlahMatkul);

    int totalBiaya = totalSKS * BIAYA_PER_SKS;
    float diskon = totalBiaya * 0.15;
    float totalBayar = totalBiaya - diskon;

    cout << "\n=== RINCIAN PEMBAYARAN ===\n";
    cout << "NIM: " << nim << "\n";
    cout << "Nama: " << nama << "\n";
    cout << "\nDaftar Mata Kuliah:\n";
    for (int i = 0; i < jumlahMatkul; i++) {
        cout << "- " << mk[i].nama << " (" << mk[i].sks << " SKS)\n";
    }
    cout << "\nTotal SKS: " << totalSKS << "\n";
    cout << "Total Biaya: Rp " << totalBiaya << "\n";
    cout << "Diskon 15%: Rp " << diskon << "\n";
    cout << "Total Bayar: Rp " << totalBayar << "\n";

    return 0;
}

