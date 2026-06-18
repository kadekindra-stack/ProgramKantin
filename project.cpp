#include <iostream>
using namespace std;
//
int main(){

    string username, password;
    string inputUsername, inputPassword;
    string confirmPassword, email;

    bool statusLogin = false;

    int menu;

    int pilihan;
    int jumlah;
    int harga;
    int subtotal=0;
    int total=0;
    int diskon=0;
    int bayar;
    int uang;
    int kembalian;

    char lagi;

    do{

        cout << "\n===== SISTEM LOGIN KASIR =====\n";
        cout << "1. Sign In (Buat Akun)\n";
        cout << "2. Login\n";
        cout << "3. Sign Out\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu : ";
        cin >> menu;

        switch(menu){

        case 1:

            cout << "\n=== SIGN IN ===\n";

            cout << "Masukkan Username : ";
            cin >> username;

            cout << "Masukkan Email : ";
            cin >> email;

            cout << "Masukkan Password : ";
            cin >> password;

            cout << "Confirm Password : ";
            cin >> confirmPassword;

            if(password == confirmPassword){

                cout << "Akun berhasil dibuat!\n";

            }
            else{

                cout << "Password tidak sama!\n";

            }

        break;

        case 2:

            cout << "\n=== LOGIN ===\n";

            cout << "Username : ";
            cin >> inputUsername;

            cout << "Password : ";
            cin >> inputPassword;

            if(inputUsername == username && inputPassword == password){

                statusLogin = true;

                cout << "Login berhasil!\n";

            }
            else{

                cout << "Username atau password salah!\n";

            }

        break;

        case 3:

            if(statusLogin == true){

                statusLogin = false;

                cout << "Berhasil Sign Out\n";

            }
            else{

                cout << "Anda belum login\n";

            }

        break;

        case 4:

            cout << "Program selesai\n";

        break;

        default:

            cout << "Menu tidak tersedia\n";

        }

        if(statusLogin == true){
        	
        	system ("cls");

        do{

            cout<<"\n============= MENU KANTIN ============="<<endl;

            cout<<"\n--- MAKANAN BERAT ---"<<endl;
            cout<<"1. Mie Ayam : 10000"<<endl;
            cout<<"2. Mie Ayam Bakso Keju : 12000"<<endl;
            cout<<"3. Indomie ORI : 7000"<<endl;
            cout<<"4. Indomie + Telur : 10000"<<endl;
            cout<<"5. Indomie 2 + Telur : 17000"<<endl;
            cout<<"6. Nasi Ayam Bento : 10000"<<endl;
            cout<<"7. Nasi Ayam Kremes : 10000"<<endl;
            cout<<"8. Nasi Kuning : 10000"<<endl;
            cout<<"9. Nasi Chili Oil : 10000"<<endl;

            cout<<"\n--- SNACK ---"<<endl;
            cout<<"10. Roti Coklat/Keju : 10000"<<endl;
            cout<<"11. Corn Dog : 10000"<<endl;
            cout<<"12. Kentang : 10000"<<endl;
            cout<<"13. Scallop : 1000"<<endl;
            cout<<"14. Pangsit : 1000"<<endl;
            cout<<"15. Tempe : 1000"<<endl;
            cout<<"16. Sosis : 1000"<<endl;

            cout<<"\n--- SNACK BUNGKUS ---"<<endl;
            cout<<"17. Yupi : 500"<<endl;
            cout<<"18. Goodtime : 2000"<<endl;
            cout<<"19. Superstar : 1000"<<endl;
            cout<<"20. Oreo : 2000"<<endl;
            cout<<"21. Chocolatos Mini : 500"<<endl;
            cout<<"22. Chocolatos Besar : 1000"<<endl;
            cout<<"23. Basreng : 1000"<<endl;
            cout<<"24. Ciki : 2000"<<endl;

            cout<<"\n--- MINUMAN ---"<<endl;
            cout<<"25. Mizone : 5000"<<endl;
            cout<<"26. Teh Pucuk : 5000"<<endl;
            cout<<"27. Fruit Tea : 5000"<<endl;
            cout<<"28. Air Mineral : 4000"<<endl;
            cout<<"29. Teh Java : 4000"<<endl;
            cout<<"30. Isoplus : 4000"<<endl;

            cout<<"\nPilih menu : ";
            cin>>pilihan;

            cout<<"Jumlah : ";
            cin>>jumlah;

            if(pilihan==1){ harga=10000; cout<<"Mie Ayam"<<endl; }
            else if(pilihan==2){ harga=12000; cout<<"Mie Ayam Bakso Keju"<<endl; }
            else if(pilihan==3){ harga=7000; cout<<"Indomie ORI"<<endl; }
            else if(pilihan==4){ harga=10000; cout<<"Indomie + Telur"<<endl; }
            else if(pilihan==5){ harga=17000; cout<<"Indomie 2 + Telur"<<endl; }
            else if(pilihan==6){ harga=10000; cout<<"Nasi Ayam Bento"<<endl; }
            else if(pilihan==7){ harga=10000; cout<<"Nasi Ayam Kremes"<<endl; }
            else if(pilihan==8){ harga=10000; cout<<"Nasi Kuning"<<endl; }
            else if(pilihan==9){ harga=10000; cout<<"Nasi Chili Oil"<<endl; }

            else if(pilihan==10){ harga=10000; cout<<"Roti Coklat/Keju"<<endl; }
            else if(pilihan==11){ harga=10000; cout<<"Corn Dog"<<endl; }
            else if(pilihan==12){ harga=10000; cout<<"Kentang"<<endl; }
            else if(pilihan==13){ harga=1000; cout<<"Scallop"<<endl; }
            else if(pilihan==14){ harga=1000; cout<<"Pangsit"<<endl; }
            else if(pilihan==15){ harga=1000; cout<<"Tempe"<<endl; }
            else if(pilihan==16){ harga=1000; cout<<"Sosis"<<endl; }

            else if(pilihan==17){ harga=500; cout<<"Yupi"<<endl; }
            else if(pilihan==18){ harga=2000; cout<<"Goodtime"<<endl; }
            else if(pilihan==19){ harga=1000; cout<<"Superstar"<<endl; }
            else if(pilihan==20){ harga=2000; cout<<"Oreo"<<endl; }
            else if(pilihan==21){ harga=500; cout<<"Chocolatos Mini"<<endl; }
            else if(pilihan==22){ harga=1000; cout<<"Chocolatos Besar"<<endl; }
            else if(pilihan==23){ harga=1000; cout<<"Basreng"<<endl; }
            else if(pilihan==24){ harga=2000; cout<<"Ciki"<<endl; }

            else if(pilihan==25){ harga=5000; cout<<"Mizone"<<endl; }
            else if(pilihan==26){ harga=5000; cout<<"Teh Pucuk"<<endl; }
            else if(pilihan==27){ harga=5000; cout<<"Fruit Tea"<<endl; }
            else if(pilihan==28){ harga=4000; cout<<"Air Mineral"<<endl; }
            else if(pilihan==29){ harga=4000; cout<<"Teh Java"<<endl; }
            else if(pilihan==30){ harga=4000; cout<<"Isoplus"<<endl; }

            else{
                cout<<"Menu tidak tersedia"<<endl;
                harga=0;
            }

            subtotal=harga*jumlah;

            cout<<"Subtotal : "<<subtotal<<endl;

            total=subtotal;

            cout<<"Pesan lagi? (y/n) : ";
            cin>>lagi;

        }while(lagi=='y' || lagi=='Y');

        cout<<"\nTotal Belanja : "<<total<<endl;

        if(total>=50000){

            diskon=total*0.10;

        }

        bayar=total-diskon;

        cout<<"Diskon : "<<diskon<<endl;
        cout<<"Total Bayar : "<<bayar<<endl;

        cout<<"Masukkan uang : ";
        cin>>uang;

        if(uang>=bayar){

            kembalian=uang-bayar;

            cout<<"\n====== STRUK PEMBAYARAN ======"<<endl;
            cout<<"Total : "<<total<<endl;
            cout<<"Diskon : "<<diskon<<endl;
            cout<<"Bayar : "<<bayar<<endl;
            cout<<"Uang : "<<uang<<endl;
            cout<<"Kembalian : "<<kembalian<<endl;
            cout<<"==============================="<<endl;

        }
        else{

            cout<<"Uang tidak cukup"<<endl;

        }

        }

    }while(menu != 4);

return 0;
}
