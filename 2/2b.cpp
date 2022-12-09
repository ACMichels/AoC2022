#include <iostream>
#include <fstream>

using namespace std;

int main() {
	
	ifstream fin("2.in");
	
	char played, outcome;
	
	int score = 0;
	
	while(fin >> played >> outcome) {
		
		char v = played - 'A';
		
		if (outcome == 'Y') {
			score += 3;
		} else if (outcome == 'Z') {
			score += 6;
			v = (v+1)%3;
		} else {
			v = (v+2)%3;
		}
		score += v+1;
		
	}
	cout << score << endl;
	
	return 0;
}