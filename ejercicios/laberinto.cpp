on: -1 izq, +1 der, +2 arriba, -2 abajo
pair<int, int> avanzar(pair<int,int> oldxy, int dir) {
    pair<int,int> xy;
    
    if(abs(dir) == 1) {
        xy.first = oldxy.first + dir;
        xy.second = oldxy.second;
    } else {
        xy.second = oldxy.second + dir/2;
        xy.first = oldxy.first;
    }
    return xy;
}

bool puedeSeguir(pair<int, int> xy, int dir) {
    pair<int, int> fxy = avanzar(xy, dir);
    if(puedeSeguir(fxy, dir)) {
        //añadir la posicion al camino
        return true;
    }
    
    // pair rxy girando a la derecha
    if(puedeSeguir(rxy, dir)) {
        // añadir la posicion al camino
        return true;
    }
    
    // pair lxy girando a la derecha
    if(puedeSeguir(lxy, dir)) {
        // añadir la posicion al camino
        return true;
    }
    
    return false;
}


int main() {
    
}
