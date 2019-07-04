#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string tarjeta;
        cin >> tarjeta;
        int desfase = tarjeta.size() % 2;
        int suma = 0;
        for(int j = desfase; j < tarjeta.size(); j += 2) {
            int digito = tarjeta[j] - 48;
            digito *= 2;
            if(digito > 9) {
                digito -= 9;
            }
            suma += digito;
        }
        for(int j = 1 - desfase; j < tarjeta.size(); j += 2) {
            int digito = tarjeta[j] - 48;
            suma += digito;
        }
        if(suma % 10 == 0) {
            cout << "Bancomega" << endl;
        } else {
            cout << "Bankarel" << endl;
        }
    }
}