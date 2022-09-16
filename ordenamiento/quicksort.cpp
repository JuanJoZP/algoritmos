#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int>& v) {
    int i = -1;
    if(v.size() > 1) {
        int last = v.size()-1;
        int swap;
        for(int j = 0; j < v.size()-1; j++) {
            if(v.at(j) < v.at(last)) {
                swap = v.at(j);
                v.at(j) = v.at(++i);
                v.at(i) = swap;
            }
        }
        swap = v.at(++i);
        v.at(i) = v.at(last);
        v.at(last) = swap;
        
        vector<int> lp (v.begin(), v.begin() + i);
        vector<int> rp (v.begin()+i+1, v.end());
        
        quicksort(lp);
        int pivot = v.at(i);
        quicksort(rp);
        
        v.clear();
        for(int h = 0; h < lp.size(); h++) {
            v.push_back(lp.at(h));
        }
        v.push_back(pivot);
        for(int h = 0; h < rp.size(); h++) {
            v.push_back(rp.at(h));
        }
        
    }
}

int main() {
    vector<int> v1 {6,1,59,9,7,2,5,4,3,0, 27};
    quicksort(v1);

    for(int h = 0; h < v1.size(); h++){
        cout << v1.at(h) << ", ";
    }
    cout << endl;

    return 0;
}
