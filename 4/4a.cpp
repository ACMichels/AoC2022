#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("4.in");
	int s1, s2, e1, e2;
	int sum = 0;
	char bin;
	
	while(fin >> s1 >> bin >> e1 >> bin >> s2 >> bin >> e2) {
		if (s1 >= s2 && e1 <= e2) {
			sum++;
		} else if (s1 <= s2 && e1 >= e2) {
			sum++;
		}
	}
	
	cout << sum << endl;
	return 0;
}