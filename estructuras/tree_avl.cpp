#include <iostream>
using namespace std;

class Node {
    int data;
    Node* izq;
    Node* der;
    
public:
    Node() {
        data = 0;
        izq = NULL;
        der = NULL;
    }

    Node(int d) {
        data = d;
        izq = NULL;
        der = NULL;
    }
    
    int getData() {
        return data;
    }
    
    Node* getIzq() {
        return izq;
    }
    
    Node* getDer() {
        return der;
    }
    
    void setIzq(Node* iz) {
        izq = iz;
    }
    
    void setDer(Node* de) {
        der = de;
    }
    
    bool hasIzq() {
        return izq != NULL;
    }
    
    bool hasDer() {
        return der != NULL;
    }
    
    bool isHoja() {
        if(izq == NULL && der == NULL) {
            return true;
        }
        return false;
    }
};

class Tree {
    Node* root;
    
    Node* searchLeaf(Node* root, int value) {
        bool left = root->getData() > value;
        if(left && !root->hasIzq()) {
            return root;
        } else if (!left && !root->hasDer()) {
            return root;
        } else {
            if(left) {
                return searchLeaf(root->getIzq(), value);
            } else {
                return searchLeaf(root->getDer(), value);
            }
        }
    }
    
public:
    
    void add(int d) {
        Node* n = new Node(d);
        if(root == NULL) {
            root = n;
        } else {
            Node* t = root;
            Node* hoja = searchLeaf(t, n->getData());
            
            if(n->getData() >= hoja->getData()) {
                hoja->setDer(n);
            } else {
                hoja->setIzq(n);
            }
        }
    }
    
    int getHeight(Node *r) {
        if(r == NULL) {
            return 0;
        } else {
            return 1 + max(getHeight(r->getIzq()), getHeight(r->getDer()));
        }
    }
    
    int getHeight() {
        return getHeight(root);
    }
    
    bool isBalanced(Node *r) {
        return abs(getHeight(r->getIzq())-getHeight(r->getDer())) <= 1;
    }
    
    bool isBalanced() {
        return isBalanced(root);
    }
    
    bool isIzqHeavy(Node *r) {
        return getHeight(r->getIzq())-getHeight(r->getDer()) > 1;
    }
    
    bool isIzqHeavy() {
        return isIzqHeavy(root);
    }
    
    Node* parent(int ch, Node *t) {
        bool izq = ch < t->getData();
        
        if (izq) {
            if(t->getIzq()->getData() == ch) return t;
            return parent(ch, t->getIzq());
        } else {
            if(t->getDer()->getData() == ch) return t;
            return parent(ch, t->getDer());
        }
        
        return NULL;
    }
    
    Node* parent(int ch) {
        return parent(ch, root);
    }
    
    bool isHijoIzq(int ch) {
        Node* t = parent(ch);
        
        return t->getIzq()->getData() == ch;
    }
    
    void preorder() {
        preorder(root);
    }
    
    void preorder(Node* r) {
        if(r!= NULL) {
            cout << r->getData()<<"\t";
            preorder(r->getIzq());
            preorder(r->getDer());
        }
    }
    
    void inorder() {
        inorder(root);
    }
    
    void inorder(Node* n) {
        if (n == NULL) return;
        inorder(n->getIzq());
        cout << n->getData() << "\t";
        inorder(n->getDer());
    }
};

 
int main() {
    // Write C++ code here
    Tree tree = Tree();
    
    tree.add(18);
    tree.add(12);
    tree.add(8);
    tree.add(7);
    tree.add(6);
    tree.add(15);
    tree.add(24);
    tree.add(21);
    tree.add(41);

    
    tree.preorder();
    cout << endl;

    //cout << tree.getHeight() << endl;
    //cout << tree.isBalanced() << endl;
    
    //cout << tree.isIzqHeavy() << endl;
    //cout << tree.parent(41)->getData() << endl;
    //cout << tree.isHijoIzq(15) << endl;

    return 0;
}
