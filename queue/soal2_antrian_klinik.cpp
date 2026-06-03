// ============================================================
//  PRAKTIKUM STRUKTUR DATA
//  Soal 2 : Antrian Nomor Urut Klinik (Penomoran Otomatis)
//  Nama   : Syauqi Nuzul Abdi
//  NIM    : 202512042
//  Konsep : Queue<int> + Counter untuk nomor unik & berurutan
// ============================================================

#include <iostream>   // cin, cout, endl
#include <queue>      // std::queue
using namespace std;

// ------------------------------------------------------------
//  ambilNomor()
//  Pasien baru mengambil nomor antrian.
//  Counter nomorUrut selalu bertambah → nomor tidak pernah
//  berulang meski pasien sebelumnya sudah dipanggil.
// ------------------------------------------------------------
void ambilNomor(queue<int>& antrian, int& nomorUrut) {
    // Increment counter SEBELUM push agar dimulai dari 1
    nomorUrut++;

    antrian.push(nomorUrut);    // enqueue nomor baru ke belakang

    cout << "  ✔ Nomor antrian Anda : " << nomorUrut << endl;
    cout << "  Posisi dalam antrian : " << antrian.size() << endl;
}

// ------------------------------------------------------------
//  panggilPasien()
//  Dokter memanggil pasien terdepan (nomor terkecil = pertama
//  masuk), lalu menghapusnya dari antrian.
// ------------------------------------------------------------
void panggilPasien(queue<int>& antrian) {
    if (antrian.empty()) {
        cout << "  [!] Tidak ada pasien dalam antrian." << endl;
        return;
    }

    int nomor = antrian.front();    // baca nomor terdepan
    antrian.pop();                  // dequeue → hapus dari depan

    cout << "  📢 Memanggil pasien nomor : " << nomor << endl;
    cout << "  Sisa antrian             : "
         << antrian.size() << " pasien" << endl;
}

// ------------------------------------------------------------
//  lihatAntrian()
//  Menampilkan semua nomor yang masih menunggu.
//  Gunakan parameter by value agar antrian asli aman.
// ------------------------------------------------------------
void lihatAntrian(queue<int> antrian) {
    if (antrian.empty()) {
        cout << "  [Antrian kosong]" << endl;
        return;
    }

    cout << "\n  ╔══════════════════════╗" << endl;
    cout << "  ║   ANTRIAN KLINIK     ║" << endl;
    cout << "  ╚══════════════════════╝" << endl;

    int urutan = 1;
    while (!antrian.empty()) {
        cout << "  Antrian ke-" << urutan++
             << "  →  Nomor " << antrian.front() << endl;
        antrian.pop();
    }
}

// ------------------------------------------------------------
//  main()
// ------------------------------------------------------------
int main() {
    queue<int> antrian;     // menyimpan nomor-nomor antrian pasien
    int nomorUrut = 0;      // counter global; mulai 0, naik saat pasien ambil nomor
    int pilihan;

    cout << "========================================" << endl;
    cout << "     SISTEM ANTRIAN KLINIK              " << endl;
    cout << "========================================" << endl;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Ambil Nomor Antrian" << endl;
        cout << "2. Panggil Pasien Berikutnya" << endl;
        cout << "3. Lihat Antrian Saat Ini" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih : ";
        cin  >> pilihan;

        switch (pilihan) {
            case 1: ambilNomor(antrian, nomorUrut); break;
            case 2: panggilPasien(antrian);         break;
            case 3: lihatAntrian(antrian);          break;
            case 4: cout << "\nSistem antrian ditutup.\n"; break;
            default: cout << "  [!] Pilihan tidak valid.\n";
        }

    } while (pilihan != 4);

    return 0;
}
