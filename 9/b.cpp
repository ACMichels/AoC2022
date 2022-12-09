#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int moveCloser(int pos, int target) {
	return (target-pos > 0) - (target-pos < 0);
}

int main() {
	ifstream fin("input.txt");
	
	set<pair<int, int>> visited;
	vector<int> px(10, 0);
	vector<int> py(10, 0);
	visited.insert({px[9], py[9]});
	
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
			px[0] += modx;
			py[0] += mody;
			
			for (int j = 1; j < 10; j++) {
				if (abs(px[j-1]-px[j]) > 1 || abs(py[j-1]-py[j]) > 1) {
					px[j] += moveCloser(px[j], px[j-1]);
					py[j] += moveCloser(py[j], py[j-1]);
				} else {
					break;
				}
			}
			visited.insert({px[9], py[9]});
		}
	}
	cout << visited.size() << endl;
	
	return 0;
}