// Online C++ compiler to run C++ program online
#include <string.h>

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Node {
  T data;
  Node *n;

 public:
  Node(T d) {
    data = d;
    n = NULL;
  }

  T get() { return data; }
  Node *next() { return n; }
  void next(Node *node) { n = node; }
};

template <typename T>
class List {
  Node<T> *ptr;

 public:
  List() { ptr = NULL; }

  void add(T d) {
    Node<T> *n = new Node(d);
    Node<T> *i = ptr;
    if (i == NULL) {
      ptr = n;
    } else {
      while (i->next() != NULL) {
        i = i->next();
      }
      i->next(n);
    }
  }

  T search(bool (*query)(T, T), T value) {
    Node<T> *i = ptr;
    if (i == NULL) {
      return NULL;
    } else {
      while (!query(i->get(), value) && i->next() != NULL) {
        i = i->next();
      }
      if (query(i->get(), value)) {
        return i->get();
      } else {
        return NULL;
      }
    }
  }
};

bool isFruit(const char *compare, const char *fruit) {
  return strcmp(fruit, compare) == 0;
};

void printEl(const char *value) {
  if (value == NULL) {
    cout << "El elemento no esta" << endl;
  } else {
    cout << "El elemento es: " << value << endl;
  }
}

int hashFruit(const char *value, int size) {
  int result = 0;
  for (int i = 0; i < strlen(value); i++) {
    result += value[i];
  }

  return result % size;
}

template <typename T>
class Hash {
  vector<List<T>> *table = NULL;
  int (*hashFunc)(T, int);
  int size_h;

 public:
  Hash(int size, int (*func)(T, int)) {
    size_h = size;
    table = new vector<List<T>>(size);
    hashFunc = func;
  }

  void add(T value) {
    int i = hashFunc(value, size_h);
    table->at(i).add(value);
  }

  T get(T value, bool (*query)(T, T)) {
    int i = hashFunc(value, size_h);
    return table->at(i).search(query, value);
  }
};

int main() {
  Hash<const char *> frutas = Hash<const char *>(100, &hashFruit);
  frutas.add("banano");
  frutas.add("onanab");
  const char *a = frutas.get("papaya", &isFruit);
  const char *b = frutas.get("banano", &isFruit);
  const char *c = frutas.get("onanab", &isFruit);

  printEl(a);
  printEl(b);
  printEl(c);

  return 0;
}
