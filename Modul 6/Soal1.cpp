#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int random(int bil)
{
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize()
{
    srand(time(NULL));
}

void clrscr()
{
    system("cls");
}

void sequentialSearching()
{
    clrscr();

    int data[100];
    int cari = 20; 
    int counter = 0, flag = 0, save;

    randomize();

    cout << "Generating 100 number . . .\n";

    for (int i = 0; i < 100; i++)
    {
        data[i] = random(100) + 1;
        cout << data[i] << " ";
    }

    cout << "\nDone.\n";

    for (int i = 0; i < 100; i++)
    {
        if (data[i] == cari)
        {
            counter++;
            flag = 1;
            save = i;
        }
    }

    cout << endl;

    if (flag == 1)
    {
        cout << "Data ada, sebanyak " << counter << endl;
        cout << "Pada indeks ke-" << save << endl;
    }
    else
    {
        cout << "Data tidak ada\n";
    }

    system("pause");
}

void binarySearching()
{
    clrscr();

    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukan jumlah data? ";
    cin >> n;

    int angka[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Angka ke - [" << i << "] : ";
        cin >> angka[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (angka[j] > angka[j + 1])
            {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }

    cout << "=========================================================\n";
    cout << "Data yang telah diurutkan adalah:\n";

    for (int i = 0; i < n; i++)
    {
        cout << angka[i] << " ";
    }

    cout << "\n=========================================================\n";

    cout << "Masukan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;

    while (kiri <= kanan)
    {
        tengah = (kiri + kanan) / 2;

        if (key == angka[tengah])
        {
            ketemu = true;
            break;
        }
        else if (key < angka[tengah])
        {
            kanan = tengah - 1;
        }
        else
        {
            kiri = tengah + 1;
        }
    }

    if (ketemu == true)
    {
        cout << "Angka ditemukan!\n";
    }
    else
    {
        cout << "Angka tidak ditemukan!\n";
    }

    system("pause");
}

void perbedaan()
{
    clrscr();

    cout << "Perbedaan Sequential Searching dan Binary Searching\n\n";

    cout << "1. Sequential Searching\n";
    cout << "- Pencarian dilakukan satu per satu dari awal.\n";
    cout << "- Tidak perlu data terurut.\n";
    cout << "- Lebih lambat untuk data besar.\n\n";

    cout << "2. Binary Searching\n";
    cout << "- Pencarian dilakukan dengan membagi data menjadi dua bagian.\n";
    cout << "- Data harus terurut.\n";
    cout << "- Lebih cepat untuk data besar.\n";

    cout << endl;

    system("pause");
}

int main()
{
    int pilih;

    do
    {
        clrscr();

        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            sequentialSearching();
            break;

        case 2:
            binarySearching();
            break;

        case 3:
            perbedaan();
            break;

        case 4:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Menu tidak tersedia!\n";
            system("pause");
        }

    } while (pilih != 4);

    return 0;
}