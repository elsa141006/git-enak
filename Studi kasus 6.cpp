#include<iostream>
using namespace std;

class nilai{
  public:
    int data[30];

void masuk(){
  cout<<"Masukkan Nilai \n";
  for(int i=0; i<30; i++){
    cout<<"Data ke-"<<i+1<<": ";
    cin>>data[i];
  }
  cout<<endl;
}

float rata(){
  int total=0;
  for(int i =0; i<30; i++){
    total += data[i];
  }
  return static_cast<float>(total)/30;
}

int tinggi(){
  int max = data[0];
  for(int i = 0; i < 30; i++){
    if(data[i] > max){
      max = data[i];
    }
  }
  return max;
}

int rendah(){
  int min = data[0];
  for(int i = 0; i < 30; i++){
    if(data[i] < min){
      min = data[i];
    }
  }
  return min;
}

};

int main(){
  nilai n;
  int pilih;
  n.masuk(); 
  
  do{
    cout << "=====DAFTAR NILAI=====" << endl;
    cout << "1. Nilai Rata-rata" << endl;
    cout << "2. Nilai Tertinggi" << endl;
    cout << "3. Nilai Terendah" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih Daftar: ";
    cin >> pilih;
    switch(pilih){
      case 1:
        cout << "Nilai Rata-rata: " <<n.rata() << endl;
        break;
      case 2:
        cout << "Nilai Tertinggi: " <<n.tinggi() << endl;
        break;
      case 3:
        cout << "Nilai Terendah: " <<n.rendah() << endl;
        break;
      case 4:
        cout << "Terima Kasih" << endl;
        break;
    }
	}while(pilih != 4);
}
  
