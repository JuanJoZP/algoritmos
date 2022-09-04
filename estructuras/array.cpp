// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int insertar(int* v, int n, int x, int pos) {
    for(int i =n; i>pos; i--) {
        v[i] = v[i-1];
    }
    v[pos] = x;
    
    return n+1;
}

int eliminar(int* v, int n, int pos) {
    for(int i=pos; i<n-1; i++) {
        v[i] = v[i+1];
    }
    
    return n-1;
}


int main() {
    int vector[5] = {1,2,3,4,5};
    int tam = 5;
    
    tam = eliminar(vector, tam, 2);
    tam = insertar(vector, tam, 3, 2);
    
    for(int i=0; i<tam;i++) {
        cout << vector[i] << ", ";
    }
    
    
    return 0;
}
