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

bool inBounds(int width, int height, int x, int y) {
	return x >= 0 && y >= 0 && x < width && y < height;
}

int main() {
	ifstream fin("input.txt");
	vector<string> field;
	string line;
	pos start, end;
	
	for(int i = 0; getline(fin, line); i++) {
		field.push_back(line);
		auto index = line.find('S');
		if (index != line.npos) {
			start = {index, i};
			field[i][index] = 'a';
		}
		index = line.find('E');
		if (index != line.npos) {
			end = {index, i};
			field[i][index] = 'z';
		}
	}
	
	int width = field[0].length();
	int height = field.size();
	
	vector<vector<bool>> visited(height, vector<bool>(width, false));
	
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
		
		constexpr int mod[] = {0, 1, 0, -1, 0};
		for (int i = 0; i < 4; i++) {
			if (inBounds(width, height, current.p.x+mod[i+1], current.p.y+mod[i]) && !visited[current.p.y+mod[i]][current.p.x+mod[i+1]] && field[current.p.y][current.p.x] - (int)field[current.p.y+mod[i]][current.p.x+mod[i+1]] >= -1) {
				pqueue.push({{current.p.x+mod[i+1], current.p.y+mod[i]}, current.distance + 1});
			}
		}
	}
	
	return 0;
}
