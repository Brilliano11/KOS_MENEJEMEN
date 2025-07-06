#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <ctime>

using namespace std;

class User {
public:
    string username;
    string password;
};

class Penyewa {
	
public:
    string nama;
    string noTelp;
    int noKamar;
    string statusBayar;
    bool terisi;

    Penyewa() {
        nama = "Kosong";
        noTelp = "0";
        noKamar = 0;
        statusBayar = "Belum Lunas";
        terisi = false;
    }
    
};

class Kos {
	
private:
    Penyewa kamar[15];
    const string FILE_KAMAR;
    const string FILE_USERS;
    const string FILE_HISTORI;

    string getTipeKamar(int noKamar) {
    	
        if (noKamar >= 1 && noKamar <= 5) return "Reguler";
        
        if (noKamar >= 6 && noKamar <= 10) return "VIP";
        
        if (noKamar >= 11 && noKamar <= 15) return "Premium";
        
        return "N/A";
    }

    int getHargaKamar(int noKamar) {
    	
        if (noKamar >= 1 && noKamar <= 5) return 500000;
        
        if (noKamar >= 6 && noKamar <= 10) return 800000;
        
        if (noKamar >= 11 && noKamar <= 15) return 1200000;
        
        return 0;
        
    }

    void bubbleSortPenyewa(Penyewa arr[], int n, string sortBy) {
        for (int i = 0; i < n - 1; i++) {
        	
            for (int j = 0; j < n - i - 1; j++) {
                bool harusTukar = false;
                if (sortBy == "nama") {
                    if (arr[j].nama > arr[j + 1].nama) harusTukar = true;
                } else if (sortBy == "status") {
                    if (arr[j].statusBayar > arr[j + 1].statusBayar) harusTukar = true;
                }
                if (harusTukar) {
                    Penyewa temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

public:
    Kos() : FILE_KAMAR("data_kos.txt"), FILE_USERS("users.txt"), FILE_HISTORI("histori_penyewa.txt") {
        for (int i = 0; i < 15; ++i) {
            kamar[i].noKamar = i + 1;
        }
        muatDataKamar();
    }
    
    void tampilkanHeader() {
    	
        cout << endl;
        
        cout << endl;
        
        cout << "==============================================================================================" << endl;
        
     	cout << " K   K  OOOOO  SSSSS      K   K  OOOOO  SSSSS   M   M    AA    N   N " << endl;
        cout << " K  K  O     O S          K  K  O     O S       MM MM   A  A   NN  N " << endl;
        cout << " KKK   O     O  SSSSS     KKK   O     O  SSSSS  M M M  AAAAAA  N N N " << endl;
        cout << " K  K  O     O      S     K  K  O     O      S  M   M  A    A  N  NN" << endl;
        cout << " K   K  OOOOO  SSSSS      K   K  OOOOO  SSSSS   M   M  A    A  N   N " << endl;
        
        cout << "==============================================================================================" << endl;
  
    }

    void tampilkanTentangProgram() {
        cout << endl;
        cout << "========================================" << endl;
        cout << "          TENTANG PROGRAM INI           " << endl;
        cout << "========================================" << endl;
        cout << endl;
        cout << " Program   : Sistem Manajemen Kos Kosman" << endl;
        cout << endl;
        cout << " Versi     : 1.0 Final" << endl;
        cout << endl;
        cout << " Dibuat    : 2024" << endl;
        cout << endl;
        cout << " Deskripsi : Aplikasi konsol sederhana untuk" << endl;
        cout << "             mengelola data penyewa, kamar," << endl;
        cout << "             dan keuangan sebuah kos." << endl;
        cout << endl;
        cout << "========================================" << endl;
        cout << endl;
    }


    void tampilkanMenu() {
    	
        cout << endl;
        cout << "+------------------------------------------+" << endl;
        cout << "|                                          |" << endl;
        cout << "|           M E N U   U T A M A            |" << endl;
        cout << "|                                          |" << endl;
        cout << "+------------------------------------------+" << endl;
        cout << "|                                          |" << endl;
        cout << "|   1.  Tambah Penyewa Baru                |" << endl;
        cout << "|                                          |" << endl;
        cout << "|   2.  Lihat Status Semua Kamar           |" << endl;
        cout << "|                                          |" << endl;
        cout << "|   3.  Cari & Filter Data Penyewa         |" << endl; 
        cout << "|                                          |" << endl;
        cout << "|   4.  Update Status Pembayaran           |" << endl;
        cout << "|                                          |" << endl;
        cout << "|   5.  Check-out & Hapus Data Penyewa     |" << endl;
        cout << "|                                          |" << endl;
        cout << "|   6.  Lihat Fasilitas Kamar              |" << endl;
        cout << "|                                          |" << endl;
        cout << "|   7.  Laporan Keuangan                   |" << endl;
        cout << "|                                          |" << endl;
        cout << "|   8.  Tampilkan Daftar Penyewa (Urutkan) |" << endl;
        cout << "|                                          |" << endl;
        cout << "|   9.  Lihat Histori Penyewa              |" << endl;
        cout << "|                                          |" << endl;
        cout << "+------------------------------------------+" << endl;
        cout << "|                                          |" << endl;
        cout << "|   0.  Logout & Keluar                    |" << endl;
        cout << "|                                          |" << endl;
        cout << "+------------------------------------------+" << endl;
        cout << endl;
        cout << "--> Masukkan Pilihan Anda (0-9): ";
        
    }
    

    bool login() {
    	
        ifstream fileCek(FILE_USERS.c_str());
        
        if (!fileCek.is_open()) {
            ofstream fileBuat(FILE_USERS.c_str());
            if (fileBuat.is_open()) {
                fileBuat << "admin admin" << endl;
                fileBuat.close();
                cout << "Info: File user tidak ditemukan. Akun default 'admin' dengan password 'admin' telah dibuat." << endl;
            }
            
        }
        
        fileCek.close();

        int percobaan = 0;
        
        while (percobaan < 3) {
        	
            string username, password;
            
            cout << endl;
            
            cout << "+------------------------------------------+" << endl;
            cout << "|       S I L A H K A N   L O G I N        |" << endl;
            cout << "+------------------------------------------+" << endl;
            cout << "   Username: ";
            cin >> username;
            cout << "   Password: ";
            cin >> password;
            cout << "+------------------------------------------+" << endl;
            
            cout << endl;
            
            ifstream file(FILE_USERS.c_str());
            string u, p;
            bool ditemukan = false;
            while (file >> u >> p) {
                if (u == username && p == password) {
                    ditemukan = true;
                    break;
                }
                
            }
            
            
            file.close();

            if (ditemukan) {
                cout << "   Login berhasil! Selamat datang, " << username << "!" << endl;
                system("cls");
                return true;
            } else {
                cout << "   Username atau password salah." << endl;
                percobaan++;
                if (percobaan < 3) {
                    cout << "   Sisa percobaan: " << 3 - percobaan << endl;
                }
                system("cls");
            }
        }
        
        cout << "   Anda telah gagal login 3 kali. Program akan keluar." << endl;
        return false;
        
    }
    

    void tambahPenyewa() {
        int no;
        cout << endl;
        cout << "========================================" << endl;
        cout << "          TAMBAH PENYEWA BARU           " << endl;
        cout << "========================================" << endl;
        cout << endl;
        cout << "Masukkan nomor kamar (1-15): ";
        cin >> no;
        cout << endl;

        if (no < 1 || no > 15) {
            cout << "Nomor kamar tidak valid!" << endl;
            return;
        }

        int index = no - 1;
        
        if (kamar[index].terisi) {
            cout << "Kamar " << no << " sudah terisi oleh " << kamar[index].nama << "." << endl;
            
        } else {
            cout << "Masukkan nama penyewa: ";
            cin.ignore();
            getline(cin, kamar[index].nama);
            cout << endl;
            cout << "Masukkan nomor telepon: ";
            getline(cin, kamar[index].noTelp);
            cout << endl;
            kamar[index].terisi = true;
            kamar[index].statusBayar = "Belum Lunas";
            cout << "----------------------------------------" << endl;
            cout << "Penyewa baru berhasil ditambahkan." << endl;
            cout << "----------------------------------------" << endl;
            simpanDataKamar();
            
        }
        
    
	}
    

    void lihatStatusKamar() {
    	
        cout << endl;
        cout << "===================================================================" << endl;
        cout << "                       STATUS SEMUA KAMAR                          " << endl;
        cout << "===================================================================" << endl;
        cout << endl;
        cout << left << setw(10) << "No Kamar" << setw(15) << "Tipe" << setw(15) << "Harga" << setw(15) << "Status" << setw(15) << "Penghuni" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        for (int i = 0; i < 15; ++i) {
            cout << left << setw(10) << kamar[i].noKamar
                 << setw(15) << getTipeKamar(kamar[i].noKamar)
                 << "Rp " << setw(11) << getHargaKamar(kamar[i].noKamar)
                 << setw(15) << (kamar[i].terisi ? "Terisi" : "Kosong")
                 << setw(15) << (kamar[i].terisi ? kamar[i].nama : "-") << endl;
        }
        cout << "===================================================================" << endl;
        cout << endl;
        
    }

    
    
    void lihatDataPenyewa() {
        int pilihan;
        
        cout << endl;
        cout << "========================================" << endl;
        cout << "        CARI & FILTER DATA PENYEWA      " << endl;
        cout << "========================================" << endl;
        cout << endl;
        cout << "1. Cari berdasarkan Nomor Kamar (Binary Search)" << endl;
        cout << endl;
        cout << "2. Cari berdasarkan Nama (Linear Search)" << endl;
        cout << endl;
        cout << "3. Filter berdasarkan Status Bayar (Linear Search)" << endl;
        cout << "----------------------------------------" << endl;
        cout << endl;
        cout << "Pilih metode: ";
        cin >> pilihan;
        cout << endl;

        if (pilihan == 1) {
            int noKamarCari;
            
            cout << "Masukkan nomor kamar yang dicari: ";
            cin >> noKamarCari;
            int index = cariKamarBinary(noKamarCari);

            if (index != -1 && kamar[index].terisi) {
                cout << endl;
                cout << "=============== DATA DITEMUKAN ===============" << endl;
                cout << endl;
                cout << "  No Kamar     : " << kamar[index].noKamar << endl;
                cout << endl;
                cout << "  Nama         : " << kamar[index].nama << endl;
                cout << endl;
                cout << "  No Telepon   : " << kamar[index].noTelp << endl;
                cout << endl;
                cout << "  Status Bayar : " << kamar[index].statusBayar << endl;
                cout << endl;
                cout << "==============================================" << endl;
            } else {
                cout << "Kamar " << noKamarCari << " kosong atau tidak ditemukan." << endl;
            }
        } else if (pilihan == 2) {
            string namaCari;
            cout << "Masukkan nama yang dicari: ";
            cin.ignore();
            getline(cin, namaCari);
            int index = cariPenyewaLinear(namaCari);
            
            if (index != -1) {
                cout << endl;
                cout << "=============== DATA DITEMUKAN ===============" << endl;
                cout << endl;
                cout << "  No Kamar     : " << kamar[index].noKamar << endl;
                cout << endl;
                cout << "  Nama         : " << kamar[index].nama << endl;
                cout << endl;
                cout << "  No Telepon   : " << kamar[index].noTelp << endl;
                cout << endl;
                cout << "  Status Bayar : " << kamar[index].statusBayar << endl;
                cout << endl;
                cout << "==============================================" << endl;
            } else {
               
			    cout << "Penyewa dengan nama '" << namaCari << "' tidak ditemukan." << endl;
            }
        } else if (pilihan == 3) {
            tampilkanPenyewaByStatus(); 
        
		} else {
            cout << "Pilihan tidak valid." << endl;
       
	    }
    }

    void updateStatusBayar() {
        int noKamar;
        
        cout << endl;
        cout << "========================================" << endl;
        cout << "        UPDATE STATUS PEMBAYARAN        " << endl;
        cout << "========================================" << endl;
        cout << endl;
        
        cout << "Masukkan nomor kamar: ";
        cin >> noKamar;

        int index = cariKamarBinary(noKamar);
        
        if (index != -1 && kamar[index].terisi) {
            int status;
            cout << endl;
            cout << "Penyewa         : " << kamar[index].nama << endl;
            cout << "Status saat ini : " << kamar[index].statusBayar << endl;
            cout << "----------------------------------------" << endl;
            cout << "Ubah status menjadi: (1: Lunas, 2: Belum Lunas): ";
            cin >> status;
            if (status == 1) {
                kamar[index].statusBayar = "Lunas";
                cout << endl;
                cout << "Status pembayaran berhasil diubah menjadi Lunas." << endl;
            } else if (status == 2) {
                kamar[index].statusBayar = "Belum Lunas";
                cout << endl;
                cout << "Status pembayaran berhasil diubah menjadi Belum Lunas." << endl;
            } else {
                cout << endl;
                cout << "Pilihan tidak valid." << endl;
                return;
            }
            simpanDataKamar();
        } else {
            cout << "Kamar " << noKamar << " kosong atau tidak valid." << endl;
        }
    }

    void hapusDataPenyewa() {
        int no;
        cout << endl;
        cout << "========================================" << endl;
        cout << "            CHECK-OUT PENYEWA           " << endl;
        cout << "========================================" << endl;
        cout << endl;
        cout << "Masukkan nomor kamar penyewa yang akan check-out: ";
        cin >> no;

        if (no < 1 || no > 15) {
            cout << "Nomor kamar tidak valid!" << endl;
            return;
        }

        int index = no - 1;
        if (kamar[index].terisi) {
            cout << "Anda akan check-out '" << kamar[index].nama << "' dari kamar " << no << "." << endl;
            cout << endl;
            cout << "Apakah Anda yakin? (y/n): ";
            char konfirmasi;
            cin >> konfirmasi;
            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                ofstream fileHistori(FILE_HISTORI.c_str(), ios::app);
                if (fileHistori.is_open()) {
                    time_t now = time(0);
                    char* dt = ctime(&now);
                    string waktuCheckout = dt;
                    waktuCheckout.erase(waktuCheckout.find_last_not_of(" \n\r\t")+1);
                    
                    fileHistori << kamar[index].noKamar << " " << kamar[index].nama << " " << kamar[index].noTelp << " " << waktuCheckout << endl;
                    fileHistori.close();
                }

                kamar[index] = Penyewa();
                kamar[index].noKamar = no;
                cout << endl;
                cout << "----------------------------------------" << endl;
                cout << "Penyewa berhasil di-checkout." << endl;
                cout << "Data tersimpan di histori." << endl;
                cout << "----------------------------------------" << endl;
                simpanDataKamar();
                
            } else {
                cout << endl;
                cout << "Check-out dibatalkan." << endl;
            }
            
        } else {
            cout << "Kamar " << no << " memang sudah kosong." << endl;
        }
        
    }
    

    void fasilitasKamar() {
        cout << endl;
        cout << "==================================================" << endl;
        cout << endl;
        cout << "           INFORMASI FASILITAS KAMAR              " << endl;
        cout << endl;
        cout << "==================================================" << endl;
        
        cout << endl;
        
        cout << endl;
        
        cout << endl;
        
        cout << "    [Tipe Reguler (Kamar 1-5)      ]" << endl;
        cout << "------------------------------------" << endl;
        cout << endl;
        cout << "1.  Kasur Single Size (90x200 cm)" << endl;
        cout << endl;
        cout << "2.  Satu Buah Bantal Kepala" << endl;
        cout << endl;
        cout << "3.  Satu Buah Guling" << endl;
        cout << endl;
        cout << "4.  Sprei Bahan Katun" << endl;
        cout << endl;
        cout << "5.  Lemari Pakaian 2 Pintu" << endl;
        cout << endl;
        cout << "6.  Meja Belajar Kayu" << endl;
        cout << endl;
        cout << "7.  Kursi Belajar Plastik" << endl;
        cout << endl;
        cout << "8.  Kamar Mandi Luar (Shared)" << endl;
        cout << endl;
        cout << "9.  Satu Buah Ember" << endl;
        cout << endl;
        cout << "10. Satu Buah Gayung" << endl;
        cout << endl;
        cout << "11. Gantungan Baju di Dinding" << endl;
        cout << endl;
        cout << "12. Satu Titik Lampu Penerangan" << endl;
        cout << endl;
        cout << "13. Lampu LED 7 Watt" << endl;
        cout << endl;
        cout << "14. Dua Buah Stopkontak" << endl;
        cout << endl;
        cout << "15. Jendela dengan Teralis" << endl;
        cout << endl;
        cout << "16. Gorden Penutup Jendela" << endl;
        cout << endl;
        cout << "17. Lantai Keramik 30x30 cm" << endl;
        cout << endl;
        cout << "18. Dinding Cat Warna Putih" << endl;
        cout << endl;
        cout << "19. Cermin Dinding Kecil" << endl;
        cout << endl;
        cout << "20. Tempat Sampah Kecil" << endl;
        cout << endl;
        cout << "21. Akses Kunci Pintu Kamar" << endl;
        cout << endl;
        cout << "22. Akses Kunci Gerbang Utama" << endl;
        cout << endl;
        cout << "23. Listrik Token (exclude)" << endl;
        cout << endl;
        cout << "24. Air Bersih (include)" << endl;
        cout << endl;
        cout << "25. Area Parkir Motor" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        
        cout << endl;
        cout << endl;
        cout << "       [Tipe VIP (Kamar 6-10)]      " << endl;
        
        cout << "------------------------------------" << endl;
        cout << endl;
        cout << "1.  Kasur Queen Size (160x200 cm)" << endl;
        cout << endl;
        cout << "2.  Dua Buah Bantal Kepala" << endl;
        cout << endl;
        cout << "3.  Dua Buah Guling" << endl;
        cout << endl;
        cout << "4.  Sprei Katun Jepang" << endl;
        cout << endl;
        cout << "5.  Lemari Pakaian 2 Pintu dengan Cermin" << endl;
        cout << endl;
        cout << "6.  Meja Rias & Belajar" << endl;
        cout << endl;
        cout << "7.  Kursi Belajar Busa" << endl;
        cout << endl;
        cout << "8.  Kamar Mandi Dalam" << endl;
        cout << endl;
        cout << "9.  Shower" << endl;
        cout << endl;
        cout << "10. Kloset Duduk" << endl;
        cout << endl;
        cout << "11. Air Conditioner (AC) 1/2 PK" << endl;
        cout << endl;
        cout << "12. Remote AC" << endl;
        cout << endl;
        cout << "13. Dua Titik Lampu Penerangan" << endl;
        cout << endl;
        cout << "14. Lampu LED 10 Watt" << endl;
        cout << endl;
        cout << "15. Empat Buah Stopkontak" << endl;
        cout << endl;
        cout << "16. Jendela Kaca Besar" << endl;
        cout << endl;
        cout << "17. Gorden Blackout" << endl;
        cout << endl;
        cout << "18. Lantai Keramik 40x40 cm" << endl;
        cout << endl;
        cout << "19. Dinding Cat Warna Krem" << endl;
        cout << endl;
        cout << "20. Cermin Full Body" << endl;
        cout << endl;
        cout << "21. Tempat Sampah Dalam Ruangan" << endl;
        cout << endl;
        cout << "22. Akses Kunci Pintu Kamar (Card Access)" << endl;
        cout << endl;
        cout << "23. Listrik Bulanan (include, batas wajar)" << endl;
        cout << endl;
        cout << "24. Air Bersih (include)" << endl;
        cout << endl;
        cout << "25. WiFi Kecepatan Up To 50 Mbps" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        
        cout << endl;
        cout << endl;
        cout << "    [Tipe Premium (Kamar 11-15)]       " << endl;
        cout << "---------------------------------------" << endl;
        cout << endl;
        cout << "1.  Kasur King Size (180x200 cm) Springbed" << endl;
        cout << endl;
        cout << "2.  Empat Buah Bantal Kualitas Hotel" << endl;
        cout << endl;
        cout << "3.  Dua Buah Guling Premium" << endl;
        cout << endl;
        cout << "4.  Sprei & Bed Cover" << endl;
        cout << endl;
        cout << "5.  Lemari Pakaian 3 Pintu Sliding" << endl;
        cout << endl;
        cout << "6.  Meja Kerja Ergonomis" << endl;
        cout << endl;
        cout << "7.  Kursi Kerja Ergonomis" << endl;
        cout << endl;
        cout << "8.  Kamar Mandi Dalam dengan Partisi Kaca" << endl;
        cout << endl;
        cout << "9.  Shower Air Panas & Dingin (Water Heater)" << endl;
        cout << endl;
        cout << "10. Kloset Duduk Eco-washer" << endl;
        cout << endl;
        cout << "11. Air Conditioner (AC) 1 PK Inverter" << endl;
        cout << endl;
        cout << "12. Smart TV 32 inch" << endl;
        cout << endl;
        cout << "13. Langganan Netflix & Disney+" << endl;
        cout << endl;
        cout << "14. Kulkas Mini Bar" << endl;
        cout << endl;
        cout << "15. Enam Buah Stopkontak" << endl;
        cout << endl;
        cout << "16. Jendela Kaca Kedap Suara" << endl;
        cout << endl;
        cout << "17. Gorden & Vitrase" << endl;
        cout << endl;
        cout << "18. Lantai Vinyl Motif Kayu" << endl;
        cout << endl;
        cout << "19. Dinding Wallpaper" << endl;
        cout << endl;
        cout << "20. Cermin Estetik dengan Lampu LED" << endl;
        cout << endl;
        cout << "21. Layanan Kebersihan Kamar (Mingguan)" << endl;
        cout << endl;
        cout << "22. Akses Kunci Pintu Kamar (Smart Lock)" << endl;
        cout << endl;
        cout << "23. Listrik Bulanan (include)" << endl;
        cout << endl;
        cout << "24. Air Minum Galon (Isi Ulang)" << endl;
        cout << endl;
        cout << "25. WiFi Prioritas Kecepatan Up To 100 Mbps" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
    }

    void laporanKeuangan() {
        long totalPemasukan = 0, potensiPemasukan = 0;
        int jumlahLunas = 0, jumlahBelumLunas = 0, kamarTerisi = 0;

        for (int i = 0; i < 15; ++i) {
            if (kamar[i].terisi) {
                kamarTerisi++;
                potensiPemasukan += getHargaKamar(kamar[i].noKamar);
                
                if (kamar[i].statusBayar == "Lunas") {
                    totalPemasukan += getHargaKamar(kamar[i].noKamar);
                    jumlahLunas++;
                } else {
                    jumlahBelumLunas++;
                }
                
            }
            
        }
        

        cout << endl;
        cout << "========================================" << endl;
        cout << "        LAPORAN KEUANGAN BULANAN        " << endl;
        cout << "========================================" << endl;
        
        cout << endl;
        cout << "Total Kamar Terisi    : " << kamarTerisi << "/15" << endl;
        cout << endl;
        cout << "Jumlah Sudah Bayar    : " << jumlahLunas << " penyewa" << endl;
        cout << endl;
        cout << "Jumlah Belum Bayar    : " << jumlahBelumLunas << " penyewa" << endl;
        
        cout << "----------------------------------------" << endl;
        
        cout << endl;
        cout << "Pemasukan Diterima    : Rp " << totalPemasukan << endl;
        cout << endl;
        cout << "Potensi Pemasukan     : Rp " << potensiPemasukan << endl;
        
		cout << endl;
        
		cout << "========================================" << endl;
        
		cout << endl;
        
    }
    
    void tampilkanDaftarTerurut() {
        Penyewa penyewaTerisi[15];
        int jumlahTerisi = 0;
        
        for (int i = 0; i < 15; i++) {
        	
            if (kamar[i].terisi) {
                penyewaTerisi[jumlahTerisi++] = kamar[i];
            }
            
        }
        
        if (jumlahTerisi == 0) {
            cout << "\nBelum ada penyewa di dalam kos." << endl;
            return;
            
        }

        int pilihan;
        
        cout << endl;
        cout << "========================================" << endl;
        cout << "      TAMPILKAN DAFTAR TERURUT          " << endl;
        cout << "========================================" << endl;
       
	    cout << endl;
        cout << "1. Urutkan berdasarkan Nama (A-Z)" << endl;
        cout << endl;
        cout << "2. Urutkan berdasarkan Status Pembayaran" << endl;
        cout << endl;
        
		cout << "Pilih tipe urutan: ";
        cin >> pilihan;

        string sortBy = (pilihan == 1) ? "nama" : (pilihan == 2) ? "status" : "";
        if (sortBy.empty()) {
            cout << "Pilihan tidak valid." << endl;
            return;
        }

        bubbleSortPenyewa(penyewaTerisi, jumlahTerisi, sortBy);

        cout << endl;
        cout << "=========== DAFTAR PENYEWA TERURUT ===========" << endl;
        cout << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << left << setw(10) << "No Kamar" << setw(20) << "Nama" << setw(20) << "Status Bayar" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << endl;
        for (int i = 0; i < jumlahTerisi; i++) {
            cout << left << setw(10) << penyewaTerisi[i].noKamar << setw(20) << penyewaTerisi[i].nama << setw(20) << penyewaTerisi[i].statusBayar << endl;
            cout << endl;
        }
        
        cout << "----------------------------------------------------------------" << endl;
        cout << "================================================================" << endl;
        cout << endl;
        
    }

    void lihatHistoriPenyewa() {
    	
        cout << endl;
        cout << "==================================================================================" << endl;
        cout << "                   HISTORI PENYEWA YANG PERNAH CHECK-OUT                          " << endl;
        cout << "==================================================================================" << endl;
        cout << endl;
        
        ifstream file(FILE_HISTORI.c_str());
        
        if (!file.is_open() || file.peek() == ifstream::traits_type::eof()) {
            cout << "                       Belum ada data histori.                                " << endl;
            cout << "==================================================================================" << endl;
            return;
            
        }
        
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << left << setw(10) << "No Kamar" << setw(20) << "Nama" << setw(15) << "No. Telp" << "Waktu Check-out" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << endl;
        
        int noKamar;
        string nama, noTelp, baris;
        while (file >> noKamar >> nama >> noTelp && getline(file, baris)) {
        	
            for(size_t j = 0; j < nama.length(); ++j) if(nama[j] == '_') nama[j] = ' ';
            cout << left << setw(10) << noKamar << setw(20) << nama << setw(15) << noTelp << baris << endl;
            cout << endl;
        }
        
        cout << "==================================================================================" << endl;
        cout << endl;
        
        file.close();
        
    }
    
    void tampilkanPenyewaByStatus() {
        int pilihan;
        
        cout << "Pilih status untuk difilter:" << endl;
        cout << "1. Lunas" << endl;
        cout << "2. Belum Lunas" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        string statusCari;
        
        if (pilihan == 1) {
            statusCari = "Lunas";
        } else if (pilihan == 2) {
            statusCari = "Belum Lunas";
        } else {
            cout << "Pilihan tidak valid." << endl;
            return;
        }
        
        cout << endl;
        cout << "====== DAFTAR PENYEWA DENGAN STATUS '" << statusCari << "' ======" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << left << setw(10) << "No Kamar" << setw(25) << "Nama" << setw(15) << "No. Telepon" << endl;
        cout << "----------------------------------------------------------" << endl;

        bool ditemukan = false;

        for (int i = 0; i < 15; i++) {
            if (kamar[i].terisi && kamar[i].statusBayar == statusCari) {
                cout << left << setw(10) << kamar[i].noKamar 
                     << setw(25) << kamar[i].nama 
                     << setw(15) << kamar[i].noTelp << endl;
                ditemukan = true;
            }
        }
        
        if (!ditemukan) {
            cout << "Tidak ada penyewa dengan status '" << statusCari << "'." << endl;
        }
        cout << "----------------------------------------------------------" << endl;
    }

    int cariKamarBinary(int noKamar) {
    	
        int kiri = 0;
        int kanan = 14;
        
        while (kiri <= kanan) {
        	
            int tengah = kiri + (kanan - kiri) / 2;
            
            if (kamar[tengah].noKamar == noKamar) {
            	
                return tengah;
            }
            if (kamar[tengah].noKamar < noKamar) {
            	
                kiri = tengah + 1;
            } else {
            	
                kanan = tengah - 1;
            }
        }
        
        return -1;
    }

    int cariPenyewaLinear(string nama) {
        for (int i = 0; i < 15; ++i) if (kamar[i].terisi && kamar[i].nama == nama) return i;
        return -1;
        
    }

    void simpanDataKamar() {
        ofstream file(FILE_KAMAR.c_str());
        if (!file.is_open()) return;
        for (int i = 0; i < 15; ++i) {
            string namaSimpan = kamar[i].nama;
            for(size_t j = 0; j < namaSimpan.length(); ++j) if(namaSimpan[j] == ' ') namaSimpan[j] = '_';
            file << kamar[i].noKamar << " " << namaSimpan << " " << kamar[i].noTelp << " " << kamar[i].statusBayar << " " << kamar[i].terisi << endl;
        }
        
        file.close();
        
    }

    void muatDataKamar() {
    	
        ifstream file(FILE_KAMAR.c_str());
        if (!file.is_open()) {
            simpanDataKamar();
            return;
        }
        int i = 0;
        while (i < 15 && file >> kamar[i].noKamar >> kamar[i].nama >> kamar[i].noTelp >> kamar[i].statusBayar >> kamar[i].terisi) {
            for(size_t j = 0; j < kamar[i].nama.length(); ++j) if(kamar[i].nama[j] == '_') kamar[i].nama[j] = ' ';
            i++;
        }
        
        file.close();
        
    }
    
};

int main() {
    Kos kosanKu;
    
    kosanKu.tampilkanHeader();

    if (kosanKu.login()) {
        int pilihan;
        do {
        	
            kosanKu.tampilkanMenu();
            cin >> pilihan;

            if (cin.fail()) {
            	
                cin.clear();
                cin.ignore(10000, '\n');
                pilihan = -1;
                
            }
            
            system("cls");
            kosanKu.tampilkanHeader();

            switch (pilihan) {
            	
                case 1:
                	
                    kosanKu.tambahPenyewa();
                    
                    break;
                    
                case 2:
                	
                    kosanKu.lihatStatusKamar();
                    
                    break;
                    
                case 3:
                    kosanKu.lihatDataPenyewa();
                    
                    break;
                    
                case 4:
                	
                    kosanKu.updateStatusBayar();
                    
                    break;
                    
                case 5:
                	
                    kosanKu.hapusDataPenyewa();
                    
                    break;
                    
                case 6:
                	
                    kosanKu.fasilitasKamar();
                    
                    break;
                    
                case 7:
                	
                    kosanKu.laporanKeuangan();
                    
                    break;
                    
                case 8:
                	
                    kosanKu.tampilkanDaftarTerurut();
                    
                    break;
                    
                case 9:
                	
                    kosanKu.lihatHistoriPenyewa();
                    
                    break;
                    
                case 0:
                	
                    kosanKu.tampilkanTentangProgram();
                    cout << "Logout berhasil. Program keluar..." << endl;
                    cout << endl;
                    
                    break;
                    
                default:
                	
                    cout << endl;
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                    cout << endl;
                    
                    break;
            }
            
            if (pilihan != 0) {
                cout << endl;
                cout << "Tekan Enter untuk kembali ke menu...";
                cin.ignore();
                cin.get();
                system("cls");
            }
            
        }
		
		 while (pilihan != 0);
        
    }

    return 0;
}
