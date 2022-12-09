#include <iostream>

using namespace std;

int main() {
	int sum = 0;
	int max = 0;
	while (true) {
		string line;
		getline(cin, line);
		
		if (line.length() > 0) {
			int value = stoi(line);
			sum += value;
		} else {
			max = sum>max?sum:max;
			sum = 0;
			cout << max << endl;
		}
	}
}