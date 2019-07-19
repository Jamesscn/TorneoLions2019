#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

struct Ciudad {
    string nombre;
    double latitud;
    double longitud;
};

bool ordenaCarreteras(pair<Ciudad, Ciudad> a, pair<Ciudad, Ciudad> b) {
    if(a.first.nombre < b.first.nombre) {
        return true;
    } else if (a.first.nombre == b.first.nombre) {
        if(a.second.nombre < b.second.nombre) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<Ciudad> unidos;
    vector<Ciudad> restantes;
    vector<pair<Ciudad, Ciudad>> carreteras;
    for(int i = 0; i < n; i++) {
        Ciudad actual;
        cin >> actual.nombre >> actual.latitud >> actual.longitud;
        restantes.push_back(actual);
    }
    unidos.push_back(restantes[0]);
    restantes.erase(restantes.begin() + 0);
    while(restantes.size() > 0) {
        double minDistancia = 2000000;
        int minI = -1;
        int minJ = -1;
        for(int i = 0; i < unidos.size(); i++) {
            for(int j = 0; j < restantes.size(); j++) {
                double deltaLat = unidos[i].latitud - restantes[j].latitud;
                double deltaLong = unidos[i].longitud - restantes[j].longitud;
                double distancia = sqrt(deltaLat * deltaLat + deltaLong * deltaLong);
                if(distancia < minDistancia) {
                    minDistancia = distancia;
                    minI = i;
                    minJ = j;
                }
            }
        }
        carreteras.push_back(make_pair(unidos[minI], restantes[minJ]));
        unidos.push_back(restantes[minJ]);
        restantes.erase(restantes.begin() + minJ);
    }
    for(int i = 0; i < carreteras.size(); i++) {
        if(carreteras[i].first.nombre > carreteras[i].second.nombre) {
            Ciudad tmp = carreteras[i].first;
            carreteras[i].first = carreteras[i].second;
            carreteras[i].second = tmp;
        }
    }
    sort(carreteras.begin(), carreteras.end(), ordenaCarreteras);
    for(int i = 0; i < carreteras.size(); i++) {
        cout << carreteras[i].first.nombre << " " << carreteras[i].second.nombre << endl;
    }
}