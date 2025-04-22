#include<iostream>
using namespace std;
int main(){
	int pilMakan, jumlah,total_agep = 0,total_agor = 0,total_ugor = 0,total_cugor = 0,total_abar=0, agep, agor, ugor,cugor,abar,alamat,kurang,lebih,ongkir;
	char lanjut;
	do{
	cout<<"----------Menu Makanan----------"<<endl;
		cout<<"1. Ayam geprek : 21000"<<endl;
		cout<<"2. Ayam goreng : 17000"<<endl;
		cout<<"3. Udang goreng : 19000"<<endl;
		cout<<"4. Cumi goreng : 20000"<<endl;
		cout<<"5. Ayam bakar : 25000"<<endl;
		cout<<"Masukkan pilihan Anda(1-5): ";
		cin>>pilMakan;
		cout << "Masukkan jumlah yang Anda ingin pesan: ";
		cin >> jumlah;
	cout << endl;
	switch (pilMakan){
		case 1:
			agep = 21000;
			total_agep += jumlah*agep;
			cout << "Anda memilih menu ayam geprek seharga Rp. " << agep << endl;
			break;
		case 2:
			agor = 17000;
			total_agor += jumlah*agor;
			cout << "Anda memilih menu ayam goreng seharga Rp. "<< agor << endl;
			break;
		case 3:
			ugor = 19000;
			total_ugor += jumlah*ugor;
			cout << "Anda memilih menu udang goreng seharga Rp. " << ugor << endl;
			break;
		case 4:
			cugor = 20000;
			total_cugor += jumlah*cugor;
			cout << "Anda memilih menu cumi goreng seharga Rp. "<< cugor << endl;
			break;
		case 5:
			abar = 25000;
			total_abar += jumlah*abar;
			cout << "Anda memilih menu ayam bakar seharga Rp. "<< abar << endl;
			break;
		default:
			cout << "Pilihan yang anda pilih tidak ada di menu!";
	}
	cout << "Apakah Anda ingin memesan lagi (Y/N) : ";
	cin >> lanjut;
}while (lanjut == 'Y'||lanjut == 'y');

cout<<"Jarak dari rumah ke rumah makan"<<endl;
cout<<"1. Kurang dari atau sama dengan 3 Km"<<endl;
cout<<"2. Lebih dari 3 Km"<<endl;
cout<<"Seberapa jauh jarak rumah Anda ke rumah makan?(1-2)"<<endl;
cin>>alamat;
if(alamat==1){
	ongkir=15000;
}else if(alamat==2){
	ongkir=25000;
}
int total_harga = total_agep + total_agor + total_ugor + total_cugor + total_abar;
int total_bayar = total_harga + ongkir;
system ("cls");

cout << "----------Struk Pembayaran----------"<<endl;
if (total_agep>0){
	cout << "Ayam Geprek = Rp. " << total_agep << endl;
} if (total_agor>0) {
	cout << "Ayam Goreng  = Rp. " << total_agor << endl;
} if (total_ugor>0){
	cout << "Udang Goreng = Rp. " << total_ugor << endl;
} if (total_cugor>0) {
	cout << "Cumi Goreng  = Rp. " << total_cugor << endl;
} if (total_abar>0) {
	cout << "Ayam Bakar  = Rp. " << total_abar << endl;
}
cout << "Total Harga = Rp. " << total_harga << endl;
cout << "Ongkir      = Rp. " << alamat << endl;
cout << "Total Bayar = Rp. " << total_bayar << endl;
	return 0;
}
