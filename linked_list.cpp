#include<iostream>
#include <math.h> 
#include <stdexcept>
#include <string>

using namespace std;

class Point {

//Atributos
    int x;
    int y;

    const int rmax = 1;

public:
    
    //Constructores
    Point(int xc, int yc) {
        x = xc;
        y = yc;

    }

    Point() {
        x = 0;
        y = 0;
    }

    //M�todos
    
    Point ofuscacion() {
        return Point(x + 2 * (rand() % rmax) - rmax, y + 2 * (rand() % rmax) - rmax);
    }
    
    double dist() {
        return dist(0,0);
    }

    double dist(int xc, int yc) {
        return sqrt(pow(x-xc, 2) + pow(y-yc, 2));
    }

    double dist(Point p) {
        return dist(p.x, p.y);
    }

    //Getters
    int getX() {
        return x;
    }

    int getY() {
        return y;
    }


    //Setters
    void setX(int xc) {
        x = xc;
    }

    void setY(int yc) {
        y = yc;
    }
    
    Point& operator=(const Point& f) { 
		setX(f.x);
		setY(f.y);
		return *this; 
	}

};

class Nodo{
  
  Point* dato;
  Nodo* pointer;
  
public:
  
  Nodo(){
      dato = NULL;
      pointer = NULL;
  }
  
  ~Nodo(){
      delete dato;
  }
  
  Nodo(Point* d){
      dato = d;
      pointer = NULL;
  }
    
  Point* getDato(){
      return dato;
  }
  
  void setDato(Point* d){
      dato = d;
  }
  
  Nodo* getNext(){
      return pointer;
  }
  
  void setNext(Nodo* p){
      pointer = p;
  }
  
  void setNext() {
      pointer = NULL;
  }
    
};

class Lista{
    Nodo* ptr;
    int size;

public:  

    Lista(){
        ptr = NULL;
        size = 0;
    }
    
    /*~Lista(){
        Nodo* t = ptr;
        Nodo * n;
        while(t->getNext() != NULL){
            n = t;
            t = t->getNext();
            delete n;
        }
    }*/
    
    void push_back(Point* d){
        
        if(size == 0){
            ptr = new Nodo(d);
            size++;
        }else{
            Nodo* t = ptr;
            while(t->getNext() != NULL){
                t = t->getNext();    
            }
            t->setNext(new Nodo(d));
            size++;
        }
        
    }
    
    int getSize(){
        return size;
    }
    
    Nodo* getPtr() {
        return ptr;
    }
    
    void setPtr(Nodo* ptrr) {
        ptr = ptrr;
    }
    
     Nodo* getNodo(int pos) {
        if(size == 0) {
            throw invalid_argument("La lista no tienen nodos");
        } else if (pos >= size || pos < 0) {
            throw invalid_argument("El nodo no esta en la lista");
        } else {
            Nodo* t = ptr;
            for(int i = 0; i < pos; i++) {
                t = t->getNext();
            }
            return t;
        }
    }
    
    void insert(Point* d, int pos) {
        if(pos > size || pos < 0) {
            throw invalid_argument("No es posible insertar un nodo en esa posicion");
        } else if(pos == 0) {
            Nodo* r = getNodo(pos);
            Nodo* n = new Nodo(d);
            n->setNext(r);
            ptr = n;
            size++;
        } else if(pos == size || size == 0) {
            push_back(d);
        } else {
            Nodo* l = getNodo(pos-1);
            Nodo* r = l->getNext();
            
            Nodo* n = new Nodo(d);
            l->setNext(n);
            n->setNext(r);
            size++;
        }
    }
    
    void remove_nodo(int pos){
        if (pos < 0 || pos >= size) {
            throw invalid_argument("No hay ningun nodo que eliminar en esa posicion");
        } else if(pos == 0) {
            Nodo* obj = ptr;
            ptr = obj->getNext();
            delete obj;
            size--;
        } else if (pos == size - 1) {
           Nodo* l = getNodo(pos-1);
           Nodo* obj = l->getNext();
           l->setNext();
           delete obj;
           size--;
        } 
        else {
            Nodo* l = getNodo(pos-1);
            Nodo* obj = l->getNext();
            Nodo* r = obj->getNext();
            
            l->setNext(r);
            delete obj;
            size--;
        }
    }
    
    void reverse() {
        for(int i = 1; i<size; i++) {
            Nodo* l = getNodo(i-1);
            Nodo* obj = l->getNext();
            if(obj->getNext() == NULL) {
                obj->setNext(ptr);
                ptr = obj;
                l->setNext();
            } else {
                Nodo* r = obj->getNext();
                obj->setNext(ptr);
                ptr = obj;
                l->setNext(r);
            }
        }
    }
    
    static Lista fusion(Lista l1, Lista l2, bool inter) {
        Lista l3 = Lista();
        
        if(inter) {
            Nodo* n1 = l1.getPtr();
            Nodo* n2 = l2.getPtr();
            for(int i = 0; i < l1.getSize(); i++) {
               l3.push_back(n1->getDato());
               l3.push_back(n2->getDato());
               n1 = n1->getNext();
               n2 = n2->getNext();
           }
        } else {
            Nodo* n1 = l1.getPtr();
            for(int i = 0; i < l1.getSize(); i++) {
               l3.push_back(n1->getDato());
               n1 = n1->getNext();
           }
           
           Nodo* n2 = l2.getPtr();
           for(int i = 0; i < l2.getSize(); i++) {
               l3.push_back(n2->getDato());
               n2 = n2->getNext();
           }
        }
        
        
        return l3;
    }
    
    void print(){
        if(size == 0){
            cout<<"La lista está vacía" <<endl;
        }else{
            Nodo* t = ptr;
            do{
                cout<<"("<<(*t).getDato()->getX()<<", "<<t->getDato()->getY()<<"), ";
                t = t->getNext();
                
            }while(t != NULL);
            cout<<endl;
        }
    }
    
};


int main()
{
   
   Lista l1 = Lista();
   Lista l2 = Lista();
   
   // PUSH BACK
   for(int i = 1; i<4; i++){
       l1.push_back(new Point(i,i));
       l2.push_back(new Point(i+3,i+3));
   }
   l1.print();
   l2.print();
   
   Lista l3 = Lista::fusion(l1,l2,1);
   l3.print();
   
   // INSERT
   //l.insert(new Point(10,10), 0);
   //l.print();
   
   // REMOVE
   //l.remove_nodo(2);
   //l.print();
	
   // REVERSE
   //l.reverse();
   //l.print();
   
   return 0;
}


int main()
{
   
   Lista l = Lista();
   
   // PUSH BACK
   for(int i = 1; i<11; i++){
       l.push_back(new Point(i,i));
   }
   l.print();
   
   // INSERT
   //l.insert(new Point(10,10), 0);
   //l.print();
   
   // REMOVE
   //l.remove_nodo(2);
   //l.print();
	
   // FALTA REVERSE
   //Lista c = Lista();
   //l.reverse(); // error loco
   //l.print();
   //c.print();
   
   return 0;
}
