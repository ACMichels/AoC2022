#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <stack>

using namespace std;

int main() {
	ifstream fin("5.in");
	string line;
	vector<deque<char>> stacks;
	int stackCount = 0;
	
	while(getline(fin, line)) {
		if (stackCount == 0) {
			stackCount = (line.length()+1)/4;
			for (int i = 0; i < stackCount; i++) {
				stacks.push_back(deque<char>());
			}
		}
		if (line[1] == '1') {
			break;
		}
		for (int i = 0; i < stackCount; i++) {
			if (line[i*4+1] != ' ') {
				stacks[i].push_back(line[i*4+1]);
			}
		}
	}
	fin.ignore();
	string word;
	int nr, from, to;
	stack<char> tmpstack;
	while(fin >> word >> nr >> word >> from >> word >> to) {
		for (int i = 0; i < nr; i++) {
			tmpstack.push(stacks[from-1].front());
			stacks[from-1].pop_front();
		}
		for (int i = 0; i < nr; i++) {
			stacks[to-1].push_front(tmpstack.top());
			tmpstack.pop();
		}
	}
	
	for (deque<char> &st : stacks) {
		cout << st.front();
	}
	cout << endl;
	return 0;
}