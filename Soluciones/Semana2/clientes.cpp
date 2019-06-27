#include <iostream>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    unordered_map<string, pair<int, int>> compras;
    unordered_set<string> clientes;
    int piezas[] = {5, 20, 15, 10, 12};
    while(true) {
        string nombre;
        int codigo, cantidad;
        cin >> nombre >> codigo >> cantidad;
        if(nombre == "FIN") {
            break;
        }
        if(compras.count(nombre) == 0) {
            compras[nombre] = make_pair(piezas[codigo - 1] * cantidad, cantidad);
        } else {
            compras[nombre].first += piezas[codigo - 1] * cantidad;
            compras[nombre].second += cantidad;
        }
        clientes.insert(nombre);
    }
    for(int i = 0; i < 3; i++) {
        int max = 0;
        string mejor;
        for(unordered_set<string>::iterator it = clientes.begin(); it != clientes.end(); it++) {
            string cliente = *it;
            if(compras[cliente].first > max) {
                max = compras[cliente].first;
                mejor = cliente;
            }
        }
        cout << mejor << " " << compras[mejor].first << " " << compras[mejor].second << endl;
        clientes.erase(mejor);
    }
}