// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int** create_matrix(int n, int m) {
    int ** mat = new int*[n];
    for(int i =0; i < n; i++) {
        mat[i] = new int[m];
        for(int j = 0; j < m; j++) {
            //mat[i][j] = 0;
            mat[i][j] = 0;
        }
    }
    
    return mat;
}


void print_matrix(int** mat, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}


class GrafoMatriz {
    int ** mat;
    int nodes;

public:   
    GrafoMatriz(int n, int enlaces[][3], int e_size) {
        mat = create_matrix(n, n);
        nodes = n;
        
        // enlaces: [[nodo1, nodo2, peso], [...], ...]
        for(int i = 0; i < e_size; i++) {
            mat[enlaces[i][0]-1][enlaces[i][1]-1] = enlaces[i][2];

        }
    }
    
    void print() {
        print_matrix(mat, nodes, nodes);
    }
};

int main() {
    int enlaces[9][3] = {{1,3,1}, {2,3,3}, {2,5,5}, {3,2,3}, {3,4,4}, {4,3,4}, {4, 5, 2}, {5,3,2}, {5,4,2}};
    GrafoMatriz grafo = GrafoMatriz(5, enlaces, 9);
    grafo.print();

    return 0;
}
