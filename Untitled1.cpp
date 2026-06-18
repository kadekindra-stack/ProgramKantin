#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
using namespace std;

int main(){

// ================= LOGIN DATABASE =================

string user1="brilliant";
string pass1="111";

string user2="henok";
string pass2="222";

string user3="danis";
string pass3="333";

string user4="indra";
string pass4="444";

string user5="kenisha";
string pass5="555";

string kasir;

string inputUsername,inputPassword;

bool statusLogin=false;

int menu;

int pilihan;
int jumlah;
int harga;

int subtotal=0;
int total=0;

int totalItem=0;

int diskonItem=0;
int diskonJumat=0;
int diskon=0;

int bayar;
int uang;
int kembalian;

char lagi;

do{

cout<<"\n===== SISTEM LOGIN KASIR ====="<<endl;
cout<<"1. Login"<<endl;
cout<<"2. Sign Out"<<endl;
cout<<"3. Keluar"<<endl;
cout<<"Pilih menu : ";
cin>>menu;

system("cls");

switch(menu){

case 1:

cout<<"\n=== LOGIN ==="<<endl;

cout<<"Username : ";
cin>>inputUsername;

cout<<"Password : ";
cin>>inputPassword;

// ================= LOGIN CHECK =================

if(inputUsername==user1 && inputPassword==pass1){

statusLogin=true;
kasir="Brilliant"; 

cout<<"\nLogin berhasil"<<endl;
Sleep(1000);
system("cls");
cout<<"Loading";
Sleep(500);
cout<<".";
Sleep(500);
cout<<".";
Sleep(500);
cout<<".";
Sleep(2000);
system("cls");
}

else if(inputUsername==user2 && inputPassword==pass2){

statusLogin=true;
kasir="Henok"; 

cout<<"Login berhasil"<<endl;
Sleep(1000);
system("cls");
cout<<"Loading";
Sleep(500);
cout<<".";
Sleep(500);
cout<<".";
Sleep(500);
cout<<".";
Sleep(2000);
system("cls");
}

else if(inputUsername==user3 && inputPassword==pass3){

statusLogin=true;
kasir="Danis"; 

cout<<"Login berhasil"<<endl;
Sleep(1000);
system("cls");
cout<<"Loading";
Sleep(500);
cout<<".";
Sleep(500);
cout<<".";
Sleep(500);
cout<<".";
Sleep(2000);
system("cls");
}

else if(inputUsername==user4 && inputPassword==pass4){

statusLogin=true;
kasir="Indra"; 

cout<<"Login berhasil"<<endl;
Sleep(1000);
system("cls");
cout<<"Loading";
Sleep(500);
cout<<".";
Sleep(500);
cout<<".";
Sleep(500);
cout<<".";
Sleep(2000);
system("cls");

}

else if(inputUsername==user5 && inputPassword==pass5){

statusLogin=true;
kasir="Kenisha"; 

cout<<"Login berhasil"<<endl;
Sleep(1000);
system("cls");
cout<<"Loading";
Sleep(500);
cout<<".";
Sleep(500);
cout<<".";
Sleep(500);
cout<<".";
Sleep(2000);
system("cls");
}

else{

cout<<"Username atau password salah"<<endl;
Sleep(1000);
system("cls");
cout<<"Loading";
Sleep(500);
cout<<".";
Sleep(500);
cout<<".";
Sleep(500);
cout<<".";
Sleep(2000);
system("cls");
}

break;

case 2:

if(statusLogin==true){

statusLogin=false;

cout<<"Berhasil Sign Out"<<endl;

}else{
	
cout<<"Anda belum login"<<endl;

}

break;

case 3:

cout<<"Program selesai"<<endl;

break;

default:

cout<<"Menu tidak tersedia"<<endl;

}

// ================= MENU KANTIN =================

if(statusLogin==true){

total=0;
totalItem=0;

do{
system("cls");
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
system("cls");
if(pilihan==1){harga=10000;}
else if(pilihan==2){harga=12000;}
else if(pilihan==3){harga=7000;}
else if(pilihan==4){harga=10000;}
else if(pilihan==5){harga=17000;}
else if(pilihan==6){harga=10000;}
else if(pilihan==7){harga=10000;}
else if(pilihan==8){harga=10000;}
else if(pilihan==9){harga=10000;}

else if(pilihan==10){harga=10000;}
else if(pilihan==11){harga=10000;}
else if(pilihan==12){harga=10000;}
else if(pilihan==13){harga=1000;}
else if(pilihan==14){harga=1000;}
else if(pilihan==15){harga=1000;}
else if(pilihan==16){harga=1000;}

else if(pilihan==17){harga=500;}
else if(pilihan==18){harga=2000;}
else if(pilihan==19){harga=1000;}
else if(pilihan==20){harga=2000;}
else if(pilihan==21){harga=500;}
else if(pilihan==22){harga=1000;}
else if(pilihan==23){harga=1000;}
else if(pilihan==24){harga=2000;}

else if(pilihan==25){harga=5000;}
else if(pilihan==26){harga=5000;}
else if(pilihan==27){harga=5000;}
else if(pilihan==28){harga=4000;}
else if(pilihan==29){harga=4000;}
else if(pilihan==30){harga=4000;}

else{
cout<<"Menu tidak tersedia"<<endl;
harga=0;
}
system("cls");
subtotal=harga*jumlah;

total=total+subtotal;

totalItem=totalItem+jumlah;

cout<<"Subtotal : "<<subtotal<<endl;

cout<<"Pesan lagi? (y/n) : ";
cin>>lagi;

}while(lagi=='y' || lagi=='Y');

cout<<"\nTotal Belanja : "<<total<<endl;

// ================= DISKON =================

if(totalItem>5){

diskonItem=total*0.15;

}else{

diskonItem=0;

}

// BARU - diskon hari jumat otomatis

time_t now=time(0);
tm *ltm=localtime(&now);

if(ltm->tm_wday==5){

diskonJumat=total*0.05;

cout<<"Diskon tambahan hari Jumat 5%"<<endl;

}else{

diskonJumat=0;

}

diskon=diskonItem+diskonJumat;

bayar=total-diskon;

cout<<"Diskon Item : "<<diskonItem<<endl;
cout<<"Diskon Jumat : "<<diskonJumat<<endl;
cout<<"Total Diskon : "<<diskon<<endl;

cout<<"Total Bayar : "<<bayar<<endl;

cout<<"Masukkan uang : ";
cin>>uang;

if(uang>=bayar){

kembalian=uang-bayar;

// ================= STRUK =================
system("cls");
cout<<"========================================\n";
cout<<"        KANTIN SMK TI BALI GLOBAL\n";
cout<<"========================================\n";
cout<<"Kasir : "<<kasir<<endl;
cout<<"Total : "<<total<<endl;
cout<<"Diskon : "<<diskon<<endl;
cout<<"Bayar : "<<bayar<<endl;
cout<<"Uang : "<<uang<<endl;
cout<<"Kembalian : "<<kembalian<<endl;
cout<<"========================================"<<endl;
cout<<"Terimakasih telah berbelanja"<<endl;
cout<<"Silahkan datang kembali"<<endl;
cout<<"Kantin SMK TI Bali Global"<<endl;
cout<<"========================================"<<endl;
cout<<"Loading";
Sleep(1000);
cout<<".";
Sleep(1000);
cout<<".";
Sleep(1000);
cout<<".";
Sleep(5000);
system("cls");
}else{

cout<<"Uang tidak cukup"<<endl;
cout<<"Loading";
Sleep(500);
cout<<".";
Sleep(500);
cout<<".";
Sleep(500);
cout<<".";
Sleep(2000);
system("cls");
}

}

}while(menu!=3);

return 0;
}
