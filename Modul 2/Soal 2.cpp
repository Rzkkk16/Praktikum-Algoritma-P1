#include <iostream>
using namespace std;

#define max 5 

struct Stack {
    int data[max];
    int atas;
};

Stack Tumpuk;

// cek kosong
int kosong()
{
    if (Tumpuk.atas == -1)
        return 1;
    else
        return 0;
}

// cek penuh
int penuh()
{
    if (Tumpuk.atas == max - 1)
        return 1;
    else
        return 0;
}

// push
void input(int data)
{
    if (penuh() == 0)
    {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << data 
        << " masuk ke Stack\n";
    }
    else
    {
        cout << "Tumpukan sudah penuh\n";
    }
}

// pop
void hapus()
{
    if (kosong() == 0)
    {
        cout << "Data Teratas Sudah Terambil\n";
        Tumpuk.atas--;
    }
    else
    {
        cout << "Tumpukan kosong\n";
    }
}

// tampil
void tampil()
{
    if (kosong() == 0)
    {
        for (int i = Tumpuk.atas; i >= 0; i--)
        {
            cout << "Tumpukan ke " << i << " = " << Tumpuk.data[i] << endl;
        }
    }
    else
    {
        cout << "Tumpukan kosong\n";
    }
}

// clear
void bersih()
{
    Tumpuk.atas = -1;
    cout << "Tumpukan kosong\n";
}

int main()
{
    int data;
    int pilihan;

    Tumpuk.atas = -1;

    do
    {
        cout << "\nMenu Stack\n";
        cout << "1. Input Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Tampil Data\n";
        cout << "4. Bersihkan Stack\n";
        cout << "5. Keluar\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan Data: ";
            cin >> data;
            input(data);
            break;
        case 2:
            hapus();
            break;
        case 3:
            tampil();
            break;
        case 4:
            bersih();
            break;
        case 5:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}