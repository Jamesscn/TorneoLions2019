#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;
    long double phi = (1 + sqrtl(5)) / 2;
    long double invPhi = (1 - sqrtl(5)) / 2;
    int i = 0;
    vector<pair<int, int>> pares;
    long double fibonacci = 0;
    while(log10(fibonacci) < 1000) {
        fibonacci = round((powl(phi, i) - powl(invPhi, i)) / sqrtl(5));
        int digitos = log10(fibonacci);
        pair<int, int> par = make_pair(i, digitos);
        pares.push_back(par);
        i++;
    }
    int respuestas[1000];
    for(int i = 1; i < pares.size(); i++) {
        if(pares[i].second != pares[i - 1].second) {
            respuestas[pares[i].second] = pares[i].first;
        }
    }
    for(int i = 0; i < n; i++) {
        int query;
        cin >> query;
        cout << respuestas[query - 1] << endl;
    }
}