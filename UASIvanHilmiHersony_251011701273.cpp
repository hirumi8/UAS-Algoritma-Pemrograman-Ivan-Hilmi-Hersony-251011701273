#include <iostream>
#include <iomanip>
using namespace std;

struct Pegawai {
    string nama;
    int jamKerja, honor, honorLembur, total;
};

class Gaji {
public:
    int hitungLembur(int jam) {
        if (jam > 8)
            return (jam - 8) * 1500;
        return 0;
    }

    int hitungTotal(int honor, int lembur) {
        return honor + lembur;
    }
};

int main() {
    Pegawai *pegawai = nullptr;
    Gaji gaji;
    int menu;

    do {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Input dan Tampilkan Laporan Gaji\n";
        cout << "2. Keluar\n";
        cout << "Pilih Menu : ";
        cin >> menu;

        while (menu < 1 || menu > 2) {
            cout << "Menu tidak valid! Pilih 1 atau 2: ";
            cin >> menu;
        }

        if (menu == 1) {
            int jumlah;
            cout << "\nMasukkan jumlah pegawai: ";
            cin >> jumlah;

            pegawai = new Pegawai[jumlah];

            for (int i = 0; i < jumlah; i++) {
                cout << "\nPegawai ke-" << i + 1 << endl;
                cout << "Nama      : ";
                cin >> pegawai[i].nama;

                do {
                    cout << "Jam Kerja : ";
                    cin >> pegawai[i].jamKerja;
                } while (pegawai[i].jamKerja <= 0);

                pegawai[i].honor = 25000;
                pegawai[i].honorLembur = gaji.hitungLembur(pegawai[i].jamKerja);
                pegawai[i].total = gaji.hitungTotal(
                    pegawai[i].honor,
                    pegawai[i].honorLembur
                );
            }

            int totalKeseluruhan = 0;

            cout << "\nPT. Meriang Gembira\n";
            cout << "Tanggal : 12 Januari 2026\n";
            cout << "========================================================\n";
            cout << left << setw(4) << "No"
                 << setw(12) << "Nama"
                 << setw(10) << "Honor"
                 << setw(12) << "Jam Kerja"
                 << setw(15) << "Honor Lembur"
                 << setw(10) << "Total" << endl;
            cout << "========================================================\n";

            for (int i = 0; i < jumlah; i++) {
                cout << left << setw(4) << i + 1
                     << setw(12) << pegawai[i].nama
                     << setw(10) << pegawai[i].honor
                     << setw(12) << pegawai[i].jamKerja
                     << setw(15) << pegawai[i].honorLembur
                     << setw(10) << pegawai[i].total << endl;

                totalKeseluruhan += pegawai[i].total;
            }

            cout << "========================================================\n";
            cout << "Total Honor Pegawai Sebesar : Rp " << totalKeseluruhan << endl;

            delete[] pegawai;
            pegawai = nullptr;
        }

    } while (menu != 2);

    cout << "\nTerima kasih telah menggunakan program ini\n";

    return 0;
}