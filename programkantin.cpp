#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

string rupiah(int angka){
    stringstream ss;
    ss << angka;
    string hasil = ss.str();
    int posisi = hasil.length() - 3;
    while(posisi > 0){
        hasil.insert(posisi,".");
        posisi -= 3;
    }
    return "Rp " + hasil;
}

int main() {
    string user1="brilliant", pass1="111";
    string user2="henok", pass2="969";
    string user3="danis", pass3="333";
    string user4="indra", pass4="444";
    string user5="kenisha", pass5="555";
    string userBaru="", passBaru=""; 

    string kasir, inputUsername, inputPassword;
    bool statusLogin=false;
    int menu;

    string namaMenu[40] = {
        "", "Bakso Ayam/Keju/Mercon/Urat/Telur", "Mie Ayam", "Mie Ayam Bakso Keju", "Mie Sedap/Indomie ORI",
        "Mie Sedap/Indomie + Telur", "Mie Sedap/Indomie 2 + Telur", "Nasi Ayam Bento", "Nasi Ayam Kremes",
        "Nasi Kuning", "Nasi Chili Oil", "Burger", "Roti Coklat/Keju", "Corn Dog Pedas/Manis", "Kentang",
        "Scallop", "Pangsit", "Tempe", "Sosis", "Yupi", "Goodtime", "Superstar", "Oreo", "Chocolatos Mini",
        "Chocolatos Besar", "Basreng", "Ciki", "Teh Gelas", "Teh Botol", "Golda", "Florida", "Mizone",
        "Teh Pucuk", "Fruit Tea", "Air Mineral", "Teh Java", "Isoplus"
    };

    int hargaMenu[37] = {
        0, 10000, 10000, 12000, 7000, 10000, 17000, 10000, 10000, 10000, 10000,
        10000, 10000, 10000, 10000, 1000, 1000, 1000, 1000, 500, 2000, 1000,
        2000, 500, 1000, 1000, 2000, 1000, 5000, 4000, 4000, 5000, 5000, 5000,
        4000, 4000, 4000
    };

    while(true) {
        if(!statusLogin){
            cout<<"\n===== SISTEM LOGIN KASIR ====="<<endl;
            cout<<"1. Register"<<endl;
            cout<<"2. Login"<<endl;
            cout<<"3. Sign Out"<<endl;
            cout<<"4. Keluar"<<endl;
            cout<<"Pilih menu : "; 
            cin>>menu;
            system("cls");

            switch(menu){
                case 1: {
                    string usernameBaru,passwordBaru,konfirmasi;
                    cout<<"\n=== REGISTER AKUN ==="<<endl;
                    cout<<"Buat Username : "; cin>>usernameBaru;
                    cout<<"Buat Password : "; cin>>passwordBaru;
                    cout<<"Konfirmasi Password : "; cin>>konfirmasi;
                    if(passwordBaru==konfirmasi){
                        userBaru=usernameBaru; passBaru=passwordBaru;
                        cout<<"Register berhasil"<<endl;
                    } else { cout<<"Password tidak sama"<<endl; }
                    Sleep(1500); system("cls");
                    break;
                }
                case 2: {
                    cout<<"\n=== LOGIN ==="<<endl;
                    cout<<"Username : "; cin>>inputUsername;
                    cout<<"Password : "; cin>>inputPassword;
                    if(inputUsername==user1 && inputPassword==pass1){statusLogin=true; kasir="Brilliant";}
                    else if(inputUsername==user2 && inputPassword==pass2){statusLogin=true; kasir="Henok";}
                    else if(inputUsername==user3 && inputPassword==pass3){statusLogin=true; kasir="Danis";}
                    else if(inputUsername==user4 && inputPassword==pass4){statusLogin=true; kasir="Indra";}
                    else if(inputUsername==user5 && inputPassword==pass5){statusLogin=true; kasir="Kenisha";}
                    else if(inputUsername==userBaru && inputPassword==passBaru && userBaru != ""){statusLogin=true; kasir=userBaru;}
                    else { cout<<"Username atau password salah"<<endl; Sleep(1000); system("cls"); break; }
                    
                    cout<<"Login berhasil"<<endl; Sleep(500); system("cls");
                    break;
                }
                case 3: {
                    if(statusLogin){
                        statusLogin=false;
                        cout<<"Berhasil Sign Out"<<endl;
                    } else {
                        cout<<"Anda belum login"<<endl;
                    }
                    Sleep(1000); system("cls");
                    break;
                }
                case 4: return 0;
                default: cout<<"Menu tidak tersedia"<<endl; Sleep(1000); system("cls");
            }
        }

        if(statusLogin){
            int pilihan, jumlah, total=0, totalItem=0;
            int diskonItem=0, diskonJumat=0, diskon=0, ppn=0;
            string itemBeli[100];
            int jumlahBeli[100], subtotalItem[100];
            int indexItem=0;
            char lagi;

            do {
                system("cls");
                cout<<"\n============= MENU KANTIN ============="<<endl;
                cout<<"--- MAKANAN BERAT ---"<<endl;
                for(int i=1; i<=10; i++) cout<<i<<". "<<namaMenu[i]<<" : "<<hargaMenu[i]<<endl;
                cout<<"--- SNACK ---"<<endl;
                for(int i=11; i<=18; i++) cout<<i<<". "<<namaMenu[i]<<" : "<<hargaMenu[i]<<endl;
                cout<<"--- SNACK BUNGKUS ---"<<endl;
                for(int i=19; i<=26; i++) cout<<i<<". "<<namaMenu[i]<<" : "<<hargaMenu[i]<<endl;
                cout<<"--- MINUMAN ---"<<endl;
                for(int i=27; i<=36; i++) cout<<i<<". "<<namaMenu[i]<<" : "<<hargaMenu[i]<<endl;

                cout<<"\nPilih menu : "; cin>>pilihan;
                if(pilihan>=1 && pilihan<=36){
                    cout<<"Jumlah : "; cin>>jumlah;
                    
                    // LANGSUNG DITAMBAHKAN
                    int tempSub = hargaMenu[pilihan] * jumlah;
                    itemBeli[indexItem]=namaMenu[pilihan];
                    jumlahBeli[indexItem]=jumlah;
                    subtotalItem[indexItem]=tempSub;
                    total += tempSub;
                    totalItem += jumlah;
                    indexItem++;
                    cout<<"Berhasil ditambahkan!"<<endl;
                } else { cout<<"Menu tidak tersedia"<<endl; }

                cout<<"Pesan lagi? (y/n) : "; cin>>lagi;
            } while(lagi=='y' || lagi=='Y');

            if(indexItem > 0){
                if(totalItem>5) diskonItem = total*0.15;
                time_t now=time(0); tm *ltm=localtime(&now);
                if(ltm->tm_wday==5) diskonJumat = total*0.05;
                diskon = diskonItem + diskonJumat;
                int bayarSblmPPN = total - diskon;
                if(bayarSblmPPN>10000) ppn = bayarSblmPPN*0.10;
                int bayarTotal = bayarSblmPPN + ppn;

                cout<<"\nTOTAL BAYAR : "<<rupiah(bayarTotal)<<endl;
                cout<<"1. Tunai\n2. QRIS\nPilih Metode : "; int metode; cin>>metode;
                int uang;
                if(metode==2){ cout<<"Silakan scan QRIS..."<<endl; Sleep(2000); uang = bayarTotal; }
                else { cout<<"Masukkan uang : "; cin>>uang; }

                if(uang >= bayarTotal){
                    system("cls");
                    cout<<"========================================"<<endl;
                    cout<<"        KANTIN SMK TI BALI GLOBAL       "<<endl;
                    cout<<"========================================"<<endl;
                    cout<<"Tanggal : "<<ltm->tm_mday<<"-"<<1+ltm->tm_mon<<"-"<<1900+ltm->tm_year<<endl;
                    cout<<"Kasir   : "<<kasir<<endl;
                    cout<<"----------------------------------------"<<endl;
                    for(int i=0;i<indexItem;i++){
                        cout<<itemBeli[i]<<endl;
                        cout<<jumlahBeli[i]<<" x Pcs @ "<<rupiah(subtotalItem[i]/jumlahBeli[i])<<" = "<<rupiah(subtotalItem[i])<<endl;
                    }
                    cout<<"----------------------------------------"<<endl;
                    cout<<"Total Item       : "<<totalItem<<endl;
                    cout<<"Total Harga      : "<<rupiah(total)<<endl;
                    cout<<"Diskon           : "<<rupiah(diskon)<<endl;
                    cout<<"PPN              : "<<rupiah(ppn)<<endl;
                    cout<<"TOTAL BAYAR      : "<<rupiah(bayarTotal)<<endl;
                    cout<<"UANG             : "<<rupiah(uang)<<endl;
                    cout<<"KEMBALIAN        : "<<rupiah(uang - bayarTotal)<<endl;
                    cout<<"========================================"<<endl;
                    cout<<"      TERIMAKASIH TELAH BERBELANJA      "<<endl;
                    cout<<"========================================"<<endl;
                } else { cout<<"Uang tidak cukup"<<endl; }
            }

            cout<<"\nKembali ke menu utama? (y/n) : ";
            char back; cin>>back;
            if(back != 'y' && back != 'Y') statusLogin = false; 
            system("cls");
        }
    }
    return 0;
}
