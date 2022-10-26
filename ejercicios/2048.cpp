#include <iostream>

#include <math.h>

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Nodo {
  int n;
  Nodo* next;

 public:
  Nodo(int d) {
    n = d;
    next = NULL;
  }

  int get() { return n; }

  Nodo* getNext() { return next; }

  void setNext(Nodo* p) { next = p; }
};

class Pila {
  Nodo* ptr;
  int n_size;

 public:
  Pila() {
    ptr = NULL;
    n_size = 0;
  }

  int size() { return n_size; }

  void push(int d) {
    if (n_size == 0) {
      ptr = new Nodo(d);
      n_size++;
    } else {
      Nodo* r = ptr;
      Nodo* n = new Nodo(d);
      n->setNext(r);
      ptr = n;
      n_size++;
    }
  }
  
  int pop() {
      if(n_size == 0) throw invalid_argument("La pila esta vacia");
      
      Nodo* n = ptr;
      if(n->getNext() != NULL) {
        ptr = n->getNext();
      } else {
          ptr = NULL;
      }
      n_size--;
      int value = n->get();
      delete n;
      
      return value;
  }
  
  int peek() {
      if(n_size == 0) return -1;
      
      Nodo* n = ptr;
      return n->get();
  }
  
  void print() {
    if (n_size == 0) {
      cout << "La lista está vacía" << endl;
    } else {
      Nodo* t = ptr;
      do {
        cout << "" << (*t).get() << ", ";
        t = t->getNext();

      } while (t != NULL);
      cout << endl;
    }
  }
};

class Juego128 {
    Pila p = Pila();
    int max;
    
public:
    Juego128(int m) {
        max = m;
    }
    
    void nextMove() {
        int maxPow = log2(max)-1;
        int next = pow(2, rand()%maxPow);
        while(p.peek() == next) {
            p.pop();
            next = 2*next;
        }
        p.push(next);
    }
    
    void nextMove(int n) {
        int next = n;
        while(p.peek() == next) {
            p.pop();
            next = 2*next;
        }
        p.push(next);
    }
    
    void print() {
        p.print();
    }
    
    void play(bool random) {
        if (random) {
            while(p.peek() != max) {
                nextMove();
                print();
                cout << "---------" << endl;
            }
        } else {
            int n = 0;
            while(p.peek() != max) {
                cin >> n;
                nextMove(n);
                print();
                cout << "---------" << endl;
            }
        }
        cout << "El juego termino" << endl;
    }
};

int main() {
    Juego128 juego = Juego128(64);
    juego.play(true);


    return 0;
}
