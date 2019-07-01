#include <iostream>
#include <algorithm>
#include <utility>

#define ull unsigned long long int

using namespace std;

void printHash(ull hash) {
	ull mask = 9223372036854775808ull;
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if((hash & mask) == 0) {
				cout << '.';
			} else {
				cout << '#';
			}
			mask >>= 1;
		}
		cout << endl;
	}
}

int main() {
	ull value;
	cin >> value;
	printHash(value);
}
