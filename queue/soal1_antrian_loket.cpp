// ============================================================
//  PRAKTIKUM STRUKTUR DATA
//  Soal 1 : Simulasi Antrian Loket Pembayaran
//  Nama   : Syauqi Nuzul Abdi
//  NIM    : 202512042
//  Konsep : Queue (FIFO – First In, First Out)
// ============================================================

#include <iostream>   // cin, cout, endl
#include <queue>      // std::queue
#include <string>     // std::string
using namespace std;

// ------------------------------------------------------------
//  tampilAntrian()
//  Mencetak seluruh isi antrian tanpa mengubah antrian asli.
//  Trik  : salin ke variabel sementara (temp), lalu pop satu
//          per satu dari temp sambil mencetak.
// ------------------------------------------------------------
void tampilAntrian(queue<string> antrian) {
    // Parameter di-pass by value → salinan otomatis terbentuk
    // sehingga antrian asli di main() tidak terpengaruh.

    if (antrian.empty()) {
        cout << "  [Antrian kosong]" << endl;
        return;
    }

    cout << "\n╔══════════════════════╗" << endl;
    cout << "  ║    DAFTAR ANTRIAN    ║" << endl;
    cout << "  ╚══════════════════════╝" << endl;

    int nomor = 1;
    while (!antrian.empty()) {
        cout << "  " << nomor++ << ". " << antrian.front() << endl;
        antrian.pop();   // hapus dari salinan, bukan aslinya
    }
}

// ------------------------------------------------------------
//  tambahPelanggan()
//  Meminta input nama lalu mendorong (push) ke antrian.
// ------------------------------------------------------------
void tambahPelanggan(queue<string>& antrian) {
    // Parameter by reference → perubahan langsung ke antrian asli

    string nama;
    cout << "  Masukkan nama pelanggan : ";
    cin.ignore();               // buang newline sisa dari cin >>
    getline(cin, nama);         // baca nama lengkap (termasuk spasi)

    antrian.push(nama);         // enqueue → masuk ke bagian BELAKANG
    cout << "  ✔ " << nama
         << " berhasil ditambahkan ke antrian." << endl;
    cout << "  Posisi    : " << antrian.size() << endl;
}

// ------------------------------------------------------------
//  layaniPelanggan()
//  Melayani satu pelanggan di bagian DEPAN antrian (dequeue).
// ------------------------------------------------------------
void layaniPelanggan(queue<string>& antrian) {
    if (antrian.empty()) {
        cout << "  [!] Antrian kosong, tidak ada pelanggan." << endl;
        return;
    }

    string dilayani = antrian.front();  // intip siapa yang terdepan
    antrian.pop();                      // dequeue → hapus dari depan

    cout << "  ✔ Melayani  : " << dilayani << endl;
    cout << "  Sisa antrian: " << antrian.size()
         << " pelanggan" << endl;
}

// ------------------------------------------------------------
//  main()
// ------------------------------------------------------------
int main() {
    queue<string> antrian;  // antrian bertipe string (nama pelanggan)
    int pilihan;

    cout << "========================================" << endl;
    cout << "   SISTEM ANTRIAN LOKET PEMBAYARAN      " << endl;
    cout << "========================================" << endl;

    do {
        // Tampilkan menu utama
        cout << "\n--- MENU ---" << endl;
        cout << "1. Tambah Pelanggan" << endl;
        cout << "2. Layani Pelanggan" << endl;
        cout << "3. Tampilkan Antrian" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih : ";
        cin  >> pilihan;

        switch (pilihan) {
            case 1: tambahPelanggan(antrian);  break;
            case 2: layaniPelanggan(antrian);  break;
            case 3: tampilAntrian(antrian);    break;
            case 4: cout << "\nProgram selesai. Sampai jumpa!\n"; break;
            default: cout << "  [!] Pilihan tidak valid.\n";
        }

    } while (pilihan != 4);

    return 0;
}
