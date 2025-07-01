#include <iostream>
using namespace std;

void tambah(int* x, int* y, int* hasil){
    *hasil = *x + *y;
}

void kurang(int* x, int* y, int* hasil){
    *hasil = *x - *y;
}

void kali(int* x, int* y, int* hasil){
    *hasil = (*x) * (*y);
}

void bagi(int* x, int* y, int* hasil){
    if(*y != 0)
        *hasil = (*x) / (*y);
    else {
        cout << "Error: Pembagian dengan nol!" << endl;
        *hasil = 0;
    }
}

int faktorial(int n) {
    if(n <= 1) return 1;
    return n * faktorial(n - 1);
}

bool isPrima(int n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    int A;
    int B;
    int hasil;

    cout << "Masukkan Angka Pertama: ";
    cin >> A;
    cout << "Masukkan Angka Kedua: ";
    cin >> B;

    tambah(&A, &B, &hasil);
    cout << A << " + " << B << " = " << hasil << endl;

    kurang(&A, &B, &hasil);
    cout << A << " - " << B << " = " << hasil << endl;

    kali(&A, &B, &hasil);
    cout << A << " * " << B << " = " << hasil << endl;

    bagi(&A, &B, &hasil);
    cout << A << " / " << B << " = " << hasil << endl;

    cout << "Faktorial dari " << A << " adalah " << faktorial(A) << endl;
    cout << "Faktorial dari " << B << " adalah " << faktorial(B) << endl;

    if(isPrima(A))
        cout << A << " adalah bilangan prima" << endl;
    else
        cout << A << " bukan bilangan prima" << endl;

    if(isPrima(B))
        cout << B << " adalah bilangan prima" << endl;
    else
        cout << B << " bukan bilangan prima" << endl;

    return 0;
}
