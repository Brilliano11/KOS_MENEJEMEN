#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

class FasilitasKamar {
private:
    vector<string> fasilitas;
    string deskripsi;

public:
    FasilitasKamar() {}
    
    void tambahFasilitas(const string& fasilitasBaru) {
        fasilitas.push_back(fasilitasBaru);
    }
    
    void setDeskripsi(const string& desc) {
        deskripsi = desc;
    }
    
    string getDeskripsi() const {
        return deskripsi;
    }
    
    vector<string> getFasilitas() const {
        return fasilitas;
    }
    
    void clearFasilitas() {
        fasilitas.clear();
    }
    
    int getJumlahFasilitas() const {
        return fasilitas.size();
    }
};

class DataPembayaran {
private:
    string namaPenyewa;
    int nomorKamar;
    int jumlahBayar;
    string tanggalBayar;
    string metodeBayar;
    string keterangan;

public:
    DataPembayaran() {
        nomorKamar = 0;
        jumlahBayar = 0;
    }
    
    DataPembayaran(string nama, int kamar, int jumlah, string tanggal, string metode, string ket) {
        namaPenyewa = nama;
        nomorKamar = kamar;
        jumlahBayar = jumlah;
        tanggalBayar = tanggal;
        metodeBayar = metode;
        keterangan = ket;
    }
    
    void setNamaPenyewa(const string& nama) { namaPenyewa = nama; }
    void setNomorKamar(int kamar) { nomorKamar = kamar; }
    void setJumlahBayar(int jumlah) { jumlahBayar = jumlah; }
    void setTanggalBayar(const string& tanggal) { tanggalBayar = tanggal; }
    void setMetodeBayar(const string& metode) { metodeBayar = metode; }
    void setKeterangan(const string& ket) { keterangan = ket; }
    
    string getNamaPenyewa() const { return namaPenyewa; }
    int getNomorKamar() const { return nomorKamar; }
    int getJumlahBayar() const { return jumlahBayar; }
    string getTanggalBayar() const { return tanggalBayar; }
    string getMetodeBayar() const { return metodeBayar; }
    string getKeterangan() const { return keterangan; }
};

void header() {
    cout << "=======================================" << endl;
    cout << "      SISTEM PENGELOLAAN KOS" << endl;
    cout << "=======================================" << endl;
}

void garis() {
    cout << "---------------------------------------" << endl;
}

void pause() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void bersihLayar() {
    system("cls");
}

void menu() {
    cout << "\n======== MENU UTAMA ========" << endl;
    cout << "1. Tambah Penyewa Baru" << endl;
    cout << "2. Lihat Status Kamar" << endl;
    cout << "3. Lihat Data Penyewa" << endl;
    cout << "4. Update Status Bayar" << endl;
    cout << "5. Hapus Data Penyewa" << endl;
    cout << "6. Cari Data Penyewa" << endl;
    cout << "7. Fasilitas Kamar" << endl;
    cout << "8. Laporan Keuangan" << endl;
    cout << "9. Backup Data ke File" << endl;
    cout << "10. Pembayaran" << endl;
    cout << "11. Pengurutan Data" << endl;
    cout << "0. Keluar Program" << endl;
    cout << "=============================" << endl;
    cout << "Masukkan pilihan Anda: ";
}

void inisialisasiFasilitas(FasilitasKamar fasilitas[]) {
    // Fasilitas Kamar Reguler (1-5)
    for (int i = 1; i <= 5; i++) {
        fasilitas[i].clearFasilitas();
        fasilitas[i].tambahFasilitas("Kasur Single");
        fasilitas[i].tambahFasilitas("Lemari Kecil");
        fasilitas[i].tambahFasilitas("Meja Belajar");
        fasilitas[i].tambahFasilitas("Kursi");
        fasilitas[i].tambahFasilitas("Kamar Mandi Dalam");
        fasilitas[i].tambahFasilitas("Wi-Fi");
        fasilitas[i].tambahFasilitas("Stop Kontak");
        fasilitas[i].tambahFasilitas("Ventilasi");
        fasilitas[i].setDeskripsi("Kamar sederhana dengan fasilitas dasar yang memadai untuk mahasiswa");
    }
    
    // Fasilitas Kamar VIP (6-10)
    for (int i = 6; i <= 10; i++) {
        fasilitas[i].clearFasilitas();
        fasilitas[i].tambahFasilitas("Kasur Queen Size");
        fasilitas[i].tambahFasilitas("Lemari 2 Pintu");
        fasilitas[i].tambahFasilitas("Meja Belajar + Rak Buku");
        fasilitas[i].tambahFasilitas("Kursi Ergonomis");
        fasilitas[i].tambahFasilitas("Kamar Mandi Dalam + Water Heater");
        fasilitas[i].tambahFasilitas("AC");
        fasilitas[i].tambahFasilitas("Wi-Fi Premium");
        fasilitas[i].tambahFasilitas("TV 32 Inch");
        fasilitas[i].tambahFasilitas("Kulkas Mini");
        fasilitas[i].tambahFasilitas("Balkon Kecil");
        fasilitas[i].tambahFasilitas("Stop Kontak + USB Port");
        fasilitas[i].setDeskripsi("Kamar nyaman dengan AC dan fasilitas lengkap untuk kenyamanan maksimal");
    }
    
    // Fasilitas Kamar Premium (11-15)
    for (int i = 11; i <= 15; i++) {
        fasilitas[i].clearFasilitas();
        fasilitas[i].tambahFasilitas("Kasur King Size");
        fasilitas[i].tambahFasilitas("Walk-in Closet");
        fasilitas[i].tambahFasilitas("Meja Kerja Eksekutif");
        fasilitas[i].tambahFasilitas("Kursi Kantor Premium");
        fasilitas[i].tambahFasilitas("Kamar Mandi Mewah + Bathtub");
        fasilitas[i].tambahFasilitas("AC Inverter");
        fasilitas[i].tambahFasilitas("Wi-Fi Fiber Optic");
        fasilitas[i].tambahFasilitas("Smart TV 43 Inch");
        fasilitas[i].tambahFasilitas("Kulkas 2 Pintu");
        fasilitas[i].tambahFasilitas("Microwave");
        fasilitas[i].tambahFasilitas("Dispenser");
        fasilitas[i].tambahFasilitas("Sofa Mini");
        fasilitas[i].tambahFasilitas("Balkon Luas + Meja Santai");
        fasilitas[i].tambahFasilitas("Sound System");
        fasilitas[i].tambahFasilitas("Smart Lock");
        fasilitas[i].tambahFasilitas("Charging Station");
        fasilitas[i].setDeskripsi("Kamar mewah dengan fasilitas premium seperti apartemen");
    }
}

void tampilkanFasilitasKamar(FasilitasKamar fasilitas[], int nomorKamar) {
    cout << "\n========== FASILITAS KAMAR " << nomorKamar << " ==========" << endl;
    cout << "Deskripsi: " << fasilitas[nomorKamar].getDeskripsi() << endl;
    cout << "\nFasilitas yang tersedia:" << endl;
    garis();
    
    vector<string> listFasilitas = fasilitas[nomorKamar].getFasilitas();
    for (size_t i = 0; i < listFasilitas.size(); i++) {
        cout << "• " << listFasilitas[i] << endl;
    }
    garis();
}

void menuFasilitasKamar(FasilitasKamar fasilitas[], string tipeKamar[], int hargaKamar[]) {
    int pilihan;
    
    do {
        bersihLayar();
        header();
        cout << "\n======== MENU FASILITAS KAMAR ========" << endl;
        cout << "1. Lihat Fasilitas Berdasarkan Tipe" << endl;
        cout << "2. Lihat Fasilitas Kamar Tertentu" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "=====================================" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: {
                bersihLayar();
                header();
                cout << "\n======== FASILITAS BERDASARKAN TIPE ========" << endl;
                cout << "1. Tipe Reguler (Kamar 1-5)" << endl;
                cout << "2. Tipe VIP (Kamar 6-10)" << endl;
                cout << "3. Tipe Premium (Kamar 11-15)" << endl;
                cout << "Pilih tipe: ";
                
                int tipe;
                cin >> tipe;
                
                bersihLayar();
                header();
                
                if (tipe == 1) {
                    cout << "\n========== FASILITAS TIPE REGULER ==========" << endl;
                    cout << "Harga: Rp " << hargaKamar[1] << "/bulan" << endl;
                    tampilkanFasilitasKamar(fasilitas, 1);
                } else if (tipe == 2) {
                    cout << "\n========== FASILITAS TIPE VIP ==========" << endl;
                    cout << "Harga: Rp " << hargaKamar[6] << "/bulan" << endl;
                    tampilkanFasilitasKamar(fasilitas, 6);
                } else if (tipe == 3) {
                    cout << "\n========== FASILITAS TIPE PREMIUM ==========" << endl;
                    cout << "Harga: Rp " << hargaKamar[11] << "/bulan" << endl;
                    tampilkanFasilitasKamar(fasilitas, 11);
                } else {
                    cout << "Tipe tidak valid!" << endl;
                }
                
                pause();
                break;
            }
            
            case 2: {
                bersihLayar();
                header();
                cout << "\n======== FASILITAS KAMAR TERTENTU ========" << endl;
                cout << "Masukkan nomor kamar (1-15): ";
                
                int nomorKamar;
                cin >> nomorKamar;
                
                if (nomorKamar >= 1 && nomorKamar <= 15) {
                    bersihLayar();
                    header();
                    cout << "Tipe: " << tipeKamar[nomorKamar] << endl;
                    cout << "Harga: Rp " << hargaKamar[nomorKamar] << "/bulan" << endl;
                    tampilkanFasilitasKamar(fasilitas, nomorKamar);
                } else {
                    cout << "Nomor kamar tidak valid!" << endl;
                }
                
                pause();
                break;
            }
                    
            case 0:
                break;
                
            default:
                cout << "Pilihan tidak valid!" << endl;
                pause();
                break;
        }
        
    } while (pilihan != 0);
}

void cariDataPenyewa(string nama[], int kamar[], int durasi[], string bayar[], 
                    string telepon[], string tipeKamar[], int hargaKamar[], int totalPenyewa) {
    if (totalPenyewa == 0) {
        cout << "Belum ada data penyewa yang terdaftar." << endl;
        return;
    }
    
    int pilihan;
    cout << "\n======== CARI DATA PENYEWA ========" << endl;
    cout << "1. Cari berdasarkan Nama" << endl;
    cout << "2. Cari berdasarkan Nomor Kamar" << endl;
    cout << "3. Cari berdasarkan Status Bayar" << endl;
    cout << "4. Cari berdasarkan Tipe Kamar" << endl;
    cout << "===================================" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihan;
    
    bool ditemukan = false;
    
    switch (pilihan) {
        case 1: {
            string cariNama;
            cout << "Masukkan nama yang dicari: ";
            cin >> cariNama;
            
            cout << "\n========== HASIL PENCARIAN NAMA ==========" << endl;
            
            for (int i = 0; i < totalPenyewa; i++) {
                if (nama[i].find(cariNama) != string::npos) {
                    cout << "\n--- PENYEWA DITEMUKAN ---" << endl;
                    cout << "Nama           : " << nama[i] << endl;
                    cout << "Telepon        : " << telepon[i] << endl;
                    cout << "Kamar          : " << kamar[i] << " (Tipe " << tipeKamar[kamar[i]] << ")" << endl;
                    cout << "Durasi         : " << durasi[i] << " bulan" << endl;
                    cout << "Status Bayar   : " << bayar[i] << endl;
                    cout << "Total Biaya    : Rp " << (hargaKamar[kamar[i]] * durasi[i]) << endl;
                    garis();
                    ditemukan = true;
                }
            }
            break;
        }
        
        case 2: {
            int cariKamar;
            cout << "Masukkan nomor kamar (1-15): ";
            cin >> cariKamar;
            
            cout << "\n========== HASIL PENCARIAN KAMAR ==========" << endl;
            
            for (int i = 0; i < totalPenyewa; i++) {
                if (kamar[i] == cariKamar) {
                    cout << "\n--- PENYEWA DITEMUKAN ---" << endl;
                    cout << "Nama           : " << nama[i] << endl;
                    cout << "Telepon        : " << telepon[i] << endl;
                    cout << "Kamar          : " << kamar[i] << " (Tipe " << tipeKamar[kamar[i]] << ")" << endl;
                    cout << "Durasi         : " << durasi[i] << " bulan" << endl;
                    cout << "Status Bayar   : " << bayar[i] << endl;
                    cout << "Total Biaya    : Rp " << (hargaKamar[kamar[i]] * durasi[i]) << endl;
                    garis();
                    ditemukan = true;
                    break;
                }
            }
            break;
        }
        
        case 3: {
            string cariStatus;
            cout << "Masukkan status bayar (Lunas/Belum): ";
            cin >> cariStatus;
            
            cout << "\n========== HASIL PENCARIAN STATUS ==========" << endl;
            
            for (int i = 0; i < totalPenyewa; i++) {
                if (bayar[i] == cariStatus) {
                    cout << "\n--- PENYEWA DITEMUKAN ---" << endl;
                    cout << "Nama           : " << nama[i] << endl;
                    cout << "Telepon        : " << telepon[i] << endl;
                    cout << "Kamar          : " << kamar[i] << " (Tipe " << tipeKamar[kamar[i]] << ")" << endl;
                    cout << "Durasi         : " << durasi[i] << " bulan" << endl;
                    cout << "Status Bayar   : " << bayar[i] << endl;
                    cout << "Total Biaya    : Rp " << (hargaKamar[kamar[i]] * durasi[i]) << endl;
                    garis();
                    ditemukan = true;
                }
            }
            break;
        }
        
        case 4: {
            string cariTipe;
            cout << "Masukkan tipe kamar (Reguler/VIP/Premium): ";
            cin >> cariTipe;
            
            cout << "\n========== HASIL PENCARIAN TIPE ==========" << endl;
            
            for (int i = 0; i < totalPenyewa; i++) {
                if (tipeKamar[kamar[i]] == cariTipe) {
                    cout << "\n--- PENYEWA DITEMUKAN ---" << endl;
                    cout << "Nama           : " << nama[i] << endl;
                    cout << "Telepon        : " << telepon[i] << endl;
                    cout << "Kamar          : " << kamar[i] << " (Tipe " << tipeKamar[kamar[i]] << ")" << endl;
                    cout << "Durasi         : " << durasi[i] << " bulan" << endl;
                    cout << "Status Bayar   : " << bayar[i] << endl;
                    cout << "Total Biaya    : Rp " << (hargaKamar[kamar[i]] * durasi[i]) << endl;
                    garis();
                    ditemukan = true;
                }
            }
            break;
        }
        
        default:
            cout << "Pilihan tidak valid!" << endl;
            return;
    }
    
    if (!ditemukan) {
        cout << "Data tidak ditemukan!" << endl;
    }
}

void laporanKeuangan(string nama[], int kamar[], int durasi[], string bayar[], 
                    string tipeKamar[], int hargaKamar[], int totalPenyewa) {
    int pilihan;
    
    do {
        bersihLayar();
        header();
        cout << "\n======== LAPORAN KEUANGAN ========" << endl;
        cout << "1. Ringkasan Pendapatan" << endl;
        cout << "2. Laporan per Tipe Kamar" << endl;
        cout << "3. Laporan Tunggakan" << endl;
        cout << "4. Proyeksi Pendapatan" << endl;
        cout << "5. Laporan Detail Lengkap" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "=================================" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: {
                bersihLayar();
                header();
                cout << "\n========== RINGKASAN PENDAPATAN ==========" << endl;
                
                long long totalPendapatan = 0;
                long long pendapatanLunas = 0;
                long long tunggakan = 0;
                int jumlahLunas = 0;
                int jumlahBelum = 0;
                
                for (int i = 0; i < totalPenyewa; i++) {
                    long long biayaPenyewa = (long long)hargaKamar[kamar[i]] * durasi[i];
                    totalPendapatan += biayaPenyewa;
                    
                    if (bayar[i] == "Lunas") {
                        pendapatanLunas += biayaPenyewa;
                        jumlahLunas++;
                    } else {
                        tunggakan += biayaPenyewa;
                        jumlahBelum++;
                    }
                }
                
                cout << "+---------------------------+------------------+" << endl;
                cout << "|        KETERANGAN         |      JUMLAH      |" << endl;
                cout << "+---------------------------+------------------+" << endl;
                cout << "| Total Penyewa             |       " << setw(2) << totalPenyewa << " orang    |" << endl;
                cout << "| Pembayaran Lunas          |       " << setw(2) << jumlahLunas << " orang    |" << endl;
                cout << "| Pembayaran Belum          |       " << setw(2) << jumlahBelum << " orang    |" << endl;
                cout << "+---------------------------+------------------+" << endl;
                cout << "| Total Pendapatan          | Rp " << setw(12) << totalPendapatan << " |" << endl;
                cout << "| Pendapatan Terealisasi    | Rp " << setw(12) << pendapatanLunas << " |" << endl;
                cout << "| Total Tunggakan           | Rp " << setw(12) << tunggakan << " |" << endl;
                cout << "+---------------------------+------------------+" << endl;
                
                if (totalPendapatan > 0) {
                    double persentaseLunas = ((double)pendapatanLunas / totalPendapatan) * 100;
                    cout << "\nPersentase Pembayaran Lunas: " << fixed << setprecision(1) << persentaseLunas << "%" << endl;
                }
                
                pause();
                break;
            }
            
            case 2: {
                bersihLayar();
                header();
                cout << "\n========== LAPORAN PER TIPE KAMAR ==========" << endl;
                
                long long pendapatanReguler = 0, pendapatanVIP = 0, pendapatanPremium = 0;
                int penyewaReguler = 0, penyewaVIP = 0, penyewaPremium = 0;
                int lunasReguler = 0, lunasVIP = 0, lunasPremium = 0;
                
                for (int i = 0; i < totalPenyewa; i++) {
                    long long biaya = (long long)hargaKamar[kamar[i]] * durasi[i];
                    
                    if (kamar[i] >= 1 && kamar[i] <= 5) {
                        pendapatanReguler += biaya;
                        penyewaReguler++;
                        if (bayar[i] == "Lunas") lunasReguler++;
                    } else if (kamar[i] >= 6 && kamar[i] <= 10) {
                        pendapatanVIP += biaya;
                        penyewaVIP++;
                        if (bayar[i] == "Lunas") lunasVIP++;
                    } else if (kamar[i] >= 11 && kamar[i] <= 15) {
                        pendapatanPremium += biaya;
                        penyewaPremium++;
                        if (bayar[i] == "Lunas") lunasPremium++;
                    }
                }
                
                cout << "+----------+----------+----------+--------------+" << endl;
                cout << "|   TIPE   | PENYEWA  |  LUNAS   |  PENDAPATAN  |" << endl;
                cout << "+----------+----------+----------+--------------+" << endl;
                cout << "| Reguler  |   " << setw(2) << penyewaReguler << "/5   |   " << setw(2) << lunasReguler 
                     << "/" << setw(2) << penyewaReguler << "   | Rp " << setw(9) << pendapatanReguler << " |" << endl;
                cout << "| VIP      |   " << setw(2) << penyewaVIP << "/5   |   " << setw(2) << lunasVIP 
                     << "/" << setw(2) << penyewaVIP << "   | Rp " << setw(9) << pendapatanVIP << " |" << endl;
                cout << "| Premium  |   " << setw(2) << penyewaPremium << "/5   |   " << setw(2) << lunasPremium 
                     << "/" << setw(2) << penyewaPremium << "   | Rp " << setw(9) << pendapatanPremium << " |" << endl;
                cout << "+----------+----------+----------+--------------+" << endl;
                
                cout << "\nAnalisis Okupansi:" << endl;
                cout << "- Reguler: " << (penyewaReguler * 100 / 5) << "% terisi" << endl;
                cout << "- VIP: " << (penyewaVIP * 100 / 5) << "% terisi" << endl;
                cout << "- Premium: " << (penyewaPremium * 100 / 5) << "% terisi" << endl;
                
                pause();
                break;
            }
            
            case 3: {
                bersihLayar();
                header();
                cout << "\n========== LAPORAN TUNGGAKAN ==========" << endl;
                
                bool adaTunggakan = false;
                long long totalTunggakan = 0;
                
                cout << "+----+---------------+-------+---------+--------------+" << endl;
                cout << "| No |     Nama      | Kamar |  Tipe   |  Tunggakan   |" << endl;
                cout << "+----+---------------+-------+---------+--------------+" << endl;
                
                int nomorUrut = 1;
                for (int i = 0; i < totalPenyewa; i++) {
                    if (bayar[i] == "Belum") {
                        long long tunggakan = (long long)hargaKamar[kamar[i]] * durasi[i];
                        cout << "| " << setw(2) << nomorUrut << " | " << setw(13) << nama[i] 
                             << " |   " << setw(2) << kamar[i] << "  | " << setw(7) << tipeKamar[kamar[i]]
                             << " | Rp " << setw(9) << tunggakan << " |" << endl;
                        totalTunggakan += tunggakan;
                        nomorUrut++;
                        adaTunggakan = true;
                    }
                }
                
                if (!adaTunggakan) {
                    cout << "|              TIDAK ADA TUNGGAKAN SAAT INI             |" << endl;
                    cout << "+-------------------------------------------------------+" << endl;
                } else {
                    cout << "+----+---------------+-------+---------+--------------+" << endl;
                    cout << "| TOTAL TUNGGAKAN                     | Rp " << setw(9) << totalTunggakan << " |" << endl;
                    cout << "+--------------------------------------+--------------+" << endl;
                }
                
                pause();
                break;
            }
            
            case 4: {
                bersihLayar();
                header();
                cout << "\n========== PROYEKSI PENDAPATAN ==========" << endl;
                
                long long pendapatanBulanIni = 0;
                
                for (int i = 0; i < totalPenyewa; i++) {
                    if (bayar[i] == "Lunas") {
                        pendapatanBulanIni += hargaKamar[kamar[i]];
                    }
                }
                
                cout << "Berdasarkan data penyewa saat ini:" << endl;
                garis();
                cout << "Pendapatan bulan ini (lunas): Rp " << pendapatanBulanIni << endl;
                cout << "Proyeksi 3 bulan            : Rp " << (pendapatanBulanIni * 3) << endl;
                cout << "Proyeksi 6 bulan            : Rp " << (pendapatanBulanIni * 6) << endl;
                cout << "Proyeksi 1 tahun            : Rp " << (pendapatanBulanIni * 12) << endl;
                
                cout << "\nProyeksi jika semua kamar terisi penuh:" << endl;
                garis();
                long long maxPendapatan = (500000 * 5) + (800000 * 5) + (1200000 * 5);
                cout << "Maksimal per bulan: Rp " << maxPendapatan << endl;
                cout << "Maksimal per tahun: Rp " << (maxPendapatan * 12) << endl;
                
                pause();
                break;
            }
            
            case 5: {
                bersihLayar();
                header();
                cout << "\n========== LAPORAN DETAIL LENGKAP ==========" << endl;
                
                if (totalPenyewa == 0) {
                    cout << "Belum ada data penyewa untuk dilaporkan." << endl;
                    pause();
                    break;
                }
                
                long long totalPendapatan = 0;
                long long pendapatanLunas = 0;
                int lunas = 0, belum = 0;
                
                for (int i = 0; i < totalPenyewa; i++) {
                    long long biaya = (long long)hargaKamar[kamar[i]] * durasi[i];
                    totalPendapatan += biaya;
                    if (bayar[i] == "Lunas") {
                        pendapatanLunas += biaya;
                        lunas++;
                    } else {
                        belum++;
                    }
                }
                
                cout << "=== RINGKASAN KEUANGAN ===" << endl;
                cout << "Total Penyewa         : " << totalPenyewa << " orang" << endl;
                cout << "Pembayaran Lunas      : " << lunas << " orang" << endl;
                cout << "Pembayaran Belum      : " << belum << " orang" << endl;
                cout << "Total Pendapatan      : Rp " << totalPendapatan << endl;
                cout << "Pendapatan Terealisasi: Rp " << pendapatanLunas << endl;
                cout << "Total Tunggakan       : Rp " << (totalPendapatan - pendapatanLunas) << endl;
                
                cout << "\n=== DETAIL PER PENYEWA ===" << endl;
                for (int i = 0; i < totalPenyewa; i++) {
                    long long biaya = (long long)hargaKamar[kamar[i]] * durasi[i];
                    cout << "\n" << (i+1) << ". " << nama[i] << endl;
                    cout << "   Kamar: " << kamar[i] << " (" << tipeKamar[kamar[i]] << ")" << endl;
                    cout << "   Durasi: " << durasi[i] << " bulan" << endl;
                    cout << "   Biaya: Rp " << biaya << " (" << bayar[i] << ")" << endl;
                }
                
                pause();
                break;
            }
            
            case 0:
                break;
                
            default:
                cout << "Pilihan tidak valid!" << endl;
                pause();
                break;
        }
        
    } while (pilihan != 0);
}

void simpanDataKeFile(string nama[], int kamar[], int durasi[], string bayar[], string telepon[], string tanggalSewa[], int totalPenyewa) {
    ofstream file("data_penyewa.txt");
    
    if (!file.is_open()) {
        cout << "Error: Tidak bisa membuka file untuk menyimpan!" << endl;
        return;
    }
    
    file << totalPenyewa << endl;
    
    for (int i = 0; i < totalPenyewa; i++) {
        file << nama[i] << endl;
        file << kamar[i] << endl;
        file << durasi[i] << endl;
        file << bayar[i] << endl;
        file << telepon[i] << endl;
        file << tanggalSewa[i] << endl; // Simpan tanggal sewa
    }
    
    file.close();
    cout << "Data berhasil disimpan ke file 'data_penyewa.txt'" << endl;
}


int muatDataDariFile(string nama[], int kamar[], int durasi[], string bayar[], string telepon[], string tanggalSewa[], string statusKamar[]) {
    ifstream file("data_penyewa.txt");
    int totalPenyewa = 0;
    
    if (!file.is_open()) {
        cout << "File 'data_penyewa.txt' tidak ditemukan. Memulai dengan data kosong." << endl;
        return 0;
    }
    
    file >> totalPenyewa;
    file.ignore();
    
    for (int i = 0; i < totalPenyewa; i++) {
        getline(file, nama[i]);
        file >> kamar[i];
        file >> durasi[i];
        file >> bayar[i];
        file >> telepon[i];
        file.ignore();
        getline(file, tanggalSewa[i]);  // Membaca tanggal sewa dari file
        
        statusKamar[kamar[i]] = "Terisi";
    }
    
    file.close();
    cout << "Data berhasil dimuat dari file. Total penyewa: " << totalPenyewa << endl;
    return totalPenyewa;
}


void backupData(string nama[], int kamar[], int durasi[], string bayar[], string telepon[], int totalPenyewa, string tipeKamar[], int hargaKamar[]) {
    string namaFile = "backup_data_penyewa.txt";
    ofstream file(namaFile.c_str());
    
    if (!file.is_open()) {
        cout << "Error: Tidak bisa membuat file backup!" << endl;
        return;
    }
    
    file << "=====================================================================" << endl;
    file << "                    SISTEM PENGELOLAAN KOS" << endl;
    file << "                      DATA PENYEWA KOS" << endl;
    file << "=====================================================================" << endl;
    file << "Total Penyewa Terdaftar: " << totalPenyewa << " orang" << endl;
    file << "=====================================================================" << endl;
    file << endl;
    
    if (totalPenyewa == 0) {
        file << "Tidak ada data penyewa yang terdaftar." << endl;
        file.close();
        cout << "Backup berhasil dibuat: " << namaFile << endl;
        return;
    }
    
    file << "+----+---------------+-------+--------+---------+----------+---------------+" << endl;
    file << "| No |     Nama      | Kamar | Durasi |  Tipe   |  Status  |  Total Biaya  |" << endl;
    file << "+----+---------------+-------+--------+---------+----------+---------------+" << endl;
    
    for (int i = 0; i < totalPenyewa; i++) {
        int totalBiaya = hargaKamar[kamar[i]] * durasi[i];
        file << "| " << setw(2) << (i+1) << " | " 
             << setw(13) << nama[i] << " |   " 
             << setw(2) << kamar[i] << "  |  " 
             << setw(2) << durasi[i] << " bl | " 
             << setw(7) << tipeKamar[kamar[i]] << " | " 
             << setw(8) << bayar[i] << " | Rp " 
             << setw(10) << totalBiaya << " |" << endl;
    }
    
    file << "+----+---------------+-------+--------+---------+----------+---------------+" << endl;
    file << endl;
    
    file << "=====================================================================" << endl;
    file << "                        DETAIL LENGKAP" << endl;
    file << "=====================================================================" << endl;
    
    for (int i = 0; i < totalPenyewa; i++) {
        file << endl;
        file << "PENYEWA #" << (i+1) << endl;
        file << "---------------------------------------------------------------------" << endl;
        file << "Nama Lengkap    : " << nama[i] << endl;
        file << "Nomor Telepon   : " << telepon[i] << endl;
        file << "Nomor Kamar     : " << kamar[i] << " (Tipe " << tipeKamar[kamar[i]] << ")" << endl;
        file << "Durasi Sewa     : " << durasi[i] << " bulan" << endl;
        file << "Harga per Bulan : Rp " << hargaKamar[kamar[i]] << endl;
        file << "Status Bayar    : " << bayar[i] << endl;
        file << "Total Biaya     : Rp " << (hargaKamar[kamar[i]] * durasi[i]) << endl;
        file << "---------------------------------------------------------------------" << endl;
    }
    
    file << endl;
    file << "=====================================================================" << endl;
    file << "                       INFORMASI KAMAR" << endl;
    file << "=====================================================================" << endl;
    file << "TIPE REGULER (Kamar 1-5)  : Rp 500.000/bulan" << endl;
    file << "TIPE VIP     (Kamar 6-10) : Rp 800.000/bulan" << endl;
    file << "TIPE PREMIUM (Kamar 11-15): Rp 1.200.000/bulan" << endl;
    file << "=====================================================================" << endl;
    
    file.close();
    cout << "Backup berhasil dibuat: " << namaFile << endl;
}

void tampilStatusKamar(string status[], int harga[], string tipe[]) {
    cout << "\n========== STATUS KAMAR ==========" << endl;
    cout << "+--------+----------+---------+---------------+" << endl;
    cout << "| Kamar  |  Status  |  Tipe   |     Harga     |" << endl;
    cout << "+--------+----------+---------+---------------+" << endl;
    
    for (int i = 1; i <= 15; i++) {
        cout << "|   " << setw(2) << i << "   | " << setw(8) << status[i] 
             << " | " << setw(7) << tipe[i] 
             << " | Rp " << setw(9) << harga[i] << " |" << endl;
    }
    cout << "+--------+----------+---------+---------------+" << endl;
}

void tampilDataPenyewa(string nama[], int kamar[], int durasi[], string bayar[], string telepon[], string tanggalSewa[], string tipeKamar[], int hargaKamar[], int totalPenyewa){

    cout << "\n================ DATA PENYEWA ================" << endl;
    
if (totalPenyewa == 0) {
        cout << "Belum ada data penyewa yang terdaftar." << endl;
        return;
    }
    
    cout << "+----+---------------+-------+--------+---------+----------+---------------+" << endl;
    cout << "| No |     Nama      | Kamar | Durasi |  Tipe   |  Status  |  Total Biaya  |" << endl;
    cout << "+----+---------------+-------+--------+---------+----------+---------------+" << endl;
    
  for (int i = 0; i < totalPenyewa; i++) {
    int totalBiaya = hargaKamar[kamar[i]] * durasi[i];
        cout << "| " << setw(2) << (i+1) << " | " << setw(13) << nama[i] 
             << " |   " << setw(2) << kamar[i] 
    << " | " << setw(7) << tipeKamar[kamar[i]]
             << " | " << setw(8) << bayar[i] 
             << " | Rp " << setw(10) << totalBiaya << " |" << endl;
    }
    cout << "+----+---------------+-------+--------+---------+----------+---------------+" << endl;
}

void tampilKamarKosong(string status[], int harga[], string tipe[]) {
    cout << "\nKamar yang tersedia:" << endl;
    garis();
    
    bool adaKosong = false;
    
    for (int i = 1; i <= 15; i++) {
        if (status[i] == "Kosong") {
            cout << "Kamar " << setw(2) << i << " - Tipe " << setw(7) << tipe[i] 
                 << " - Rp " << setw(7) << harga[i] << "/bulan" << endl;
            adaKosong = true;
        }
    }
    
    if (!adaKosong) {
        cout << "Maaf, semua kamar sudah terisi!" << endl;
    }
}

void inisialisasiKamar(string status[], int harga[], string tipe[]) {
    for (int i = 1; i <= 15; i++) {
        status[i] = "Kosong";
        
        if (i <= 5) {
            tipe[i] = "Reguler";
            harga[i] = 500000;
        } else if (i <= 10) {
            tipe[i] = "VIP";
            harga[i] = 800000;
        } else {
            tipe[i] = "Premium";
            harga[i] = 1200000;
        }
    }
}

void tampilTipeKamar() {
    cout << "\n======== INFORMASI TIPE KAMAR ========" << endl;
    cout << "TIPE REGULER (Kamar 1-5)  : Rp 500.000/bulan" << endl;
    cout << "TIPE VIP     (Kamar 6-10) : Rp 800.000/bulan" << endl;
    cout << "TIPE PREMIUM (Kamar 11-15): Rp 1.200.000/bulan" << endl;
    cout << "=======================================" << endl;
}

void tampilStatistik(string status[], string bayar[], int total) {
    int kamarTerisi = 0;
    int sudahLunas = 0;
    int belumLunas = 0;
    
    for (int i = 1; i <= 15; i++) {
        if (status[i] == "Terisi") {
            kamarTerisi++;
        }
    }
    
    for (int i = 0; i < total; i++) {
        if (bayar[i] == "Lunas") {
            sudahLunas++;
        } else {
            belumLunas++;
        }
    }
    
    cout << "\n========== STATISTIK KOS ==========" << endl;
    cout << "Total Kamar        : 15 kamar" << endl;
    cout << "Kamar Terisi       : " << kamarTerisi << " kamar" << endl;
    cout << "Kamar Kosong       : " << (15 - kamarTerisi) << " kamar" << endl;
    cout << "Pembayaran Lunas   : " << sudahLunas << " penyewa" << endl;
    cout << "Pembayaran Belum   : " << belumLunas << " penyewa" << endl;
    cout << "===================================" << endl;
}

void simpanDataPembayaran(DataPembayaran history[], int total) {
    ofstream file("data_pembayaran.txt");
    
    if (!file.is_open()) {
        cout << "Error: Tidak bisa membuka file pembayaran!" << endl;
        return;
    }
    
    file << total << endl;
    
    for (int i = 0; i < total; i++) {
        file << history[i].getNamaPenyewa() << endl;
        file << history[i].getNomorKamar() << endl;
        file << history[i].getJumlahBayar() << endl;
        file << history[i].getTanggalBayar() << endl;
        file << history[i].getMetodeBayar() << endl;
        file << history[i].getKeterangan() << endl;
    }
    
    file.close();
}

int muatDataPembayaran(DataPembayaran history[]) {
    ifstream file("data_pembayaran.txt");
    int total = 0;
    
    if (!file.is_open()) {
        return 0;
    }
    
    file >> total;
    file.ignore();
    
    for (int i = 0; i < total; i++) {
        string nama, tanggal, metode, keterangan;
        int kamar, jumlah;
        
        getline(file, nama);
        file >> kamar;
        file >> jumlah;
        file >> tanggal;
        file >> metode;
        file.ignore();
        getline(file, keterangan);
        
        history[i].setNamaPenyewa(nama);
        history[i].setNomorKamar(kamar);
        history[i].setJumlahBayar(jumlah);
        history[i].setTanggalBayar(tanggal);
        history[i].setMetodeBayar(metode);
        history[i].setKeterangan(keterangan);
    }
    
    file.close();
    return total;
}

void prosesPembayaran(string nama[], int kamar[], int durasi[], string bayar[], 
                     string telepon[], string tanggalSewa[], string tipeKamar[], 
                     int hargaKamar[], int totalPenyewa, DataPembayaran history[], 
                     int &totalPembayaran, string statusKamar[]) {
    
    if (totalPenyewa == 0) {
        cout << "Belum ada data penyewa untuk pembayaran." << endl;
        return;
    }
    
    cout << "\n========== PROSES PEMBAYARAN ==========" << endl;
    cout << "\nDaftar penyewa yang belum lunas:" << endl;
    garis();
    
    bool adaBelumLunas = false;
    vector<int> indexBelumLunas;
    
    for (int i = 0; i < totalPenyewa; i++) {
        if (bayar[i] == "Belum") {
            int totalBiaya = hargaKamar[kamar[i]] * durasi[i];
            cout << (indexBelumLunas.size() + 1) << ". " << nama[i] << " - Kamar " << kamar[i] 
                 << " - Total Tagihan: Rp " << totalBiaya << endl;
            indexBelumLunas.push_back(i);
            adaBelumLunas = true;
        }
    }
    
    if (!adaBelumLunas) {
        cout << "Semua penyewa sudah lunas!" << endl;
        return;
    }
    
    int pilihan;
    cout << "\nPilih nomor penyewa untuk pembayaran (1-" << indexBelumLunas.size() << "): ";
    cin >> pilihan;
    
    if (pilihan >= 1 && pilihan <= (int)indexBelumLunas.size()) {
        int indexPenyewa = indexBelumLunas[pilihan-1];
        int totalBiaya = hargaKamar[kamar[indexPenyewa]] * durasi[indexPenyewa];
        
        cout << "\n--- DETAIL PEMBAYARAN ---" << endl;
        cout << "Nama Penyewa    : " << nama[indexPenyewa] << endl;
        cout << "Kamar           : " << kamar[indexPenyewa] << " (Tipe " << tipeKamar[kamar[indexPenyewa]] << ")" << endl;
        cout << "Durasi Sewa     : " << durasi[indexPenyewa] << " bulan" << endl;
        cout << "Harga per Bulan : Rp " << hargaKamar[kamar[indexPenyewa]] << endl;
        cout << "Total Tagihan   : Rp " << totalBiaya << endl;
        
        cout << "\nMasukkan jumlah pembayaran: Rp ";
        int jumlahBayar;
        cin >> jumlahBayar;
        
        if (jumlahBayar >= totalBiaya) {
            cout << "\nMetode Pembayaran:" << endl;
            cout << "1. Tunai" << endl;
            cout << "2. Transfer Bank" << endl;
            cout << "3. E-Wallet" << endl;
            cout << "4. Kartu Kredit/Debit" << endl;
            cout << "Pilih metode (1-4): ";
            
            int metode;
            cin >> metode;
            
            string metodeBayar;
            switch (metode) {
                case 1: metodeBayar = "Tunai"; break;
                case 2: metodeBayar = "Transfer"; break;
                case 3: metodeBayar = "E-Wallet"; break;
                case 4: metodeBayar = "Kartu"; break;
                default: metodeBayar = "Tunai"; break;
            }
            
            cout << "Tanggal Pembayaran (DD-MM-YYYY) atau tekan Enter untuk hari ini: ";
            string tanggalBayar;
            cin.ignore();
            getline(cin, tanggalBayar);
            
            if (tanggalBayar.empty()) {
                time_t now = time(0);
                tm* ltm = localtime(&now);
                tanggalBayar = to_string(ltm->tm_mday) + "-" + 
                              to_string(1 + ltm->tm_mon) + "-" + 
                              to_string(1900 + ltm->tm_year);
            }
            
            cout << "Keterangan (opsional): ";
            string keterangan;
            getline(cin, keterangan);
            
            if (keterangan.empty()) {
                keterangan = "Pembayaran sewa kamar";
            }
            
            // Konfirmasi pembayaran
            cout << "\n--- KONFIRMASI PEMBAYARAN ---" << endl;
            cout << "Nama           : " << nama[indexPenyewa] << endl;
            cout << "Jumlah Bayar   : Rp " << jumlahBayar << endl;
            cout << "Metode         : " << metodeBayar << endl;
            cout << "Tanggal        : " << tanggalBayar << endl;
            if (jumlahBayar > totalBiaya) {
                cout << "Kembalian      : Rp " << (jumlahBayar - totalBiaya) << endl;
            }
            cout << "\nProses pembayaran? (y/n): ";
            
            char konfirmasi;
            cin >> konfirmasi;
            
            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                history[totalPembayaran].setNamaPenyewa(nama[indexPenyewa]);
                history[totalPembayaran].setNomorKamar(kamar[indexPenyewa]);
                history[totalPembayaran].setJumlahBayar(jumlahBayar);
                history[totalPembayaran].setTanggalBayar(tanggalBayar);
                history[totalPembayaran].setMetodeBayar(metodeBayar);
                history[totalPembayaran].setKeterangan(keterangan);
                totalPembayaran++;
                
                bayar[indexPenyewa] = "Lunas";
                
                simpanDataKeFile(nama, kamar, durasi, bayar, telepon, tanggalSewa, totalPenyewa);
                simpanDataPembayaran(history, totalPembayaran);
                
                cout << "\n========== BUKTI PEMBAYARAN ==========" << endl;
                cout << "No. Transaksi   : " << totalPembayaran << endl;
                cout << "Nama Penyewa    : " << nama[indexPenyewa] << endl;
                cout << "Kamar           : " << kamar[indexPenyewa] << " (Tipe " << tipeKamar[kamar[indexPenyewa]] << ")" << endl;
                cout << "Jumlah Bayar    : Rp " << jumlahBayar << endl;
                cout << "Metode          : " << metodeBayar << endl;
                cout << "Tanggal         : " << tanggalBayar << endl;
                cout << "Keterangan      : " << keterangan << endl;
                cout << "Status          : LUNAS" << endl;
                
                if (jumlahBayar > totalBiaya) {
                    cout << "Kembalian       : Rp " << (jumlahBayar - totalBiaya) << endl;
                }
                
                cout << "=======================================" << endl;
                cout << "\n?? PEMBAYARAN BERHASIL DIPROSES! ??" << endl;
                cout << "Status pembayaran " << nama[indexPenyewa] << " telah diubah menjadi LUNAS." << endl;
                
            } else {
                cout << "Pembayaran dibatalkan." << endl;
            }
            
        } else {
            cout << "\n? PEMBAYARAN GAGAL!" << endl;
            cout << "Jumlah pembayaran kurang dari total tagihan!" << endl;
            cout << "Minimum pembayaran: Rp " << totalBiaya << endl;
            cout << "Jumlah yang dibayar: Rp " << jumlahBayar << endl;
            cout << "Kekurangan: Rp " << (totalBiaya - jumlahBayar) << endl;
        }
        
    } else {
        cout << "Pilihan tidak valid! Silakan pilih nomor 1-" << indexBelumLunas.size() << endl;
    }
}

void lihatHistoryPembayaran(DataPembayaran history[], int total) {
    cout << "\n========== HISTORY PEMBAYARAN ==========" << endl;
    
    if (total == 0) {
        cout << "Belum ada data pembayaran." << endl;
        return;
    }
    
    cout << "+----+---------------+-------+-------------+----------+----------+" << endl;
    cout << "| No |     Nama      | Kamar |   Jumlah    | Tanggal  |  Metode  |" << endl;
    cout << "+----+---------------+-------+-------------+----------+----------+" << endl;
    
    for (int i = 0; i < total; i++) {
        cout << "| " << setw(2) << (i+1) << " | " << setw(13) << history[i].getNamaPenyewa() 
             << " |   " << setw(2) << history[i].getNomorKamar() 
             << "  | Rp " << setw(8) << history[i].getJumlahBayar() 
             << " | " << setw(8) << history[i].getTanggalBayar() 
             << " | " << setw(8) << history[i].getMetodeBayar() << " |" << endl;
    }
    
    cout << "+----+---------------+-------+-------------+----------+----------+" << endl;
    
    // Hitung total pembayaran
    long long totalUang = 0;
    for (int i = 0; i < total; i++) {
        totalUang += history[i].getJumlahBayar();
    }
    
    cout << "\nTotal Pembayaran Masuk: Rp " << totalUang << endl;
    cout << "Jumlah Transaksi: " << total << " transaksi" << endl;
}

void laporanPembayaranHarian(DataPembayaran history[], int total) {
    cout << "\n========== LAPORAN PEMBAYARAN HARIAN ==========" << endl;
    
    if (total == 0) {
        cout << "Belum ada data pembayaran." << endl;
        return;
    }
    
    string tanggalCari;
    cout << "Masukkan tanggal (DD-MM-YYYY): ";
    cin >> tanggalCari;
    
    cout << "\n--- PEMBAYARAN TANGGAL " << tanggalCari << " ---" << endl;
    garis();
    
    bool ditemukan = false;
    long long totalHarian = 0;
    int jumlahTransaksi = 0;
    
    for (int i = 0; i < total; i++) {
        if (history[i].getTanggalBayar() == tanggalCari) {
            cout << "• " << history[i].getNamaPenyewa() << " - Kamar " << history[i].getNomorKamar() 
                 << " - Rp " << history[i].getJumlahBayar() << " (" << history[i].getMetodeBayar() << ")" << endl;
            totalHarian += history[i].getJumlahBayar();
            jumlahTransaksi++;
            ditemukan = true;
        }
    }
    
    if (!ditemukan) {
        cout << "Tidak ada pembayaran pada tanggal tersebut." << endl;
    } else {
        garis();
        cout << "Total Pembayaran: Rp " << totalHarian << endl;
        cout << "Jumlah Transaksi: " << jumlahTransaksi << " transaksi" << endl;
    }
}

void menuPembayaran(string nama[], int kamar[], int durasi[], string bayar[], 
                   string telepon[], string tanggalSewa[], string tipeKamar[], 
                   int hargaKamar[], int totalPenyewa, DataPembayaran history[], 
                   int &totalPembayaran, string statusKamar[]) {
    
    int pilihan;
    
    do {
        bersihLayar();
        header();
        cout << "\n======== MENU PEMBAYARAN ========" << endl;
        cout << "1. Proses Pembayaran" << endl;
        cout << "2. Lihat History Pembayaran" << endl;
        cout << "3. Laporan Pembayaran Harian" << endl;
        cout << "4. Cetak Ulang Bukti Pembayaran" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "=================================" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: {
                bersihLayar();
                header();
                prosesPembayaran(nama, kamar, durasi, bayar, telepon, tanggalSewa, 
                               tipeKamar, hargaKamar, totalPenyewa, history, 
                               totalPembayaran, statusKamar);
                pause();
                break;
            }
            
            case 2: {
                bersihLayar();
                header();
                lihatHistoryPembayaran(history, totalPembayaran);
                pause();
                break;
            }
            
            case 3: {
                bersihLayar();
                header();
                laporanPembayaranHarian(history, totalPembayaran);
                pause();
                break;
            }
            
            case 4: {
                bersihLayar();
                header();
                cout << "\n========== CETAK ULANG BUKTI ==========" << endl;
                
                if (totalPembayaran == 0) {
                    cout << "Belum ada data pembayaran." << endl;
                } else {
                    cout << "Daftar pembayaran:" << endl;
                    for (int i = 0; i < totalPembayaran; i++) {
                        cout << (i+1) << ". " << history[i].getNamaPenyewa() 
                             << " - " << history[i].getTanggalBayar() 
                             << " - Rp " << history[i].getJumlahBayar() << endl;
                    }
                    
                    int pilihBukti;
                    cout << "\nPilih nomor pembayaran: ";
                    cin >> pilihBukti;
                    
                    if (pilihBukti >= 1 && pilihBukti <= totalPembayaran) {
                        cout << "\n========== BUKTI PEMBAYARAN ==========" << endl;
                        cout << "Nama Penyewa    : " << history[pilihBukti-1].getNamaPenyewa() << endl;
                        cout << "Kamar           : " << history[pilihBukti-1].getNomorKamar() << endl;
                        cout << "Jumlah Bayar    : Rp " << history[pilihBukti-1].getJumlahBayar() << endl;
                        cout << "Metode          : " << history[pilihBukti-1].getMetodeBayar() << endl;
                        cout << "Tanggal         : " << history[pilihBukti-1].getTanggalBayar() << endl;
                        cout << "Keterangan      : " << history[pilihBukti-1].getKeterangan() << endl;
                        cout << "Status          : LUNAS" << endl;
                        cout << "=======================================" << endl;
                    } else {
                        cout << "Pilihan tidak valid!" << endl;
                    }
                }
                
                pause();
                break;
            }
            
            case 0:
                break;
                
            default:
                cout << "Pilihan tidak valid!" << endl;
                pause();
                break;
        }
        
    } while (pilihan != 0);
}

// Tambahkan fungsi bubble sort setelah fungsi menuPembayaran dan sebelum fungsi main

// Fungsi untuk membandingkan tanggal (format DD-MM-YYYY)
bool bandingkanTanggal(string tanggal1, string tanggal2) {
    // Parsing tanggal1
    int hari1 = stoi(tanggal1.substr(0, 2));
    int bulan1 = stoi(tanggal1.substr(3, 2));
    int tahun1 = stoi(tanggal1.substr(6, 4));
    
    // Parsing tanggal2
    int hari2 = stoi(tanggal2.substr(0, 2));
    int bulan2 = stoi(tanggal2.substr(3, 2));
    int tahun2 = stoi(tanggal2.substr(6, 4));
    
    // Bandingkan tahun terlebih dahulu
    if (tahun1 != tahun2) return tahun1 < tahun2;
    // Jika tahun sama, bandingkan bulan
    if (bulan1 != bulan2) return bulan1 < bulan2;
    // Jika bulan sama, bandingkan hari
    return hari1 < hari2;
}

// Fungsi bubble sort berdasarkan tanggal sewa (dari yang terlama ke terbaru)
void bubbleSortTanggalSewa(string nama[], int kamar[], int durasi[], string bayar[], 
                          string telepon[], string tanggalSewa[], int totalPenyewa) {
    cout << "\n========== MENGURUTKAN BERDASARKAN TANGGAL SEWA ==========" << endl;
    cout << "Sedang mengurutkan data..." << endl;
    
    for (int i = 0; i < totalPenyewa - 1; i++) {
        for (int j = 0; j < totalPenyewa - i - 1; j++) {
            if (!bandingkanTanggal(tanggalSewa[j], tanggalSewa[j + 1])) {
                // Tukar semua data yang terkait
                swap(nama[j], nama[j + 1]);
                swap(kamar[j], kamar[j + 1]);
                swap(durasi[j], durasi[j + 1]);
                swap(bayar[j], bayar[j + 1]);
                swap(telepon[j], telepon[j + 1]);
                swap(tanggalSewa[j], tanggalSewa[j + 1]);
            }
        }
    }
    
    cout << "? Data berhasil diurutkan berdasarkan tanggal sewa (terlama ke terbaru)!" << endl;
}

// Fungsi bubble sort berdasarkan nomor kamar (dari yang terbesar ke terkecil)
void bubbleSortNomorKamar(string nama[], int kamar[], int durasi[], string bayar[], 
                         string telepon[], string tanggalSewa[], int totalPenyewa) {
    cout << "\n========== MENGURUTKAN BERDASARKAN NOMOR KAMAR ==========" << endl;
    cout << "Sedang mengurutkan data..." << endl;
    
    for (int i = 0; i < totalPenyewa - 1; i++) {
        for (int j = 0; j < totalPenyewa - i - 1; j++) {
            if (kamar[j] < kamar[j + 1]) { // Urutkan dari besar ke kecil
                // Tukar semua data yang terkait
                swap(nama[j], nama[j + 1]);
                swap(kamar[j], kamar[j + 1]);
                swap(durasi[j], durasi[j + 1]);
                swap(bayar[j], bayar[j + 1]);
                swap(telepon[j], telepon[j + 1]);
                swap(tanggalSewa[j], tanggalSewa[j + 1]);
            }
        }
    }
    
    cout << "? Data berhasil diurutkan berdasarkan nomor kamar (terbesar ke terkecil)!" << endl;
}

// Menu untuk fitur pengurutan
void menuPengurutan(string nama[], int kamar[], int durasi[], string bayar[], 
                   string telepon[], string tanggalSewa[], string tipeKamar[], 
                   int hargaKamar[], int totalPenyewa) {
    
    int pilihan;
    
    do {
        bersihLayar();
        header();
        cout << "\n======== MENU PENGURUTAN DATA ========" << endl;
        cout << "1. Urutkan berdasarkan Tanggal Sewa" << endl;
        cout << "2. Urutkan berdasarkan Nomor Kamar (Besar ke Kecil)" << endl;
        cout << "3. Lihat Data Setelah Pengurutan" << endl;
        cout << "4. Simpan Data yang Sudah Diurutkan" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "=====================================" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: {
                bersihLayar();
                header();
                
                if (totalPenyewa == 0) {
                    cout << "Belum ada data penyewa untuk diurutkan." << endl;
                } else {
                    cout << "Data sebelum pengurutan:" << endl;
                    tampilDataPenyewa(nama, kamar, durasi, bayar, telepon, tanggalSewa, tipeKamar, hargaKamar, totalPenyewa);
                    
                    bubbleSortTanggalSewa(nama, kamar, durasi, bayar, telepon, tanggalSewa, totalPenyewa);
                    
                    cout << "\nData setelah pengurutan berdasarkan tanggal sewa:" << endl;
                    tampilDataPenyewa(nama, kamar, durasi, bayar, telepon, tanggalSewa, tipeKamar, hargaKamar, totalPenyewa);
                }
                
                pause();
                break;
            }
            
            case 2: {
                bersihLayar();
                header();
                
                if (totalPenyewa == 0) {
                    cout << "Belum ada data penyewa untuk diurutkan." << endl;
                } else {
                    cout << "Data sebelum pengurutan:" << endl;
                    tampilDataPenyewa(nama, kamar, durasi, bayar, telepon, tanggalSewa, tipeKamar, hargaKamar, totalPenyewa);
                    
                    bubbleSortNomorKamar(nama, kamar, durasi, bayar, telepon, tanggalSewa, totalPenyewa);
                    
                    cout << "\nData setelah pengurutan berdasarkan nomor kamar (besar ke kecil):" << endl;
                    tampilDataPenyewa(nama, kamar, durasi, bayar, telepon, tanggalSewa, tipeKamar, hargaKamar, totalPenyewa);
                }
                
                pause();
                break;
            }
            
            case 3: {
                bersihLayar();
                header();
                cout << "\n========== DATA PENYEWA SAAT INI ==========" << endl;
                tampilDataPenyewa(nama, kamar, durasi, bayar, telepon, tanggalSewa, tipeKamar, hargaKamar, totalPenyewa);
                
                if (totalPenyewa > 0) {
                    cout << "\nDetail lengkap penyewa (urutan saat ini):" << endl;
                    garis();
                    
                    for (int i = 0; i < totalPenyewa; i++) {
                        cout << "\nPenyewa #" << (i+1) << endl;
                        cout << "Nama           : " << nama[i] << endl;
                        cout << "Telepon        : " << telepon[i] << endl;
                        cout << "Kamar          : " << kamar[i] << " (Tipe " << tipeKamar[kamar[i]] << ")" << endl;
                        cout << "Durasi         : " << durasi[i] << " bulan" << endl;
                        cout << "Tanggal Sewa   : " << tanggalSewa[i] << endl;
                        cout << "Status Bayar   : " << bayar[i] << endl;
                        cout << "Total Biaya    : Rp " << (hargaKamar[kamar[i]] * durasi[i]) << endl;
                        garis();
                    }
                }
                
                pause();
                break;
            }
            
            case 4: {
                bersihLayar();
                header();
                cout << "\n========== SIMPAN DATA YANG SUDAH DIURUTKAN ==========" << endl;
                
                if (totalPenyewa == 0) {
                    cout << "Tidak ada data untuk disimpan." << endl;
                } else {
                    simpanDataKeFile(nama, kamar, durasi, bayar, telepon, tanggalSewa, totalPenyewa);
                    cout << "\n? Data yang sudah diurutkan berhasil disimpan ke file!" << endl;
                    cout << "File: 'data_penyewa.txt'" << endl;
                }
                
                pause();
                break;
            }
            
            case 0:
                break;
                
            default:
                cout << "Pilihan tidak valid!" << endl;
                pause();
                break;
        }
        
    } while (pilihan != 0);
}

int main() {
    string nama[25];
    int kamar[25];
    int durasi[25];
    string bayar[25];
    string telepon[25];
    string tanggalSewa[25];
    
    string statusKamar[16];
    int hargaKamar[16];
    string tipeKamar[16];
    
    FasilitasKamar fasilitasKamar[16];
    
    DataPembayaran historyPembayaran[100];
    int totalPembayaran = 0;
    
    inisialisasiKamar(statusKamar, hargaKamar, tipeKamar);
    inisialisasiFasilitas(fasilitasKamar);
    
int totalPenyewa = muatDataDariFile(nama, kamar, durasi, bayar, telepon, tanggalSewa, statusKamar);
    totalPembayaran = muatDataPembayaran(historyPembayaran);
    int pilihan;
    
    bersihLayar();
    header();
    
    cout << "\nSelamat datang di Sistem Pengelolaan Kos!" << endl;
    cout << "Sistem ini mengelola 15 kamar dengan 3 tipe kualitas." << endl;
    
    tampilTipeKamar();
    pause();
    
    do {
        bersihLayar();
        header();
        tampilStatistik(statusKamar, bayar, totalPenyewa);
        menu();
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: {
    bersihLayar();
    header();
    cout << "\n========== TAMBAH PENYEWA BARU ==========" << endl;
    
    if (totalPenyewa >= 25) {
        cout << "Maaf! Kapasitas maksimal 25 penyewa sudah penuh." << endl;
        pause();
        break;
    }
    
    tampilKamarKosong(statusKamar, hargaKamar, tipeKamar);
    
    bool adaKosong = false;
    for (int i = 1; i <= 15; i++) {
        if (statusKamar[i] == "Kosong") {
            adaKosong = true;
            break;
        }
    }
    
    if (!adaKosong) {
        pause();
        break;
    }
    
    cout << "\n--- INPUT DATA PENYEWA ---" << endl;
    cout << "Nama penyewa: ";
    cin >> nama[totalPenyewa];
    
    cout << "Nomor telepon: ";
    cin >> telepon[totalPenyewa];
    
    do {
        cout << "Nomor kamar (1-15): ";
        cin >> kamar[totalPenyewa];
        
        if (kamar[totalPenyewa] < 1 || kamar[totalPenyewa] > 15) {
            cout << "Error: Nomor kamar harus antara 1-15!" << endl;
            continue;
        }
        
        if (statusKamar[kamar[totalPenyewa]] == "Terisi") {
            cout << "Error: Kamar sudah terisi! Pilih kamar lain." << endl;
            continue;
        }
        
        break;
    } while (true);
    
    cout << "Durasi sewa (bulan): ";
    cin >> durasi[totalPenyewa];
    
    cout << "Status pembayaran (Lunas/Belum): ";
    cin >> bayar[totalPenyewa];
    
    cout << "Tanggal Sewa (DD-MM-YYYY): ";
    cin >> tanggalSewa[totalPenyewa];  // Input tanggal sewa
    
    statusKamar[kamar[totalPenyewa]] = "Terisi";
    totalPenyewa++;
    
    simpanDataKeFile(nama, kamar, durasi, bayar, telepon, tanggalSewa, totalPenyewa);  // Menyimpan data termasuk tanggal
    
    cout << "\nBERHASIL! Penyewa baru telah ditambahkan." << endl;
    cout << "Tipe kamar: " << tipeKamar[kamar[totalPenyewa-1]] << endl;
    cout << "Biaya per bulan: Rp " << hargaKamar[kamar[totalPenyewa-1]] << endl;
    cout << "Total biaya: Rp " << (hargaKamar[kamar[totalPenyewa-1]] * durasi[totalPenyewa-1]) << endl;
    
    // Tampilkan fasilitas kamar yang dipilih
    cout << "\n--- FASILITAS KAMAR YANG ANDA PILIH ---" << endl;
    tampilkanFasilitasKamar(fasilitasKamar, kamar[totalPenyewa-1]);
    
    pause();
    break;
}
            
            case 2: {
                bersihLayar();
                header();
tampilStatusKamar(statusKamar, hargaKamar, tipeKamar);
				 pause();
                break;
            }
            
           case 3: {
    bersihLayar();
    header();
tampilDataPenyewa(nama, kamar, durasi, bayar, telepon, tanggalSewa, tipeKamar, hargaKamar, totalPenyewa);    

    if (totalPenyewa > 0) {
        cout << "\nDetail lengkap penyewa:" << endl;
        garis();

        for (int i = 0; i < totalPenyewa; i++) {
            cout << "\nPenyewa #" << (i+1) << endl;
            cout << "Nama           : " << nama[i] << endl;
            cout << "Telepon        : " << telepon[i] << endl;
            cout << "Kamar          : " << kamar[i] << " (Tipe " << tipeKamar[kamar[i]] << ")" << endl;
            cout << "Durasi         : " << durasi[i] << " bulan" << endl;
            cout << "Tanggal Sewa   : " << tanggalSewa[i] << endl;  // Menampilkan tanggal sewa
		    cout << "Status Bayar   : " << bayar[i] << endl;
            cout << "Total Biaya    : Rp " << (hargaKamar[kamar[i]] * durasi[i]) << endl;
            garis();
        }
    }

    pause();
    break;
}

            case 4: {
    bersihLayar();
    header();
    cout << "\n========== UPDATE STATUS BAYAR ==========" << endl;
    
    if (totalPenyewa == 0) {
        cout << "Belum ada data penyewa untuk diupdate." << endl;
        pause();
        break;
    }
    
    cout << "\nDaftar penyewa yang belum lunas:" << endl;
    garis();
    
    bool adaBelumLunas = false;
    for (int i = 0; i < totalPenyewa; i++) {
        if (bayar[i] == "Belum") {
            int totalBiaya = hargaKamar[kamar[i]] * durasi[i];
            cout << (i+1) << ". " << nama[i] << " - Kamar " << kamar[i] 
                 << " - Total Tagihan: Rp " << totalBiaya << " - Status: " << bayar[i] << endl;
            adaBelumLunas = true;
        }
    }
    
    if (!adaBelumLunas) {
        cout << "Semua penyewa sudah lunas!" << endl;
        pause();
        break;
    }
    
    cout << "\nDaftar semua penyewa:" << endl;
    garis();
    for (int i = 0; i < totalPenyewa; i++) {
        int totalBiaya = hargaKamar[kamar[i]] * durasi[i];
        cout << (i+1) << ". " << nama[i] << " - Kamar " << kamar[i] 
             << " - Tagihan: Rp " << totalBiaya << " - Status: " << bayar[i] << endl;
    }
    
    int nomorPenyewa;
    cout << "\nPilih nomor penyewa yang akan diupdate: ";
    cin >> nomorPenyewa;
    
    if (nomorPenyewa >= 1 && nomorPenyewa <= totalPenyewa) {
        if (bayar[nomorPenyewa-1] == "Belum") {
            int totalBiaya = hargaKamar[kamar[nomorPenyewa-1]] * durasi[nomorPenyewa-1];
            
            cout << "\n--- KONFIRMASI PEMBAYARAN ---" << endl;
            cout << "Nama Penyewa    : " << nama[nomorPenyewa-1] << endl;
            cout << "Kamar           : " << kamar[nomorPenyewa-1] << " (Tipe " << tipeKamar[kamar[nomorPenyewa-1]] << ")" << endl;
            cout << "Total Tagihan   : Rp " << totalBiaya << endl;
            cout << "\nApakah pembayaran sudah diterima? (y/n): ";
            
            char konfirmasi;
            cin >> konfirmasi;
            
            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                // Simpan ke history pembayaran
                historyPembayaran[totalPembayaran].setNamaPenyewa(nama[nomorPenyewa-1]);
                historyPembayaran[totalPembayaran].setNomorKamar(kamar[nomorPenyewa-1]);
                historyPembayaran[totalPembayaran].setJumlahBayar(totalBiaya);
                
                // Get current date
                time_t now = time(0);
                tm* ltm = localtime(&now);
                string tanggalHariIni = to_string(ltm->tm_mday) + "-" + 
                                       to_string(1 + ltm->tm_mon) + "-" + 
                                       to_string(1900 + ltm->tm_year);
                
                historyPembayaran[totalPembayaran].setTanggalBayar(tanggalHariIni);
                historyPembayaran[totalPembayaran].setMetodeBayar("Manual Update");
                historyPembayaran[totalPembayaran].setKeterangan("Status diupdate manual oleh admin");
                totalPembayaran++;
                
                // Update status pembayaran
                bayar[nomorPenyewa-1] = "Lunas";
                
                // Simpan data
                simpanDataKeFile(nama, kamar, durasi, bayar, telepon, tanggalSewa, totalPenyewa);
                simpanDataPembayaran(historyPembayaran, totalPembayaran);
                
                cout << "\n========== KONFIRMASI PEMBAYARAN ==========" << endl;
                cout << "Nama Penyewa    : " << nama[nomorPenyewa-1] << endl;
                cout << "Kamar           : " << kamar[nomorPenyewa-1] << endl;
                cout << "Jumlah Bayar    : Rp " << totalBiaya << endl;
                cout << "Tanggal         : " << tanggalHariIni << endl;
                cout << "Status          : LUNAS" << endl;
                cout << "=======================================" << endl;
                
                cout << "\nBERHASIL! Status pembayaran " << nama[nomorPenyewa-1] 
                     << " telah diubah menjadi LUNAS." << endl;
            } else {
                cout << "Update status dibatalkan." << endl;
            }
        } else {
            cout << "Pembayaran penyewa ini sudah lunas sebelumnya." << endl;
        }
    } else {
        cout << "Error: Nomor penyewa tidak valid!" << endl;
    }
    
    pause();
    break;
}
            
            case 5: {
                bersihLayar();
                header();
                cout << "\n========== HAPUS DATA PENYEWA ==========" << endl;
                
                if (totalPenyewa == 0) {
                    cout << "Belum ada data penyewa untuk dihapus." << endl;
                    pause();
                    break;
                }
                
                tampilDataPenyewa(nama, kamar, durasi, bayar, telepon, tanggalSewa, tipeKamar, hargaKamar, totalPenyewa);

                
                int nomorHapus;
                cout << "\nPilih nomor penyewa yang akan dihapus: ";
                cin >> nomorHapus;
                
                if (nomorHapus >= 1 && nomorHapus <= totalPenyewa) {
                    cout << "\nAnda yakin ingin menghapus data penyewa: " 
                         << nama[nomorHapus-1] << "? (y/n): ";
                    char konfirmasi;
                    cin >> konfirmasi;
                    
                    if (konfirmasi == 'y' || konfirmasi == 'Y') {
                        statusKamar[kamar[nomorHapus-1]] = "Kosong";
                        
                        for (int i = nomorHapus-1; i < totalPenyewa-1; i++) {
						    nama[i] = nama[i+1];
						    kamar[i] = kamar[i+1];
						    durasi[i] = durasi[i+1];
						    bayar[i] = bayar[i+1];
						    telepon[i] = telepon[i+1];
						    tanggalSewa[i] = tanggalSewa[i+1];  // Tambahkan ini
						}
                        
                        totalPenyewa--;
                        simpanDataKeFile(nama, kamar, durasi, bayar, telepon, tanggalSewa, totalPenyewa);
                        cout << "\nBERHASIL! Data penyewa telah dihapus." << endl;
                    } else {
                        cout << "Penghapusan dibatalkan." << endl;
                    }
                } else {
                    cout << "Error: Nomor penyewa tidak valid!" << endl;
                }
                
                pause();
                break;
            }
            
            case 6: {
                bersihLayar();
                header();
                cariDataPenyewa(nama, kamar, durasi, bayar, telepon, tipeKamar, hargaKamar, totalPenyewa);
                pause();
                break;
            }
            
            case 7: {
                menuFasilitasKamar(fasilitasKamar, tipeKamar, hargaKamar);
                break;
            }
            
            case 8: {
                laporanKeuangan(nama, kamar, durasi, bayar, tipeKamar, hargaKamar, totalPenyewa);
                break;
            }
            
            case 9: {
                bersihLayar();
                header();
                cout << "\n========== BACKUP DATA ==========" << endl;
                
                if (totalPenyewa == 0) {
                    cout << "Tidak ada data untuk di-backup." << endl;
                } else {
                    backupData(nama, kamar, durasi, bayar, telepon, totalPenyewa, tipeKamar, hargaKamar);
                }
                
                pause();
                break;
            }
            case 10: {
    menuPembayaran(nama, kamar, durasi, bayar, telepon, tanggalSewa, tipeKamar, hargaKamar, totalPenyewa, historyPembayaran, totalPembayaran, statusKamar);
    break;
}
            
            case 11: {
                menuPengurutan(nama, kamar, durasi, bayar, telepon, tanggalSewa, tipeKamar, hargaKamar, totalPenyewa);
                break;
            }
            
            case 0: {
                bersihLayar();
                header();
                cout << "\n========== TERIMA KASIH ==========" << endl;
                cout << "Program Sistem Pengelolaan Kos telah selesai." << endl;
                cout << "Data tersimpan otomatis di file 'data_penyewa.txt'" << endl;
                cout << "Sampai jumpa kembali!" << endl;
                cout << "==================================" << endl;
                break;
            }
            
            default: {
                cout << "\nERROR! Pilihan tidak valid." << endl;
                cout << "Silakan pilih menu 0-11 saja." << endl;
                pause();
                break;
}
        }
        
    } while (pilihan != 0);
    
    return 0;
}
