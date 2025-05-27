#include<iostream>
#include<vector>
using namespace std;

class barang{
	public:
		string nama;
		int jumlah;
		double harga;
		
		barang(string n, int j, double h){
			nama=n;
			jumlah=j;
			harga=h;
		}
		double totalHarga(){
			return jumlah*harga;
		}
		void tampilkan(){
			cout<<nama<<"\t"<<jumlah<<"\t"<<harga<<"\tRp "<<totalHarga()<<endl;
		}
};

class kasir{
	private:
		vector<barang> daftarBelanja;
	public:
		void tambahBarang(string nama, int jumlah, double harga){
			barang b(nama, jumlah, harga);
			daftarBelanja.push_back(b);
		}
		
		void tampilNota(){
			double total = 0;
			cout<<"\n=== NOTA BELANJAAN ==="<<endl;
			cout<<"Nma \tQty\tHarga\tTotal"<<endl;
			for(int i=0;i<daftarBelanja.size();i++){
				barang b = daftarBelanja[i];
				b.tampilkan();
				total += b.totalHarga();
			}
			cout<<"----------------------------------"<<endl;
			cout<<"subtotal: Rp "<<total<<endl;
			
			double diskon=0;
			if(total>=100000){
				diskon=0.10*total;
				cout<<"Disakon 10%: Rp "<<diskon<<endl;
			} else {
				cout<<"Diskon: Rp 0 (Belanja < 100000)"<<endl;
				
			double totalBayar=total-diskon;
			cout<<"Total Bayar: "<<totalBayar<<endl;
			
			double uang;cout<<"Uang Dibayar: Rp ";
			cin>>uang;
			
			if(uang<totalBayar){
				cout<<"Uang tidak cukup!" << endl;
			} else {
				double kembalian=uang-totalBayar;
				cout<<"Kembalian: Rp "<<kembalian<<endl;
			}
		}	
	}
};

int main(){
	kasir kasir;
	int jumlahBarang;
	
	cout<<"Berapa jenis barang yang ingin dibeli? ";
	cin>>jumlahBarang;
	
	for(int i=0;i<jumlahBarang;i++){
		string nama;
		int qty;
		double harga;
		
		cout<<"\nBarang ke-"<<i+1<<endl;
		cout<<"Nama barang: ";
		cin>>ws;
		getline(cin,nama);
		cout<<"Jumlah: ";
		cin>>qty;
		cout<<"Harga per item: ";
		cin>>harga;
		
		kasir.tambahBarang(nama, qty, harga); 
	}
	kasir.tampilNota();
	return 0;
}
