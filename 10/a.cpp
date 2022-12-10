#include <iostream>
#include <fstream>
#include <set>
#include <utility>

using namespace std;

int main() {
	ifstream fin("input.txt");
	
	int sum = 1;
	int score = 0;
	int cycleCount = 0;
	
	string word;
	
	while(fin >> word) {
		if (word[0] == 'n') {
			cycleCount++;
			
			if ((cycleCount - 20) % 40 == 0 && cycleCount <= 220) {
				score += cycleCount* sum;
			}
			
		} else {
			int value;
			fin >> value;
			cycleCount += 2;
			
			if (((cycleCount - 20) % 40 == 0 || (cycleCount - 20) % 40 == 1) && cycleCount <= 220) {
				score += (cycleCount - ((cycleCount - 20) % 40 == 1 ? 1 : 0))  * sum;
			}
			
			sum += value;
		}
		
	}
	cout << score << endl;
	
	return 0;
}
