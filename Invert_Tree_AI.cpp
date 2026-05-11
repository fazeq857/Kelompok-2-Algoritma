#include <iostream>
#include <queue>

using namespace std;

// 1. Definisi struktur untuk node pada Binary Tree (Sesuai dengan LeetCode)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2. Kelas Solusi yang berisi logika Invert Binary Tree
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base case: Jika node kosong, kembalikan nullptr
        if (root == nullptr) {
            return nullptr;
        }
        
        // Simpan pointer anak kiri sementara
        TreeNode* temp = root->left;
        
        // Tukar anak kiri dan anak kanan
        root->left = root->right;
        root->right = temp;
        
        // Rekursi untuk anak kiri dan kanan yang baru
        invertTree(root->left);
        invertTree(root->right);
        
        // Kembalikan node root yang sudah diproses
        return root;
    }
};

// ==========================================
// Fungsi Bantuan (Helper Functions)
// ==========================================

// Fungsi untuk mencetak tree secara Level-Order (seperti format array di LeetCode)
void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "[]" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    cout << "[ ";
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr != nullptr) {
            cout << curr->val << " ";
            // Masukkan anak-anaknya ke dalam antrean (queue)
            q.push(curr->left);
            q.push(curr->right);
        } else {
            // Untuk memvisualisasikan node yang kosong
            cout << "null "; 
        }
    }
    cout << "]" << endl;
}

// 3. Fungsi Main untuk menjalankan program
int main() {
    // Membangun pohon uji coba (Test Case 1 dari LeetCode)
    // Input: root = [4,2,7,1,3,6,9]
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "--- Invert Binary Tree ---" << endl;
    
    // Cetak tree sebelum di-invert
    cout << "Sebelum Invert : ";
    printTree(root);

    // Proses Invert
    Solution sol;
    TreeNode* invertedRoot = sol.invertTree(root);

    // Cetak tree setelah di-invert
    cout << "Setelah Invert : ";
    printTree(invertedRoot);

    // Catatan: Dalam program C++ yang sesungguhnya (production), 
    // pastikan untuk selalu mendealokasikan memori (menggunakan delete) 
    // untuk mencegah memory leak. Di sini dilewati agar kode tetap fokus pada algoritma.

    return 0;
}