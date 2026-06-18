#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

//================ WARNA =================
void setColor(int color){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void loading1 (){
	Sleep(1500);
	system("cls");
	cout<<"loading";
	Sleep(500);    
	for(int i=0;i<3;i++){
	cout<<".";
	Sleep(500);
	}
	system("cls");
}

void loading2 (){
	system("cls");
	cout<<("Loading");
	for(int i=0;i<3;i++){
	cout<<".";
	Sleep(400);
	}
	cout<<endl;
	system("cls");
}

// ================== FORMAT RUPIAH ==================
string rupiah(int angka) {
    stringstream ss;
    ss << angka;
    string hasil = ss.str();

    int posisi = hasil.length() - 3;
    while (posisi > 0) {
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
void tampilSummary(string namaMenu[]) {
	system("cls");
	setColor(14);
    cout << "\n========= SUMMARY PENJUALAN =========\n";
    setColor(7);
    cout << "Total item terjual : " << g_totalItem << endl;
    cout << "Total pendapatan   : " << rupiah(g_totalPendapatan) << endl;

    cout << "\n--- MENU TERJUAL ---\n";
    for (int i = 1; i <= 40; i++) {
        if (g_jumlahMenu[i] > 0) {
            cout << namaMenu[i] << " : " << g_jumlahMenu[i] << " pcs\n";
        }
    }
    cout << "=====================================\n";
}

void editPesanan(string itemBeli[], int jumlahBeli[], int subtotalItem[],
                 int &indexItem, int &total, int &totalItem) {

    if(indexItem == 0){
        cout << "Belum ada pesanan!\n";
        Sleep(1000);
        return;
    }
	loading2();
	system("cls");
	setColor(14);
    cout << "======================\n";
    cout << "==== EDIT PESANAN ====\n";
    cout << "======================\n";
	setColor(7);
    for(int i = 0; i < indexItem; i++){
        cout << i+1 << ". " << itemBeli[i]
             << " (" << jumlahBeli[i] << ") = "
             << rupiah(subtotalItem[i]) << endl;
    }

    int pilih;
    cout << "\nPilih nomor item (0 = kembali): ";
    cin >> pilih;

    if(pilih == 0) return;

    int idx = pilih - 1;

    int aksi;
    cout << "\n1. Hapus item\n";
    cout << "2. Kurangi jumlah\n";
    cout << "Pilih : ";
    cin >> aksi;

    if(aksi == 1){
        total -= subtotalItem[idx];
        totalItem -= jumlahBeli[idx];

        for(int i = idx; i < indexItem - 1; i++){
            itemBeli[i] = itemBeli[i+1];
            jumlahBeli[i] = jumlahBeli[i+1];
            subtotalItem[i] = subtotalItem[i+1];
        }

        indexItem--;
    }
    else if(aksi == 2){
        int kurang;
        cout << "Kurangi berapa? : ";
        cin >> kurang;

        if(kurang >= jumlahBeli[idx]){
            total -= subtotalItem[idx];
            totalItem -= jumlahBeli[idx];

            for(int i = idx; i < indexItem - 1; i++){
                itemBeli[i] = itemBeli[i+1];
                jumlahBeli[i] = jumlahBeli[i+1];
                subtotalItem[i] = subtotalItem[i+1];
            }

            indexItem--;
        }
        else{
            int harga = subtotalItem[idx] / jumlahBeli[idx];

            jumlahBeli[idx] -= kurang;

            int pengurangan = harga * kurang;
            subtotalItem[idx] -= pengurangan;

            total -= pengurangan;
            totalItem -= kurang;
        }
    }

    Sleep(1000);
}

int main() {

    // ---------- DATA USER ----------
    string user1 = "brilliant", pass1 = "911";
    string user2 = "henok", pass2 = "969";
    string user3 = "danis", pass3 = "333";
    string user4 = "indra", pass4 = "444";
    string user5 = "kenisha", pass5 = "555";

    string userBaru = "", passBaru = "";
    
    string kasir, inputUsername, inputPassword;
    bool statusLogin = false;
    int menu;

    // ---------- DATA MENU ----------
    string namaMenu[42] = {
        "",
        "Bakso Ayam", "Bakso Keju", "Bakso Mercon", "Bakso Urat", "Bakso Telur",
        "Mie Ayam", "Mie Ayam Bakso Keju", "Mie Sedap/Indomie ORI", "Mie Sedap/Indomie + Telur",
        "Mie Sedap/Indomie 2 + Telur", "Nasi Ayam Bento", "Nasi Ayam Kremes", "Nasi Kuning",
        "Nasi Chili Oil", "Burger", "Roti Coklat/Keju", "Corn Dog Pedas/Manis",
        "Kentang", "Scallop", "Pangsit", "Tempe", "Sosis", "Yupi", "Goodtime",
        "Superstar", "Oreo", "Chocolatos Mini", "Chocolatos Besar", "Basreng",
        "Ciki", "Teh Gelas", "Teh Botol", "Golda", "Florida", "Mizone",
        "Teh Pucuk", "Fruit Tea", "Air Mineral", "Teh Java", "Isoplus"
    };

    int hargaMenu[42] = {
        0,
        10000,10000,10000,10000,10000,10000,12000,
        7000,10000,17000,10000,10000,10000,10000,10000,10000,
        10000,10000,1000,1000,1000,1000,500,2000,1000,2000,500,
        1000,1000,2000,1000,5000,4000,4000,5000,5000,5000,4000,
        4000,4000
    };

    // ================== LOOP UTAMA ==================
    while (true) {

        // ---------- MENU LOGIN ----------
        if (!statusLogin) {
        	setColor(14);
            cout << "\n===== SISTEM LOGIN KASIR =====\n";
            setColor(7);
            cout << "1. Register\n";
            cout << "2. Login\n";
            cout << "3. Rekapan\n";
            cout << "4. Keluar\n";
            cout << "Pilih menu : ";
            cin >> menu;
			loading2();

            switch (menu) {

        case 1: {
            string usernameBaru, passwordBaru, konfirmasi;
				setColor(14);
            cout << "\n=== REGISTER AKUN ===\n";
                setColor(7);
            cout << "Buat Username : "; cin >> usernameBaru;
            cout << "Buat Password : "; cin >> passwordBaru;
            cout << "Konfirmasi Password : "; cin >> konfirmasi;

            if (passwordBaru == konfirmasi) {
                userBaru = usernameBaru;
                passBaru = passwordBaru;
                setColor(10);
            cout << "Register berhasil\n";
            } else {
                setColor(4);
            cout << "Password tidak sama\n";
                    }
				setColor(7);
        	loading1();
            break;
                }

        case 2: {
            	setColor(14);
            cout << "\n=== LOGIN ===\n";
                setColor(7);
            cout << "Username : "; cin >> inputUsername;
            cout << "Password : "; cin >> inputPassword;

        	if (inputUsername == user1 && inputPassword == pass1) {
            	statusLogin = true; kasir = "Brilliant";
                    }
            else if (inputUsername == user2 && inputPassword == pass2) {
            	statusLogin = true; kasir = "Henok";
                    }
            else if (inputUsername == user3 && inputPassword == pass3) {
                statusLogin = true; kasir = "Danis";
                    }
            else if (inputUsername == user4 && inputPassword == pass4) {
                statusLogin = true; kasir = "Indra";
                    }
            else if (inputUsername == user5 && inputPassword == pass5) {
                statusLogin = true; kasir = "Kenisha";
                    }
            else if (inputUsername == userBaru && inputPassword == passBaru && userBaru != "") {
                statusLogin = true; kasir = userBaru;
                    }
            else {
                setColor(4);
            cout << "Username atau password salah\n";
                setColor(7);
            loading1();
                break;
    	            }
				setColor(10);
            cout << "Login berhasil\n";
                setColor(7);
            loading1();
            break;
                }

        case 3: {
            if (!statusLogin) {
			    setColor(14);
			cout << "\n=== LOGIN UNTUK MELIHAT REKAPAN ===\n";
			    setColor(7);
			
			cout << "Username : "; cin >> inputUsername;
			cout << "Password : "; cin >> inputPassword;
			
			if (inputUsername == user1 && inputPassword == pass1) {
			statusLogin = true; kasir = "Brilliant";
			        }
			else if (inputUsername == user2 && inputPassword == pass2) {
			statusLogin = true; kasir = "Henok";
			        }
			else if (inputUsername == user3 && inputPassword == pass3) {
			statusLogin = true; kasir = "Danis";
			        }
			else if (inputUsername == user4 && inputPassword == pass4) {
			statusLogin = true; kasir = "Indra";
			        }
			else if (inputUsername == user5 && inputPassword == pass5) {
			statusLogin = true; kasir = "Kenisha";
			        }
			else if (inputUsername == userBaru && inputPassword == passBaru && userBaru != "") {
			statusLogin = true; kasir = userBaru;
			        }
			else {
				setColor(4);
			cout << "Login gagal!\n";
				setColor(7);
			Sleep(1500);
			system("cls");
			break;
			        }

        setColor(10);
        cout << "Login berhasil!\n";
        setColor(7);
        Sleep(1000);
        system("cls");
    }

    // ===== SETELAH LOGIN BERHASIL =====
    tampilSummary(namaMenu);

    char pilih;
    cout << "\nMasuk ke menu makanan? (y/n) : ";
    cin >> pilih;

    if (pilih == 'y' || pilih == 'Y') {
        statusLogin = true;
        system("cls");
    } else if (pilih == 'n' || pilih == 'N') {
        cout << "Program selesai...\n";
        return 0;
    } else {
        setColor(4);
        cout << "Input tidak valid!\n";
        setColor(7);
        Sleep(1000);
        system("cls");
    }

    break;
}
                    
                case 4:
                    return 0;

                default:
                	setColor(4);
                    cout << "Menu tidak tersedia\n";
                    setColor(7);
                    Sleep(1000);
                    system("cls");
            }
        }

        // ================== MENU KANTIN ==================
        if (statusLogin) {

            int pilihan, jumlah;
            int total = 0, totalItem = 0;
            int diskonItem = 0, diskonJumat = 0, diskon = 0, ppn = 0;

            string itemBeli[100];
            int jumlahBeli[100], subtotalItem[100];
            int indexItem = 0;

            char lagi;

			bool dariEdit = false;
            do {
                system("cls");
				setColor(14);
                cout << "\n============= MENU KANTIN =============\n";
                setColor(12);
				cout << " " << endl;
				cout << "|---------------------|" << endl;
                cout << "|--- MAKANAN BERAT ---|" << endl;
                cout << "|---------------------|" << endl;
                setColor(7);
                for (int i = 1; i <= 14; i++)
                    cout << i << ". " << namaMenu[i] << " : " << hargaMenu[i] << endl;
				cout << " " << endl;
				setColor(10);
				cout << "|-------------|" << endl;
                cout << "|--- SNACK ---|" << endl;
                cout << "|-------------|" << endl;
                setColor(7);
                for (int i = 15; i <= 22; i++)
                    cout << i << ". " << namaMenu[i] << " : " << hargaMenu[i] << endl;
				cout << " " << endl;
				setColor(15);
				cout << "|---------------------|" << endl;
                cout << "|--- SNACK BUNGKUS ---|" << endl;
                cout << "|---------------------|" << endl;
                setColor(7);
                for (int i = 23; i <= 30; i++)
                    cout << i << ". " << namaMenu[i] << " : " << hargaMenu[i] << endl;
				cout << " " << endl;
				setColor(11);
				cout << "|---------------|" << endl;
                cout << "|--- MINUMAN ---|" << endl;
                cout << "|---------------|" << endl;
                setColor(7);
                for (int i = 31; i <= 40; i++)
                    cout << i << ". " << namaMenu[i] << " : " << hargaMenu[i] << endl;

                cout << "\nPilih menu (0 = Membatalkan Pesanan) : ";
                cin >> pilihan;

				if(pilihan == 0){
    				editPesanan(itemBeli, jumlahBeli, subtotalItem,
                	indexItem, total, totalItem);

    			char pilihLanjut;
    				cout << "\n1. Tambah pesanan\n";
    				cout << "2. Lanjut ke pembayaran\n";
    				cout << "Pilih : ";
    				cin >> pilihLanjut;

    			if(pilihLanjut == '1'){
        			dariEdit = false;
        continue;
    }
    			else if(pilihLanjut == '2'){
        			dariEdit = true;
        break;
    }
    			else{
        			cout << "Input tidak valid!\n";
       				Sleep(1000);
        continue;
    }
}
					
                if(pilihan>=1 && pilihan<=40){
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
				if(!dariEdit){
   					cout<<"Pesan lagi? (y/n) : ";
    				cin>>lagi;
					loading2();
}
				
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
				system("cls");
                cout<<"\nTotal Item   : "<<totalItem<<endl;
                cout<<"Total Harga  : "<<rupiah(total)<<endl;
                cout<<"Diskon       : "<<rupiah(diskon)<<endl;
                cout<<"PPN 10%      : "<<rupiah(ppn)<<endl;
                cout<<"TOTAL BAYAR  : "<<rupiah(bayarTotal)<<endl;
                cout<<endl;

				// ===== PEMBAYARAN =====
				int metode;
					string metodeBayar;
				int uang = 0;

				bool pembayaranBerhasil = false;
				bool sudahCobaQRIS = false;
				bool gagalBayar = false;

				while (!pembayaranBerhasil) {
					cout << " " <<endl ;
		    setColor(14);
		    cout << "===============================\n";
		    cout << "====== Metode Pembayaran ======\n";
		    cout << "===============================\n";
		    setColor(7);
		
		    cout << "1. Tunai\n2. QRIS\nPilih Metode : ";
		    cin >> metode;

    // ================= TUNAI =================
    if (metode == 1) {
        metodeBayar = "Tunai";

        while (true) {
            cout << "Masukkan uang : ";
            cin >> uang;

            if (uang < bayarTotal) {
                setColor(4);
                cout << "\nUang kurang!\n";
                setColor(7);

                cout << "1. Ulangi input\n";
                cout << "2. Ganti ke QRIS\n";
                cout << "3. Edit pesanan\n";
                cout << "Pilih : ";

                int opsi;
                cin >> opsi;

                if (opsi == 1) {
                    continue;
                }
                else if (opsi == 2) {
                    break; 
                }
                else if (opsi == 3) {
    editPesanan(itemBeli, jumlahBeli, subtotalItem,
                indexItem, total, totalItem);

    // ===== HITUNG ULANG TOTAL =====
    diskonItem = 0;
    diskonJumat = 0;
    diskon = 0;
    ppn = 0;

    if(totalItem>5) diskonItem = total*0.15;

    time_t now=time(0);
    tm *ltm=localtime(&now);

    if(ltm->tm_wday==5) diskonJumat = total*0.05;

    diskon = diskonItem + diskonJumat;

    int bayarSblmPPN = total - diskon;

    if(bayarSblmPPN>10000)
        ppn = bayarSblmPPN*0.10;

    bayarTotal = bayarSblmPPN + ppn;

    system("cls");

    cout << "\nTotal Item   : " << totalItem << endl;
    cout << "Total Harga  : " << rupiah(total) << endl;
    cout << "Diskon       : " << rupiah(diskon) << endl;
    cout << "PPN 10%      : " << rupiah(ppn) << endl;
    cout << "TOTAL BAYAR  : " << rupiah(bayarTotal) << endl;
    cout << endl;

    continue;
}

                    if(totalItem>5) diskonItem = total*0.15;

                    time_t now=time(0);
                    tm *ltm=localtime(&now);
                    if(ltm->tm_wday==5) diskonJumat = total*0.05;

                    diskon = diskonItem + diskonJumat;
                    int bayarSblmPPN = total - diskon;

                    if(bayarSblmPPN>10000)
                        ppn = bayarSblmPPN*0.10;

                    bayarTotal = bayarSblmPPN + ppn;

                    break;
                }
            else {
                pembayaranBerhasil = true;
                break;
            }
        }
    }

    // ================= QRIS =================
    		else if (metode == 2) {
        		metodeBayar = "QRIS";

        		system("cls");
        		cout << "Silakan scan QRIS";
        		Sleep(1500);
        	for(int i=0;i<3;i++){
        	    cout<<".";
            	Sleep(1500);
        }
        	cout << " " << endl;

        	char konfirmasi;
        		cout << "Apakah pembayaran sudah masuk? (y/n) : ";
        		cin >> konfirmasi;
				loading2();

        		if (konfirmasi == 'y' || konfirmasi == 'Y') {
            		uang = bayarTotal;
            		pembayaranBerhasil = true;
        }
        else {
            	if (sudahCobaQRIS) {
                	setColor(4);
                	cout << "Pembayaran gagal 2x! Transaksi dibatalkan.\n";
                	setColor(7);
                	gagalBayar = true;
                break;
            } 	else {
                	setColor(4);
                	cout << "Pembayaran belum masuk!\n";
                	setColor(7);
                	sudahCobaQRIS = true;
            }
        }
    }

    			else {
        			setColor(4);
        			cout << "Metode tidak valid!\n";
        			setColor(7);
    }
}
				
                // ===== MENCETAK STRUK =====
                if (gagalBayar){
                	continue;
				}
                if (pembayaranBerhasil) {
                	// ===== MENGUPDATE REKAP GLOBAL =====
				g_totalItem += totalItem;
				g_totalPendapatan += bayarTotal;
				
				for (int i = 0; i < indexItem; i++) {
				    for (int j = 1; j <= 40; j++) {
				        if (itemBeli[i] == namaMenu[j]) {
				            g_jumlahMenu[j] += jumlahBeli[i];
				        }
				    }
				}
				
	
    			system("cls");
    			setColor(7);

    		cout << "========================================\n";
    		cout << "        KANTIN SMK TI BALI GLOBAL       \n";
    		cout << "========================================\n";

    		cout << "Tanggal : " << ltm->tm_mday << "-"
         		 << 1 + ltm->tm_mon << "-"
                 << 1900 + ltm->tm_year << endl;
		    cout << "Waktu   : " << ltm->tm_hour << ":"
		         << ltm->tm_min << ":"
		         << ltm->tm_sec << endl;
		    cout << "Kasir   : " << kasir << endl;
		    cout << "----------------------------------------\n";	

			for (int i = 0; i < indexItem; i++) {
		    cout << itemBeli[i] << endl;
		    cout << jumlahBeli[i] << " x Pcs @ "
		    	 << rupiah(subtotalItem[i] / jumlahBeli[i])
		         << " = " << rupiah(subtotalItem[i]) << endl;
    }
		    cout << "----------------------------------------\n";
		    cout << "Total Item       : " << totalItem << endl;
		    cout << "Total Harga      : " << rupiah(total) << endl;
		    cout << "Diskon           : " << rupiah(diskon) << endl;
		    cout << "PPN 10%          : " << rupiah(ppn) << endl;
		    cout << "----------------------------------------\n";
		    cout << "TOTAL BAYAR      : " << rupiah(bayarTotal) << endl;
		    cout << "METODE BAYAR     : " << metodeBayar << endl;
		    cout << "UANG             : " << rupiah(uang) << endl;
		    cout << "KEMBALIAN        : " << rupiah(uang - bayarTotal) << endl;
		
		    cout << "========================================\n";
		    cout << "      TERIMAKASIH TELAH BERBELANJA      \n";
		    cout << "========================================\n";

		    char ulang;
		    cout << "\nTransaksi lagi? (y/n): ";
		    cin >> ulang;
		
		    if (ulang == 'y' || ulang == 'Y') {
		        system("cls");
		    }
		    else {
		        statusLogin = false;
		
		        cout << "\nKembali ke menu login...\n";
		        Sleep(1000);
		        system("cls");
		    }
		}
	} 
}
} 
return 0;
}

