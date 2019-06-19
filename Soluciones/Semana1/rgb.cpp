#include <iostream>

using namespace std;

int mayor(int a, int b, int c) {
    if(b > a) {
        a = b;
    }
    if(c > a) {
        a = c;
    }
    return a;
}

int main() {
    int casos;
    cin >> casos;
    string colores[] = {"", "azul", "verde", "cyan", "rojo", "morado", "amarillo", "blanco"};
    for(int i = 0; i < casos; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        int max = mayor(r, g, b);
        r = (r == max);
        g = (g == max);
        b = (b == max);
        int codigo = 4 * r + 2 * g + b;
        cout << colores[codigo] << endl;
    }
}