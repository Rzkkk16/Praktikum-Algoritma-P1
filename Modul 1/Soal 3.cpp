#include <iostream>
using namespace std;

struct Soal3 
{
    char huruf, kata[20];
    int angka;
};

main () {
    Soal3 data[1];

    int i = 0;
    {
        // Input data
        cout << "\n\n----------------------------------\n";
        cout << "\nMasukkan Sebuah Huruf        = "; cin >> data[i].huruf;
        cout << "Masukkan Sebuah angka          = "; cin >> data[i].angka;
        cout << "Masukkan Sebuah Kata           = "; cin >> data[i].kata;

        // Output data
        cout << "\nHuruf Yang Anda Masukkan Adalah    = " << data[i].huruf;
        cout << "\nAngka Yang Anda Masukkan Adalah    = " << data[i].angka;
        cout << "\nKata Yang Anda Masukkan Adalah     = " << data[i].kata;
        cout << endl << endl;
    }
}