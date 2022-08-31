#include <iostream>
using namespace std;

int busqueda_terciaria(int v[], int n, int x) {
    int ini = 0;
    int fin = n-1;
    int n1 = n/3;
    int n2 = 2*n/3;
    while(ini <= fin) {
        n1 = (fin + 2*ini) / 3;
        n2 = (2*fin + ini) / 3;
        if(v[n1] == x) {
            return n1;
        } else if(v[n2] == x) {
            return n2;
        } else {
            if(v[n1] > x) {
                fin = n1-1;
            } else if(v[n2] < x) {
                ini = n2+1;
            } else {
                ini = n1+1;
                fin = n2-1;
            }
        }
    }
    return -1;
}

int main() {
    int vector[] = {1,2,3,5,6,8,9,10};
    
    cout << busqueda_terciaria(vector, 10, 5);

    return 0;
}
