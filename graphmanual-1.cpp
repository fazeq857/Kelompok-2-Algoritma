#include <iostream>
#include <vector>

using namespace std;

      class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusting(n + 1, 0); 
        vector<int> trusted(n + 1, 0);
        
        for (int i = 0; i < trust.size(); i++) {
            int outgoing = trust[i][0];
            int incoming = trust[i][1];
            
            trusting[outgoing]++;
            trusted[incoming]++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (trusted[i] == n - 1 && trusting[i] == 0) {
                return i;
            }
        }
        
        return -1;
    }
};

int main() {
    Solution solusi;
   
    //Deklarasi variabel n
    int n = 5;
   
    //Deklarasi pasangan trust
    vector<vector<int>> trust = {
        {1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 4}, {2, 5}, {3, 1}, {3, 4}, {3, 5}, {4, 2}, {4, 5} //Deklarasikan pasangan nodes dalam bentuk array
    };

    //Memanggil fungsi findJudge dan menyimpan hasilnya
    int results = solusi.findJudge(n, trust); //Memanggil fungsi findjudge dari class solution, dengan menggunakan n & trust sebagai parameter

    //Menampilkan hasil
    if (results != -1) {
        cout << "Output: " << results << endl;
        cout << "Penjelasan: Hakim kotanya adalah orang ke-" << results << endl;
    //Menampilkan hasil kalau salah
    } else {
        cout << "Output: -1" << endl;
        cout << "Penjelasan: Tidak ada hakim kota yang memenuhi syarat." << endl;
    }

    return 0;
}