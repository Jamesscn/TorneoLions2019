#include <unordered_map>
#include <iostream>
#include <stack>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	string dictA, dictB;
	cin >> dictA >> dictB;
	unordered_map<char, int> digitosA;
	for(int i = 0; i < a; i++) {
		digitosA[dictA[i]] = i;
	}
	if(a == 1) {
		digitosA[dictA[0]] = 1;
	}
	string valor;
	cin >> valor;
	int valorDecimal = 0;
	for(int i = 0; i < valor.size(); i++) {
		valorDecimal *= a;
		valorDecimal += digitosA[valor[i]];
	}
	stack<char> digitosB;
	if(valorDecimal == 0) {
		digitosB.push(dictB[0]);
	}
	while(valorDecimal > 0) {
		digitosB.push(dictB[valorDecimal % b]);
		if(b == 1) {
			valorDecimal--;
		} else {
			valorDecimal /= b;
		}
	}
	while(digitosB.size() > 0) {
		cout << digitosB.top();
		digitosB.pop();
	}
	cout << endl;
}
