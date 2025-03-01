#include <iostream>
#include <string>
using namespace std;

// Struct untuk menyimpan informasi batalyon
struct Batalyon {
    int id;
    string namaJenderal;
    string tipePasukan;
    int jumlahPasukan;
};

// Kapasitas maksimum batalyon
const int MAX_BATALYON = 100; 
Batalyon batalyonList[MAX_BATALYON];
int jumlahBatalyon = 0;

// Daftar tipe pasukan yang tersedia
string tipePasukanTersedia[] = {"Infantry", "Kavaleri", "Archer"};
const int JUMLAH_TIPE = 3;

// Fungsi untuk mengecek apakah tipe pasukan valid
bool cekTipePasukan(string tipe) {
    for (int i = 0; i < JUMLAH_TIPE; i++) {
        if (tipePasukanTersedia[i] == tipe)
            return true;
    }
    return false;
}

// Fungsi untuk mengecek apakah jenderal sudah terdaftar
bool cekJenderal(string nama) {
    for (int i = 0; i < jumlahBatalyon; i++) {
        if (batalyonList[i].namaJenderal == nama)
            return true;
    }
    return false;
}


// Fungsi untuk menambah batalyon baru
void tambahBatalyon() {
    if (jumlahBatalyon >= MAX_BATALYON) {
        cout << "Data batalyon penuh!" << endl;
        return;
    }
    
    Batalyon baru;
    baru.id = jumlahBatalyon + 1;
    cin.ignore();
    
    cout << "Masukkan Nama Jenderal: ";
    getline(cin, baru.namaJenderal);
    if (cekJenderal(baru.namaJenderal)) {
        cout << "Error: Nama jenderal sudah terdaftar!" << endl;
        return;
    }
    
    cout << "Masukkan Tipe Pasukan (Infantry, Kavaleri, Archer): ";
    getline(cin, baru.tipePasukan);
    if (!cekTipePasukan(baru.tipePasukan)) {
        cout << "Error: Tipe pasukan tidak valid!" << endl;
        return;
    }
    
    cout << "Masukkan Jumlah Pasukan: ";
    cin >> baru.jumlahPasukan;
    if (baru.jumlahPasukan < 1) {
        cout << "Error: Jumlah pasukan harus lebih dari 0!" << endl;
        return;
    }
    
    batalyonList[jumlahBatalyon++] = baru;
    cout << "Batalyon berhasil ditambahkan!" << endl;
    system ("pause");
    system ("cls");
}

// Fungsi untuk mencari batalyon menggunakan binary search
int binarySearch(string nama) {
    int left = 0, right = jumlahBatalyon - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (batalyonList[mid].namaJenderal == nama)
            return mid;
        else if (batalyonList[mid].namaJenderal < nama)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Fungsi untuk mencari batalyon berdasarkan nama jenderal
void cariBatalyon() {
    string nama;
    cin.ignore();
    cout << "Masukkan Nama Jenderal yang Dicari: ";
    getline(cin, nama);
    
    int hasil = binarySearch(nama);
    if (hasil != -1) {
        cout << "Batalyon Ditemukan!\nID: " << batalyonList[hasil].id
             << "\nNama Jenderal: " << batalyonList[hasil].namaJenderal
             << "\nTipe Pasukan: " << batalyonList[hasil].tipePasukan
             << "\nJumlah Pasukan: " << batalyonList[hasil].jumlahPasukan << endl;
             
    } else {
        cout << "Error: Batalyon tidak ditemukan!" << endl;
    }
   
    
}

// Fungsi untuk menampilkan menu utama
void menu() {
    int pilihan;
    do {
        
        cout << "\nMenu:\n1. Tambah Batalyon\n2. Cari Batalyon\n3. Keluar\nPilihan: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1: tambahBatalyon(); break;
            case 2: cariBatalyon(); break;
            case 3: cout << "Keluar dari program." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
        cin.ignore();
    } while (pilihan != 3);
}

// Fungsi utama untuk menjalankan program
int main() {
    menu();
    return 0;
}
