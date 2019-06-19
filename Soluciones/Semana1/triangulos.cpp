#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		int lado;
		cin >> lado;
		float altura = lado * sqrt(3) / 2;
		cout << fixed << setprecision(2);
		cout << altura << endl;
	}
}