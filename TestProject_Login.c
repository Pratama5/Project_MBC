#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//Function Prototype place//
int mainmenu();																/*Fungsi Prototipe ADMIN*/
int menu_admin();
int login_admin();
int cek_bioapoteker();
int cek_biodokter();

int menu_apoteker();														/*Fungsi Prototipe APOTEKER*/
int masuk_apoteker();
int reg_apoteker();
int daftar_obat();
int input_obat();
int hapus_obat();
int login_apoteker();

int menu_dokter();															/*Fungsi Prototipe DOKTER*/
int masuk_dokter();
int reg_dokter();
int login_dokter();
int input_konsul();
int hapus_konsul();
int daftar_konsul();

int menu_pasien();															/*Fungsi Prototipe PASIEN*/
int masuk_pasien();
int reg_pasien();
int login_pasien();
int beli_obat();
int struk_obat();
int pesan_konsul();
int struk_konsul();
int riwayat();

/*~*/

int main(){																						//Success
	mainmenu();
}
int mainmenu(){																					//Success
	int pil;
	
	printf("==== Menu ====\n");
	printf("1. Admin\n");
	printf("2. Apoteker\n");
	printf("3. Dokter\n");
	printf("4. Pasien\n");
	printf("Masukkan pilihan: \n");scanf("%d",&pil);
	getchar();
	switch(pil){
		case 1:{
			login_admin();
			break;
		}
		case 2:{
			masuk_apoteker();
			break;
		}
		case 3:{
			masuk_dokter();
			break;
		}
		case 4:{
			masuk_pasien();
			break;
		}
	}
}
int menu_admin(){																				//Success
	int pil;
	system("cls");
	
	printf("=====Menu Admin====\n");
	printf("(1).Lihat Biodata Dokter\n");
	printf("(2).Lihat Biodata Apoteker\n");
	printf("(3).Lihat kesediaan Obat-obatan\n");
	printf("(4).Lihat kesediaan Konsultasi\n");
	printf("(5).Lihat riwayat konsultasi\n");
	printf("(6).Lihat riwayat pembelian obat\n");
	printf("(7).Keluar\n");
	printf("Pilihan Anda: ");scanf("%d",&pil);
	getchar();
	switch(pil){
		case 1:{
			cek_biodokter();
			break;
		}
		case 2:{
			cek_bioapoteker();
			break;
		}
		case 3:{
			system("cls");
			daftar_obat();
			system("pause");
			menu_admin();
			break;
		}
		case 4:{
			system("cls");
			daftar_konsul();
			system("pause");
			menu_admin();
			break;
		}
		case 5:{
			system("cls");
			struk_konsul();
			system("pause");
			menu_admin();
			break;
		}
		case 6:{
			system("cls");
			struk_obat();
			system("pause");
			menu_admin();
			break;
		}
		case 7:{
			system("cls");
			mainmenu();
			break;
		}
	}
	return 0; 
}
int cek_bioapoteker(){																			//Success	
	system("cls");																	
	FILE *f_jasa;
	
	struct akun{
		char uname[50],pass[50];
		char nama[50],tgl_lahir[50],tmp_lahir[50],nik[20];
		};
	struct akun read;
	int i=1;
	
	f_jasa=fopen("File_apoteker","rb");
	printf("Menampilkan Biodata Para APOTEKER\n");
	while(fread(&read,sizeof(read),1,f_jasa) == 1){
	printf("-------------------------------------------------\n");
	printf("%d.\t Username\t:%s\n",i,read.uname);
	printf("\t Nama\t\t:%s\n",read.nama);
	printf("\t Tanggal lahir\t:%s\n",read.tgl_lahir);
	printf("\t Tempat lahir\t:%s\n",read.tmp_lahir);
	printf("\t Nomor NIK\t:%s\n",read.nik);
	i++;
	}
	system("pause");
	fclose(f_jasa);
	menu_admin();
}
int cek_biodokter(){																			//Success
	system("cls");
	FILE *f_jasa;
	struct akun{
		char uname[50],pass[50];
		char nama[50],tgl_lahir[50],tmp_lahir[50],spesialis[50],nik[20];
		};
	struct akun read;
	int i=1;
	
	f_jasa=fopen("File_dokter.dat","rb");
	printf("Menampilkan Biodata Para DOKTER\n");
	while(fread(&read,sizeof(read),1,f_jasa) == 1){
	printf("-------------------------------------------------\n");
	printf("%d.\t Username\t:%s\n",i,read.uname);
	printf("\t Nama\t\t:%s\n",read.nama);
	printf("\t Spesailisasi\t:%s\n",read.spesialis);
	printf("\t Tanggal lahir\t:%s\n",read.tgl_lahir);
	printf("\t Tempat lahir\t:%s\n",read.tmp_lahir);
	printf("\t Nomor NIK\t:%s\n",read.nik);
	i++;
	}
	system("pause");
	fclose(f_jasa);
	menu_admin();
}
int login_admin(){																				//Success
	struct akun{
		char uname[50],pass[50];	
	}akun_admin;
	
	system("cls");
	
	printf("Selamat datang untuk ADMIN\n");
	printf("Username Admin\t:");gets(akun_admin.uname);
	printf("Password Admin\t:");gets(akun_admin.pass);
	
	if(strcmp(akun_admin.uname,"ADMIN")==0 && strcmp(akun_admin.pass,"ADMIN1")==0){
		printf("Login berhasil\n");
		system("pause");
	}else{
		printf("Login gagal!");
		system("pause");
		login_admin();
	}
	menu_admin();
}
int menu_apoteker(){																			//Success
	int pil;
	
	system("cls");
	printf("Selamat datang untuk APOTEKER\n");
	printf("Silahkan pilih Menu: \n");
	printf("(1).Input Obat\n");
	printf("(2).Hapus Obat\n");																	
	printf("(3).Lihat Riwayat Pembelian Obat\n");
	printf("(4).Kembali Menu Utama\n");
	printf("Pilihan: ");scanf("%d",&pil);
	getchar();
	switch(pil){
		case 1:{
			system("cls");
			printf("Silahkan Daftarkan Obat yang akan Dimasukkan\n");
			input_obat();
			system("pause");
			menu_apoteker();
			break;
		}
		case 2:{
			system("cls");
			daftar_obat();
			system("pause");
			hapus_obat();
			menu_apoteker();
			break;
		}
		case 3:{
			system("cls");
			struk_obat();
			system("pause");
			break;
		}
		case 4:{
			system("cls");
			mainmenu();
			break;
		}
	}	
}
int daftar_obat(){																				//Success
	
	struct stok{
		char obat[50];
		int harga;
	}stok_obat;
	struct stok stok;
	int i;
	FILE *f_jasa;
	i=1;
	printf("==== Menampilkan Obat yang terdaftar ====\n");
	
	f_jasa=fopen("File_Obat.dat","rb");
	while(fread(&stok,sizeof(stok),1,f_jasa)==1){
	printf("================================\n");
	printf("%d.\tNama obat\t\t: %s\n",i,stok.obat);
	printf("\tHarga per satuan\t: Rp. %d\n",stok.harga);	
	i++;
	}
	fclose(f_jasa);	
	

}
int input_obat(){																				//Success
	struct stok{
		char obat[50];
		int harga;
	}stok_obat;
	
	struct stok stok;
	
	FILE *f_jasa;
	f_jasa=fopen("File_Obat.dat","ab");
	printf("Silahkan Daftarkan obat yang akan dimasukkan\n");
	printf("Nama Obat: ");gets(stok.obat);
	printf("Harga obat per satuan: Rp.");scanf("%d",&stok.harga);
	getchar();
	printf("Obat berhasil didaftarkan\n");
	
	fwrite(&stok,sizeof(stok),1,f_jasa);
	fclose(f_jasa);
}
int hapus_obat(){																				//Success
	FILE *f_jasa;
	FILE *f_jasa2;
	
	struct stok{
		char obat[50];
		int harga;
	}stok_obat;
	struct stok stok;
	char cari[50];
	
	f_jasa=fopen("File_Obat.dat","rb");
	f_jasa2=fopen("File_Obat2.dat","wb");	
	
	printf("Menghapus Obat dari Daftar!!!\n");
	printf("\nMasukan Nama obat yang akan dihapus : "); gets(cari);

	printf("Obat yang akan Dihapus: %s\n",cari);
	system("pause");
	while(fread(&stok,sizeof(stok),1,f_jasa)==1){	
		if (strcmp(stok.obat, cari)!=0){	
			fwrite(&stok,sizeof(stok),1,f_jasa2);
			}
		}
	fclose(f_jasa);
	fclose(f_jasa2);
	remove("File_Obat.dat");
	rename("File_Obat2.dat","File_Obat.dat");
}
int masuk_apoteker(){																			//Success
	int pil;
	system("cls");
	printf("Selamat Datang di Login Apoteker\n");
	printf("(1).Registrasi	- Untuk pengguna baru\n");
	printf("(2).Login 	- Untuk pengguna yang sudah punya akun\n");
	printf("Pilihan: ");scanf("%d",&pil);
	getchar();
	switch(pil){
		case 1:{
			reg_apoteker();
			break;
		}
		case 2:{
			login_apoteker();
			break;
		}
		default :{masuk_apoteker();}
	}
	menu_apoteker();
}
int reg_apoteker(){																				//Success
	system("cls");
	FILE *f_jasa;
	struct akun{
		char uname[50],pass[50];
		char nama[50],tgl_lahir[50],tmp_lahir[50],nik[20];
		};
	struct akun write;	
	f_jasa=fopen("File_apoteker","ab");
	printf("=== MENU REGISTRASI APOTEKER ===\n");
	printf("Masukkan Username dan Password anda\n");
	printf("Username: ");gets(write.uname);
	printf("Pass:");gets(write.pass);
	printf("Username dan Password anda berhasil didaftarkan\n\n");
	
	printf("Silahkan lengkapi Data Diri anda\n");
	printf("Nama Lengkap: ");gets(write.nama);
	printf("Tanggal Lahir (dd-mm-yyyy): ");gets(write.tgl_lahir);
	printf("Tempat Lahir: ");gets(write.tmp_lahir);
	printf("Nomor NIK: ");gets(write.nik);
	fwrite(&write,sizeof(write),1,f_jasa);
	fclose(f_jasa);
	
	masuk_apoteker();
}
int login_apoteker(){																			//Success
	system("cls");
	FILE *f_jasa;
	struct akun{
		char uname[50],pass[50];
		};
		
	struct akun read, cek;
	printf("=== MENU LOGIN APOTEKER ===\n");	
	printf("Masukkan Username anda: \n");gets(cek.uname);
	printf("Masukkan Password anda: \n");gets(cek.pass);
	
	f_jasa=fopen("File_apoteker","rb");
	while(fread(&read,sizeof(read),1,f_jasa) == 1){
		if(strcmp(read.uname,cek.uname)==0 && strcmp(read.pass,cek.pass)==0){
			printf("Login berhasil\n");
			printf("Selamat datang %s\n",read.uname);
			fclose(f_jasa);
			system("pause");
			break;
		}else{
			printf("Login gagal\nSilahkan Coba Lagi\n");
			masuk_apoteker();
			break;
		} 
	}	
}
int masuk_dokter(){																				//Success
	int pil;
	system("cls");
	printf("Selamat Datang di Login Dokter\n");
	printf("(1).Registrasi	- Untuk pengguna baru\n");
	printf("(2).Login 	- Untuk pengguna yang sudah punya akun\n");
	printf("Pilihan: ");scanf("%d",&pil);
	getchar();
	switch(pil){
		case 1:{
			reg_dokter();
			break;
		}
		case 2:{
			login_dokter();
			break;
		}
		default :{masuk_dokter();}
	}
	menu_dokter();
	return 0;
}
int reg_dokter(){																				//Success
	system("cls");
	FILE *f_jasa;
	struct akun{
		char uname[50],pass[50];
		char nama[50],tgl_lahir[50],tmp_lahir[50],spesialis[50],nik[20];
		};
	struct akun write;	
	f_jasa=fopen("File_dokter.dat","ab");
	printf("=== MENU REGISTRASI Dokter ===\n");
	printf("Masukkan Username dan Password anda\n");
	printf("Username: ");gets(write.uname);
	printf("Pass:");gets(write.pass);
	printf("Username dan Password anda berhasil didaftarkan\n");
	
	printf("Silahkan lengkapi Data Diri anda\n");
	printf("Nama Lengkap: ");gets(write.nama);
	printf("Spesialisasi: ");gets(write.spesialis);
	printf("Tanggal Lahir(dd-mm-yyyy): ");gets(write.tgl_lahir);
	printf("Tempat Lahir: ");gets(write.tmp_lahir);
	printf("Nomor NIK: ");gets(write.nik);
	
	fwrite(&write,sizeof(write),1,f_jasa);
	fclose(f_jasa);
	system("pause");
	masuk_dokter();
}
int login_dokter(){																				//Success
	system("cls");
	FILE *f_jasa;
	struct akun{
		char uname[50],pass[50];
		};
		
	struct akun read, cek;
	printf("=== MENU LOGIN Dokter ===\n");	
	printf("Masukkan Username anda: \n");gets(cek.uname);
	printf("Masukkan Password anda: \n");gets(cek.pass);
	
	f_jasa=fopen("File_dokter","rb");
	while(fread(&read,sizeof(read),1,f_jasa) == 1){
		if(strcmp(read.uname,cek.uname)==0 && strcmp(read.pass,cek.pass)==0){
			printf("Login berhasil\n");
			printf("Selamat datang %s\n",read.uname);
			fclose(f_jasa);
			system("pause");
			break;
		}else{
			printf("Login gagal\nSilahkan Coba Lagi\n");
			system("pause");
			masuk_dokter();
			break;
		} 
	}	
}
int menu_dokter(){																				//success
		int pil;
	
	system("cls");
	printf("Selamat datang untuk DOKTER\n");
	printf("Silahkan pilih Menu: \n");
	printf("(1).Input Konsultasi\n");
	printf("(2).Hapus Konsultasi\n");																	
	printf("(3).Lihat Riwayat Konsultasi\n");
	printf("(4).Kembali ke Menu Utama\n");
	printf("Pilihan: ");scanf("%d",&pil);
	getchar();
	switch(pil){
		case 1:{
			system("cls");
			printf("Silahkan Daftarkan Konsultasi yang akan Dimasukkan\n");
			input_konsul();
			system("pause");
			menu_dokter();
			break;
		}
		case 2:{
			system("cls");
			daftar_konsul();
			system("pause");
			hapus_konsul();
			menu_dokter();
			break;
		}
		case 3:{
			system("cls");
			struk_konsul();
			system("pause");
			break;
		}
		case 4:{
			system("cls");
			mainmenu();
			break;
		}
	}	
}
int input_konsul(){																				//Success
	struct konsul{
		char tema[50],dokter[50];
		int waktu,harga;
	}konsultasi;
	
	printf("Silahkan Daftarkan Konsultasi yang akan dimasukkan\n");
	FILE *f_jasa;
	f_jasa=fopen("File_Konsultasi.dat","ab");
	
	printf("Nama Konsultasi: ");gets(konsultasi.tema);
	printf("Nama anda: dr.");gets(konsultasi.dokter);
	printf("Harga Konsultasi per pertemuan: Rp.");scanf("%d",&konsultasi.harga);
	printf("Waktu Konsultasi per pertemuan (menit): ");scanf("%d",&konsultasi.waktu);
	getchar();
	printf("Konsultasi berhasil didaftarkan\n");
	
	fwrite(&konsultasi,sizeof(konsultasi),1,f_jasa);
	fclose(f_jasa);
}
int daftar_konsul(){																			//Success
		
	struct konsul{
		char tema[50],dokter[50];
		int waktu,harga;
	}konsultasi;

	int i;
	FILE *f_jasa;
	i=1;
	printf("====Menampilkan Konsultasi yang terdaftar====\n");
	
	f_jasa=fopen("File_Konsultasi.dat","rb");
	
	while(fread(&konsultasi,sizeof(konsultasi),1,f_jasa)==1){
	printf("================================\n");
	printf("%d.\t Nama Konsultasi\t\t:%s\n",i,konsultasi.tema);
	printf("\t Dokter yang menangani\t:dr. %s \n",konsultasi.dokter);
	printf("\t Harga per konsultasi\t:Rp. %d\n",konsultasi.harga);	
	printf("\t Waktu per Konsultasi\t:%d menit\n",konsultasi.waktu);
	i++;
	}
	fclose(f_jasa);	
}
int hapus_konsul(){																				//Success
		FILE *f_jasa;
	FILE *f_jasa2;
	
	struct stok{
		char obat[50];
		int harga;
	}stok_obat;
	struct stok stok;
	char cari[50];
	
	f_jasa=fopen("File_Konsultasi.dat","rb");
	f_jasa2=fopen("File_Konsultasi2.dat","wb");	
	
	printf("Menghapus Konsul dari Daftar!!!\n");
	printf("\nMasukan Nama Konsultasi yang akan dihapus : "); gets(cari);

	printf("Konsultasi yang akan Dihapus: %s\n",cari);
	system("pause");
	while(fread(&stok,sizeof(stok),1,f_jasa)==1){	
		if (strcmp(stok.obat, cari)!=0){	
			fwrite(&stok,sizeof(stok),1,f_jasa2);
			}
		}
	fclose(f_jasa);
	fclose(f_jasa2);
	remove("File_Konsultasi.dat");
	rename("File_Konsultasi2.dat","File_Konsultasi.dat");
}
int masuk_pasien(){																				//Success
	int pil;
	system("cls");
	printf("Selamat Datang di Login Pasien\n");
	printf("(1).Registrasi	- Untuk pengguna baru\n");
	printf("(2).Login 	- Untuk pengguna yang sudah punya akun\n");
	printf("Pilihan: ");scanf("%d",&pil);
	getchar();
	switch(pil){
		case 1:{
			reg_pasien();
			break;
		}
		case 2:{
			login_pasien();
			break;
		}
		default :{masuk_pasien();}
	}
	menu_pasien();
}
int reg_pasien(){																				//Success
	system("cls");
	FILE *f_jasa;
	struct akun{
		char uname[50],pass[50];
		char nama[50],tgl_lahir[50],tmp_lahir[50];
		};
	struct akun write;	
	f_jasa=fopen("File_pasien","ab");
	printf("=== MENU REGISTRASI PASIEN ===\n");
	printf("Masukkan Username dan Password anda\n");
	printf("Username: ");gets(write.uname);
	printf("Pass:");gets(write.pass);
	printf("Username dan Password anda berhasil didaftarkan\n");
	
	printf("Silahkan lengkapi Data Diri anda\n");
	printf("Nama Lengkap: ");gets(write.nama);
	printf("Tanggal Lahir: ");gets(write.tgl_lahir);
	printf("Tempat Lahir: ");gets(write.tmp_lahir);
	
	fwrite(&write,sizeof(write),1,f_jasa);
	fclose(f_jasa);
	
	masuk_pasien();
}
int login_pasien(){																				//Success
	system("cls");
	FILE *f_jasa;
	struct akun{
		char uname[50],pass[50];
		};
		
	struct akun read, cek;
	printf("=== MENU LOGIN PASIEN ===\n");	
	printf("Masukkan Username anda: \n");gets(cek.uname);
	printf("Masukkan Password anda: \n");gets(cek.pass);
	
	f_jasa=fopen("File_pasien","rb");
	while(fread(&read,sizeof(read),1,f_jasa) == 1){
		if(strcmp(read.uname,cek.uname)==0 && strcmp(read.pass,cek.pass)==0){
			printf("Login berhasil\n");
			printf("Selamat datang %s\n",read.uname);
			fclose(f_jasa);
			system("pause");
			break;
		}else{
			printf("Login gagal\nSilahkan Coba Lagi\n");
			fclose(f_jasa);
			masuk_pasien();
			break;
		} 
	}	
}
int menu_pasien(){																				//Success
		int pil;
	
	system("cls");
	printf("Selamat datang untuk PASIEN\n");
	printf("Silahkan pilih Menu: \n");
	printf("(1).Beli Obat\n");
	printf("(2).Konsultasi\n");																	
	printf("(3).Lihat Riwayat Transaksi\n");
	printf("Pilihan: ");scanf("%d",&pil);
	getchar();
	switch(pil){
		case 1:{
			system("cls");
			printf("Silahkan Lihat Obat yang akan dibeli\n");
			daftar_obat();
			system("pause");
			beli_obat();
			break;
		}
		case 2:{
			system("cls");
			daftar_konsul();
			system("pause");
			pesan_konsul();
			break;
		}
		case 3:{
			system("cls");
			riwayat();
			break;
		}
	}	
}
int beli_obat(){																				//Success
	FILE* f_jasa;
	
	struct data{
		char nama[50],obat[50],tgl[50];
		int banyak;
	}struk;
	f_jasa=fopen("File_strukobat.dat","ab");
	
	printf("\n\nSilahkan isi Data berikut!!\n");
	printf("Nama Anda: ");gets(struk.nama);
	printf("Tanggal Pembelian(dd-mm-yyyy): ");gets(struk.tgl);
	printf("Obat yang dibeli: ");gets(struk.obat);
	printf("Banyaknya obat dibeli: ");scanf("%d",&struk.banyak);
	getchar();
	printf("Anda berhasil melakukan Pembelian!!\n");
	printf("Silahkan datang lagi! :) \n");
	system("pause");
	fwrite(&struk,sizeof(struk),1,f_jasa);
	fclose(f_jasa);
	menu_pasien();
}
int pesan_konsul(){																				//Success
	FILE* f_jasa;
	
	struct data{
		char nama[50],tema[50],tgl[50],tglk[50],waktu[10];
	}struk;
	f_jasa=fopen("File_strukkonsul.dat","ab");
	
	printf("Silahkan isi Data berikut!!\n");
	printf("Nama Anda: ");gets(struk.nama);
	printf("Tanggal Pemesanan(dd-mm-yyyy): ");gets(struk.tgl);
	printf("Konsultasi yang dipesan: ");gets(struk.tema);
	printf("Waktu Konsultasi (hh-mm): ");gets(struk.waktu);
	printf("Tanggal Konsultasi(dd-mm-yyyy):");gets(struk.tglk);
	printf("Anda berhasil melakukan Pembelian!!\n");
	printf("Silahkan datang lagi! :) \n");
	
	fwrite(&struk,sizeof(struk),1,f_jasa);
	fclose(f_jasa);
	system("pause");
	menu_pasien();
}
int riwayat(){																					//Success
	int pil;
	
	printf("Anda akan melihat riwayat transaksi Anda....\n");
	printf("(1).Riwayat pembelian obat\n");
	printf("(2).Riwayat pemesanan Jasa Konsultasi\n");
	printf("Pilihan anda: ");scanf("%d",&pil);
	getchar();
	switch(pil){
		case 1:{
			struk_obat();
			break;
		}
		case 2:{
			struk_konsul();
			break;
		}
	}
}
int struk_obat(){																				//Success
	FILE *f_jasa;
	
	struct data{
		char nama[50],obat[50],tgl[50];
		int banyak;
	}struk;
	int i=1;
	
	f_jasa=fopen("File_strukobat.dat","rb");
	while(fread(&struk,sizeof(struk),1,f_jasa) == 1){
		printf("--------------------------------------------------\n");
		printf("%d.\t Nama pembeli\t\t\t:%s\n",i,struk.nama);
		printf("\t Tanggal Pemelian\t\t:%s\n",struk.tgl);
		printf("\t Obat yang Dibeli\t\t:%s\n",struk.obat);
		printf("\t Banyak obat yang dibeli\t:%d pcs\n",struk.banyak);
		i++;
}
	fclose(f_jasa);
}
int struk_konsul(){																				//Success
	FILE *f_jasa;
	
struct data{
	
		char nama[50],tema[50],tgl[50],tglk[50],waktu[10];
	}struk;
	int i=1;
	
	f_jasa=fopen("File_strukkonsul.dat","rb");
	while(fread(&struk,sizeof(struk),1,f_jasa) == 1){
		printf("--------------------------------------------------\n");
		printf("%d.\t Nama pemesan\t\t\t:%s\n",i,struk.nama);
		printf("\t Tanggal pemesanan\t\t:%s\n",struk.tgl);
		printf("\t Konsultasi yang dipilih\t:%s\n",struk.tema);
		printf("\t Tanggal Konsultasi\t\t:%s\n",struk.tglk);
		printf("\t Waktu Konsultasi\t\t:%s\n",struk.waktu);
		i++;
}
	fclose(f_jasa);
}
