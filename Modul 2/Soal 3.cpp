#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define n 10
using namespace std;

int PIL, F, R;
char PILIHAN[1], HURUF;
char Q[n];

int full () {
    if (R == n - 1)
        return 1;
    else
        return 0;
}

int empty () {
    if (F == -1 || F > R)
        return 1;
    else
        return 0;
}

void INSERT() {
    if (full() == 0) {
        cout << "Masukkan Data : ";
        cin >> HURUF;
        if (F == -1)
            F = 0;
        R++;
        Q[R] = HURUF;
    } else {
        cout << "QUEUE PENUH" << endl;
    }
}
void DELETE() {
    if (empty() == 0) {
        cout << "Data yang dihapus : " << Q[F] << endl;
        F++;
    } else {
        cout << "QUEUE KOSONG" << endl;
    }
}

void CETAKLAYAR() {
    if (empty() == 0) {
        cout << "Isi QUEUE : ";
        for (int i = F; i <= R; i++) {
            cout << Q[i] << " ";
        }
        cout << endl;
    } else {
        cout << "QUEUE KOSONG" << endl;
    }
}

void Inisialisasi() {
    F = R = -1;
}
void RESET() {
    F = R = -1;
    cout << "QUEUE KOSONG" << endl;
}


int main()
{
    Inisialisasi();
    do
    {
        cout << "QUEUE" << endl;
        cout << "================" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. RESET" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN : ";
        cin >> PILIHAN;

        PIL = atoi(PILIHAN);

        switch (PIL)
        {
        case 1:
            INSERT();
            break;
        case 2:
            DELETE();
            break;
        case 3:
            CETAKLAYAR();
            break;
        case 4:
            RESET();
            break;
        default:
            cout << "TERIMA KASIH" << endl;
            break;
        }

        cout << "press any key to continue" << endl;
        getch();
        system("cls");

    } while (PIL != 5);
}