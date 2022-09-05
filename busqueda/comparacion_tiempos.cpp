#include <iostream>
#include <ctime>
#define arr_len(a) (sizeof(a) / sizeof(a[0]))
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

int busqueda_lineal(int v[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(v[i] == x) {
            return i;
        }
    }
}

int main() {
    cout << "a";
    int vector[1000000];
    
    for(int i = 0; i < 1000000; i++) {
        vector[i] = i;
    }
    // binaria
    double start1 = double(clock());
    cout << busqueda_binaria(vector, arr_len(vector), 2) << endl;
    double finish1 = double(clock());
    
    double start2 = double(clock());
    cout << busqueda_lineal(vector, arr_len(vector), 999999) << endl;
    double finish2 = double(clock());
    
    cout << "El tiempo de ejecucion de busqueda binaria fue: " << finish1-start1 << endl;
    cout << "El tiempo de ejecucion de busqueda lineal fue: " << finish2-start2 << endl;

    return 0;
}
