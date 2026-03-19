#include <iostream>
using namespace std;

struct BPKB 
{
    char plat[15], nama[20], jenis[10], alamat[30], kota[20];
};

main () {
    BPKB data[1] = {{"LOS S4N T0S", "Carl Jhonson", "BMW", "Groove Street", "Los Santos"}};

    int i = 0;
    {
        // Output data
        cout << "\n\n----------------------------------\n";
        cout << "Output";
        cout << "\n----------------------------------\n";
        cout << "\nPlat nomor      = " << data[i].plat;
        cout << "\nNama pemilik    = " << data[i].nama;
        cout << "\nJenis kendaraan = " << data[i].jenis;
        cout << "\nAlamat          = " << data[i].alamat;
        cout << "\nKota            = " << data[i].kota;
        cout << endl << endl;
    }
}