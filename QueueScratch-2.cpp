#include <iostream>

using namespace std;

class RecentCounter {
private:
    int* records; 
    int head;     
    int tail;     

public:
    RecentCounter() {
        records = new int[10005]; 
        head = 0;
        tail = 0;
    }
    
    // Destructor
    ~RecentCounter() {
        delete[] records;
    }
    
    int ping(int t) {
        // waktu panggilan baru di posisi 'tail', lalu geser tail
        records[tail] = t;
        tail++;
        
        // Geser 'head' jika waktu di posisi head sudah lebih dari 3000ms yang lalu
        while (head < tail && records[head] < t - 3000) {
            head++;
        }
        
        return tail - head;
    }
};

int main() {
    RecentCounter* obj = new RecentCounter();
    
    cout << "--Recent call--" << endl;
    cout << "Ping pada 1ms    : " << obj->ping(1) << " panggilan yg valid" << endl;
    cout << "Ping pada 50ms   : " << obj->ping(50) << " panggilan yg valid" << endl;
    cout << "Ping pada 2998ms : " << obj->ping(2998) << " panggilan yg valid" << endl;
    cout << "Ping pada 3001ms : " << obj->ping(3001) << " panggilan yg valid" << endl;
    cout << "Ping pada 3051ms : " << obj->ping(3051) << " panggilan yg valid" << endl;
    
    delete obj; 
    
    return 0;
}