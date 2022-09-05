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

void select_sort(vector<int>* v) {
  int x_temp, i_min;
  int len = v->size();

  for (int i = 0; i < len; ++i) {
    i_min = i;
    for (int j = i; j < len; ++j) {
      if (v->at(j) < v->at(i_min)) i_min = j;
    }
    x_temp = v->at(i);
    v->at(i) = v->at(i_min);
    v->at(i_min) = x_temp;
  }
}

void select_sort(int v[], int len) {
  int x_temp, i_min;

  for (int i = 0; i < len; ++i) {
    i_min = i;
    for (int j = i; j < len; ++j) {
      if (v[j] < v[i_min]) i_min = j;
    }
    x_temp = v[i];
    v[i] = v[i_min];
    v[i_min] = x_temp;
  }
}

int main() {
  int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  vector<int> vec{9, 8, 7, 6, 5, 4, 3, 2, 1};

  print(arr, arr_len(arr));
  // print(vec);

  select_sort(&vec);
  print(vec);

  select_sort(arr, arr_len(arr));
  // print(arr, arr_len(arr));

  return 0;
}
