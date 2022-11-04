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
    
public:
    
    void addr(int d){
      if(root != NULL)
        addr(d, root, root);
      else
        root =  new Node(d);
    }

    void addr(int d, Node* t, Node* pt){
        if(t == NULL){
            Node* n = new Node(d);
            if(d < pt->getData()){
                pt->setIzq(n);
            }else{
                pt->setDer(n);
            }
        }else{
            if(d < t->getData()){
                addr(d, t->getIzq(), t);
            }else{
                addr(d, t->getDer(), t);
            }
            
            if(!isBalanced(t)) {
                if(isIzqHeavy(t)) {
                    if(isHijoIzq(d)) {
                        Node *z = t->getIzq();
                        Node *pt = parent(t->getData());
                        t->setIzq(z->getDer());
                        z->setDer(t);
                        
                        if(pt == NULL) {
                            root = z;
                        } else {
                            pt->setIzq(z);
                        }
                    } else {
                        Node *z = t->getIzq();
                        Node *zd = z->getDer();
                        Node *pt = parent(t->getData());
                        
                        z->setDer(zd->getIzq());
                        zd->setIzq(z);
                        t->setIzq(zd->getDer());
                        zd->setDer(t);
                        if(pt == NULL) {
                            root = zd;
                        } else {
                            pt->setIzq(zd);
                        }
                        // rotacion 2 izq-der
                    }
                } else if(isDerHeavy(t)) {
                    if(isHijoDer(d)) {
                        Node *z = t->getDer();
                        Node *pt = parent(t->getData());
                        t->setDer(z->getIzq());
                        z->setIzq(t);
                        
                        if(pt == NULL) {
                            root = z;
                        } else {
                            pt->setDer(z);
                        }
                    } else {
                        // rotacion 2 der-izq
                    }
                }
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
    
    bool isDerHeavy(Node *r) {
        return getHeight(r->getIzq())-getHeight(r->getDer()) < -1;
    }
    
    bool isDerHeavy() {
        return isDerHeavy(root);
    }
    
    Node* parent(int ch, Node *t) {
        if(t == NULL) {
            return NULL;
        } else {
            if(t->getData() == ch) {
                return NULL;
            } else {
                if(t->getData() > ch) {
                    if(t->hasIzq()) {
                        if(t->getIzq()->getData() == ch) {
                            return t;
                        } else {
                            return parent(ch, t->getIzq());
                        }
                    } else {
                        return NULL;
                    }
                } else {
                    if(t->hasDer()) {
                        if(t->getDer()->getData() == ch) {
                            return t;
                        } else {
                            return parent(ch, t->getDer());
                        }
                    } else {
                        return NULL;
                    }
                }
            }
        }
    }
    
    Node* parent(int ch) {
        return parent(ch, root);
    }
    
    bool isHijoIzq(int ch) {
        Node* t = parent(ch);
        
        return t->getIzq()->getData() == ch;
    }
    
    bool isHijoDer(int ch) {
        Node* t = parent(ch);
        
        return t->getDer()->getData() == ch;
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
    
    tree.addr(15);
    tree.addr(10);
    tree.addr(20);
    tree.addr(5);
  
    tree.preorder();
    cout << endl;
    
    tree.addr(8);
    
    tree.preorder();
    cout << endl;


    //cout << tree.getHeight() << endl;
    //cout << tree.isBalanced() << endl;
    
    //cout << tree.isIzqHeavy() << endl;
    //cout << tree.parent(41)->getData() << endl;
    //cout << tree.isHijoIzq(15) << endl;

    return 0;
}
