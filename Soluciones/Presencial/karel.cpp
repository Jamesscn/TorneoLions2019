#include <iostream>
#include <vector>
#include <cmath>

#define inf 2000000

using namespace std;

struct Beeper {
    int x;
    int y;
};

int minTurnos = inf;
vector<Beeper> mejorCamino;

void moverXP(int &vueltas, int n, int dx) {
    if(dx > 0) {
        int its = n - vueltas;
        for(int j = 0; j < its; j++) {
            cout << "turnLeft();" << endl;
            vueltas++;
        }
        for(int j = 0; j < dx; j++) {
            cout << "move();" << endl;
        }
    }
}

void moverYP(int &vueltas, int n, int dy) {
    if(dy > 0) {
        int its = n - vueltas;
        for(int j = 0; j < its; j++) {
            cout << "turnLeft();" << endl;
            vueltas++;
        }
        for(int j = 0; j < dy; j++) {
            cout << "move();" << endl;
        }
    }
}

void moverXN(int &vueltas, int n, int dx) {
    if(dx < 0) {
        int its = n - vueltas;
        for(int j = 0; j < its; j++) {
            cout << "turnLeft();" << endl;
            vueltas++;
        }
        for(int j = 0; j < -dx; j++) {
            cout << "move();" << endl;
        }
    }    
}

void moverYN(int &vueltas, int n, int dy) {
    if(dy < 0) {
        int its = n - vueltas;
        for(int j = 0; j < its; j++) {
            cout << "turnLeft();" << endl;
            vueltas++;
        }
        for(int j = 0; j < -dy; j++) {
            cout << "move();" << endl;
        }
    }
}

void dfs(vector<Beeper> camino, vector<Beeper> restantes, int anguloInicial, int xKarel, int yKarel) {
    if(restantes.size() == 0) {
        int turnos = 0;
        for(int i = 0; i < camino.size(); i++) {
            int deltaX = abs(camino[i].x - xKarel);
            int deltaY = abs(camino[i].y - yKarel);
            int vueltas;
            if(deltaY == 0 && (anguloInicial == 0 || anguloInicial == 2)) {
                if(camino[i].x > xKarel && anguloInicial == 0) {
                    vueltas = 0;
                } else if (camino[i].x < xKarel && anguloInicial == 2) {
                    vueltas = 0;
                } else {
                    vueltas = 2;
                }
            } else if (deltaX == 0 && (anguloInicial == 1 || anguloInicial == 3)) {
                if(camino[i].y > yKarel && anguloInicial == 1) {
                    vueltas = 0;
                } else if (camino[i].y < yKarel && anguloInicial == 3) {
                    vueltas = 0;
                } else {
                    vueltas = 2;
                }
            } else {
                int cuadrante;
                if(camino[i].x > xKarel) {
                    if(camino[i].y > yKarel) {
                        cuadrante = 0;
                    } else {
                        cuadrante = 3;
                    }
                } else {
                    if(camino[i].y > yKarel) {
                        cuadrante = 1;
                    } else {
                        cuadrante = 2;
                    }
                }
                cuadrante += (4 - anguloInicial);
                cuadrante %= 4;
                int arrVueltas[] = {1, 2, 3, 3};
                vueltas = arrVueltas[cuadrante];
            }
            anguloInicial = (anguloInicial + vueltas) % 4;
            xKarel = camino[i].x;
            yKarel = camino[i].y;
            turnos += deltaX + deltaY + vueltas;
        }
        if(turnos < minTurnos) {
            minTurnos = turnos;
            mejorCamino.clear();
            for(int i = 0; i < camino.size(); i++) {
                mejorCamino.push_back(camino[i]);
            }
        }
        return;
    }
    for(int i = 0; i < restantes.size(); i++) {
        Beeper tmp = restantes[i];
        camino.push_back(restantes[i]);
        restantes.erase(restantes.begin() + i);
        dfs(camino, restantes, anguloInicial, xKarel, yKarel);
        restantes.insert(restantes.begin() + i, tmp);
        camino.pop_back();
    }
}

int main() {
    int x, y, angulo;
    string direccion;
    int cantidad;
    cin >> x >> y >> direccion >> cantidad;
    if(direccion == "ESTE") {
        angulo = 0;
    } else if (direccion == "NORTE") {
        angulo = 1;
    } else if (direccion == "OESTE") {
        angulo = 2;
    } else {
        angulo = 3;
    }
    vector<Beeper> caminoTemporal;
    vector<Beeper> restantes;
    //checar si hay un beeper sobre la posicion inicial
    for(int i = 0; i < cantidad; i++) {
        Beeper b;
        cin >> b.x >> b.y;
        if(b.x == x && b.y == y) {
            cout << "pickBeeper();" << endl;
        } else {
            restantes.push_back(b);
        }
    }
    dfs(caminoTemporal, restantes, angulo, x, y);
    for(int i = 0; i < mejorCamino.size(); i++) {
        int deltaX = mejorCamino[i].x - x;
        int deltaY = mejorCamino[i].y - y;
        int vueltas = 0;
        if(angulo == 0) {
            moverXP(vueltas, 0, deltaX);
            moverYP(vueltas, 1, deltaY);
            moverXN(vueltas, 2, deltaX);
            moverYN(vueltas, 3, deltaY);
        } else if (angulo == 1) {
            moverYP(vueltas, 0, deltaY);
            moverXN(vueltas, 1, deltaX);
            moverYN(vueltas, 2, deltaY);
            moverXP(vueltas, 3, deltaX);
        } else if (angulo == 2) {
            moverXN(vueltas, 0, deltaX);
            moverYN(vueltas, 1, deltaY);
            moverXP(vueltas, 2, deltaX);
            moverYP(vueltas, 3, deltaY);
        } else {
            moverYN(vueltas, 0, deltaY);
            moverXP(vueltas, 1, deltaX);
            moverYP(vueltas, 2, deltaY);
            moverXN(vueltas, 3, deltaX);
        }
        angulo = (angulo + vueltas) % 4;
        cout << "pickBeeper();" << endl;
        x = mejorCamino[i].x;
        y = mejorCamino[i].y;
    }
}