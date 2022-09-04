#include <iostream>
using namespace std;

int busqueda_binaria(int v[], int n, int x) {
    int ini = 0;
    int fin = n-1;
    int i;
    while(ini <= fin) {
        i = (fin+ini) / 2;
        if(v[i] == x) {
            return i;
        } else {
            if(v[i] > x) {
                fin = i-1;
            } else {
                ini = i+1;
            }
        }
    }
    return -1;
}

int main() {
    int vector[] = {1,2,3,5,6,8,9,10};
    
    cout << busqueda_binaria(vector, 10, 8);

    return 0;
}
