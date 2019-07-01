#include <iostream>
#include <algorithm>
#include <utility>

#define ull unsigned long long int

using namespace std;

int min(int a, int b) {
	if(b < a) {
		return b;
	}
	return a;
}

bool sortHash(pair<int, ull> a, pair<int, ull> b) {
	if(a.second < b.second) {
		return true;
	}
	return false;
}

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

/*
 * Explicación:
 *
 * Se simulan las N generaciones de Conway y se guardan todos en hashes
 * o unsigned long long ints (tamaño de 64 bits) con cada bit de este
 * dato siendo un lugar en el mapa (prendido o apagado). Luego, se
 * comparan estos hashes a ver cuales son cero, cuales se repiten y
 * cuales no se repiten. En base a estos calculos, se obtiene la
 * respuesta.
 */

int main() {
	int generations;
	cin >> generations;
	bool map[8][8];
	bool nextMap[8][8];
	string trash;
	getline(cin, trash);
	pair<int, ull> hashes[generations + 1];
	for(int y = 0; y < 8; y++) {
		string input;
		getline(cin, input);
		for(int x = 0; x < 8; x++) {
			if(input[x] == '#') {
				map[y][x] = true;
			} else {
				map[y][x] = false;
			}
		}
	}
	for(int gen = 0; gen <= generations; gen++) {
		ull currHash = 0;
		for(int y = 0; y < 8; y++) {
			for(int x = 0; x < 8; x++) {
				currHash <<= 1;
				int neighbours = 0;
				for(int j = -1; j <= 1; j++) {
					for(int i = -1; i <= 1; i++) {
						if(y + j >= 0 && y + j < 8 && x + i >= 0 && x + i < 8 && !(j == 0 && i == 0)) {
							neighbours += map[y + j][x + i];
						}
					}
				}
				if(neighbours < 2 || neighbours > 3) {
					nextMap[y][x] = false;
				} else if (neighbours == 3) {
					nextMap[y][x] = true;
				} else {
					nextMap[y][x] = map[y][x];
				}
				currHash += map[y][x];
			}
		}
		hashes[gen] = make_pair(gen, currHash);
		for(int y = 0; y < 8; y++) {
			for(int x = 0; x < 8; x++) {
				map[y][x] = nextMap[y][x];
			}
		}
	}
	for(int i = 0; i <= generations; i++) {
		if(hashes[i].second == 0) {
			printHash(0);
			cout << "desaparece despues de " << i << " turnos" << endl;
			return 0;
		}
	}
	ull lastHash = hashes[generations].second;
	ull repeatHash;
	sort(hashes, hashes + generations + 1, sortHash);
	int repeatGen = generations + 1;
	for(int i = 1; i <= generations; i++) {
		if(hashes[i].second == hashes[i - 1].second) {
			int rep = min(hashes[i].first, hashes[i - 1].first);
			if(rep < repeatGen) {
				repeatGen = rep;
				if(rep == hashes[i].first) {
					repeatHash = hashes[i].second;
				} else {
					repeatHash = hashes[i - 1].second;
				}
			}
		}
	}
	if(repeatGen != generations + 1) {
		printHash(repeatHash);
		cout << "repite despues de " << repeatGen << " turnos" << endl;
	} else {
		printHash(lastHash);
		cout << "inestable" << endl;
	}
}
