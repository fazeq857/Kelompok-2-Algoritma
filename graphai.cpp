#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trust_scores(n + 1, 0);
        
        for (auto& t : trust) {
            trust_scores[t[0]]--; // Orang yang mempercayai kehilangan poin
            trust_scores[t[1]]++; // Orang yang dipercayai mendapat poin
        }
        
        for (int i = 1; i <= n; i++) {
            // Hakim kota harus memiliki skor n - 1
            if (trust_scores[i] == n - 1) {
                return i;
            }
        }
        
        return -1; 
    }
};

int main() {
    Solution solusi;
    
    // Inisialisasi variabel berdasarkan soalmu
    int n = 5;
    
    // Penulisan array 2D dalam C++ menggunakan kurung kurawal {}
    vector<vector<int>> trust = {
        {1, 2}, {1, 3}, {3, 2}, {4, 5}, 
        {1, 5}, {4, 2}, {5, 2}, {3, 5}
    };

    // Memanggil fungsi findJudge
    int hasil = solusi.findJudge(n, trust);

    // Menampilkan output ke layar
    if (hasil != -1) {
        cout << "Output: " << hasil << endl;
        cout << "Penjelasan: Hakim kotanya adalah orang ke-" << hasil << endl;
    } else {
        cout << "Output: -1" << endl;
        cout << "Penjelasan: Tidak ada hakim kota yang memenuhi syarat." << endl;
    }

    return 0;
}