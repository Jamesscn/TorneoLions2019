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

class BigInt {
    public:
        string valor;

        void operator=(const BigInt& b) {
            valor = b.valor;
        }

        void operator=(const char* b) {
            valor = b;
        }

        void operator+=(const BigInt& b) {
            string suma = "";
            int minSize = min(b.valor.size(), valor.size());
            int carry = 0;
            for(int i = 0; i < minSize; i++) {
                int digitoA = valor[valor.size() - 1 - i] - '0';
                int digitoB = b.valor[b.valor.size() - 1 - i] - '0';
                int digitoC = (digitoA + digitoB + carry) % 10;
                carry = (digitoA + digitoB + carry) / 10;
                suma = (char)('0' + digitoC) + suma;
            }
            for(int i = 0; i < b.valor.size() - minSize; i++) {
                int digitoB = b.valor[b.valor.size() - minSize - 1 - i] - '0';
                int digitoC = (digitoB + carry) % 10;
                carry = (digitoB + carry) / 10;
                suma = (char)('0' + digitoC) + suma;
            }
            for(int i = 0; i < valor.size() - minSize; i++) {
                int digitoA = valor[valor.size() - minSize - 1 - i] - '0';
                int digitoC = (digitoA + carry) % 10;
                carry = (digitoA + carry) / 10;
                suma = (char)('0' + digitoC) + suma;
            }
			if(carry > 0) {
				suma = (char)('0' + carry) + suma;
			}
			valor = suma;
        }

        void imprime() {
            cout << valor << endl;
        }
};

int main() {
    int suma;
    cin >> suma;
    BigInt posibles[max(123, suma + 1)];
    vector<int> alfas;
    for(int i = 0; i < 123; i++) {
        if(esAlfa(i)) {
            alfas.push_back(i);
            posibles[i] = "1";
        } else {
            posibles[i] = "0";
        }
    }
    for(int i = 96; i <= suma; i++) {
        BigInt totales;
        totales = "0";
        if(esAlfa(i)) {
            totales = "1";
        }
        for(int j = 0; j < alfas.size(); j++) {
            if(i - alfas[j] < 0) {
                break;
            }
            totales += posibles[i - alfas[j]];
        }
        posibles[i] = totales;
    }
    posibles[suma].imprime();
}