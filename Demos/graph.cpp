#include <ncurses.h>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include <queue>
#include <stack>

using namespace std;

class Point {
public:
	int x;
	int y;
	int prevX;
	int prevY;
	bool visited;

	Point(int _x, int _y) {
		x = _x;
		y = _y;
		visited = false;
	}

	void visit(int _x, int _y) {
		prevX = _x;
		prevY = _y;
		visited = true;
	}
};

void wait(int millis) {
	this_thread::sleep_for(chrono::milliseconds(millis));
}

int main() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	int len;
	ifstream mapFile;
	mapFile.open("map.txt");
	mapFile >> len;
	bool grid[len][len];
	vector<vector<Point>> map;
	string line;
	for(int i = 0; i < len; i++) {
		move(i, 0);
		mapFile >> line;
		vector<Point> v;
		for(int j = 0; j < len; j++) {
			Point p(i, j);
			v.push_back(p);
			if(line[j] == '#') {
				grid[i][j] = true;
				attron(A_REVERSE);
				printw(" ");
				attroff(A_REVERSE);
			} else {
				grid[i][j] = false;
				printw(" ");
			}
		}
		map.push_back(v);
	}
	mapFile.close();
	refresh();
	int startX = 0;
	int startY = 1;
	int targetX = len - 2;
	int targetY = len - 1;
	move(startX, startY);
	printw("@");
	//do bfs
	//find route
	//highlight route :D
	//goto route
	queue<Point> bfs;
	bfs.push(map[startX][startY]);
	while(bfs.size() > 0) {
		Point current = bfs.front();
		bfs.pop();
		int cx = current.x;
		int cy = current.y;
		if(cx != startX || cy != startY) {
			move(cx, cy);
			if(current.prevY == cy - 1) {
				printw("<");
			} else if (current.prevY == cy + 1) {
				printw(">");
			} else if (current.prevX == cx - 1) {
				printw("^");
			} else {
				printw("v");
			}
		}
		refresh();
		wait(100);
		if(cx == targetX && cy == targetY) {
			break;
		}
		if(cx - 1 >= 0) {
			if(!map[cx - 1][cy].visited && !grid[cx - 1][cy]) {
				map[cx - 1][cy].visit(cx, cy);
				bfs.push(map[cx - 1][cy]);
			}
		}
		if(cx + 1 < len) {
			if(!map[cx + 1][cy].visited && !grid[cx + 1][cy]) {
				map[cx + 1][cy].visit(cx, cy);
				bfs.push(map[cx + 1][cy]);
			}
		}
		if(cy - 1 >= 0) {
			if(!map[cx][cy - 1].visited && !grid[cx][cy - 1]) {
				map[cx][cy - 1].visit(cx, cy);
				bfs.push(map[cx][cy - 1]);
			}
		}
		if(cy + 1 < len) {
			if(!map[cx][cy + 1].visited && !grid[cx][cy + 1]) {
				map[cx][cy + 1].visit(cx, cy);
				bfs.push(map[cx][cy + 1]);
			}
		}
	}
	attroff(COLOR_PAIR(1));
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	attron(COLOR_PAIR(2));
	Point curr = map[targetX][targetY];
	vector<Point> path;
	path.push_back(curr);
	while(curr.x != startX || curr.y != startY) {
		wait(100);
		move(curr.x, curr.y);
		printw("*");
		move(curr.x, curr.y);
		curr = map[curr.prevX][curr.prevY];
		path.push_back(curr);
		refresh();
	}
	for(int i = path.size() - 1; i >= 0; i--) {
		wait(250);
		printw(" ");
		move(path[i].x, path[i].y);
		printw("@");
		move(path[i].x, path[i].y);
		refresh();
	}
	for(int i = 0; i < 6; i++) {
		wait(400);
		if(i % 2 == 0) {
			attron(A_REVERSE);	
		}
		for(int j = 0; j < path.size(); j++) {
			move(path[j].x, path[j].y);
			printw(" ");
			move(path[j].x, path[j].y);
		}
		attroff(A_REVERSE);
		refresh();
	}
	attroff(COLOR_PAIR(2));
	getch();
	endwin();
}
