#include <time.h>

#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> v_left, vector<int> v_right) {
  vector<int> m(v_left.size() + v_right.size());
  int l_index = 0;
  int r_index = 0;

  for (int i = 0; i < m.size(); i++) {
    if (l_index >= v_left.size()) {
      m[i] = v_right[r_index++];
    } else if (r_index >= v_right.size()) {
      m[i] = v_left[l_index++];
    } else if (v_left[l_index] <= v_right[r_index]) {
      m[i] = v_left[l_index];
      l_index++;
    } else {
      m[i] = v_right[r_index];
      r_index++;
    }
  }

  return m;
}

vector<int> merge_sort(vector<int> v) {
  if (v.size() <= 1) {
    return v;
  }
  vector<int> v_left(v.begin(), v.begin() + v.size() / 2);
  vector<int> v_right(v.begin() + v.size() / 2, v.end());

  v_left = merge_sort(v_left);
  v_right = merge_sort(v_right);
  vector<int> merged = merge(v_left, v_right);

  return merged;
}

int main() {
  srand(time(0));

  vector<int> v1(10);
  for (int i = 0; i < 10; i++) {
    v1[i] = rand() % 20;
  }

  for (int i = 0; i < 10; i++) {
    cout << v1[i] << ", ";
  }
  cout << endl;

  v1 = merge_sort(v1);

  for (int i = 0; i < 10; i++) {
    cout << v1[i] << ", ";
  }
  cout << endl;

  return 0;
}