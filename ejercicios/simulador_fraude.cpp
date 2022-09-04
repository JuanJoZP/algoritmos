#include <iostream>
#include <string>
using namespace std;

class Transaccion {
  int origen;
  int destino;
  int monto;
  Transaccion* next;

 public:
  Transaccion() {
    origen = 0;
    destino = 0;
    monto = 0;
    next = NULL;
  }

  Transaccion(int o, int d, int m) {
    origen = o;
    destino = d;
    monto = m;
    next = NULL;
  }

  int get_origen() { return origen; }

  void set_origen(int o) { origen = o; }

  int get_destino() { return destino; }

  void set_destino(int d) { destino = d; }

  int get_monto() { return monto; }

  void set_monto(int m) { monto = m; }

  Transaccion* getNext() { return next; }

  void setNext(Transaccion* t) { next = t; }

  Transaccion& operator=(const Transaccion& f) {
    origen = f.origen;
    destino = f.destino;
    monto = f.monto;
    return *this;
  }

  string to_string() {
    return "(" + std::to_string(origen) + "," + std::to_string(destino) + "," +
           std::to_string(monto) + ")";
  }

  friend std::ostream& operator<<(std::ostream& os, Transaccion& b) {
    return os << b.to_string();
  }
};

// Definición de lista con transacciones

class Lista {
  int size;
  Transaccion* ptr;

 public:
  // Métodos
  Lista() {
    size = 0;
    ptr = NULL;
  }

  void push_back(int o, int d, int m) {
    if (size == 0) {
      ptr = new Transaccion(o, d, m);
      size++;
    } else {
      Transaccion* t = ptr;
      while (t->getNext() != NULL) {
        t = t->getNext();
      }
      t->setNext(new Transaccion(o, d, m));
      size++;
    }
  }

  Transaccion* getPtr() { return ptr; }

  void print() {
    if (size == 0) {
      cout << "La lista está vacía" << endl;
    } else {
      Transaccion* t = ptr;
      do {
        cout << t->to_string() << endl;
        t = t->getNext();

      } while (t != NULL);
      cout << endl;
    }
  }
};

int main() {
  srand(1234);
  const int num_emp = 10;    // Número de empresas
  const int num_trans = 10;  // Número de transacciones
  int error = 3;           // Variable para incluir errores en las transacciones
  int monto_max = 100000;  // Variable para definir el máximo valor de un monto

  int mat_bank[num_emp][num_emp];  // Declaración de la matriz con información
                                   // reportada por el banco, calculada con las
                                   // transacciones originales
  int mat_emp[num_emp][num_emp];   // Declaración de la matriz con información
                                   // alterada, reportada por la empresa,
                                   // calculada con las transacciones alteradas

  Lista* lista = new Lista();

  // Creación de transacciones. Valide que no haya transacciones con un mismo
  // origen y destino, y que el monto no pase del máximo establecido: monto =
  // rand()%100000;
  int origen, destino, monto;
  for (int i = 0; i < num_trans; i++) {
    monto = rand() % monto_max;
    origen = rand() % num_emp;
    do {
      destino = rand() % num_emp;
    } while (origen == destino);

    lista->push_back(origen, destino, monto);
  }

  // Imprimir lista de transacciones originales
  lista->print();

  // Limpiar basura en las matrices
  for (int i = 0; i < num_emp; i++) {
    for (int j = 0; j < num_emp; j++) {
      mat_bank[i][j] = 0;
      mat_emp[i][j] = 0;
    }
  }

  // Calcular monto total de transacciones entre empresas en mat_bank
  Transaccion* t = lista->getPtr();
  for (int i = 0; i < num_trans; i++) {
    mat_bank[t->get_origen()][t->get_destino()] += t->get_monto();
    t = t->getNext();
  }

  // Imprimir la matriz mat_bank
  for (int i = 0; i < num_emp; i++) {
    for (int j = 0; j < num_emp; j++) {
      int p = mat_bank[i][j];
      if (p == 0) {
        cout << mat_bank[i][j] << ",       ";
      } else {
        cout << mat_bank[i][j] << ",   ";
      }
    }
    cout << endl;
  }
  cout << endl;

  // Alterar las transacciones cuyo indice%error == 0, disminuyendo su valor en
  // 25% (monto*0.75)
  t = lista->getPtr();
  for (int i = 0; i < num_trans; i++) {
    if (i % error == 0) {
      t->set_monto(t->get_monto() * 0.75);
    }
    t = t->getNext();
  }

  // Imprimir lista de transacciones alteradas
  lista->print();

  // Calcular monto total de transacciones alteradas entre empresas en mat_emp
  t = lista->getPtr();
  for (int i = 0; i < num_trans; i++) {
    mat_emp[t->get_origen()][t->get_destino()] += t->get_monto();
    t = t->getNext();
  }

  // Imprimir la matriz mat_alt
  for (int i = 0; i < num_emp; i++) {
    cout << endl;
    for (int j = 0; j < num_emp; j++) {
      int p = mat_emp[i][j];
      if (p == 0) {
        cout << mat_emp[i][j] << ",       ";
      } else {
        cout << mat_emp[i][j] << ",   ";
      }
    }
  }
  cout << endl << endl;

  // Imprimir las diferencias encontradas entre las matrices
  for (int i = 0; i < num_emp; i++) {
    for (int j = 0; j < num_emp; j++) {
      if (mat_bank[i][j] != mat_emp[i][j])
        cout << "Diferencia en total de transacciones entre empresas " << i
             << " y " << j << " por " << (mat_emp[i][j] - mat_bank[i][j])
             << endl;
    }
  }

  return 0;
}
