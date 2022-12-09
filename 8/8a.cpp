#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;


int main() {
	ifstream fin("8.in");
	string word;
	
	vector<string> field;
	
	while(fin >> word) {
		field.push_back(word);
	}
	
	int sizex = field[0].length();
	int sizey = field.size();
	
	vector<string> visible;
	string s(sizex, '0');
	for (int i = 0; i < sizey; i++) {
		visible.push_back(s);
	}
	
	for (int i = 0; i < sizey; i++) {
		int height = 0;
		for (int j = 0; j < sizex; j++) {
			if (field[i][j]-'0'+1 > height) {
				height = field[i][j]-'0'+1;
				visible[i][j] = '1';
			}
		}
	}
	
	for (int j = 0; j < sizex; j++) {
		int height = 0;
		for (int i = 0; i < sizey; i++) {
			if (field[i][j]-'0'+1 > height) {
				height = field[i][j]-'0'+1;
				visible[i][j] = '1';
			}
		}
	}
	
	for (int i = sizey-1; i >= 0; i--) {
		int height = 0;
		for (int j = sizex-1; j >= 0; j--) {
			if (field[i][j]-'0'+1 > height) {
				height = field[i][j]-'0'+1;
				visible[i][j] = '1';
			}
		}
	}
	
	for (int j = sizex-1; j >= 0; j--) {
		int height = 0;
		for (int i = sizey-1; i >= 0; i--) {
			if (field[i][j]-'0'+1 > height) {
				height = field[i][j]-'0'+1;
				visible[i][j] = '1';
			}
		}
	}
	
	int sum = 0;
	for (int i = 0; i < sizey; i++) {
		for (int j = 0; j < sizex; j++) {
			if (visible[i][j] == '1') {
				sum++;
			}
		}
	}
	cout << sum << endl;
	
	for (int i = 0; i < sizey; i++) {
		cout << visible[i] << endl;
	}
	
	return 0;
}