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
            mapa[x][y].x = x;
            mapa[x][y].y = y;
            if(str[x] == '#') {
                mapa[x][y].pared = true;
            } else {
                mapa[x][y].pared = mapa[x][y].visitado = false;
                if(str[x] == 'X') {
                    inicial = mapa[x][y];
                } else if(str[x] == 'H') {
                    final = mapa[x][y];
                }
            }
        }
    }
    queue<Bloque> busqueda;
    busqueda.push(inicial);
    while(busqueda.size() > 0) {
        Bloque actual = busqueda.front();
        busqueda.pop();
        if(actual.x == final.x && actual.y == final.y) {
            break;
        }
        int x = actual.x;
        int y = actual.y;
        if(x - 1 >= 0) {
            if(!mapa[x - 1][y].pared && !mapa[x - 1][y].visitado) {
                mapa[x - 1][y].xPrevio = x;
                mapa[x - 1][y].yPrevio = y;
                mapa[x - 1][y].visitado = true;
                busqueda.push(mapa[x - 1][y]);
            }
        }
        if(x + 1 < n) {
            if(!mapa[x + 1][y].pared && !mapa[x + 1][y].visitado) {
                mapa[x + 1][y].xPrevio = x;
                mapa[x + 1][y].yPrevio = y;
                mapa[x + 1][y].visitado = true;
                busqueda.push(mapa[x + 1][y]);
            }
        }
        if(y - 1 >= 0) {
            if(!mapa[x][y - 1].pared && !mapa[x][y - 1].visitado) {
                mapa[x][y - 1].xPrevio = x;
                mapa[x][y - 1].yPrevio = y;
                mapa[x][y - 1].visitado = true;
                busqueda.push(mapa[x][y - 1]);
            }
        }
        if(y + 1 < n) {
            if(!mapa[x][y + 1].pared && !mapa[x][y + 1].visitado) {
                mapa[x][y + 1].xPrevio = x;
                mapa[x][y + 1].yPrevio = y;
                mapa[x][y + 1].visitado = true;
                busqueda.push(mapa[x][y + 1]);
            }
        }
    }
    queue<Bloque> camino;
    camino.push(final);
    stack<string> comandos;
    while(camino.size() > 0) {
        Bloque actual = camino.front();
        camino.pop();
        if(actual.x == inicial.x && actual.y == inicial.y) {
            break;
        }
        if(actual.xPrevio == actual.x - 1) {
            camino.push(mapa[actual.x - 1][actual.y]);
            comandos.push("DERECHA");
        } else if (actual.xPrevio == actual.x + 1) {
            camino.push(mapa[actual.x + 1][actual.y]);
            comandos.push("IZQUIERDA");
        } else if (actual.yPrevio == actual.y - 1) {
            camino.push(mapa[actual.x][actual.y - 1]);
            comandos.push("ABAJO");
        } else {
            camino.push(mapa[actual.x][actual.y + 1]);
            comandos.push("ARRIBA");
        }
    }
    while(comandos.size() > 0) {
        string actual = comandos.top();
        comandos.pop();
        cout << actual << endl;
    }
}