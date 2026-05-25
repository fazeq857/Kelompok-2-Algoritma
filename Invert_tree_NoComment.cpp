#include <iostream>
#include <queue>
using namespace std;


struct Node {
    int num; 
    Node* left; 
    Node* right; 

    
    Node(int x) {
        num = x; //
        left  = nullptr;  
        right = nullptr;  
    }
};


void inverttree(Node* root) {
    if (root == nullptr) return; 

    
    swap(root->left, root->right); 

    inverttree(root->left); 
    inverttree(root->right); 


void printtree(Node* root) {
    cout << "[";  

    queue<Node*> antrian; 
    antrian.push(root); 
    bool first = true; 

    while (!antrian.empty()) { 
        Node* sekarang = antrian.front(); 
        antrian.pop(); 

        if (!first) cout << ' '; 
        cout << sekarang->num; 
        first = false;

        
        if (sekarang->left  != nullptr) antrian.push(sekarang->left);
        if (sekarang->right != nullptr) antrian.push(sekarang->right); 
        
    }

    cout << "]" << endl;  
}


void deleteTree(Node* root) { 
    if (root == nullptr) return; 
    deleteTree(root->left); 
    deleteTree(root->right); 
    delete root; 
}


int main() {

    cout << "Membalikkan Tree Biner" << endl << endl;

    Node* root  = new Node(4); 
    Node* n2    = new Node(2); 
    Node* n7    = new Node(7); 
    Node* n1    = new Node(1); 
    Node* n3    = new Node(3); 
    Node* n6    = new Node(6); 
    Node* n9    = new Node(9); 

   
    root->left  = n2; 
    root->right = n7;
    n2->left    = n1;
    n2->right   = n3;
    n7->left    = n6;
    n7->right   = n9;

    cout << "Tree sebelum dibalik:" << endl; 
    printtree(root); 

    inverttree (root);  

    cout << "\nTree setelah dibalik:" << endl;
    printtree(root); 

    deleteTree(root);

    return 0;
}