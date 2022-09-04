// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Punto {
public:
    int x;
    int y;
    
    Punto() {
        x = 0;
        y = 0;
    }
    
    Punto(int xn, int yn) {
        if(xn > 0) {
            x = xn; 
        } else {
            x = 0;
        }
        
        if(yn > 0) {
            y = yn; 
        } else {
            y = 0;
        }
    }
    
    void setX(int xn) {
        x = xn;
    }
    
    void setY(int yn) {
        y = yn;
    }
    
    
};

class Area {
    Punto inf_izq;
    Punto sup_der;
    
public:
    Area(Punto p1, Punto p2) {
        inf_izq = p1;
        sup_der = p2;
    }
    
    bool contienePunto(Punto p) {
        if(p.x <= sup_der.x && p.y <= sup_der.y && p.x >= inf_izq.x && p.y >= inf_izq.y) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    // Write C++ code here
    Punto a1 = Punto(1, 1);
    Punto a2 = Punto(20, 20);
    Area a = Area(a1,a2);

    Punto p1 = Punto(1, 21); 
    cout << a.contienePunto(p1) << endl; // false
    
    Punto p2 = Punto(3, 7);
    cout << a.contienePunto(p2) << endl; // true
    

    return 0;
}
