#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long long int nik;
    string nama, tempat, alamat, desa, kec, agama, sKawin, pkr, kwn, golD;
    int tanggal, bulan, tahun, rt, rw, tgl, bln, thn;
    char jenisKelamin;
    char ulang;

    do {
        cout << "Masukkan NIK: ";
        cin >> nik;
        cin.ignore();

        cout << "Masukkan Nama: ";
        getline(cin, nama);

        cout << "Masukkan Tempat: ";
        getline(cin, tempat);

        cout << "Masukkan Tanggal Lahir: ";
        cin >> tanggal;
        cout << "Masukkan Bulan Lahir: ";
        cin >> bulan;
        cout << "Masukkan Tahun Lahir: ";
        cin >> tahun;
        cin.ignore();

        cout << "Masukkan Jenis Kelamin (L/P): ";
        cin >> jenisKelamin;
        cin.ignore();

        cout << "Masukkan Gol. Darah: ";
        getline(cin, golD);

        cout << "Masukkan Alamat: ";
        getline(cin, alamat);

        cout << "Masukkan RT: ";
        cin >> rt;
        cout << "Masukkan RW: ";
        cin >> rw;
        cin.ignore();

        cout << "Masukkan Kel/Desa: ";
        getline(cin, desa);

        cout << "Masukkan Kecamatan: ";
        getline(cin, kec);

        cout << "Masukkan Agama: ";
        getline(cin, agama);

        cout << "Masukkan Status Perkawinan: ";
        getline(cin, sKawin);

        cout << "Masukkan Pekerjaan: ";
        getline(cin, pkr);

        cout << "Masukkan Kewarganegaraan: ";
        getline(cin, kwn);

        cout << "Masukkan Tanggal Berlaku Hingga: ";
        cin >> tgl;
        cout << "Masukkan Bulan Berlaku Hingga: ";
        cin >> bln;
        cout << "Masukkan Tahun Berlaku Hingga: ";
        cin >> thn;
        cin.ignore();

        system("cls");

        cout << "----------KARTU TANDA KEWARGANEGARAAN----------" << endl;
        cout << left << setw(25) << "NIK" << ": " << nik << endl;
        cout << left << setw(25) << "Nama" << ": " << nama << endl;
        cout << left << setw(25) << "Tempat/Tgl Lahir" << ": " << tempat << ", " << tanggal << "-" << bulan << "-" << tahun << endl;
        cout << left << setw(25) << "Jenis Kelamin" << ": " << jenisKelamin << endl;
        cout << left << setw(25) << "Gol. Darah" << ": " << golD << endl;
        cout << left << setw(25) << "Alamat" << ": " << alamat << endl;
        cout << left << setw(25) << "RT/RW" << ": " << rt << "/" << rw << endl;
        cout << left << setw(25) << "Kel/Desa" << ": " << desa << endl;
        cout << left << setw(25) << "Kecamatan" << ": " << kec << endl;
        cout << left << setw(25) << "Agama" << ": " << agama << endl;
        cout << left << setw(25) << "Status Perkawinan" << ": " << sKawin << endl;
        cout << left << setw(25) << "Pekerjaan" << ": " << pkr << endl;
        cout << left << setw(25) << "Kewarganegaraan" << ": " << kwn << endl;
        cout << left << setw(25) << "Berlaku Hingga" << ": " << tgl << "-" << bln << "-" << thn << endl;

        cout << "\nApakah Anda ingin mengisi data lagi? (Y/N): ";
        cin >> ulang;
        cin.ignore();
        cout << endl;

    } while (ulang == 'Y' || ulang == 'y');

    cout << "Terima kasih :)" << endl;
    return 0;
}

