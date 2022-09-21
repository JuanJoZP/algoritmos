// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

// devuelve true si hex1 es mayor o igual a hex2
bool hex_g(string hex1, string hex2) {
    if(hex1.size() > hex2.size()) return true;
    else if (hex1.size() < hex2.size()) return false;
    else {
        for(int i = 0; i < hex1.size(); i++) {
            if(hex1[i] >= hex2[i]) return true;
            else return false;
        }
        return true;
    }
}

void heapsort(vector<string> &v) {
    int left, right, n, last_parent;
    for(int i = 0; i < v.size(); i++) {
        n = v.size()-i-1;
        // se usa formula diferente si el vector es par o impar
        last_parent = (n%2 == 0) ? n/2 - 1 : (n+1)/2 - 1;
        
        for(int i = last_parent; i >= 0; i--) {
            left = 2*(i+1)-1;
            right = 2*(i+1);
            
            if(hex_g(v.at(left), v.at(i))) {
                swap(v.at(i), v.at(left));
            }
            
            // no mira el nodo derecho del ultimo arbol cuando el vector es impar
            if((i==last_parent && n%2 == 0) || i!=last_parent) {
                if(hex_g(v.at(right), v.at(i))) {
                    swap(v.at(i), v.at(right));
                }
            }
        }
        swap(v.at(0), v.at(n));
    }
}

int main() {
    vector<string> lista {"10E", "20F", "1F2", "A7B", "234", "001", "A2E", "23B", "F1A", "C21"};
    heapsort(lista);

    for(int i = 0; i < lista.size(); i++) {
        cout << lista[i] << ", ";
    }

    return 0;
}
