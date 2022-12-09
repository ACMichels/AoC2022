#include <iostream>
#include <fstream>

using namespace std;

int main() {
	
	ifstream fin("2.in");
	
	char played, response;
	
	int score = 0;
	
	while(fin >> played >> response) {
//		cout << played << " " << response << endl;
		
		if (played == response-23) {
			score += 3;
//			cout << "+3" << endl;
		} else if ((played-'A'+'X'-response+3)%3 == 2) {
			score += 6;
//			cout << "+6" << endl;
		}
		score += response-'X'+1;
//		cout << "+" << response-'X'+1 << endl;
	}
	cout << score << endl;
	
	return 0;
}