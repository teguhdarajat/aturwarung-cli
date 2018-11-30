#include <iostream>
#include <iomanip>
#include <conio.h>
#include <vector>

using namespace std;

vector<int> idBarang;
vector<string> namaBarang;
vector<int> stokBarang;
vector<int> hargaBarang;

int masuk = 0;
int k = 0;

void garis(){
    cout << "+----------------------------------------------------+\n";
}

void tabelBarang(){
    garis();
    cout << fixed;
    cout << "|";
    cout << left << setw(13) << "ID";
    cout << right << setw(13) << "PRODUK";
    cout << right << setw(13) << "HARGA";
    cout << right << setw(13) << "STOK";
    cout << "|" << endl;
    garis();
}

bool cekVectorBarang(){
    int jumlahData = idBarang.size();
    if(jumlahData < 1){
        return false;
    }
    else{
        return true;
    }
}

void insertBarang(int id, string nama, int stok, int harga){
    idBarang.push_back(id);
    namaBarang.push_back(nama);
    stokBarang.push_back(stok);
    hargaBarang.push_back(harga);
}

void tampilData(){
    int jumlahData;
    jumlahData = idBarang.size();
    tabelBarang();
    for(int i = 0; i < jumlahData; i++){
        cout << "|";
        cout << left << setw(13) << idBarang[i];
        cout << right << setw(13) << namaBarang[i];
        cout << right << setw(13) << hargaBarang[i];
        cout << right << setw(13) << stokBarang[i];
        cout << "|" << endl;
    }
    garis();
}

void hapusData(int id){
    bool status = false;
    int jumlahData = idBarang.size();
    for (int i = 0; i < jumlahData; i++){
        if(id == idBarang[i]){
            idBarang.erase(idBarang.begin() + i);
            namaBarang.erase(namaBarang.begin() + i);
            hargaBarang.erase(hargaBarang.begin()  + i);
            stokBarang.erase(stokBarang.begin() + i);
            cout << "Data berhasil di hapus\n";
            status = true;
            break;
        }
    }
    if(status == false){
        cout << "Data tidak ditemukan!\n";
    }
}

void updateStok(int dataStokLama, int dataStokBaru){
    for (int i = 0; i < stokBarang.size(); i++){
        if(dataStokLama == stokBarang[i]){
            stokBarang[i] = dataStokBaru;
        }
    }
}

void ubahData(int idPilih){
    int id, harga, stok;
    string nama;
    bool status = false;
    for (int i = 0; i < idBarang.size(); i++){
        if(idPilih == idBarang[i]){
            cout << "ID : ";
            cin >> id;
            cout << "Nama Barang : ";
            cin >> nama;
            cout << "Harga Barang: ";
            cin >> harga;
            cout << "Stok : ";
            cin >> stok;
            idBarang[i] = id;
            namaBarang[i] = nama;
            hargaBarang[i] = harga;
            stokBarang[i] = stok;
            cout << "Data berhasil di ubah\n";
            status = true;
            break;
        }
        else{
            status == false;
        }
    }
    if(status == false){
        cout << "Data tidak ditemukan!\n";
    }
}

void ubahStok(int stok, int stokLama){
    int jumlahData = idBarang.size();
    for (int i = 0; i < jumlahData; i++){
        if(stokLama == stokBarang[i]){
            stokBarang[i] = stok;
            break;
        }
    }
}

void transaksi(){
    int pilihID, id, stokLama, jumlahPembelian[99], hargaTotal[99], tambahBelanja = 1, harga[99], kembalian, bayar;
    string produk[99];
    int stok[99], stokBaru, status = 0, l = 0;
    char iterasiTransaksi;
    long total = 0;

    if(cekVectorBarang()){
        while(tambahBelanja == 1){
        system("cls");
        garis();
        cout << "|                    DATA PRODUK                     |\n";
        tampilData();
        cout << "Pilih ID Barang : ";
        cin >> id;

        for (int i = 0; i < idBarang.size(); i++){
            if(id == idBarang[i]){
                produk[l] = namaBarang[i];
                harga[l] = hargaBarang[i];
                stok[l] = stokBarang[i];
                status = 1;
                break;
            }
            else{
                status = 0;
            }
        }

        if(status == 1){
            cout << produk[l] << endl;
            cout << "Harga : " << harga[l] << endl;
            cout << "Jumlah Pembelian : ";
            cin >> jumlahPembelian[l];
            hargaTotal[l] = harga[l] * jumlahPembelian[l];
            total = total + hargaTotal[l];
            stokLama = stok[l];
            stokBaru = stok[l] - jumlahPembelian[l];
            if(stokBaru >= 0){
                updateStok(stokLama, stokBaru);
            }


            l++;
        }

        cout << "Lakukan pembelian lagi ? (y/n) " << endl;
        cin >> iterasiTransaksi;

        if(((iterasiTransaksi == 'n') || (iterasiTransaksi == 'N')) && (stokBaru >= 0)){
            while(true){
                system("cls");
                cout << fixed;

                cout << fixed;
                cout << "+--------------------------------------------------------------+\n";
                cout << "|";
                cout << left << setw(13) << "PRODUK";
                cout << right << setw(13) << "HARGA";
                cout << right << setw(23) << "JUMLAH PEMBELIAN";
                cout << right << setw(13) << "TOTAL";
                cout << "|" << endl;
                cout << "+--------------------------------------------------------------+\n";
                for (int z = 0; z < l; z++){
                    cout << "|";
                    cout << left << setw(13) << produk[z];
                    cout << right << setw(13) << harga[z];
                    cout << right << setw(23) << jumlahPembelian[z];
                    cout << right << setw(13) << hargaTotal[z];
                    cout << "|" << endl;
                }
                cout << "+--------------------------------------------------------------+\n";
                cout << "|";
                cout << left << setw(13) << "TOTAL PEMBAYARAN";
                cout << right << setw(46) << total;
                cout << "|" << endl;
                cout << "+--------------------------------------------------------------+\n";

                cout << "Pembayaran : ";
                cin >> bayar;
                if (bayar >= total){
                    kembalian = bayar - total;
                    cout << "Kembalian : " << kembalian << endl;
                    cout << "Terima Kasih\n";
                    tambahBelanja = 0;
                        break;
                    }
                    else{
                        cout << "Pembayaran kurang!\n";
                    }
                }
            }
        }
    }
    else{
        cout << "Data masih kosong\n";
    }
}


void menu(){
    int id , harga, stok, pilih, idPilih;
    string nama;
    system("cls");
    cout<<"Menu Aplikasi POS Atur Warung"<<endl;
    garis();
    cout<<"1. Insert / Tambah Data Barang"<<endl;
    cout<<"2. Lihat Data Barang"<<endl;
    cout<<"3. Ubah Data Barang"<<endl;
    cout<<"4. Hapus Data Barang"<<endl;
    cout<<"5. Aplikasi Kasir"<<endl;
    cout<<"6. Keluar"<<endl;
    cout<<"Pilih : ";
    cin>>pilih;
    cout<<endl;
    switch(pilih)
    {
        case 1:
        cout << "Input ID Barang : ";
        cin >> id;
        cout << "Input Nama Barang : ";
        cin >> nama;
        cout << "Input Harga Barang: ";
        cin >> harga;
        cout << "Input Stok Barang : ";
        cin >> stok;
        insertBarang(id, nama, stok, harga);
        cout << "Data berhasil di masukan!\n";
        getch();
        break;

        case 2:
        system("cls");
        garis();
        cout << "|                    DATA PRODUK                     |\n";
        tampilData();
        getch();
        break;

        case 3:
        system("cls");
        garis();
        cout << "|                  UBAH DATA PRODUK                  |"<<endl;
        tampilData();
        cout << "Pilih ID barang yang ingin di ubah : ";
        cin >> idPilih;
        ubahData(idPilih);
        getch();
        break;

        case 4:
        cout<<"Masukan ID yang ingin dihapus : "<<endl;
        cin>>id;
        hapusData(id);
        getch();
        break;

        case 5:
        system("cls");
        transaksi();
        getch();
        break;

        case 6:
        k = 1;
        return;
        break;

        default: cout<<"Pilihan yang anda masukkan salah!"<<endl;
        getch();
        break;
    }
}

int main(){
    while(true){
        if(k == 1){
            break;
        }
        menu();
    }

    return 0;
}

