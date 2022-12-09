#include <iostream>
#include <fstream>
#include <set>
#include <utility>

using namespace std;

int moveCloser(int pos, int target) {
	return (target-pos > 0) - (target-pos < 0);
}

int main() {
	ifstream fin("input.txt");
	
	set<pair<int, int>> visited;
	int hx = 0, hy = 0;
	int tx = 0, ty = 0;
	visited.insert({tx, ty});
	
	char dir;
	int steps;
	while(fin >> dir >> steps) {
		int modx = 0, mody = 0;
		switch(dir) {
			case 'U': {
				mody = -1;
				break;
			}
			case 'R': {
				modx = 1;
				break;
			}
			case 'D': {
				mody = 1;
				break;
			}
			case 'L': {
				modx = -1;
				break;
			}
		}
		for (int i = 0; i < steps; i++) {
			hx += modx;
			hy += mody;
			
			if (abs(hx-tx) > 1 || abs(hy-ty) > 1) {
				tx += moveCloser(tx, hx);
				ty += moveCloser(ty, hy);
				
				visited.insert({tx, ty});
			}
		}
	}
	cout << visited.size() << endl;
	
	return 0;
}