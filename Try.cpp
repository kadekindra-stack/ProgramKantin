#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

// ================== FORMAT RUPIAH ==================
string rupiah(int angka){
    stringstream ss;
    ss << angka;
    string hasil = ss.str();

    int posisi = hasil.length() - 3;
    while(posisi > 0){
        hasil.insert(posisi, ".");
        posisi -= 3;
    }

    return "Rp " + hasil;
}

// ================== GLOBAL ==================
int g_totalItem = 0;
int g_totalPendapatan = 0;
int g_jumlahMenu[40] = {0};

// ================== SUMMARY ==================
void tampilSummary(string namaMenu[]){
    cout << "\n========= SUMMARY PENJUALAN =========\n";
    cout << "Total item terjual : " << g_totalItem << endl;
    cout << "Total pendapatan   : " << rupiah(g_totalPendapatan) << endl;

    cout << "\n--- MENU TERJUAL ---\n";
    for(int i = 1; i <= 36; i++){
        if(g_jumlahMenu[i] > 0){
            cout << namaMenu[i] << " : " << g_jumlahMenu[i] << " pcs\n";
        }
    }

    cout << "=====================================\n";
}

// ================== MAIN ==================
int main(){

    // ---------- DATA USER ----------
    string user1="brilliant", pass1="111";
    string user2="henok", pass2="969";
    string user3="danis", pass3="333";
    string user4="indra", pass4="444";
    string user5="kenisha", pass5="555";

    string userBaru="", passBaru="";

    string kasir, inputUsername, inputPassword;
    bool statusLogin = false;
    int menu;

    // ---------- DATA MENU ----------
    string namaMenu[40] = {
        "", "Bakso Ayam/Keju/Mercon/Urat/Telur", "Mie Ayam",
        "Mie Ayam Bakso Keju", "Mie Sedap/Indomie ORI",
        "Mie Sedap/Indomie + Telur", "Mie Sedap/Indomie 2 + Telur",
        "Nasi Ayam Bento", "Nasi Ayam Kremes", "Nasi Kuning",
        "Nasi Chili Oil", "Burger", "Roti Coklat/Keju",
        "Corn Dog Pedas/Manis", "Kentang", "Scallop",
        "Pangsit", "Tempe", "Sosis", "Yupi", "Goodtime",
        "Superstar", "Oreo", "Chocolatos Mini", "Chocolatos Besar",
        "Basreng", "Ciki", "Teh Gelas", "Teh Botol", "Golda",
        "Florida", "Mizone", "Teh Pucuk", "Fruit Tea",
        "Air Mineral", "Teh Java", "Isoplus"
    };

    int hargaMenu[37] = {
        0,10000,10000,12000,7000,10000,17000,10000,10000,10000,10000,
        10000,10000,10000,10000,1000,1000,1000,1000,500,2000,1000,
        2000,500,1000,1000,2000,1000,5000,4000,4000,5000,5000,5000,
        4000,4000,4000
    };

    // ================== LOOP UTAMA ==================
    while(true){

        // ---------- MENU LOGIN ----------
        if(!statusLogin){
            cout<<"\n===== SISTEM LOGIN KASIR =====\n";
            cout<<"1. Register\n";
            cout<<"2. Login\n";
            cout<<"3. Sign Out\n";
            cout<<"4. Rekapan\n";
            cout<<"5. Keluar\n";
            cout<<"Pilih menu : ";
            cin>>menu;

            system("cls");

            switch(menu){

                // ===== REGISTER =====
                case 1:{
                    string usernameBaru,passwordBaru,konfirmasi;

                    cout<<"\n=== REGISTER AKUN ===\n";
                    cout<<"Buat Username : "; cin>>usernameBaru;
                    cout<<"Buat Password : "; cin>>passwordBaru;
                    cout<<"Konfirmasi Password : "; cin>>konfirmasi;

                    if(passwordBaru==konfirmasi){
                        userBaru=usernameBaru;
                        passBaru=passwordBaru;
                        cout<<"Register berhasil\n";
                    }else{
                        cout<<"Password tidak sama\n";
                    }

                    Sleep(1500);
                    system("cls");
                    break;
                }

                // ===== LOGIN =====
                case 2:{
                    cout<<"\n=== LOGIN ===\n";
                    cout<<"Username : "; cin>>inputUsername;
                    cout<<"Password : "; cin>>inputPassword;

                    if(inputUsername==user1 && inputPassword==pass1){
                        statusLogin=true; kasir="Brilliant";
                    }
                    else if(inputUsername==user2 && inputPassword==pass2){
                        statusLogin=true; kasir="Henok";
                    }
                    else if(inputUsername==user3 && inputPassword==pass3){
                        statusLogin=true; kasir="Danis";
                    }
                    else if(inputUsername==user4 && inputPassword==pass4){
                        statusLogin=true; kasir="Indra";
                    }
                    else if(inputUsername==user5 && inputPassword==pass5){
                        statusLogin=true; kasir="Kenisha";
                    }
                    else if(inputUsername==userBaru && inputPassword==passBaru && userBaru!=""){
                        statusLogin=true; kasir=userBaru;
                    }
                    else{
                        cout<<"Username atau password salah\n";
                        Sleep(1000);
                        system("cls");
                        break;
                    }

                    cout<<"Login berhasil\n";
                    Sleep(500);
                    system("cls");
                    break;
                }

                // ===== SIGN OUT =====
                case 3:{
                    if(statusLogin){
                        statusLogin=false;
                        cout<<"Berhasil Sign Out\n";
                    }else{
                        cout<<"Anda belum login\n";
                    }

                    Sleep(1000);
                    system("cls");
                    break;
                }

                // ===== REKAP =====
                case 4:{
    				tampilSummary(namaMenu);

    			char pilih;
    				cout<<"\nMasuk ke menu makanan? (y/n) : ";
   					cin>>pilih;

    			if(pilih=='y' || pilih=='Y'){
        			statusLogin = true;
        			system("cls");
    }
    			else if(pilih=='n' || pilih=='N'){
        			cout<<"Program selesai...\n";
        		return 0; 
    }
    			else{
        			cout<<"Input tidak valid!\n";
        			Sleep(1000);
        			system("cls");
    }

    break;
}
                // ===== KELUAR =====
                case 5:
                    return 0;

                default:
                    cout<<"Menu tidak tersedia\n";
                    Sleep(1000);
                    system("cls");
            }
        }

        // ================== MENU KANTIN ==================
        if(statusLogin){

            int pilihan, jumlah;
            int total=0, totalItem=0;
            int diskonItem=0, diskonJumat=0, diskon=0, ppn=0;

            string itemBeli[100];
            int jumlahBeli[100], subtotalItem[100];
            int indexItem=0;

            char lagi;

            // ===== INPUT PESANAN =====
            do{
                system("cls");

                cout<<"\n============= MENU KANTIN =============\n";

				cout<<"--- MAKANAN BERAT ---\n";
                for(int i=1;i<=10;i++)
                    cout<<i<<". "<<namaMenu[i]<<" : "<<hargaMenu[i]<<endl;

                cout<<"--- SNACK ---\n";
                for(int i=11;i<=18;i++)
                    cout<<i<<". "<<namaMenu[i]<<" : "<<hargaMenu[i]<<endl;

                cout<<"--- SNACK BUNGKUS ---\n";
                for(int i=19;i<=26;i++)
                    cout<<i<<". "<<namaMenu[i]<<" : "<<hargaMenu[i]<<endl;

                cout<<"--- MINUMAN ---\n";
                for(int i=27;i<=36;i++)
                    cout<<i<<". "<<namaMenu[i]<<" : "<<hargaMenu[i]<<endl;
                    

                cout<<"\nPilih menu : ";
                cin>>pilihan;
                cout<<""<<endl;
               
			   
			    // ===== HAPUS PESANAN =====
				if(pilihan == 0){
   				 if(indexItem == 0){
      				 cout<<"Belum ada pesanan!\n";
        			Sleep(1000);
       	continue;
    }

    				cout<<"\n--- DAFTAR PESANAN ---\n";
 			for(int i = 0; i < indexItem; i++){
       		 		cout<<i+1<<". "<<itemBeli[i]
          		  <<" ("<<jumlahBeli[i]<<") - "
          		 <<rupiah(subtotalItem[i])<<endl;
    }

   		 int hapus;
			    cout<<"Pilih nomor yang ingin dihapus (0 = batal): ";
			    cin>>hapus;

    			if(hapus == 0){
       			 cout<<"Batal hapus\n";
       			 Sleep(800);
        continue;
    }

    			if(hapus < 1 || hapus > indexItem){
       		 cout<<"Pilihan tidak valid!\n";
       		 Sleep(1000);
        continue;
    }

    int idx = hapus - 1;

    // update total
    total -= subtotalItem[idx];
    totalItem -= jumlahBeli[idx];

    // geser data
    for(int i = idx; i < indexItem - 1; i++){
        itemBeli[i] = itemBeli[i+1];
        jumlahBeli[i] = jumlahBeli[i+1];
        subtotalItem[i] = subtotalItem[i+1];
    }

    indexItem--;

    cout<<"Pesanan berhasil dihapus!\n";
    Sleep(1000);
    continue;
}

                if(pilihan>=1 && pilihan<=36){
                    cout<<"Jumlah : ";
                    cin>>jumlah;

                    int tempSub = hargaMenu[pilihan]*jumlah;

                    itemBeli[indexItem]=namaMenu[pilihan];
                    jumlahBeli[indexItem]=jumlah;
                    subtotalItem[indexItem]=tempSub;

                    total += tempSub;
                    totalItem += jumlah;
                    indexItem++;

                    cout<<"Berhasil ditambahkan!\n";
                }else{
                    cout<<"Menu tidak tersedia\n";
                }

                cout<<"Pesan lagi? (y/n) : ";
                cin>>lagi;

            }while(lagi=='y' || lagi=='Y');

            // ===== PROSES TOTAL =====
            if(indexItem>0){

                if(totalItem>5) diskonItem = total*0.15;

                time_t now=time(0);
                tm *ltm=localtime(&now);

                if(ltm->tm_wday==5) diskonJumat = total*0.05;

                diskon = diskonItem + diskonJumat;

                int bayarSblmPPN = total - diskon;

                if(bayarSblmPPN>10000)
                    ppn = bayarSblmPPN*0.10;

                int bayarTotal = bayarSblmPPN + ppn;

                // ===== TAMPIL TOTAL =====
                cout<<"\nTotal Item   : "<<totalItem<<endl;
                cout<<"Total Harga  : "<<rupiah(total)<<endl;
                cout<<"Diskon       : "<<rupiah(diskon)<<endl;
                cout<<"PPN 10%      : "<<rupiah(ppn)<<endl;
                cout<<"TOTAL BAYAR  : "<<rupiah(bayarTotal)<<endl;
                cout<<endl;

                // ===== PEMBAYARAN =====
                int metode;
                string metodeBayar;
                int uang=0;

                bool pembayaranBerhasil=false;
                bool sudahCobaQRIS=false;

                while(!pembayaranBerhasil){

                    cout<<"1. Tunai\n2. QRIS\nPilih Metode : ";
                    cin>>metode;

                    // --- TUNAI ---
                    if(metode==1){
                        metodeBayar="Tunai";

                        cout<<"Masukkan uang : ";
                        cin>>uang;

                        if(uang<bayarTotal){
                            cout<<"Uang kurang! Transaksi ditolak.\n";
                            break;
                        }else{
                            pembayaranBerhasil=true;
                        }
                    }

                    // --- QRIS ---
                    else if(metode==2){
                        metodeBayar="QRIS";

                        cout<<"Silakan scan QRIS...\n";
                        Sleep(2000);

                        char konfirmasi;
                        cout<<"Apakah pembayaran sudah masuk? (y/n) : ";
                        cin>>konfirmasi;

                        if(konfirmasi=='y' || konfirmasi=='Y'){
                            uang=bayarTotal;
                            pembayaranBerhasil=true;
                        }else{
                            if(sudahCobaQRIS){
                                cout<<"Pembayaran gagal 2x! Transaksi dibatalkan.\n";
                                break;
                            }else{
                                cout<<"Pembayaran belum masuk! Kembali ke metode pembayaran...\n";
                                sudahCobaQRIS=true;
                            }
                        }
                    }

                    else{
                        cout<<"Metode tidak valid!\n";
                    }
                }

                // ===== CETAK STRUK =====
                if(pembayaranBerhasil){

                    system("cls");

                    cout<<"========================================\n";
                    cout<<"        KANTIN SMK TI BALI GLOBAL       \n";
                    cout<<"========================================\n";

                    cout<<"Tanggal : "<<ltm->tm_mday<<"-"<<1+ltm->tm_mon<<"-"<<1900+ltm->tm_year<<endl;
                    cout<<"Waktu   : "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;

                    cout<<"Kasir   : "<<kasir<<endl;
                    cout<<"----------------------------------------\n";

                    for(int i=0;i<indexItem;i++){
                        cout<<itemBeli[i]<<endl;
                        cout<<jumlahBeli[i]<<" x Pcs @ "
                            <<rupiah(subtotalItem[i]/jumlahBeli[i])
                            <<" = "<<rupiah(subtotalItem[i])<<endl;
                    }

                    cout<<"----------------------------------------\n";
                    cout<<"Total Item       : "<<totalItem<<endl;
                    cout<<"Total Harga      : "<<rupiah(total)<<endl;
                    cout<<"Diskon           : "<<rupiah(diskon)<<endl;
                    cout<<"PPN 10%          : "<<rupiah(ppn)<<endl;
                    cout<<"----------------------------------------\n";
                    cout<<"TOTAL BAYAR      : "<<rupiah(bayarTotal)<<endl;
                    cout<<"METODE BAYAR     : "<<metodeBayar<<endl;
                    cout<<"UANG             : "<<rupiah(uang)<<endl;
                    cout<<"KEMBALIAN        : "<<rupiah(uang-bayarTotal)<<endl;

                    cout<<"========================================\n";
                    cout<<"      TERIMAKASIH TELAH BERBELANJA      \n";
                    cout<<"========================================\n";

                    // ===== UPDATE GLOBAL =====
                    g_totalItem += totalItem;
                    g_totalPendapatan += bayarTotal;

                    for(int i=0;i<indexItem;i++){
                        for(int j=1;j<=36;j++){
                            if(itemBeli[i]==namaMenu[j]){
                                g_jumlahMenu[j]+=jumlahBeli[i];
                            }
                        }
                    }
                }
                else{
                    cout<<"Uang tidak cukup\n";
                }
            }

            // ===== KEMBALI MENU =====
            cout<<"\nKembali ke menu utama? (y/n) : ";
            char back;
            cin>>back;

            if(back!='y' && back!='Y')
                statusLogin=false;

            system("cls");
        }
    }

    return 0;
}
