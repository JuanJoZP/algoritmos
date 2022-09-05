#include <iostream>
#include <vector>
using namespace std;
#define arr_len(a) (sizeof(a) / sizeof(a[0]))

void print(int v[], int n) {
  cout << "[";
  for (int i = 0; i < n - 1; i++) {
    cout << v[i] << ", ";
  }
  cout << v[n - 1] << "]" << endl;
}

void print(vector<int> v) {
  vector<int>::iterator it;
  cout << "[";
  for (it = v.begin(); it != v.end() - 1; ++it) {
    cout << *it << ", ";
  }

  cout << *(v.end() - 1) << "]" << endl;
}

void insert_sort(vector<int>* v) {}
// va ordenando subvectores, luego trata de ordenar un elemento mas a la vez,
// haciendo corrimientos hasta que quede en la posicion correcta, luego sigue
// con un vector de un elemento mas

void insert_sort(int v[], int len) {}

int main() {
  int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  vector<int> vec{9, 8, 7, 6, 5, 4, 3, 2, 1};

  print(arr, arr_len(arr));
  print(vec);

  insert_sort(&vec);
  print(vec);

  insert_sort(arr, arr_len(arr));
  print(arr, arr_len(arr));

  return 0;
}
