#include <iostream>
using namespace std;

void tampilkanLaporan(int pengeluaran[], int sisa[], int bulan, int index = 0, int totalPengeluaran = 0, int totalTabungan = 0) {
    if (index == bulan) {
    	cout << endl;
        cout << "SISA PERBULAN :" << endl;
        for (int i = 0; i < bulan; i++) {
            cout << "Bulan ke-" << i + 1 << " : RP " << sisa[i] << endl;
        }
		cout << endl;
		cout << "-----------------------------------"<<endl;
        cout << "UANG KELUAR = " << totalPengeluaran << endl;
        cout << "TABUNGAN    = " << totalTabungan << endl;
        cout << "-----------------------------------"<<endl;
        return;
    }

    cout << "bulan ke-" << index + 1 << " : RP " << pengeluaran[index] << endl;
    sisa[index] = sisa[index]; 

    tampilkanLaporan(
        pengeluaran,
        sisa,
        bulan,
        index + 1,
        totalPengeluaran + pengeluaran[index],
        totalTabungan + sisa[index]
    );
}

int main() {
    int uangSaku, jumlahBulan;

    cout << "---PROGRAM RINCIAN KEUANGAN GUEH---" << endl;
    cout << "Masukan Jumlah Uang Saku : ";
    cin >> uangSaku;
    cout << "Masukan Jumlah Bulan : ";
    cin >> jumlahBulan;

    int pengeluaran[jumlahBulan];
    int sisa[jumlahBulan];

    for (int i = 0; i < jumlahBulan; i++) {
        cout << "Pengeluaran Bulan ke-" << i + 1 << " : ";
        cin >> pengeluaran[i];
        sisa[i] = uangSaku - pengeluaran[i]; 
    }

    cout << "-----------------------------" << endl;
    cout << "      RINCIAN KEUANGAN GUEH" << endl;
    cout << "-----------------------------" << endl;
    cout << "PEMASUKAN    : " << uangSaku << endl;
    cout << "PENGELUARAN  : " << endl;

    tampilkanLaporan(pengeluaran, sisa, jumlahBulan);

    return 0;
}

