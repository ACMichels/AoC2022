#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

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

int findAndReplace(string& line, char find, char replace) {
	auto index = line.find(find);
	if (index != line.npos) {
		line[index] = replace;
		return index;
	}
	return -1;
}

int main() {
	ifstream fin("input.txt");
	vector<string> field;
	string line;
	pos start, end;
	
	for(int i = 0; getline(fin, line); i++) {
		if (int index = findAndReplace(line, 'S', 'a'); index >= 0) {
			start = {index, i};
		}
		if (int index = findAndReplace(line, 'E', 'z'); index >= 0) {
			end = {index, i};
		}
		field.push_back(line);
	}
	
	int width = field[0].length();
	int height = field.size();
	
	vector<vector<bool>> visited(height, vector<bool>(width, false));
	
	auto cmp = [](node& n1, node& n2) { return n1.distance > n2.distance; };
	priority_queue<node, vector<node>, decltype(cmp)> pqueue(cmp);
	
	pqueue.push({end, 0});
	
	while(pqueue.size() > 0) {
		node current = pqueue.top();
		pqueue.pop();
		
		if (visited[current.p.y][current.p.x]) {
			continue;
		}
		visited[current.p.y][current.p.x] = true;
		
		if (field[current.p.y][current.p.x] == 'a') {
			cout << current.distance << endl;
			break;
		}
		
		constexpr int mod[] = {0, 1, 0, -1, 0};
		for (int i = 0; i < 4; i++) {
			const int newX = current.p.x+mod[i+1];
			const int newY = current.p.y+mod[i];
			if (inBounds(width, height, newX, newY) && !visited[newY][newX] && field[current.p.y][current.p.x] - (int)field[newY][newX] <= 1) {
				pqueue.push({{newX, newY}, current.distance + 1});
			}
		}
	}
	return 0;
}
