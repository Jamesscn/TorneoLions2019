#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Nodo {
    int x;
    int y;
    int indice;
    vector<int> posibles;
};

int cuadrada(int x, int y) {
    int a = x / 3;
    int b = y / 3;
    return 3 * b + a;
}

int main() {
    int sudoku[9][9];
    int frecuenciaHorizontal[9][9];
    int frecuenciaVertical[9][9];
    int frecuenciaCuadrada[9][9];
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            frecuenciaHorizontal[i][j] = 0;
            frecuenciaVertical[i][j] = 0;
            frecuenciaCuadrada[i][j] = 0;
        }
    }
    for(int y = 0; y < 9; y++) {
        for(int x = 0; x < 9; x++) {
            cin >> sudoku[y][x];
            if(sudoku[y][x] != 0) {
                frecuenciaHorizontal[x][sudoku[y][x] - 1]++;
                frecuenciaVertical[y][sudoku[y][x] - 1]++;
                frecuenciaCuadrada[cuadrada(x, y)][sudoku[y][x] - 1]++;
            }
        }
    }
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(frecuenciaHorizontal[i][j] > 1 || frecuenciaVertical[i][j] > 1 || frecuenciaCuadrada[i][j] > 1) {
                cout << "Imposible" << endl;
                return 0;
            }
        }
    }
    vector<Nodo> faltantes;
    for(int y = 0; y < 9; y++) {
        for(int x = 0; x < 9; x++) {
            if(sudoku[y][x] == 0) {
                Nodo n;
                n.x = x;
                n.y = y;
                for(int i = 0; i < 9; i++) {
                    if(frecuenciaHorizontal[x][i] == 0 && frecuenciaVertical[y][i] == 0 && frecuenciaCuadrada[cuadrada(x, y)][i] == 0) {
                        n.posibles.push_back(i);
                    }
                }
                n.indice = 0;
                faltantes.push_back(n);
            }
        }
    }
    for(int i = 0; i < faltantes.size(); i++) {
        if(faltantes[i].posibles.size() == 0) {
            cout << "Imposible" << endl;
            return 0;
        }
    }
    int faltIndice = 0;
    bool posible = true;
    while(faltIndice < faltantes.size()) {
        int x = faltantes[faltIndice].x;
        int y = faltantes[faltIndice].y;
        int valor = faltantes[faltIndice].posibles[faltantes[faltIndice].indice];
        frecuenciaHorizontal[x][valor]++;
        frecuenciaVertical[y][valor]++;
        frecuenciaCuadrada[cuadrada(x, y)][valor]++;
        if(frecuenciaHorizontal[x][valor] == 1 && frecuenciaVertical[y][valor] == 1 && frecuenciaCuadrada[cuadrada(x, y)][valor] == 1) {
            sudoku[y][x] = valor + 1;
            faltIndice++;
        } else {
            bool fin = true;
            for(int i = faltIndice; i >= 0; i--) {
                x = faltantes[i].x;
                y = faltantes[i].y;
                valor = faltantes[i].posibles[faltantes[i].indice];
                frecuenciaHorizontal[x][valor]--;
                frecuenciaVertical[y][valor]--;
                frecuenciaCuadrada[cuadrada(x, y)][valor]--;
                if(faltantes[i].indice == faltantes[i].posibles.size() - 1) {
                    faltantes[i].indice = 0;
                    faltIndice--;
                } else {
                    faltantes[i].indice++;
                    fin = false;
                    break;
                }
            }
            if(fin) {
                posible = false;
                break;
            }
        }
    }
    if(posible) {
        for(int y = 0; y < 9; y++) {
            for(int x = 0; x < 9; x++) {
                cout << sudoku[y][x] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Imposible" << endl;
    }
}