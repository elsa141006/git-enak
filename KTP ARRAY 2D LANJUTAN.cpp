#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int TOTAL_WILAYAH = 20;
string wilayah[TOTAL_WILAYAH][2] = {
    {"Pleret", "Pleret"}, {"Wonokromo", "Pleret"}, {"Timbulharjo", "Sewon"},
    {"Panjangrejo", "Pundong"}, {"Bangunjiwo", "Kasihan"}, {"Ngestiharjo", "Kasihan"},
    {"Gilangharjo", "Pandak"}, {"Wijirejo", "Pandak"}, {"Sumbermulyo", "Bambanglipuro"},
    {"Sidomulyo", "Bambanglipuro"}, {"Srihardono", "Pundong"}, {"Murtigading", "Sanden"},
    {"Trimurti", "Srandakan"}, {"Poncosari", "Srandakan"}, {"Guwosari", "Pajangan"},
    {"Sendangsari", "Pajangan"}, {"Seloharjo", "Pundong"}, {"Sriharjo", "Imogiri"},
    {"Karangtalun", "Imogiri"}, {"Wukirsari", "Imogiri"}
};

class KTP {
public:
    char nik[20];
    string nama;
    string tempatLahir;
    string tanggalLahir;
    string jenisKelamin;
    string golDarah;
    string alamat;
    string rtRw;
    string kelurahan;
    string kecamatan;
    string agama;
    string status;
    string pekerjaan;
    string kewarganegaraan;
    string berlakuSampai;
};

class PengurutKTP {
public:
    static void urutNama(KTP data[], int jumlah, bool naik = true) {
        for (int i = 0; i < jumlah - 1; ++i) {
            for (int j = 0; j < jumlah - i - 1; ++j) {
                bool kondisi = naik ? (data[j].nama > data[j + 1].nama)
                                    : (data[j].nama < data[j + 1].nama);
                if (kondisi) swap(data[j], data[j + 1]);
            }
        }
    }

    static void urutTanggal(KTP data[], int jumlah, bool naik = true) {
        for (int i = 0; i < jumlah - 1; ++i) {
            for (int j = 0; j < jumlah - i - 1; ++j) {
                bool kondisi = naik ? (data[j].tanggalLahir > data[j + 1].tanggalLahir)
                                    : (data[j].tanggalLahir < data[j + 1].tanggalLahir);
                if (kondisi) swap(data[j], data[j + 1]);
            }
        }
    }

    static void urutNIK(KTP data[], int jumlah, bool naik = true) {
        for (int i = 0; i < jumlah - 1; ++i) {
            for (int j = 0; j < jumlah - i - 1; ++j) {
                bool kondisi = naik ? (string(data[j].nik) > string(data[j + 1].nik))
                                    : (string(data[j].nik) < string(data[j + 1].nik));
                if (kondisi) swap(data[j], data[j + 1]);
            }
        }
    }
};

string formatTanggal(string input) {
    stringstream ss(input);
    string hari, bulan, tahun;
    ss >> hari >> bulan >> tahun;

    string angkaBulan;
    if (bulan == "Januari" || bulan == "januari" || bulan == "JANUARI") angkaBulan = "01";
    else if (bulan == "Februari" || bulan == "februari" || bulan == "FEBRUARI") angkaBulan = "02";
    else if (bulan == "Maret" || bulan == "maret" || bulan == "MARET") angkaBulan = "03";
    else if (bulan == "April" || bulan == "april" || bulan == "APRIL") angkaBulan = "04";
    else if (bulan == "Mei" || bulan == "mei" || bulan == "MEI") angkaBulan = "05";
    else if (bulan == "Juni" || bulan == "juni" || bulan == "JUNI") angkaBulan = "06";
    else if (bulan == "Juli" || bulan == "juli" || bulan == "JULI") angkaBulan = "07";
    else if (bulan == "Agustus" || bulan == "agustus" || bulan == "AGUSTUS") angkaBulan = "08";
    else if (bulan == "September" || bulan == "september" || bulan == "SEPTEMBER") angkaBulan = "09";
    else if (bulan == "Oktober" || bulan == "oktober" || bulan == "OKTOBER") angkaBulan = "10";
    else if (bulan == "November" || bulan == "november" || bulan == "NOVEMBER") angkaBulan = "11";
    else if (bulan == "Desember" || bulan == "desember" || bulan == "DESEMBER") angkaBulan = "12";
    else angkaBulan = "00"; 

    if (hari.length() == 1) hari = "0" + hari;
    return hari + "-" + angkaBulan + "-" + tahun;
}

bool pilihNaikTurun() {
    int pilih;
    cout << "Pilih urutan:\n1. Naik\n2. Turun\nPilihan: ";
    cin >> pilih;
    return pilih == 1;
}

void pilihKelamin(string &kelamin) {
    int pilih;
    cout << "Pilih jenis kelamin:\n1. Laki-laki\n2. Perempuan\nPilihan: ";
    cin >> pilih;
    kelamin = (pilih == 1) ? "Laki-laki" : "Perempuan";
    cin.ignore();
}

void pilihAgama(string &agama) {
    int pilih;
    cout << "Pilih agama:\n1. Islam\n2. Kristen\n3. Katolik\n4. Hindu\n5. Buddha\n6. Konghucu\nPilihan: ";
    cin >> pilih;
    switch (pilih) {
        case 1: agama = "Islam"; break;
        case 2: agama = "Kristen"; break;
        case 3: agama = "Katolik"; break;
        case 4: agama = "Hindu"; break;
        case 5: agama = "Buddha"; break;
        case 6: agama = "Konghucu"; break;
        default: agama = "Tidak Diketahui"; break;
    }
    cin.ignore();
}

void inputData(KTP &data) {
    cout << "Masukkan NIK: "; cin >> data.nik; cin.ignore();
    cout << "Masukkan Nama: "; getline(cin, data.nama);
    cout << "Tempat Lahir: "; getline(cin, data.tempatLahir);

    string tanggal;
    cout << "Tanggal Lahir (contoh: 7 Juli 2000): ";
    getline(cin, tanggal);
    data.tanggalLahir = formatTanggal(tanggal);

    pilihKelamin(data.jenisKelamin);
    cout << "Golongan Darah: "; cin >> data.golDarah; cin.ignore();
    cout << "Alamat: "; getline(cin, data.alamat);
    cout << "RT/RW: "; getline(cin, data.rtRw);

    cout << "Pilih wilayah:\n";
    for (int i = 0; i < TOTAL_WILAYAH; ++i) {
        cout << i + 1 << ". " << wilayah[i][0] << " / " << wilayah[i][1] << endl;
    }
    int pilihWilayah;
    cout << "Pilihan Anda: "; cin >> pilihWilayah; cin.ignore();
    if (pilihWilayah >= 1 && pilihWilayah <= TOTAL_WILAYAH) {
        data.kelurahan = wilayah[pilihWilayah - 1][0];
        data.kecamatan = wilayah[pilihWilayah - 1][1];
    } else {
        data.kelurahan = "Tidak Diketahui";
        data.kecamatan = "Tidak Diketahui";
    }

    pilihAgama(data.agama);
    cout << "Status Perkawinan: "; getline(cin, data.status);
    cout << "Pekerjaan: "; getline(cin, data.pekerjaan);
    cout << "Kewarganegaraan: "; getline(cin, data.kewarganegaraan);
    cout << "Berlaku Hingga: "; getline(cin, data.berlakuSampai);
}

void tampilkan(const KTP &data) {
    cout << "\n========== DATA KTP ==========\n";
    cout << "NIK                 : " << data.nik << endl;
    cout << "Nama                : " << data.nama << endl;
    cout << "Tempat/Tgl Lahir    : " << data.tempatLahir << ", " << data.tanggalLahir << endl;
    cout << "Jenis Kelamin       : " << data.jenisKelamin << "   Gol Darah: " << data.golDarah << endl;
    cout << "Alamat              : " << data.alamat << endl;
    cout << "RT/RW               : " << data.rtRw << endl;
    cout << "Kelurahan/Desa      : " << data.kelurahan << endl;
    cout << "Kecamatan           : " << data.kecamatan << endl;
    cout << "Agama               : " << data.agama << endl;
    cout << "Status Perkawinan   : " << data.status << endl;
    cout << "Pekerjaan           : " << data.pekerjaan << endl;
    cout << "Kewarganegaraan     : " << data.kewarganegaraan << endl;
    cout << "Berlaku Hingga      : " << data.berlakuSampai << endl;
    cout << "==============================\n";
}

void cariNIK(KTP data[], int jumlah) {
    char cari[20];
    cout << "Masukkan NIK: ";
    cin >> cari;
    for (int i = 0; i < jumlah; i++) {
        if (string(data[i].nik) == string(cari)) {
            tampilkan(data[i]);
            return;
        }
    }
    cout << "Data tidak ditemukan.\n";
}

void cariNama(KTP data[], int jumlah) {
    string nama;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, nama);
    bool ditemukan = false;
    for (int i = 0; i < jumlah; i++) {
        if (data[i].nama.find(nama) != string::npos) {
            tampilkan(data[i]);
            ditemukan = true;
        }
    }
    if (!ditemukan) cout << "Data tidak ditemukan.\n";
}

int main() {
    int jumlah;
    cout << "Berapa banyak data yang ingin Anda masukkan? ";
    cin >> jumlah; cin.ignore();

    KTP penduduk[100];

    for (int i = 0; i < jumlah; i++) {
        cout << "\nInput data ke-" << i + 1 << ":\n";
        inputData(penduduk[i]);
    }

    int menu;
    do {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Tampilkan Semua Data\n";
        cout << "2. Cari Berdasarkan NIK\n";
        cout << "3. Cari Berdasarkan Nama\n";
        cout << "4. Urutkan Berdasarkan Nama\n";
        cout << "5. Urutkan Berdasarkan Tanggal Lahir\n";
        cout << "6. Urutkan Berdasarkan NIK\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu) {
            case 1:
                for (int i = 0; i < jumlah; i++) tampilkan(penduduk[i]);
                break;
            case 2:
                cariNIK(penduduk, jumlah);
                break;
            case 3:
                cariNama(penduduk, jumlah);
                break;
            case 4: {
                bool urutan = pilihNaikTurun();
                PengurutKTP::urutNama(penduduk, jumlah, urutan);
                cout << "Data diurutkan berdasarkan nama.\n";
                break;
            }
            case 5: {
                bool urutan = pilihNaikTurun();
                PengurutKTP::urutTanggal(penduduk, jumlah, urutan);
                cout << "Data diurutkan berdasarkan tanggal lahir.\n";
                break;
            }
            case 6: {
                bool urutan = pilihNaikTurun();
                PengurutKTP::urutNIK(penduduk, jumlah, urutan);
                cout << "Data diurutkan berdasarkan NIK.\n";
                break;
            }
            case 0:
                cout << "Program selesai.\n"; break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (menu != 0);

    return 0;
}

