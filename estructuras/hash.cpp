#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

class HashTel {
  int sid = 0;
  const static int size_h = 10;
  vector<tuple<string, string, int>> table = vector<tuple<string, string, int>> (size_h);

public :

  HashTel(const int size) {
  }
  
  int getCode(string data) {
      string first3 = data.substr(0,3);
      string last = data.substr(3);
      
      int hash = 0;
      for(int i = 0; i < last.length(); i++ ) {
          sid = 5;
          hash = (hash + last[i]) * sid;
      }
      
      return hash % size_h;
  }
  
  void addValue(string tel, tuple<string, string, int> data) {
      int code = getCode(tel);
      table[code] = data;
  }
  
  void showTable() {
      for(int i = 0; i < size_h; i++) {
          cout << "Telefono: " << get<0>(table.at(i)) << endl 
          << "Nombre: " << get<1>(table.at(i)) << endl 
          << "Edad: " << get<2>(table.at(i));
      }
  }
  
};

int main() {
    HashTel tel = HashTel(100);

    tel.addValue("3215700339", tuple<string, string, int>{"3215700339", "Juan Jose", 17});
    tel.addValue("3216474294", tuple<string, string, int>{"3216474294", "Arnulfo", 23});
    tel.showTable();
    
    // falta el metodo get value 
    // falta el metodo rehash
    // falta usar el rehash en add si hay colision
  return 0;
}
