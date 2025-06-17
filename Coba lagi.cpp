#include<iostream>
using namespace std;

int main(){
  string matkul[3] = {"Matematika", "Bahasa Indonesia", "Ipa"};
  string nama[4];
  double nilai[4][3];

  for(int i=0; i<4; i++){
    cout << "Masukkan nama siswa ke-" << i+1 << ": ";
    cin >> nama[i];
    for(int j=0; j<3; j++){
      cout << "    Nilai " << matkul[j] << ": ";
      cin >> nilai[i][j];
    }
  }

cout << "=== TABEL NILAI SISWA ===" << endl;
  cout << "Nama\tMatematika\tBahasa Indonesia\tIpa\tRata-rata siswa" << endl;
  for(int i=0; i<4; i++){
    cout << nama[i] << "\t" << nilai[i][0] << "\t\t" << nilai[i][1] << "\t\t\t" << nilai[i][2] << "\t\t" << (nilai[i][0] +
      nilai[i][1] + nilai[i][2]) / 3.0 <<endl;
  }
  cout << "=====================================================" << endl;
  cout << endl;
  
  cout<<"Rata-rata tiap mata pelajaran: "<<endl;
  for(int j=0; j<3; j++){
    cout << matkul[j] << ": " << (nilai[0][j] + nilai[1][j] + nilai[2][j] + nilai[3][j]) / 4.0 << endl;
	}
  return 0;
}

