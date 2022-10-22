// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
    char data;
    Node* childs[27];
    int size_childs = 0;
    bool end;
    
public:
    Node(char d) {
        data = d;
        end = false;
    }
    
    char getData() {
        return data;
    }
    
    std::array<Node*, 27> getChilds() {
        return childs;
    }
    
    Node* getChild(int pos) {
        return childs[pos];
    }
    
    Node* findChild(char d) {
        for(int i = 0; i < size_childs; i++) {
            Node* n = childs[i];
            if(n->getData() == d) {
                return n;
            }
        }
        return nullptr;
    }
    
    Node* addChild(char d) {
        Node* n = new Node(d);
        childs[size_childs] = n;
        size_childs++;
        
        return n;
    }
    
    bool isEnd() {
        return end;
    }
    
    void setEnd() {
        end = true;
    }
};

class Names {
    Node* root = new Node(' ');

public:
    void addName(string name) {
        Node* n = root;
        for(int i = 0; i < name.size(); i++) {
            char letter = (char)tolower(name[i]);
  
            Node* repeated = n->findChild(letter);
            if(repeated != nullptr) {
                n = repeated; 
            } else {
                n = n->addChild(letter);
            }
            
            if(i == name.size()-1) {
                n->setEnd();
            }
        }
    }
    
    void print() {
        print(root);
    }
    
    void print(Node* root) {
        Node* r[] = root->getChilds();
        
        for(int i = 0; i < (*r).size(); i++) {
            cout << i;
        }
    }
};

int main() {

    Names list;
    list.addName("Juan");
    list.print();
    
    return 0;
}
