// Sorting Peringkat.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 

#include <iostream>


using namespace std;

void tampilkan(int arr[], int n){
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void quickshortAsc(int arr[], int low, int high){
    int i = low, j = high;
    int pivot = arr[(low + high) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (low < j)
        quickshortAsc(arr, low, j);
    if (i < high)
        quickshortAsc(arr, i, high);
}

void quickShortDesc(int arr[], int low, int high) {
    int i = low, j = high;
    int pivot = arr[(low + high) / 2];

    while (i <= j)
    {
        while (arr[i] > pivot) i++;
        while (arr[j] < pivot) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (low < j)
        quickShortDesc(arr, low, j);
    if (i < high)
        quickShortDesc(arr, i, high);

}
int main()
{
    while (true)
    {


        int n;

        cout << "Masukkan jumlah data : ";
        cin >> n;

        int arr[100];



        for (int i = 0; i < n; i++) {
            cout << "Masukkan data ke-" << i + 1 << " : ";
            cin >> arr[i];
        }

        int pilihan;
        cout << "Pilih sorting : " << endl;
        cout << "1. Ascending" << endl;
        cout << "2. Descending" << endl;
        cin >> pilihan;

        if (pilihan == 1) {
            quickshortAsc(arr, 0, n - 1);
            cout << "Hasil sorting Ascending : ";
            tampilkan(arr, n);
        }
        else if (pilihan == 2) {
            quickShortDesc(arr, 0, n - 1);
            cout << "Hasil sorting Descending : ";
            tampilkan(arr, n);
        }
        else {
            cout << "Pilihan tidak valid" << endl;
        }
    }
	return 0;
}