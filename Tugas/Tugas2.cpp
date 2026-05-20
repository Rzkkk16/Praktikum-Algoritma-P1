#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
char pilihan[1];
string dataBaru;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();
void ClearS();
void hapusTargetH();
void hapusTargetHT();

int main() 
{
    menu :
    cout<<"Double Linked List Non Circular (DLLNC)"<<endl;
    cout<<"======================================="<<endl;
    cout<<"Silahkan Pilih Program DLLNC yang ingin dijalankan!"<<endl;
    cout<<"1. DLLNC dengan Head"<<endl;
    cout<<"2. DLLNC dengan Head dan Tail"<<endl;
    cout<<"3. Quit"<<endl;
    cout<<"Pilihan : ";
    cin>>menu;
    system("cls");
    if(menu==1){
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head)"<<endl;
            cout<<"============================================"<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang"<<endl;
            cout<<"6. Reset"<<endl;
            cout<<"7. HapusTarget"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);

            switch(pil){
            case 1:
                tambahDepanH();
                break;
            case 2:
                tambahBelakangH();
                break;
            case 3:
                tampilkanH();
                break;
            case 4:
                hapusDepanH();
                break;
            case 5:
                hapusBelakangH();
                break;
            case 6:
                clearH();
                break;
            case 7:
                hapusTargetH();
                break;
            default:
                system("cls");
                goto menu;
            }

            cout<<"\npress any key to continue"<<endl;
            getch();
            system("cls");

        } while (pil<7);
    } else if(menu==2){
        do { 
            cout<<"Double Linked List Non Circular (DLLNC) (Head dan Tail)"<<endl;
            cout<<"======================================================"<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang"<<endl;
            cout<<"6. Reset"<<endl;
            cout<<"7. HapusTarget"<<endl;
            cout<<"8. Reset V2.0"<<endl;
            cout<<"9. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);

            switch(pil){
            case 1:
                tambahDepanHT();
                break;
            case 2:
                tambahBelakangHT();
                break;
            case 3:
                tampilkanHT();
                break;
            case 4:
                hapusDepanHT();
                break;
            case 5:
                hapusBelakangHT();
                break;
            case 6:
                clearHT();
                break;
            case 7:
                hapusTargetHT();
                break;
            case 8:
                ClearS();
                break;
            default:
                system("cls");
                goto menu;
            }

            cout<<"\npress any key to continue"<<endl;
            getch();
            system("cls");

        } while (pil<7);
    } else {
        cout<<"\nTERIMA KASIH"<<endl;
        cout<<"Program was made by Abdurrazak (2510817110017)."<<endl;
    }
}

void initH(){
    head = NULL;
}

void initHT(){
    head = NULL;
    tail = NULL;
}

int isEmptyH(){
    if(head==NULL) return 1;
    else return 0;
}

int isEmptyHT(){
    if(tail==NULL) return 1;
    else return 0;
}

void tambahDepanH(){
    cin.ignore();
    
    string input, data[100];
    int jumlah = 0;

    cout<<"Masukkan Data : ";
    getline(cin, input);

    string sementara = "";

    for(int i = 0; i <= input.length(); i++){
        if(input[i] == ' ' || input[i] == '\0'){
            if(sementara != ""){
                data[jumlah] = sementara;
                jumlah++;
                sementara = "";
            }
        } else {
            sementara += input[i];
        }
    }

    for(int i = jumlah - 1; i >= 0; i--){
        TNode *baru;
        baru = new TNode;

        baru->data = data[i];
        baru->next = NULL;
        baru->prev = NULL;

        if(isEmptyH()==1){
            head = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }

    cout<<"Data ";
    for(int i = 0; i < jumlah; i++){
        cout<<"\""<<data[i]<<"\" ";

        if(i < jumlah - 1){
            cout<<", ";
        }
    }
    cout<<"berhasil ditambahkan di bagian depan."<<endl;
}

void tambahDepanHT(){
    cin.ignore();

    string input, data[100];
    int jumlah = 0;

    cout<<"Masukkan Data : ";
    getline(cin, input);

    string sementara = "";

    for(int i = 0; i <= input.length(); i++){
        if(input[i] == ' ' || input[i] == '\0'){
            if(sementara != ""){
                data[jumlah] = sementara;
                jumlah++;
                sementara = "";
            }
        } else {
            sementara += input[i];
        }
    }

    for(int i = jumlah - 1; i >= 0; i--){
        TNode *baru;

        baru = new TNode;

        baru->data = data[i];
        baru->next = NULL;
        baru->prev = NULL;

        if(isEmptyHT()==1){
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }

    cout<<"Data ";

    for(int i = 0; i < jumlah; i++){
        cout<<"\""<<data[i]<<"\"";

        if(i < jumlah - 1){
            cout<<", ";
        }
    }

    cout<<" berhasil ditambahkan di bagian depan."<<endl;
}


void tambahBelakangH(){
    cin.ignore();

    string input, data[100];
    int jumlah = 0;

    cout<<"Masukkan Data : ";
    getline(cin, input);

    string sementara = "";

    for(int i = 0; i <= input.length(); i++){
        if(input[i] == ' ' || input[i] == '\0'){
            if(sementara != ""){
                data[jumlah] = sementara;
                jumlah++;
                sementara = "";
            }
        } else {
            sementara += input[i];
        }
    }

    for(int i = 0; i < jumlah; i++){
        TNode *baru, *bantu;

        baru = new TNode;

        baru->data = data[i];
        baru->next = NULL;
        baru->prev = NULL;

        if(isEmptyH()==1){
            head = baru;
        } else {
            bantu = head;

            while(bantu->next != NULL){
                bantu = bantu->next;
            }

            bantu->next = baru;
            baru->prev = bantu;
        }
    }

    cout<<"Data ";

    for(int i = 0; i < jumlah; i++){
        cout<<"\""<<data[i]<<"\"";

        if(i < jumlah - 1){
            cout<<", ";
        }
    }

    cout<<" berhasil ditambahkan di bagian belakang."<<endl;
}


void tambahBelakangHT(){
    cin.ignore();

    string input, data[100];
    int jumlah = 0;

    cout<<"Masukkan Data : ";
    getline(cin, input);

    string sementara = "";

    for(int i = 0; i <= input.length(); i++){
        if(input[i] == ' ' || input[i] == '\0'){
            if(sementara != ""){
                data[jumlah] = sementara;
                jumlah++;
                sementara = "";
            }
        } else {
            sementara += input[i];
        }
    }

    for(int i = 0; i < jumlah; i++){
        TNode *baru;

        baru = new TNode;

        baru->data = data[i];
        baru->next = NULL;
        baru->prev = NULL;

        if(isEmptyHT()==1){
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }

    cout<<"Data ";

    for(int i = 0; i < jumlah; i++){
        cout<<"\""<<data[i]<<"\"";

        if(i < jumlah - 1){
            cout<<", ";
        }
    }

    cout<<" berhasil ditambahkan di bagian belakang."<<endl;
}

void tampilkanH(){
    TNode *bantu;
    bantu = head;
    if(isEmptyH()==0){
        while(bantu != NULL){
            cout<<bantu->data<<" ";
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void tampilkanHT(){
    TNode *bantu;
    bantu = head;
    if(isEmptyHT()==0){
        while(bantu != tail->next){
            cout<<bantu->data<<" ";
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void hapusDepanH(){
    TNode *hapus;
    string data;
    if(isEmptyH()==0){
            hapus = head;
            data = hapus->data;
        if (head->next != NULL){
            head = head->next;
            head->prev = NULL;
        } else {
            initH();
        }
        delete hapus;
        cout << "Data \""<<data<<"\" yang berada di depan telah berhasil dihapus."<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void hapusDepanHT(){
    TNode *hapus;
    string data;
    if(isEmptyHT()==0){
            hapus = head;
            data = hapus->data;
        if (head->next != NULL){
            head = head->next;
            head->prev = NULL;
        } else {
            initHT();
        }
        delete hapus;
        cout << "Data \""<<data<<"\" yang berada di depan telah berhasil dihapus."<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void hapusBelakangH(){
    int N, jumlah = 0, langkah;
    string data;

    if(isEmptyH()==0){

        cout<<"Hapus node ke-N dari belakang : ";
        cin>>N;

        TNode *bantu, *hapus;

        bantu = head;

        while(bantu != NULL){
            jumlah++;
            bantu = bantu->next;
        }

        if(N > jumlah){
            langkah = N % jumlah;

            if(langkah == 0){
                langkah = jumlah;
            }

        } else {

            langkah = N;

        }

        int posisi = jumlah - langkah + 1;

        bantu = head;

        for(int i = 1; i < posisi; i++){
            bantu = bantu->next;
        }

        hapus = bantu;
        data = hapus->data;

        if(head->next == NULL){

            initH();

        } else if(hapus == head){

            head = head->next;
            head->prev = NULL;

        } else if(hapus->next == NULL){

            hapus->prev->next = NULL;

        } else {

            hapus->prev->next = hapus->next;
            hapus->next->prev = hapus->prev;

        }

        delete hapus;

        cout<<"Data \""<<data
            <<"\" pada node ke-"<<langkah
            <<" dari belakang berhasil dihapus."<<endl;

    } else {

        cout<<"Tidak terdapat data pada Linked List."<<endl;

    }
}

void hapusBelakangHT(){
    int N, jumlah = 0, langkah;
    string data;

    if(isEmptyHT()==0){

        cout<<"Hapus node ke-N dari belakang : ";
        cin>>N;

        TNode *bantu, *hapus;

        bantu = head;

        while(bantu != NULL){
            jumlah++;
            bantu = bantu->next;
        }

        if(N > jumlah){

            langkah = N % jumlah;

            if(langkah == 0){
                langkah = jumlah;
            }

        } else {

            langkah = N;

        }

        hapus = tail;

        for(int i = 1; i < langkah; i++){
            hapus = hapus->prev;
        }

        data = hapus->data;

        if(head == tail){

            initHT();

        } else if(hapus == head){

            head = head->next;
            head->prev = NULL;

        } else if(hapus == tail){

            tail = tail->prev;
            tail->next = NULL;

        } else {

            hapus->prev->next = hapus->next;
            hapus->next->prev = hapus->prev;

        }

        delete hapus;

        cout<<"Data \""<<data
            <<"\" pada node ke-"<<langkah
            <<" dari belakang berhasil dihapus."<<endl;

    } else {

        cout<<"Tidak terdapat data pada Linked List."<<endl;

    }
}

void clearH() {
    TNode *hapus, *bantu;
    bantu = head;
    while(bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    initH();
    cout<<"Seluruh elemen pada Linked List telah dibersihkan."<<endl;
}

void clearHT(){
    TNode *hapus, *bantu;
    bantu = head;
    while(bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    initHT();
    cout<<"Seluruh elemen pada Linked List telah dibersihkan."<<endl;
}

void hapusTargetH(){
    string target;
    int ditemukan = 0;

    if(isEmptyH()==0){

        cout<<"Masukkan target data yang ingin dihapus : ";
        cin>>target;

        TNode *bantu, *hapus;

        bantu = head;

        while(bantu != NULL){

            if(bantu->data == target){

                ditemukan++;

                hapus = bantu;

                if(hapus == head){

                    head = head->next;

                    if(head != NULL){
                        head->prev = NULL;
                    }

                    bantu = head;

                } else if(hapus->next == NULL){

                    hapus->prev->next = NULL;

                    bantu = NULL;

                } else {

                    hapus->prev->next = hapus->next;
                    hapus->next->prev = hapus->prev;

                    bantu = hapus->next;
                }

                delete hapus;

            } else {

                bantu = bantu->next;

            }
        }

        if(ditemukan > 0){

            cout<<"Seluruh data \""<<target<<"\" berhasil dihapus."<<endl;

        } else {

            cout<<"Data \""<<target<<"\" tidak ditemukan."<<endl;

        }

    } else {

        cout<<"Tidak terdapat data pada Linked List."<<endl;

    }
}

void hapusTargetHT(){
    string target;
    int ditemukan = 0;

    if(isEmptyHT()==0){

        cout<<"Masukkan target data yang ingin dihapus : ";
        cin>>target;

        TNode *bantu, *hapus;

        bantu = head;

        while(bantu != NULL){

            if(bantu->data == target){

                ditemukan++;

                hapus = bantu;

                if(head == tail){

                    head = NULL;
                    tail = NULL;

                    bantu = NULL;

                } else if(hapus == head){

                    head = head->next;
                    head->prev = NULL;

                    bantu = head;

                } else if(hapus == tail){

                    tail = tail->prev;
                    tail->next = NULL;

                    bantu = NULL;

                } else {

                    hapus->prev->next = hapus->next;
                    hapus->next->prev = hapus->prev;

                    bantu = hapus->next;
                }

                delete hapus;

            } else {

                bantu = bantu->next;

            }
        }

        if(ditemukan > 0){

            cout<<"Seluruh data \""<<target<<"\" berhasil dihapus."<<endl;

        } else {

            cout<<"Data \""<<target<<"\" tidak ditemukan."<<endl;

        }

    } else {

        cout<<"Tidak terdapat data pada Linked List."<<endl;

    }
}

void ClearS(){
    TNode *hapusDepan, *hapusBelakang;
    int nomor = 1;

    if(head != NULL){

        while(head != NULL){

            if(head == tail){

                cout<<"Penghapusan ke-"<<nomor
                    <<" : \""<<head->data
                    <<"\" telah dihapus."<<endl;

                delete head;

                head = NULL;
                tail = NULL;

                nomor++;

            } else {

                hapusDepan = head;

                cout<<"Penghapusan ke-"<<nomor
                    <<" : \""<<hapusDepan->data
                    <<"\" telah dihapus dari depan."<<endl;

                head = head->next;
                head->prev = NULL;

                delete hapusDepan;

                nomor++;

                if(head != NULL){

                    hapusBelakang = tail;

                    cout<<"Penghapusan ke-"<<nomor
                        <<" : \""<<hapusBelakang->data
                        <<"\" telah dihapus dari belakang."<<endl;

                    tail = tail->prev;

                    if(tail != NULL){
                        tail->next = NULL;
                    }

                    delete hapusBelakang;

                    nomor++;
                }
            }
        }

        cout<<"Seluruh data berhasil dibersihkan."<<endl;

    } else {

        cout<<"Tidak terdapat data pada Linked List."<<endl;

    }
}