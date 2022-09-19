// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

void heapsort(vector<int> &v) {
    int left, right, n, last_parent;
    for(int i = 0; i < v.size(); i++) {
        n = v.size()-i-1;
        // se usa formula diferente si el vector es par o impar
        last_parent = (n%2 == 0) ? n/2 - 1 : (n+1)/2 - 1;
        
        for(int i = last_parent; i >= 0; i--) {
            left = 2*(i+1)-1;
            right = 2*(i+1);
            
            if(v.at(i) < v.at(left)) {
                swap(v.at(i), v.at(left));
            }
            
            // no mira el nodo derecho del ultimo arbol cuando el vector es impar
            if((i==last_parent && n%2 == 0) || i!=last_parent) {
                if(v.at(i) < v.at(right)) {
                    swap(v.at(i), v.at(right));
                }
            }
        }
        swap(v.at(0), v.at(n));
    }
}

int main() {
    vector<int> v1 {4,2,7,1,5,9,8,3,6,5,7,3,12,343};
    heapsort(v1);
    
    for(int i = 0; i < v1.size(); i++) {
        cout << v1.at(i) << ", ";
    }
}
