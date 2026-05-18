#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 1. Definisi Struktur Node Pohon Biner
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 2. Kelas Solusi dengan Swap Manual (Pakai temp)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base case: jika node kosong
        if (!root) return nullptr;
        
        // Tukar posisi anak kiri dan kanan secara manual dengan variabel temp
        TreeNode* temp = root->left;   // Simpan anak kiri ke temp
        root->left = root->right;      // Anak kiri diganti dengan anak kanan
        root->right = temp;            // Anak kanan diganti dengan temp (anak kiri lama)
        
        // Rekursi ke bawah untuk setiap cabang
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};

// ==========================================
// FUNGSI BANTUAN (UNTUK TESTING)
// ==========================================

// Fungsi untuk membangun pohon dari array/vector (Level-order)
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Node Kiri
        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        // Node Kanan
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Fungsi untuk mencetak pohon (Level-order)
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "[]";
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    cout << "[ ";
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
    }
    cout << "]";
}

// 3. Fungsi Main (Titik Eksekusi)
int main() {
    Solution sol;

    // Contoh Input LeetCode: [4, 2, 7, 1, 3, 6, 9]
    vector<int> input = {4, 2, 7, 1, 3, 6, 9};

    TreeNode* root = buildTree(input);

    cout << "--- Program Invert Binary Tree ---" << endl;
    
    cout << "Pohon Asal     : ";
    printLevelOrder(root);
    cout << endl;

    // Jalankan fungsi invert
    root = sol.invertTree(root);

    cout << "Setelah Invert : ";
    printLevelOrder(root);
    cout << endl;

    return 0;
}