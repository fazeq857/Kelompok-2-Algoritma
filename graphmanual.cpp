#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> percaya_orang_lain(n + 1, 0); 
        vector<int> dipercaya_orang(n + 1, 0);
        
        for (int i = 0; i < trust.size(); i++) {
            int pemberi = trust[i][0];
            int penerima = trust[i][1];
            
            percaya_orang_lain[pemberi]++;
            dipercaya_orang[penerima]++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (dipercaya_orang[i] == n - 1 && percaya_orang_lain[i] == 0) {
                return i;
            }
        }
        
        return -1;
    }
};

int main() {
    Solution solusi;
   
    int n = 4;
   
    vector<vector<int>> trust = {
        {1, 3}, {2, 3}, {4, 3}, 
        {1, 2}, {2, 4}
    };

    int hasil = solusi.findJudge(n, trust);

    if (hasil != -1) {
        cout << "Output: " << hasil << endl;
        cout << "Penjelasan: Hakim kotanya adalah orang ke-" << hasil << endl;
    } else {
        cout << "Output: -1" << endl;
        cout << "Penjelasan: Tidak ada hakim kota yang memenuhi syarat." << endl;
    }

    return 0;
}