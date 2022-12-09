#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int sum = 0;
	vector<int> sums;
	while (true) {
		string line;
		getline(cin, line);
		
		if (line.length() > 0) {
			int value = stoi(line);
			sum += value;
		} else {
			sums.push_back(sum);
			sort(sums.begin(), sums.end());
			sum = 0;
			if (sums.size() >= 3) {
				int totalSum = 0;
				for (int i = 0; i < 3; i++) {
					cout << "! " << sums[sums.size()-1-i] << endl;
					totalSum += sums[sums.size()-1-i];
				}
				cout << "-- " << totalSum << endl;
			}
		}
	}
}