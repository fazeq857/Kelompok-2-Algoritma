#include <iostream>
using namespace std;

class RecentCounter {
private:
    int* records; 
    int head;     
    int tail;     

public:
// Constructor 
    RecentCounter() {
        records = new int[10005]; // Meminjam Ruang memori
        head = 0;
        tail = 0;
    }
    
    // Destructor (Mencegah Memory Leak)
    ~RecentCounter() {
        delete[] records;
    }
    
    int ping(int t) {
        // Masuk (Enqueue), waktu panggilan baru di posisi 'tail', lalu geser tail
        records[tail] = t;
        tail++;
        
        // Pembersihan Data Basi (Dequeue) Geser 'head'
        // jika waktu di posisi head sudah lebih dari 3000ms yang lalu
        while (head < tail && records[head] < t - 3000) {
            head++;
        }
        
        // Menghitung total (Output)
        return tail - head;
    }
};

int main() {
    RecentCounter* obj = new RecentCounter();
    
    cout << "--Recent call--" << endl;
    cout << "Ping pada 1ms    : " << obj->ping(1) << " panggilan yg valid" << endl;
    cout << "Ping pada 100ms  : " << obj->ping(100) << " panggilan yg valid" << endl;
    cout << "Ping pada 3001ms : " << obj->ping(3001) << " panggilan yg valid" << endl;
    cout << "Ping pada 3002ms : " << obj->ping(3002) << " panggilan yg valid" << endl;
    
    delete obj; 
    
    return 0;
}