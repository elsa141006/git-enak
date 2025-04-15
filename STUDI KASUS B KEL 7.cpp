#include<iostream>
using namespace std;
int main(){
	int pilMakan, jumlah,total_goreng = 0,total_bakar = 0, hargaMakan_goreng, hargaMakan_bakar;
	char lanjut;
	do{
	cout << "----------Menu Makanan----------" << endl;
	cout << "1.Ayam Goreng\tRp17.000" << endl;
	cout << "2.Ayam Bakar\tRp21.000" << endl;
	cout << "Masukkan Pilihan anda: ";
	cin >> pilMakan;
	cout << "Masukkan jumlah yang Anda ingin pesan: ";
	cin >> jumlah;
	cout << endl;
	switch (pilMakan){
		case 1:
			hargaMakan_goreng = 17000;
			total_goreng += jumlah*hargaMakan_goreng;
			cout << "Anda memilih menu ayam goreng seharga Rp. " << hargaMakan_goreng << endl;
			break;
		case 2:
			hargaMakan_bakar = 21000;
			total_bakar += jumlah*hargaMakan_bakar;
			cout << "Anda memilih menu ayam bakar seharga Rp. "<< hargaMakan_bakar << endl;
			break;
		default:
			cout << "Pilihan yang anda pilih tidak ada di menu!";
	}
	cout << "Apakah Anda ingin memesan lagi (Y/N) : ";
	cin >> lanjut;
}while (lanjut == 'Y'||lanjut == 'y');

int total_harga = total_goreng + total_bakar;
double diskon = (total_harga>45000)?0.1*total_harga:0;
double total_bayar = total_harga-diskon;

system ("cls");

cout << "----------Struk Pembayaran----------"<<endl;
if (total_goreng>0){
	cout << "Ayam Goreng = Rp. " << total_goreng << endl;
} if (total_bakar>0) {
	cout << "Ayam Bakar  = Rp. " << total_bakar << endl;
}
cout << "Total Harga = Rp. " << total_harga << endl;
cout << "Diskon      = Rp. " << diskon << endl;
cout << "Total Bayar = Rp. " << total_bayar << endl;
	return 0;
}
