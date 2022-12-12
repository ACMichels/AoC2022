#include <iostream>
#include <fstream>
#include <set>
#include <utility>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

struct Monkey{
	queue<int> items;
	int operation;
	int operationValue = 0;
	bool byItself = false;
	int divisor;
	int trueThrow;
	int falseThrow;
	int assessCount = 0;
};

int main() {
	ifstream fin("input.txt");
	
	vector<Monkey> monkeys;
	
	string line;
	string word;
	
	while(getline(fin, line)) {
		Monkey mk;
		
		// Items
		getline(fin, line);
		stringstream ss(line);
		ss >> word;
		int worryValue;
		while(ss >> word >> worryValue) {
			mk.items.push(worryValue);
		}
		
		// Operator
		getline(fin, line);
		stringstream ss2(line);
		char op;
		string opWord;
		ss2 >> word >> word >> word >> word >> op >> opWord;
		if (op == '*') {
			mk.operation = 0;
		} else {
			mk.operation = 1;
		}
		if (opWord[0] == 'o') { // old*old
			mk.byItself = true;
		} else {
			mk.operationValue = stoi(opWord);
		}
		
		// Divisibility test
		getline(fin, line);
		stringstream ss3(line);
		int div;
		ss3 >> word >> word >> word >> div;
		mk.divisor = div;
		
		// True
		getline(fin, line);
		stringstream ss4(line);
		int monkeyTrue;
		ss4 >> word >> word >> word >> word >> word >> monkeyTrue;
		mk.trueThrow = monkeyTrue;
		
		// False
		getline(fin, line);
		stringstream ss5(line);
		int monkeyFalse;
		ss5 >> word >> word >> word >> word >> word >> monkeyFalse;
		mk.falseThrow = monkeyFalse;
		
		getline(fin, line);
		
		monkeys.push_back(mk);
	}
	
	for (int t = 0; t < 20; t++) {
		for (int m = 0; m < monkeys.size(); m++) {
			Monkey& mk = monkeys[m];
			while(mk.items.size() > 0) {
				int item = mk.items.front();
				mk.items.pop();
				mk.assessCount++;
				
				// Operation
				if (mk.byItself) {
					mk.operationValue = item;
				}
				if (mk.operation == 0) { // *
					item *= mk.operationValue;
				} else {
					item += mk.operationValue;
				}
				
				// Loose interest
				int old_item = item;
				item /= 3;
				
				// Throw
				if (item % mk.divisor == 0) {
					monkeys[mk.trueThrow].items.push(item);
				} else {
					monkeys[mk.falseThrow].items.push(item);
				}
			}
		}
	}
	
	
	vector<int> assessCounts;
	for (Monkey& m : monkeys) {
		assessCounts.push_back(m.assessCount);
	}
	sort(assessCounts.begin(), assessCounts.end(), greater<int>());
	
	for (int v : assessCounts) {
		cout << v << endl;
	}
	cout << endl;
	
	cout << assessCounts[0] * assessCounts[1] << endl;
	
	return 0;
}
