#include <iostream>
#include <queue>
using namespace std;

// Satu kotak/node di dalam tree
struct Node {
    int num; // nilai yang disimpan di node
    Node* left; // pointer ke anak kiri
    Node* right; // pointer ke anak kanan

    // Constructor: otomatis isi nilai saat buat node baru
    Node(int x) {
        num = x; //
        left  = nullptr;  // belum punya anak kiri
        right = nullptr;  // belum punya anak kanan
    }
};

// Fungsi Invert
// Menukar anak kiri dan kanan di setiap node secara rekursif
void inverttree(Node* root) {
    if (root == nullptr) return; // base case =kalau sudah sampai node kosong selesai

    
    swap(root->left, root->right); // tukar anak kiri dan kanan

    inverttree(root->left); // lanjut ke anak kiri (yang sekarang sudah jadi anak kanan)
    inverttree(root->right); // lanjut ke anak kanan (yang sekarang sudah jadi anak kiri)
}

// Fungsi Cetaknya
// Cetak tree per baris/level pakai queue
void printtree(Node* root) {
    cout << "[";  // kurung buka

    queue<Node*> antrian; // buat antrian
    antrian.push(root); 
    bool first = true; // untuk mengatur spasi antar angka

    while (!antrian.empty()) { // selama masih ada node di antrian
        Node* sekarang = antrian.front(); // ambil node paling depan
        antrian.pop(); // keluarkan dari antrian

        if (!first) cout << ' '; // spasi antar angka, tapi tidak sebelum angka pertama
        cout << sekarang->num; // cetak nilai node sekarang
        first = false;

        // Masukkan anak-anaknya ke antrian
        if (sekarang->left  != nullptr) antrian.push(sekarang->left);
        if (sekarang->right != nullptr) antrian.push(sekarang->right); 
        //Jika Node yang sedang diproses punya anak kiri atau kanan
        //masukkan anak-anak ke antrian paling belakang.
    }

    cout << "]" << endl;  // kurung tutup
}

// memersihkan memori supaya tidak memory leak
void deleteTree(Node* root) { 
    if (root == nullptr) return; // kalau sudah kosong, selesai
    deleteTree(root->left); // bersihkan anak kiri dulu
    deleteTree(root->right); // bersihkan anak kanan
    delete root; // baru hapus node sekarang setelah anak-anaknya sudah dibersihkan
}


int main() {

    cout << "Membalikkan Tree Biner" << endl << endl;

    // Buat node-node secara manual
    Node* root  = new Node(4); // root node dengan nilai 4
    Node* n2    = new Node(2); // node dengan nilai 2
    Node* n7    = new Node(7); // node dengan nilai 7
    Node* n1    = new Node(1); // node dengan nilai 1
    Node* n3    = new Node(3); // node dengan nilai 3
    Node* n6    = new Node(6); // node dengan nilai 6
    Node* n9    = new Node(9); // node dengan nilai 9

    // Sambungkan node-node membentuk tree
    root->left  = n2; // anak kiri root adalah n2
    root->right = n7;
    n2->left    = n1;
    n2->right   = n3;
    n7->left    = n6;
    n7->right   = n9;

    cout << "Tree sebelum dibalik:" << endl; 
    printtree(root); // tampilkan tree sebelum dibalik

    inverttree (root);  // proses utama

    cout << "\nTree setelah dibalik:" << endl;
    printtree(root); // tampilkan tree setelah dibalik

    // Bersihkan memori
    deleteTree(root);

    return 0;
}
