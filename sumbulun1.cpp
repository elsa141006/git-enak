#include <iostream>
using namespace std;

class ArraySorter {
private:
    int array2D[3][3];
    int array1D[9];

public:
    // Input array 2D
    void input() {
        cout << "Masukkan elemen array 3x3:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << "Elemen [" << i << "][" << j << "]: ";
                cin >> array2D[i][j];
            }
        }
    }

    // Konversi 2D ke 1D
    void convertTo1D() {
        int k = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                array1D[k] = array2D[i][j];
                k++;
            }
        }
    }

    // Bubble sort
    void bubbleSort() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8 - i; j++) {
                if (array1D[j] > array1D[j + 1]) {
                    int temp = array1D[j];
                    array1D[j] = array1D[j + 1];
                    array1D[j + 1] = temp;
                }
            }
        }
    }

    // Konversi 1D ke 2D
    void convertTo2D() {
        int k = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                array2D[i][j] = array1D[k];
                k++;
            }
        }
    }

    // Tampilkan array 2D
    void display(const string &pesan) {
        cout << "\n" << pesan << "\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << array2D[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Jalankan proses lengkap
    void process() {
        input();
        display("Array sebelum diurutkan:");
        convertTo1D();
        bubbleSort();
        convertTo2D();
        display("Array setelah diurutkan:");
    }
};

int main() {
    ArraySorter sorter;
    sorter.process();

    return 0;
}

