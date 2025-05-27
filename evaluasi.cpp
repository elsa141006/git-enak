#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class mahasiswa{
	public:
		string username;
		string nim;
		string nama;
		string prodi;
		string fakultas;
		
		mahasiswa(string u, string n, string nama, string p, string f){
			username=u;
			nim=n;
			nama=nama;
			prodi=p;
			fakultas=f;
		}
		
		bool login(string inputusername, string inputnim){
			return username==inputusername && nim==inputnim;
		}
		
		void tampilkanprofile(){
			cout<<"Nama: "<<nama<<endl;
			cout<<"NIM: "<<nim<<endl;
			cout<<"Prodi: "<<prodi<<endl;
			cout<<"Fakultas: "<<fakultas<<endl;
		}
};

class krs{
	private:
		vector<string> daftarmatkul;
		
	public:
		void tambahmatkul(string matkul){
			daftarmatkul.push_back(matkul);
			cout<<matkul<<"berhasil ditambahkan ke KRS"<<endl;
		}
		
		void hapusmatkul(string matkul){
			for(int i=0; i<daftarmatkul.size(); i++){
				if(daftarmatkul[i]==matkul){
					daftarmatkul.erase(daftarmatkul.begin()+i);
					cout<<matkul<<"berhasil dihapusdari KRS"<<endl;
					return;
				}
			}
			cout<<"Matakuliah tidak ditemukan diKRS"<<endl;
		}
		
		void tampilkalkrs(){
			cout<<"Daftar mata kuliah yang diambil: ";
			for(int i=0; i<daftarmatkul.size(); i++){
				cout<<"- "<<daftarmatkul[i]<<endl;
			}
		}
		
		int jumlahmatkul(){
			return daftarmatkul.size();
		}
};

class pembayaran{
	public:
		void pilihanmetode(string metode){
			cout<<"Metode pembayaran yang dipilih: "<<metode<<endl;
		}
		
		void unduhslip(int jumlahmatkul){
			int biayapermatkul=50000;
			int total=jumlahmatkul*biayapermatkul;
			ofstream file("slip_pembayaran.txt");
			file<<"=== SLIP PEMBAYARAN SPP ==="<<endl;
			file<<"Jumlah mata kuliah: "<<jumlahmatkul<<endl;
			file<<"biaya permatkul: "<<biayapermatkul<<endl;
			file<<"total pembayaran: "<<total<<endl;
			file.close();
			cout<<"Slip pembayaran berhasil diunduh"<<endl;
		}
};

int main(){
	mahasiswa mhs("elsa","2400018235","Nabilah Elsa Rahmadani","Informatika","FTI");
	krs krs;
	pembayaran bayar;
	
	string user,pass;
	cout<<"=====Portal Mahasiswa====="<<endl;
	cout<<"Username: ";
	cin>>user;
	cout<<"NIM: ";
	cin>>pass;
	
	if(!mhs.login(user,pass)){
		cout<<"Login gagal.";
		return 0;
	}
	
	int pilihan;
		do{
			cout<<"===MENU UTAMA==="<<endl;
			cout << "1. Lihat Profil\n";
	        cout << "2. Tambah Mata Kuliah (KRS)\n";
	        cout << "3. Hapus Mata Kuliah (KRS)\n";
	        cout << "4. Lihat KRS\n";
	        cout << "5. Pilih Metode Pembayaran\n";
	        cout << "6. Unduh Slip Pembayaran\n";
	        cout << "0. Keluar\n";
	        cout << "Pilihan Anda: ";
	        cin >> pilihan;
	        
	        switch(pilihan){
	        	case 1:
	        		mhs.tampilkanprofile();
	        		break;
	        	case 2:{string matkul;
	        		cout<<"Masukkan nama mata kuliah: ";
	        		cin.ignore();
	        		getline(cin, matkul);
	        		krs.tambahmatkul(matkul);
					break;
				}
				case 3:{
					string matkul;
	        		cout<<"Masukkan nama mata kuliah: ";
	        		cin.ignore();
	        		getline(cin, matkul);
	        		krs.hapusmatkul(matkul);
					break;
				}
				case 4:
					krs.tampilkalkrs();
					break;
				case 5:{
					string metode;
					cout<<"Masukkan metode pembayaran (cash/debit): ";
					cin >>metode;
					bayar.pilihanmetode(metode);
					break;
				}
				case 6:
					bayar.unduhslip(krs.jumlahmatkul());
					break;
				case 0:
					cout << "Terima kasih, keluar dari sistem.\n";
	                break;
	            default:
	                cout << "Pilihan tidak valid!\n";
        	} 
		} while(pilihan != 0);
		
		return 0;
	
}
