#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Vector {
    private:
        int size = 0;
        int capacity = 2;
        int *v;
        
        void print_vect(){
            cout << "El vector se ve asi:";
            cout << "[";
            for(int i = 0; i<capacity; i++){
                cout<<v[i]<<", ";
            }
            cout << "]";
            cout << endl;
        }
        
        void capacity_x2(){
            int aux[capacity];
            for(int i=0; i<capacity; i++) {
               aux[i] = v[i];
            }
               
            //crea nuevo vector del doble de tamaño
            capacity = capacity * 2;
            v = new int[capacity]; // posible error
               
            // pasa los datos viejos al nuevo vector
            for(int i = 0; i < capacity / 2; i++) {
               v[i] = aux[i];
            }
            
        }
        
        void move_right(int x) {
            for(int i=size+1; i > x; i--) {
                v[i] = v[i-1];
            }
        }

        void move_left(int x){
            for(int i= x; i<capacity; i++){
                v[i] = v[i+1];
            }
        }
        
    public:
        Vector() {
            v = new int[capacity];
        }
        
        void push_back(int x) {
            // cuando no esta lleno el vector
            if(capacity > size) {
                v[size] = x;
                size++;
            } else { // cuando se llena el vector
               // vector auxiliar para los datos viejos
               capacity_x2();
               
               v[size] = x;
               size++;
            }
            print_vect();
        }
        
        bool insert(int x, int i) {
            if(i<size) {
                if(capacity > size) {
                    move_right(i);
                    v[i] = x;
                } else {
                    capacity_x2();
                    move_right(i);
                    v[i] = x;
                }
                print_vect();
                return true;
            } else {
                cout << "nada";
                return false;
            }
        }
        
        bool remove(int i) {
            if(i<size) {
                move_left(i);
                size--;
                return true;
            } else {
                return false;
            }
            print_vect();
        }
        
        int get(int i) {
            return v[i];
        }
        
        void set(int x, int i) {
            v[i] = x;
            print_vect();
        }
};        


// ordena de menor a mayor
// recorre el vector n veces, encuentra el menor valor, lo inserta en un v auxiliar
// luego bora ese valor del vector original y repite, retrona el vector auxiliar
void selection_sort(int v[], int* vaux, int n){
    // se puede optimizar haciendol sobre un mismo vector
    // sin borrar el elemento, sino que los intercambia
    int min = 100000;
    for(int i=0; i < n; i++) {
        for(int j=0; j<n; j++){
            if(min > n) {
                min = j;
            } else if(v[j] < v[min]) {
                min = j;
            }
        }
        vaux[i] = v[min];
        v[min] = 100000;
        min = 100000;
    }

}

// ordenamiento insertando en un vector nuevo
void ordenamiento_insertando(int v[], int* v_aux) {
    //ordenar insertando cada elemento en un vector auxiliar
    //para cada elemento del vector original se recorre el vector nuevo y se inserta donde corresponda
}

void insert_sort // va ordenando subvectores, luego trata de ordenar un elemento mas a la vez, haciendo corrimientos hasta que quede en la posicion correcta, luego sigue con un vector de un elemento mas

void shell_sort

int main() {

    int arr[] = {2,3,5,3,6,8,9,12};
    int v_ordenado[10];
    //ordenamiento_borrando(vector, v_ordenado, 8);
    
    int myints[] = {16,2,77,29};
    vector<int> vect (myints, myints + sizeof(myints) / sizeof(int));
    vector<int> vect_o;
    
    ordenamiento_insertando(vect, vect_o);
    
    return 0;
}
