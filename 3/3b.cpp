#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

char getSim(string& line1, string& line2, string& line3) {
	int s1 = 0, s2 = 0, s3 = 0;
	while(true) {
		if (line1[s1] == line2[s2] && line1[s1] == line3[s3]) {
			return line1[s1];
		}
		if (line1[s1] <= line2[s2] && line1[s1] <= line3[s3]) {
			s1++;
		} else if (line2[s2] <= line1[s1] && line2[s2] <= line3[s3]) {
			s2++;
		} else {
			s3++;
		}
	}
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
	string line1, line2, line3;
	int score = 0;
	
	while(fin >> line1 >> line2 >> line3) {
		sort(line1.begin(), line1.end());
		sort(line2.begin(), line2.end());
		sort(line3.begin(), line3.end());
		
		char c = getSim(line1, line2, line3);
		int val = getVal(c);
		score += val;
	}
	
	cout << score << endl;
	return 0;
}