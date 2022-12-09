#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

char getSim(string& line, int halfsize) {
	int s1 = 0, s2 = halfsize;
	while(s1 < halfsize && s2 < line.size()) {
		if (line[s1] == line[s2]) {
			return line[s1];
		}
		if (line[s1] < line[s2]) {
			s1++;
		} else {
			s2++;
		}
	}
	return ' ';
}

int getVal(char c) {
	if (c >= 'a' && c <= 'z') {
		return c-'a'+1;
	}
	if (c >= 'A' && c <= 'Z') {
		return c-'A'+27;
	}
	return 0;
}

int main() {
	ifstream fin("3.in");
	string line;
	int score = 0;
	
	while(fin >> line) {
		int halfsize = line.size()/2;
		auto halfway = line.begin() + halfsize;
		sort(line.begin(), halfway);
		sort(halfway, line.end());
		
		char c = getSim(line, halfsize);
		int val = getVal(c);
		score += val;
	}
	
	cout << score << endl;
	return 0;
}