#include <iostream>
#include <fstream>
#include <set>
#include <utility>
#include <sstream>

using namespace std;

void process(stringstream& ss, int pos, int cycleTime) {
	
	
	if (abs(((cycleTime-1)%40) - pos) <= 1) {
		ss << '#';
	} else {
		ss << '.';
	}
	
	if ((cycleTime) % 40 == 0) {
		ss << endl;
	}
}

int main() {
	ifstream fin("input.txt");
	
	int sum = 1;
	int score = 0;
	int cycleCount = 0;
	
	string word;
	stringstream ss;
	
	while(fin >> word) {
		if (word[0] == 'n') {
			cycleCount++;
			process(ss, sum, cycleCount);
		} else {
			int value;
			fin >> value;
			
			cycleCount++;
			process(ss, sum, cycleCount);
			cycleCount++;
			process(ss, sum, cycleCount);
			
			sum += value;
		}
		
	}
	cout << ss.str() << endl;
	
	return 0;
}
