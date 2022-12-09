#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>

#define BUFFER_SIZE 14

using namespace std;

bool different(char buffer[BUFFER_SIZE]) {
	for (int i = 0; i < BUFFER_SIZE-1; i++) {
		for (int j = i+1; j < BUFFER_SIZE; j++) {
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
		char buffer[BUFFER_SIZE];
		for (int i = 0; i < line.size(); i++) {
			buffer[i%BUFFER_SIZE] = line[i];
			if (i >= BUFFER_SIZE-1 && different(buffer)) {
				cout << i+1 << endl;
				break;
			}
		}
	}
	return 0;
}