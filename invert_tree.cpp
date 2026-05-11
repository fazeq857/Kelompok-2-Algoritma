#include <iostream>  
#include <queue>     
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // buat node baru dengan nilai x
    TreeNode(int x) {
        val   = x;
        left  = nullptr;  
        right = nullptr;  
    }
};


// fungsi membalik tree.
TreeNode* invertTree(TreeNode* root) {


    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* simpan = root->left;

    root->left = root->right;

    root->right = simpan;

    invertTree(root->left);

    invertTree(root->right);

    return root;
}


// print tree

void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "(tree kosong)" << endl;
        return;
    }

    queue<TreeNode*> antrian;  
    antrian.push(root);        

    while (!antrian.empty()) {

        int jumlahNodeDiLevel = antrian.size();

        for (int i = 0; i < jumlahNodeDiLevel; i++) {

            TreeNode* node = antrian.front();
            antrian.pop();

            cout << node->val;

            if (i < jumlahNodeDiLevel - 1) {
                cout << "  ";
            }

            if (node->left  != nullptr) antrian.push(node->left);
            if (node->right != nullptr) antrian.push(node->right);
        }

        cout << endl;
    }
}


// hapus tree (bersihkan memori)
void hapusTree(TreeNode* root) {
    if (root == nullptr) return;
    hapusTree(root->left);
    hapusTree(root->right);
    delete root;
}



// membuat tree secara manual
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

  
    root->left  = node2;  
    root->right = node7;   
    node2->left  = node1; 
    node2->right = node3;  
    node7->left  = node6;  
    node7->right = node9;  

    cout << "Tree SEBELUM dibalik (per level):" << endl;
    cout << "------------------------------------" << endl;
    printTree(root);
    cout << endl;

    invertTree(root);

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
