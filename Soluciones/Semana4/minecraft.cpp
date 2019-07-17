#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Bloque {
    int x;
    int y;
    int xPrevio;
    int yPrevio;
    bool pared;
    bool visitado;
};

int main() {
    int n;
    cin >> n;
    Bloque mapa[n][n];
    Bloque inicial, final;
    for(int y = 0; y < n; y++) {
        string str;
        cin >> str;
        for(int x = 0; x < n; x++) {
            mapa[y][x].x = x;
            mapa[y][x].y = y;
            if(str[x] == '#') {
                mapa[y][x].pared = true;
            } else {
                mapa[y][x].pared = mapa[y][x].visitado = false;
                if(str[x] == 'X') {
                    inicial = mapa[y][x];
                    mapa[y][x].visitado = true;
                } else if(str[x] == 'H') {
                    final = mapa[y][x];
                }
            }
        }
    }
    queue<Bloque> busqueda;
    busqueda.push(mapa[inicial.y][inicial.x]);
    while(busqueda.size() > 0) {
        Bloque actual = busqueda.front();
        busqueda.pop();
        if(actual.x == final.x && actual.y == final.y) {
            break;
        }
        int x = actual.x;
        int y = actual.y;
        if(x - 1 >= 0) {
            if(!mapa[y][x - 1].pared && !mapa[y][x - 1].visitado) {
                mapa[y][x - 1].xPrevio = x;
                mapa[y][x - 1].yPrevio = y;
                mapa[y][x - 1].visitado = true;
                busqueda.push(mapa[y][x - 1]);
            }
        }
        if(x + 1 < n) {
            if(!mapa[y][x + 1].pared && !mapa[y][x + 1].visitado) {
                mapa[y][x + 1].xPrevio = x;
                mapa[y][x + 1].yPrevio = y;
                mapa[y][x + 1].visitado = true;
                busqueda.push(mapa[y][x + 1]);
            }
        }
        if(y - 1 >= 0) {
            if(!mapa[y - 1][x].pared && !mapa[y - 1][x].visitado) {
                mapa[y - 1][x].xPrevio = x;
                mapa[y - 1][x].yPrevio = y;
                mapa[y - 1][x].visitado = true;
                busqueda.push(mapa[y - 1][x]);
            }
        }
        if(y + 1 < n) {
            if(!mapa[y + 1][x].pared && !mapa[y + 1][x].visitado) {
                mapa[y + 1][x].xPrevio = x;
                mapa[y + 1][x].yPrevio = y;
                mapa[y + 1][x].visitado = true;
                busqueda.push(mapa[y + 1][x]);
            }
        }
    }
    queue<Bloque> camino;
    camino.push(mapa[final.y][final.x]);
    stack<string> comandos;
    while(camino.size() > 0) {
        Bloque actual = camino.front();
        camino.pop();
        if(actual.x == inicial.x && actual.y == inicial.y) {
            break;
        }
        if(actual.xPrevio == actual.x - 1) {
            camino.push(mapa[actual.y][actual.x - 1]);
            comandos.push("DERECHA");
        } else if (actual.xPrevio == actual.x + 1) {
            camino.push(mapa[actual.y][actual.x + 1]);
            comandos.push("IZQUIERDA");
        } else if (actual.yPrevio == actual.y - 1) {
            camino.push(mapa[actual.y - 1][actual.x]);
            comandos.push("ABAJO");
        } else {
            camino.push(mapa[actual.y + 1][actual.x]);
            comandos.push("ARRIBA");
        }
    }
    while(comandos.size() > 0) {
        string actual = comandos.top();
        comandos.pop();
        cout << actual << endl;
    }
}