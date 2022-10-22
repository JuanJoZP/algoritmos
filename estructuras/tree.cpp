// Online C++ compiler to run C++ program online
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


/* Function to print level
order traversal a tree*/
void printLevelOrder() {
    printLevelOrder(root);
}

void printLevelOrder(Node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
/* Print nodes at a current level */
void printCurrentLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->getData() << " ";
    else if (level > 1) {
        printCurrentLevel(root->getIzq(), level - 1);
        printCurrentLevel(root->getDer(), level - 1);
    }
}
 
/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(Node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->getIzq());
        int rheight = height(node->getDer());
 
        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}
};

int main() {
    // Write C++ code here
    Tree tree = Tree();
    
    tree.add(18);
    tree.add(12);
    tree.add(15);
    tree.add(24);
    tree.add(21);
    tree.add(41);
    
    tree.preorder();
    cout << endl;
    tree.inorder();
    cout << endl;
    tree.printLevelOrder();

    return 0;
}
