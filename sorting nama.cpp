#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Fungsi untuk menukar dua string
void tukar(string& a, string& b) {
    string temp = a;
    a = b;
    b = temp;
}

// Fungsi partisi untuk Quick Sort
int partisi(vector<string>& arr, int low, int high) {
    string pivot = arr[high]; // Memilih elemen terakhir sebagai pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // Jika nama saat ini lebih kecil dari pivot (urutan alfabet)
        if (arr[j] < pivot) {
            i++;
            tukar(arr[i], arr[j]);
        }
    }
    tukar(arr[i + 1], arr[high]);
    return (i + 1);
}

// Fungsi Quick Sort utama
void quickSort(vector<string>& arr, int low, int high) {
    if (low < high) {
        int pi = partisi(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    while (true) {
        int n;

        cout << "Masukkan jumlah data : ";
        if (!(cin >> n) || n <= 0) {
            cerr << "Jumlah data tidak valid.\n";
            return 1;
        }

        vector<string> nama;
        nama.reserve(n);

        string line;
        getline(cin, line); // consume endline after reading n

        for (int i = 0; i < n; i++) {
            cout << "Masukkan data ke-" << i + 1 << " : ";
            getline(cin, line);
            // Jika pengguna menekan enter kosong, minta ulang
            if (line.empty()) {
                // pastikan membaca sesuatu (opsional: bisa loop sampai tidak kosong)
                getline(cin, line);
            }
            nama.push_back(line);
        }

        cout << "Nama sebelum sorting: " << endl;
        for (const string& s : nama) cout << s << endl;
        cout << endl;

        quickSort(nama, 0, n - 1);

        cout << "Nama setelah sorting: " << endl;
        for (const string& s : nama) cout << s << endl;
    }
    return 0;
}