// ============================================================
//  PRAKTIKUM STRUKTUR DATA
//  Soal 3 : Antrian Pemesanan Makanan di Kantin
//  Nama   : Syauqi Nuzul Abdi
//  NIM    : 202512042
//  Konsep : Queue<struct> – menyimpan data majemuk dalam antrian
// ============================================================

#include <iostream>   // cin, cout, endl
#include <queue>      // std::queue
#include <string>     // std::string
using namespace std;

// ------------------------------------------------------------
//  Struct Pesanan
//  Mewakili satu pesanan yang terdiri dari dua field.
//  Dengan struct, satu elemen queue dapat menyimpan lebih dari
//  satu informasi sekaligus.
// ------------------------------------------------------------
struct Pesanan {
    string namaPembeli;   // siapa yang memesan
    string menuPesanan;   // apa yang dipesan
};

// ------------------------------------------------------------
//  cetakPesanan()
//  Helper: mencetak satu objek Pesanan dengan format rapi.
// ------------------------------------------------------------
void cetakPesanan(int no, const Pesanan& p) {
    cout << "  " << no << ". "
         << p.namaPembeli << "  →  " << p.menuPesanan << endl;
}

// ------------------------------------------------------------
//  tambahPesanan()
//  Meminta input nama & menu, lalu enqueue ke belakang antrian.
// ------------------------------------------------------------
void tambahPesanan(queue<Pesanan>& antrian) {
    Pesanan baru;

    cin.ignore();   // bersihkan buffer sebelum getline
    cout << "  Nama Pembeli : ";
    getline(cin, baru.namaPembeli);   // terima nama lengkap

    cout << "  Menu Pesanan : ";
    getline(cin, baru.menuPesanan);   // terima nama menu

    antrian.push(baru);   // enqueue → masuk ke BELAKANG

    cout << "  ✔ Pesanan berhasil ditambahkan." << endl;
    cout << "  Total antrian: " << antrian.size() << endl;
}

// ------------------------------------------------------------
//  prosesPesanan()
//  Mengambil pesanan dari DEPAN antrian untuk diproses
//  (front → tampil, pop → hapus dari antrian).
// ------------------------------------------------------------
void prosesPesanan(queue<Pesanan>& antrian) {
    if (antrian.empty()) {
        cout << "  [!] Tidak ada pesanan dalam antrian." << endl;
        return;
    }

    Pesanan depan = antrian.front();   // baca pesanan terdepan
    antrian.pop();                     // dequeue → hapus dari depan

    cout << "  🍽  Memproses pesanan :" << endl;
    cout << "      Pembeli : " << depan.namaPembeli << endl;
    cout << "      Menu    : " << depan.menuPesanan << endl;
    cout << "  Sisa antrian: " << antrian.size() << endl;
}

// ------------------------------------------------------------
//  tampilDaftar()
//  Mencetak semua pesanan yang masih antri.
//  Pass by value → salinan antrian, aslinya tidak berubah.
// ------------------------------------------------------------
void tampilDaftar(queue<Pesanan> antrian) {
    if (antrian.empty()) {
        cout << "  [Tidak ada pesanan]" << endl;
        return;
    }

    cout << "\n  ╔══════════════════════════════════╗" << endl;
    cout << "  ║         DAFTAR PESANAN           ║" << endl;
    cout << "  ╚══════════════════════════════════╝" << endl;

    int no = 1;
    while (!antrian.empty()) {
        cetakPesanan(no++, antrian.front());
        antrian.pop();
    }
}

// ------------------------------------------------------------
//  cekDepan()
//  Menampilkan pesanan paling depan TANPA menghapusnya.
//  Hanya menggunakan front() → antrian tidak berubah.
// ------------------------------------------------------------
void cekDepan(const queue<Pesanan>& antrian) {
    if (antrian.empty()) {
        cout << "  [!] Antrian kosong." << endl;
        return;
    }

    // front() hanya membaca, tidak memodifikasi antrian
    const Pesanan& depan = antrian.front();

    cout << "\n  Pesanan paling depan:" << endl;
    cout << "  Pembeli : " << depan.namaPembeli << endl;
    cout << "  Menu    : " << depan.menuPesanan << endl;
}

// ------------------------------------------------------------
//  main()
// ------------------------------------------------------------
int main() {
    queue<Pesanan> antrian;   // antrian berisi objek struct Pesanan
    int pilihan;

    cout << "========================================" << endl;
    cout << "    SISTEM ANTRIAN KANTIN KAMPUS        " << endl;
    cout << "========================================" << endl;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Tambah Pesanan" << endl;
        cout << "2. Proses Pesanan Berikutnya" << endl;
        cout << "3. Tampilkan Daftar Pesanan" << endl;
        cout << "4. Cek Pesanan Paling Depan" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih : ";
        cin  >> pilihan;

        switch (pilihan) {
            case 1: tambahPesanan(antrian); break;
            case 2: prosesPesanan(antrian); break;
            case 3: tampilDaftar(antrian);  break;
            case 4: cekDepan(antrian);      break;
            case 5: cout << "\nKasir ditutup. Terima kasih!\n"; break;
            default: cout << "  [!] Pilihan tidak valid.\n";
        }

    } while (pilihan != 5);

    return 0;
}
