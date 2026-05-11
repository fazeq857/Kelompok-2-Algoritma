#include <iostream>

using namespace std;

class RecentCounter {
private:
    int* records; // Array dinamis buatan sendiri
    int head;     // Penunjuk elemen terdepan (paling lama)
    int tail;     // Penunjuk elemen paling belakang (baru masuk)

public:
    RecentCounter() {
        // Alokasi memori manual untuk 10005 elemen 
        // (batas maksimal panggilan di LeetCode adalah 10.000)
        records = new int[10005]; 
        head = 0;
        tail = 0;
    }
    
    // Destructor untuk membersihkan memori (mencegah memory leak)
    ~RecentCounter() {
        delete[] records;
    }
    
    int ping(int t) {
        // Masukkan waktu panggilan baru di posisi 'tail', lalu geser tail
        records[tail] = t;
        tail++;
        
        // Geser 'head' jika waktu di posisi head sudah lebih dari 3000ms yang lalu
        while (head < tail && records[head] < t - 3000) {
            head++;
        }
        
        // Jumlah panggilan yang valid adalah jarak antara tail dan head
        return tail - head;
    }
};

// Fungsi main ditambahkan agar program bisa di-Run di VS Code
int main() {
    // Membuat objek dari class RecentCounter
    RecentCounter* obj = new RecentCounter();
    
    cout << "--- Pengujian Queue Versi From Scratch ---" << endl;
    cout << "Ping di 1ms    : " << obj->ping(1) << " panggilan valid" << endl;
    cout << "Ping di 100ms  : " << obj->ping(100) << " panggilan valid" << endl;
    cout << "Ping di 3001ms : " << obj->ping(3001) << " panggilan valid" << endl;
    cout << "Ping di 3002ms : " << obj->ping(3002) << " panggilan valid" << endl;
    
    // Membersihkan memori objek (sangat penting untuk mencegah memory leak)
    delete obj; 
    
    return 0;
}