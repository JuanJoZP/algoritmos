// Online C++ compiler to run C++ program online
#include <iostream>

template <typename T>
class Hash : private Map {
  pair<int, vector<T> *> *hashMap;
  int size_h;

  int getCode(T data) { return rand() % size_h; }

  int findHash(int hash_code)  // devuelve el indice en el que esta el hash
                               // dentro de hashMap
      // si no esta entonces lo añade en posicion donde este en orden junto con
      // el apuntador a un vector vacio y devuelve el indice donde quedo

      public :

      Hash(int size_h)
      : Map() {
    hashMap = new pair<int, vector<T> *>[size_h];
    size_h = size_h;
  }

  void add_h(T data) {
    int hash_code = getCode(data);
    hashMap[findHash(hash_code)].second.push_back(data);
  }
};

int main() {
  // Write C++ code here
  std::cout << "Hello world!";
  // pregunta: al rehashear como encuentro nuevamente el elemento
  //  hasheo una vez y ya esta ocupada, entonces hago rehash y lo ubico en otra
  //  parte cuando voy a buscar el dato, uso el hash y me encuentro con el dato
  //  que no es

  // si la funcion es irreversible como funcionan los al

  // numeros de telefono
  return 0;
}
