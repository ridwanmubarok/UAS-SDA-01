#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Buat class Orang untuk menyimpan data nama dan alamat
class Orang {
public:
    string nama;
    string alamat;

    // Constructor untuk membuat objek Orang
    Orang(string nama, string alamat) : nama(nama), alamat(alamat) {}
};

// Fungsi untuk sorting memakai Bubble Sort
void sortingBubble(vector<Orang>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Kalo nama yang sekarang lebih gede dari nama selanjutnya, menukar posisinya
            if (arr[j].nama > arr[j + 1].nama) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Fungsi untuk sorting memakai Selection Sort
void sortingSelection(vector<Orang>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            // Mencari index dengan nama terkecil
            if (arr[j].nama < arr[minIdx].nama) {
                minIdx = j;
            }
        }
        // Menukar posisi elemen terkecil ke posisi yang sesuai
        swap(arr[minIdx], arr[i]);
    }
}

// Fungsi untuk menampilkan array
void cetakArray(const vector<Orang>& arr) {
    cout << "Nama\t\tAlamat\n";
    for (const auto& p : arr) {
        cout << p.nama << "\t\t" << p.alamat << "\n";
    }
    cout << "\n";
}

int main() {
    // Buat vector untuk menyimpan data nama dan alamat
    vector<Orang> orang = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}
    };

    // Menampilkan array awal sebelum di-sort
    cout << "Original Array:\n";
    cetakArray(orang);

    // Sorting memakai fungsi Bubble Sort yang sudah didefinisikan sebelumnya
    vector<Orang> bubbleSortArray = orang;
    sortingBubble(bubbleSortArray);
    cout << "Setelah Bubble Sort:\n";
    cetakArray(bubbleSortArray);

    // Sorting memakai fungsi Selection Sort yang sudah didefinisikan sebelumnya
    vector<Orang> selectionSortArray = orang;
    sortingSelection(selectionSortArray);
    cout << "Setelah Selection Sort:\n";

    // menampilkan array setelah di-sort
    cetakArray(selectionSortArray);

    return 0;
}