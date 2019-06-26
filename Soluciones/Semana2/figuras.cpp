#include <iostream>
#include <utility>

using namespace std;

int productoPunto(pair<int, int> a, pair<int, int> b) {
    return a.first * b.first + a.second * b.second;
}

int productoCruz(pair<int, int> a, pair<int, int> b) {
    return a.first * b.second - a.second * b.first;
}

int deltaX(pair<int, int> a, pair<int, int> b) {
    return b.first - a.first;
}

int deltaY(pair<int, int> a, pair<int, int> b) {
    return b.second - a.second;
}

int magnitud(pair<int, int> a) {
    return a.first * a.first + a.second * a.second;
}

int main() {
    pair<int, int> puntos[4];
    int magnitudes[4];
    int prodPuntos[4];
    pair<int, int> lados[4];
    for(int i = 0; i < 4; i++) {
        cin >> puntos[i].first >> puntos[i].second;
    }
    for(int i = 0; i < 4; i++) {
        pair<int, int> vectorPrevio;
        pair<int, int> vectorSiguiente;
        vectorPrevio.first = deltaX(puntos[i], puntos[(i + 3) % 4]);
        vectorPrevio.second = deltaY(puntos[i], puntos[(i + 3) % 4]);
        vectorSiguiente.first = deltaX(puntos[i], puntos[(i + 1) % 4]);
        vectorSiguiente.second = deltaY(puntos[i], puntos[(i + 1) % 4]);
        magnitudes[i] = magnitud(vectorPrevio);
        prodPuntos[i] = productoPunto(vectorPrevio, vectorSiguiente);
        lados[i] = vectorSiguiente;
    }
    bool ladosIguales = true;
    bool angulosRectos = true;
    bool ABparaleloCD = false;
    bool ADparaleloBC = false;
    for(int i = 1; i < 4; i++) {
        if(magnitudes[i] != magnitudes[0]) {
            ladosIguales = false;
        }
    }
    for(int i = 0; i < 4; i++) {
        if(prodPuntos[i] != 0) {
            angulosRectos = false;
        }
    }
    if(productoCruz(lados[0], lados[2]) == 0) {
        ABparaleloCD = true;
    }
    if(productoCruz(lados[1], lados[3]) == 0) {
        ADparaleloBC = true;
    }
    if(ladosIguales) {
        cout << "Cuadrado" << endl;
    } else if (angulosRectos) {
        cout << "Rectangulo" << endl;
    } else if (ABparaleloCD && ADparaleloBC) {
        cout << "Paralelogramo" << endl;
    } else if (ABparaleloCD || ADparaleloBC) {
        cout << "Trapezoide" << endl;
    } else {
        cout << "Ninguno" << endl;
    }
}