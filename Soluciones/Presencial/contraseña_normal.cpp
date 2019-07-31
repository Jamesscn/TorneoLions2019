#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool esAlfa(int x) {
    if(x >= '0' && x <= '9') {
        return true;
    }
    if(x >= 'A' && x <= 'Z') {
        return true;
    }
    if(x >= 'a' && x <= 'z') {
        return true;
    }
    return false;
}

int main() {
    int suma;
    cin >> suma;
    unsigned long long int posibles[max(123, suma + 1)];
    vector<int> alfas;
    for(int i = 0; i < 123; i++) {
        if(esAlfa(i)) {
            alfas.push_back(i);
            posibles[i] = 1;
        } else {
            posibles[i] = 0;
        }
    }
    for(int i = 96; i <= suma; i++) {
        unsigned long long int totales;
        totales = 0;
        if(esAlfa(i)) {
            totales = 1;
        }
        for(int j = 0; j < alfas.size(); j++) {
            if(i - alfas[j] < 0) {
                break;
            }
            totales += posibles[i - alfas[j]];
        }
        posibles[i] = totales;
    }
    cout << posibles[suma] << endl;
}