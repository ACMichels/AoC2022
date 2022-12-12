#include <iostream>
#include <fstream>
#include <set>
#include <utility>
#include <queue>
#include <sstream>
#include <algorithm>
#include <queue>

using namespace std;

struct pos {
	int x, y;
};

struct node {
	pos p;
	int distance;
};

int main() {
	ifstream fin("input.txt");
	
	vector<string> field;
	
	string line;
	
	while(getline(fin, line)) {
		field.push_back(line);
	}
	
	int width = field[0].length();
	int height = field.size();
	
	vector<vector<bool>> visited(height, vector<bool>(width, false));
	
	pos start, end;
	
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (field[i][j] == 'S') {
				start = {j, i};
			} else if (field[i][j] == 'E') {
				end = {j, i};
			}
		}
	}
	
	field[start.y][start.x] = 'a';
	field[end.y][end.x] = 'z';
	
	auto cmp = [](node n1, node n2) { return n1.distance > n2.distance; };
	priority_queue<node, vector<node>, decltype(cmp)> pqueue(cmp);
	
	pqueue.push({start, 0});
	
	while(pqueue.size() > 0) {
		node current = pqueue.top();
		pqueue.pop();
		if (visited[current.p.y][current.p.x]) {
			continue;
		}
		visited[current.p.y][current.p.x] = true;
		
		if (current.p.x == end.x && current.p.y == end.y) {
			cout << current.distance << endl;
			break;
		}
		
		
		if (current.p.x > 0 && !visited[current.p.y][current.p.x-1] && (field[current.p.y][current.p.x] - (int)field[current.p.y][current.p.x-1] >= -1 || field[current.p.y][current.p.x-1] == 'E' && field[current.p.y][current.p.x] >= 'y')) {
			pqueue.push({{current.p.x-1, current.p.y}, current.distance + 1});
		}
		if (current.p.y > 0 && !visited[current.p.y-1][current.p.x] && (field[current.p.y][current.p.x] - (int)field[current.p.y-1][current.p.x] >= -1 || field[current.p.y-1][current.p.x] == 'E' && field[current.p.y][current.p.x] >= 'y')) {
			pqueue.push({{current.p.x, current.p.y-1}, current.distance + 1});
		}
		
		if (current.p.x < width-1 && !visited[current.p.y][current.p.x+1] && (field[current.p.y][current.p.x] - (int)field[current.p.y][current.p.x+1] >= -1 || field[current.p.y][current.p.x+1] == 'E' && field[current.p.y][current.p.x] >= 'y')) {
			pqueue.push({{current.p.x+1, current.p.y}, current.distance + 1});
		}
		if (current.p.y < height-1 && !visited[current.p.y+1][current.p.x] && (field[current.p.y][current.p.x] - (int)field[current.p.y+1][current.p.x] >= -1 || field[current.p.y+1][current.p.x] == 'E' && field[current.p.y][current.p.x] >= 'y')) {
			pqueue.push({{current.p.x, current.p.y+1}, current.distance + 1});
		}
	}
	
	
	
	return 0;
}
