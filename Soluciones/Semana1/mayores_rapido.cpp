#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

/*
 * Esta implementación no es la más sencilla, pero sí es la más eficiente
 * Complejidad de tiempo: O(N log N)
 */

struct Estructura {
	int valor;
	int indice;
	int mayores;
};

bool ordenaValor(Estructura a, Estructura b) {
	if(a.valor < b.valor) {
		return true;
	}
	return false;
}

bool ordenaIndice(Estructura a, Estructura b) {
	if(a.indice < b.indice) {
		return true;
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	Estructura valores[n];
	for(int i = 0; i < n; i++) {
		cin >> valores[i].valor;
		valores[i].indice = i;
	}
	sort(valores, valores + n, ordenaValor);
	int index = n - 1;
	valores[n - 1].mayores = 0;
	for(int i = n - 2; i >= 0; i--) {
		if(valores[i].valor != valores[i + 1].valor) {
			index = i;
		}
		valores[i].mayores = n - index - 1;
	}
	sort(valores, valores + n, ordenaIndice);
	for(int i = 0; i < n; i++) {
		cout << valores[i].mayores << endl;
	}
}
