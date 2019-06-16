#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	bool palindromo = true;
	for(int i = 0; i <= s.length() / 2; i++) {
		if(s[i] != s[s.length() - i - 1]) {
			palindromo = false;
			break;
		}
	}
	if(palindromo) {
		cout << "SI ES PALINDROMO" << endl;
	} else {
		cout << "NO ES PALINDROMO" << endl;
	}
}
