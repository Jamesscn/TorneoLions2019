#include <iostream>

using namespace std;

int main() {
	int k;
	cin >> k;
	for(int n = 0; n < k; n++) {
		string s;
		cin >> s;
		bool palindromo = true;
		for(int i = 0; i <= s.length() / 2; i++) {
			if((s[i] % 32 + 64) != (s[s.length() - i - 1] % 32 + 64)) {
				palindromo = false;
				break;
			}
		}
		if(palindromo) {
			cout << "Si" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}
