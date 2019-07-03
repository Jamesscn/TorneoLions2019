#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int mayorRacha = 0;
	int rachaActual = 0;
	int valorPrevio = -1;
	for(int i = 0; i < n; i++) {
		int valor;
		cin >> valor;
		if(valor >= valorPrevio) {
			rachaActual++;
			if(rachaActual > mayorRacha) {
				mayorRacha++;
			}
		} else {
			rachaActual = 1;
		}
		valorPrevio = valor;
	}
	cout << mayorRacha << endl;
}