#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Nodo {
    int x;
    int y;
    bool pared;
    bool visitado;
}

int main() {
    int x, y;
    Nodo mapa[y][x];
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            char c;
            cin >> c;
            mapa[i][j].x = j;
            mapa[i][j].y = i;
            mapa[i][j].pared = false;
            mapa[i][j].visitado = false;
            if(c == "#") {
                mapa[i][j].pared = true;
            }
        }
    }
    //check regions
}