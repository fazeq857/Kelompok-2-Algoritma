#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
private:
    queue<int> q; // Menggunakan struktur data queue bawaan C++

public:
    RecentCounter() {}
    
    int ping(int t) {
        q.push(t); // Masukkan waktu panggilan baru ke antrean (otomatis di posisi tail)
        
        // Hapus elemen di depan antrean (head) jika waktunya lebih dari 3000ms yang lalu
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        
        // Sisa elemen di queue adalah jumlah panggilan yang valid
        return q.size();
    }
};

// Fungsi main ditambahkan agar program bisa di-Run di VS Code
int main() {
    // Membuat objek dari class RecentCounter
    RecentCounter* obj = new RecentCounter();
    
    cout << "--- Pengujian Queue ---" << endl;
    cout << "Ping di 1ms    : " << obj->ping(1) << " panggilan valid" << endl;
    cout << "Ping di 100ms  : " << obj->ping(100) << " panggilan valid" << endl;
    cout << "Ping di 3001ms : " << obj->ping(3001) << " panggilan valid" << endl;
    cout << "Ping di 3002ms : " << obj->ping(3002) << " panggilan valid" << endl;
    
    // Membersihkan memori objek
    delete obj; 
    
    return 0;
}