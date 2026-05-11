#include <iostream>  
#include <queue>     
using namespace std;


// DEFINISI STRUCT NODE
// Setiap node punya: nilai (val), pointer ke kiri, pointer ke kanan

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // buat node baru dengan nilai x
    TreeNode(int x) {
        val   = x;
        left  = nullptr;  // awalnya belum punya anak kiri
        right = nullptr;  // awalnya belum punya anak kanan
    }
};


// FUNGSI 1: INVERT TREE
// fungsi membalik tree.
// tukar kiri-kanan di node ini, lalu rekursi ke bawah.
TreeNode* invertTree(TreeNode* root) {

    // BASE CASE: Kalau node kosong (nullptr), tidak ada yang perlu dibalik.
    // Langsung berhenti dan kembalikan nullptr.
    
    if (root == nullptr) {
        return nullptr;
    }

    // Simpan anak kiri ke variabel sementara
    TreeNode* simpan = root->left;

    // Isi anak kiri dengan anak kanan
    root->left = root->right;

    // Isi anak kanan dengan yang tadi kita simpan
    root->right = simpan;

    // Lakukan hal yang sama ke semua node di bawah kiri
    invertTree(root->left);

    // Lakukan hal yang sama ke semua node di bawah kanan
    invertTree(root->right);

    // Kembalikan root yang sudah dibalik
    return root;
}


// PRINT TREE 
// Supaya kita bisa lihat tree sebelum dan sesudah dibalik.
// Pakai queue untuk print per baris (per level).

void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "(tree kosong)" << endl;
        return;
    }

    queue<TreeNode*> antrian;  // buat antrian node
    antrian.push(root);        // masukkan root dulu

    while (!antrian.empty()) {

        // Ambil semua node di level ini
        int jumlahNodeDiLevel = antrian.size();

        for (int i = 0; i < jumlahNodeDiLevel; i++) {

            // Ambil node paling depan dari antrian
            TreeNode* node = antrian.front();
            antrian.pop();

            // Cetak nilainya
            cout << node->val;

            // Kalau bukan node terakhir di level ini, cetak spasi
            if (i < jumlahNodeDiLevel - 1) {
                cout << "  ";
            }

            // Masukkan anak-anaknya ke antrian untuk level berikutnya
            if (node->left  != nullptr) antrian.push(node->left);
            if (node->right != nullptr) antrian.push(node->right);
        }

        cout << endl;  // pindah baris setelah satu level selesai
    }
}


// FUNGSI 3: HAPUS TREE (bersihkan memori)
void hapusTree(TreeNode* root) {
    if (root == nullptr) return;
    hapusTree(root->left);
    hapusTree(root->right);
    delete root;
}


// MAIN FUNCTION
// membuat tree secara manual, lalu jalankan invertTree.
int main() {

    cout << "   PROGRAM INVERT BINARY TREE              " << endl;
    cout << endl;


    // Buat semua node
    TreeNode* root  = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node9 = new TreeNode(9);

    // Hubungkan node-node jadi tree
    root->left  = node2;   // 4 → kiri = 2
    root->right = node7;   // 4 → kanan = 7
    node2->left  = node1;  // 2 → kiri = 1
    node2->right = node3;  // 2 → kanan = 3
    node7->left  = node6;  // 7 → kiri = 6
    node7->right = node9;  // 7 → kanan = 9

    // Tampilkan tree SEBELUM dibalik
    cout << "Tree SEBELUM dibalik (per level):" << endl;
    cout << "------------------------------------" << endl;
    printTree(root);
    cout << endl;

    // Jalankan fungsi invert
    invertTree(root);

    // Tampilkan tree SESUDAH dibalik
    cout << "Tree SESUDAH dibalik (per level):" << endl;
    cout << "------------------------------------" << endl;
    printTree(root);
    cout << endl;

    cout << "-------------------------------------------" << endl;
    cout << " Hasil:" << endl;
    cout << " Level 1: 4         (root tidak berubah)" << endl;
    cout << " Level 2: 7  2      (tadinya: 2  7)" << endl;
    cout << " Level 3: 9  6  3  1 (tadinya: 1  3  6  9)" << endl;
    cout << "-------------------------------------------" << endl;

    // Bersihkan memori
    hapusTree(root);

    return 0;
}