#include <iostream>

using namespace std;

/*
 * Esta implementación es la más facil, pero no la más eficiente
 * Complejidad de tiempo: O(N^2)
 */

int main() {
	int n;
	cin >> n;
	int valores[n];
	for(int i = 0; i < n; i++) {
		cin >> valores[i];
	}
	for(int i = 0; i < n; i++) {
		int mayores = 0;
		for(int j = 0; j < n; j++) {
			if(i != j && valores[j] > valores[i]) {
				mayores++;
			}
		}
		cout << mayores << endl;
	}
}
