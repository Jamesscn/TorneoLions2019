#include <iostream>
#include <cmath>

using namespace std;

struct Punto {
    int x;
    int y;
};

int main() {
    int n;
    cin >> n;
    Punto iniciales[n];
    Punto finales[n];
    for(int i = 0; i < n; i++) {
        cin >> iniciales[i].x >> iniciales[i].y;
    }
    for(int i = 0; i < n; i++) {
        cin >> finales[i].x >> finales[i].y;
    }
    int dx = finales[0].x - iniciales[0].x;
    int dy = finales[0].y - iniciales[0].y;
    bool traslacion = true;
    for(int i = 1; i < n; i++) {
        if(iniciales[i].x + dx != finales[i].x || iniciales[i].y + dy != finales[i].y) {
            traslacion = false;
            break;
        }
    }
    if(traslacion) {
        cout << "traslacion " << dx << " " << dy << endl;
        return 0;
    }
    bool reflejoX = true;
    for(int i = 0; i < n; i++) {
        if(iniciales[i].y != -finales[i].y) {
            reflejoX = false;
            break;
        }
    }
    if(reflejoX) {
        cout << "reflexion x" << endl;
        return 0;
    }
    bool reflejoY = true;
    for(int i = 0; i < n; i++) {
        if(iniciales[i].x != -finales[i].x) {
            reflejoY = false;
            break;
        }
    }
    if(reflejoY) {
        cout << "reflexion y" << endl;
        return 0;
    }
    int indice = 0;
    while(iniciales[indice].x == 0 && iniciales[indice].y == 0) {
        indice++;
    }
    int factor = finales[indice].y / iniciales[indice].y;
    bool escalamiento = true;
    if(factor == 1) {
        escalamiento = false;
    }
    for(int i = 0; i < n; i++) {
        if(iniciales[i].x * factor != finales[i].x || iniciales[i].y * factor != finales[i].y) {
            escalamiento = false;
            break;
        }
    }
    if(escalamiento) {
        cout << "escalamiento " << factor << endl;
        return 0;
    }
    double angulo = asin((double)(finales[indice].y * iniciales[indice].x - finales[indice].x * iniciales[indice].y)/(iniciales[indice].x * iniciales[indice].x + iniciales[indice].y * iniciales[indice].y)) * 180 / 3.1415926535;
    cout << "rotacion " << round(angulo) << endl;
}