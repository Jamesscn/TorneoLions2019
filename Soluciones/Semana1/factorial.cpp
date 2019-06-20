#include <iostream>

using namespace std;

int main() {
	int factorial;
	cin >> factorial;
	unsigned long long int valor = 1;
	for(int i = 2; i <= factorial; i++) {
		valor *= i;
	}
	cout << valor << endl;
}
