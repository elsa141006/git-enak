#include<iostream>
using namespace std;
int main(){
	long long int nik;
	string nama, tempat,alamat, desa,kec,agama,sKawin,pkr,kwn,golD;
	int tanggal,bulan,tahun,rt,rw,tgl,bln,thn;
	char jenisKelamin;
	
	cout<<"Masukkan NIK: ";
	cin>>nik;
	cout<<"Masukkan Nama: ";
	cin>>nama;
	cout<<"Masukkan Tempat: ";
	cin>>tempat;
	cout<<"Masukkan Tanggal Lahir: ";
	cin>>tanggal;
	cout<<"Masukkan Bulan Lahir: ";
	cin>>bulan;
	cout<<"Masukkan Tahun Lahir: ";
	cin>>tahun;
	cout<<"Masukkan Jenis Kelamin: ";
	cin>>jenisKelamin;
	cout<<"Masukkan Gol. Darah: ";
	cin>>golD;
	cout<<"Masukkan Alamat: ";
	cin>>alamat;
	cout<<"Masukkan RT: ";
	cin>>rt;
	cout<<"Masukkan RW: ";
	cin>>rw;
	cout<<"Masukkan Kel/Desa: ";
	cin>>desa;
	cout<<"Masukkan Kecamatan: ";
	cin>>kec;
	cout<<"Masukkan Agama: ";
	cin>>agama;
	cout<<"Masukkan Status Perkawinan: ";
	cin>>sKawin;
	cout<<"Masukkan Pekerjaan: ";
	cin>>pkr;
	cout<<"Masukkan Kewarganegaraan: ";
	cin>>kwn;
	cout<<"Masukkan Tanggal Berlaku Hingga: ";
	cin>>tgl;
	cout<<"Masukkan Bulan Berlaku Hingga: ";
	cin>>bln;
	cout<<"Masukkan Tahun Berlaku Hingga: ";
	cin>>thn;
	
	system("CLS");
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
	
	return 0;
}
