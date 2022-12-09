#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

bool different(char buffer[4]) {
	for (int i = 0; i < 3; i++) {
		for (int j = i+1; j < 4; j++) {
			if (buffer[i] == buffer[j]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ifstream fin("6.in");
	string line;
	
	while(getline(fin, line)) {
		char buffer[4] = {0, 0, 0, 0};
		for (int i = 0; i < line.size(); i++) {
			buffer[i%4] = line[i];
			if (i >= 3 && different(buffer)) {
				cout << i+1 << endl;
				break;
			}
		}
	}
	return 0;
}