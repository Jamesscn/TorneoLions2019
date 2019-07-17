#include <cstdlib>
#include <ncurses.h>
#include <random>
#include <limits>
#include <thread>
#include <chrono>

using namespace std;

unsigned long long int strToInt(char* str) {
	int index = 0;
	unsigned long long int output = 0;
	while(str[index] != '\0') {
		output *= 10;
		output += str[index] - 48;
		index++;
	}
	return output;
}

int main(int argc, char** argv) {
	random_device rd;
	mt19937_64 eng(rd());
	uniform_int_distribution<unsigned long long int> distr;
	char symbols[] = {'.', 'X'};
	initscr();
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	bool map[8][8];
	bool nextMap[8][8];
	unsigned long long int seed = distr(eng);
	if(argc == 2) {
		seed = strToInt(argv[1]); //convert
	}
	unsigned long long int mask = 1;
	for(int y = 0; y < 8; y++) {
		for(int x = 0; x < 8; x++) {
			if((seed & mask) == 0) {
				map[7 - y][7 - x] = false;
			} else {
				map[7 - y][7 - x] = true;
			}
			mask <<= 1;
		}
	}
	unsigned long long int generation = 0;
	while(true) {
		clear();
		for(int y = 0; y < 8; y++) {
			for(int x = 0; x < 8; x++) {
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
			}
		}
		for(int y = 0; y < 8; y++) {
			move(y, 0);
			for(int x = 0; x < 8; x++) {
				//map[y][x] = nextMap[y][x];
				if(map[y][x]) {
					attron(COLOR_PAIR(1));
				}
				printw("%c", symbols[map[y][x]]);
				attroff(COLOR_PAIR(1));
				map[y][x] = nextMap[y][x];
			}
		}
		move(8, 0);
		printw("%d", generation);
		move(9, 0);
		printw("seed: %llu", seed);
		generation++;
		refresh();
		this_thread::sleep_for(chrono::milliseconds(800));
	}
	endwin();
}
