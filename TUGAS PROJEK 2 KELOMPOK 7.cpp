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

        cout<<"----------KARTU TANDA KEWARGANEGARAAN----------"<<endl;
		cout<<"NIK \t\t\t: "<<nik<<endl;
		cout<<"Nama \t\t\t: "<<nama<<endl;
		cout<<"Tempat/Tgl Lahir \t: "<<tempat<<", "<<tanggal<<"-"<<bulan<<"-"<<tahun<<endl;
		cout<<"Jenis Kelamin \t\t: "<<jenisKelamin<<endl;
		cout<<"Gol. Darah \t\t: "<<golD<<endl;
		cout<<"Alamat \t\t\t: "<<alamat<<endl;
		cout<<"RT/RW \t\t\t: "<<rt<<"/"<<rw<<endl;
		cout<<"Kel/Desa \t\t: "<<desa<<endl;
		cout<<"Kecamatan \t\t: "<<kec<<endl;
		cout<<"Agama \t\t\t: "<<agama<<endl;
		cout<<"Status Perkawinan \t: "<<sKawin<<endl;
		cout<<"Pekerjaan \t\t: "<<pkr<<endl;
		cout<<"Kewarganegaraan \t: "<<kwn<<endl;
		cout<<"Berlaku Hingga \t\t: "<<tgl<<"-"<<bln<<"-"<<thn<<endl;
        cout << "\nApakah Anda ingin mengisi data lagi? (Y/N): ";
        cin >> ulang;
        cin.ignore();
        cout << endl;

    } while (ulang == 'Y' || ulang == 'y');
    cout << "Terima kasih :)" << endl;
    return 0;
}

