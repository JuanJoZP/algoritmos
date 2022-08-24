#include <iostream>
using namespace std;

class Ciclista {
    string nombre;
    int tiempo;
    Ciclista* next;
    
    public: 
        
        void setNext(Ciclista* d) {
            next = d;
        }
        
        Ciclista* getNext() {
            return next;
        }
};

class Etapa {
    int n_etapa;
    int n_ciclistas;
    Etapa* next;
    Ciclista* c_ptr;
    
    public:
        Etapa(Carrera c) {
            n_etapa = c.getSize();
            n_ciclistas = 0;
            Etapa* next = NULL;
            c_ptr = NULL;
        }
        
        void setNext(Etapa* d) {
            next = d;
        }
        
        Etapa* getNext() {
            return next;
        }
        
        void push_back(Ciclista* d){
            if(size == 0){
                ptr = d;
                size++;
            }else{
                Nodo* t = ptr;
                while(t->getNext() != NULL){
                    t = t->getNext();    
                }
                t->setNext(d);
                size++;
            }
        }
};

class Carrera{
    int size;
    Etapa* ptr;
    
    public:
        Carrera() {
            size = 0;
            ptr = NULL
        }
        
        int getSize() {
            return size;
        }
        
        void push_back(Etapa* d){
            if(size == 0){
                ptr = d;
                size++;
            }else{
                Nodo* t = ptr;
                while(t->getNext() != NULL){
                    t = t->getNext();    
                }
                t->setNext(d);
                size++;
            }
        }
};

int main() {
    

    return 0;
}
