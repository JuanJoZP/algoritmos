#include <time.h>

#include <iostream>
#include <vector>
using namespace std;

class Nodo {
  int valor;
  Nodo* next;

 public:
  Nodo() { next = NULL; }

  Nodo(int d) {
    valor = d;
    next = NULL;
  }

  int getValor() { return valor; }

  Nodo* getNext() { return next; }

  void setNext(Nodo* p) { next = p; }
};

class Lista {
  Nodo* ptr;
  Lista* next;
  int size;

 public:
  Lista() {
    ptr = NULL;
    size = 0;
    next = NULL;
  }

  Lista* getNext() { return next; }

  void setNext(Lista* p) { next = p; }

  Nodo* getPtr() { return ptr; }

  // insercion ordenada
  void insert(int d) {
    Nodo* n = new Nodo(d);
    Nodo* l = ptr;

    if (size == 0) {
      ptr = n;
      size++;
    } else if (n->getValor() <= l->getValor()) {
      ptr = n;
      n->setNext(l);
      size++;
    } else {
      while (l->getNext() != NULL && l->getNext()->getValor() < n->getValor()) {
        l = l->getNext();
      }

      if (l->getNext() != NULL) {
        Nodo* r = l->getNext();
        l->setNext(n);
        n->setNext(r);
      } else {
        l->setNext(n);
      }
      size++;
    }
  }

  void print() {
    if (size == 0) {
      cout << "La lista está vacía" << endl;
    } else {
      Nodo* t = ptr;
      do {
        cout << t->getValor() << ", ";
        t = t->getNext();

      } while (t != NULL);
      cout << endl;
    }
  }
};

class Bucket {
  int size;
  Lista* ptr;

 public:
  // inicializa la cantidad de cubetas necesarias
  Bucket(int n) {
    size = n;
    Lista* t = new Lista();
    ptr = t;

    for (int i = 0; i < n - 1; i++) {
      Lista* n = new Lista();
      t->setNext(n);
      t = n;
    }
  }

  Lista* getLista(int pos) {
    Lista* t = ptr;
    for (int i = 0; i < pos; i++) {
      t = t->getNext();
    }
    return t;
  }

  // inserta el valor en la cubeta que le corresponde
  void insert(int d, int min_v, int max_v) {
    int l_index = (d - min_v) * size / (max_v - min_v + 1);
    Lista* l = getLista(l_index);
    l->insert(d);
  }

  // ordena un vector de enteros en el rango [min, max]
  vector<int> sort(vector<int> v, int min_v, int max_v) {
    for (int x : v) {
      insert(x, min_v, max_v);
    }
    vector<int> r;

    Lista* t = ptr;
    while (t != NULL) {
      Nodo* tl = t->getPtr();
      while (tl != NULL) {
        r.push_back(tl->getValor());
        tl = tl->getNext();
      }
      t = t->getNext();
    }

    // falta limpiar los buckets para poder reusar la clase
    return r;
  }

  void print() {
    Lista* t = ptr;
    do {
      t->print();
      t = t->getNext();

    } while (t != NULL);
    cout << endl;
  }
};

int main() {
  srand(time(0));
  vector<int> v(15);
  Bucket bucket = Bucket(10);
  int max = 50;
  int min = 0;
  int range = max - min + 1;

  for (int& x : v) {
    x = rand() % range + min;
  }

  for (int x : v) {
    cout << x << ", ";
  }
  cout << endl;

  v = bucket.sort(v, min, max);
  cout << "bucket:" << endl;
  bucket.print();

  for (int x : v) {
    cout << x << ", ";
  }
  cout << endl;

  return 0;
}