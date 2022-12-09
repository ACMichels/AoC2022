#include <iostream>
#include <fstream>
#include <vector>

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
	
	int bestVision = 0;
	for (int i = 1; i < sizey-1; i++) {
		for (int j = 1; j < sizex-1; j++) {
			
			int v1 = 1, v2 = 1, v3 = 1, v4 = 1;
			for (int k = i-1; k > 0 && field[k][j] < field[i][j]; k--, v1++){}
			for (int k = i+1; k < sizey-1 && field[k][j] < field[i][j]; k++, v2++){}
			for (int k = j-1; k > 0 && field[i][k] < field[i][j]; k--, v3++){}
			for (int k = j+1; k < sizex-1 && field[i][k] < field[i][j]; k++, v4++){}
			int score = v1 * v2 * v3 * v4;
			
			if (score > bestVision) {
				bestVision = score;
			}
		}
	}
	
	cout << bestVision << endl;
	
	return 0;
}