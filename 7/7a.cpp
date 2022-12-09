#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>

#define TOTAL_SIZE 100000

using namespace std;

struct dir {
	string name;
	vector<dir> subDirs;
	dir* parent;
	int fileSizes;
	int totalSize;
};

int calcSizes(dir* d) {
	int totalSize = d->fileSizes;
	
	for (dir &subD : d->subDirs) {
		totalSize += calcSizes(&subD);
	}
	
	d->totalSize = totalSize;
	return totalSize;
}

int findSmallDirs(dir* d) {
	int smallSize = 0;
	
	if (d->totalSize <= TOTAL_SIZE) {
		smallSize += d->totalSize;
	}
	
	for (dir &subD : d->subDirs) {
		smallSize += findSmallDirs(&subD);
	}
	
	return smallSize;
}

int main() {
	ifstream fin("7.in");
	string word;
	
	dir root = {"", vector<dir>(), NULL, 0, 0};
	dir* current = &root;
	
	while(fin >> word) {
		cout << word << " ";
		switch(word[0]) {
			case '$': { // Command
				fin >> word;
				cout << word << " ";
				if (word[0] == 'c') { // cd
					fin >> word;
					cout << word << " ";
					switch(word[0]) {
						case '/': {
							current = &root;
							break;
						}
						case '.': {
							current = current->parent;
							break;
						}
						default: {
							bool switched = false;
							for (dir& d : current->subDirs) {
								if (d.name.compare(word) == 0) {
									current = &d;
									switched = true;
									break;
								}
							}
							if (!switched) {
								current->subDirs.push_back({word, vector<dir>(), current, 0, 0});
								current = &current->subDirs[current->subDirs.size()-1];
							}
							break;
						}
					}
				} else if (word[0] == 'l') {
					current->fileSizes = 0;
				}
				break;
			}
			case 'd': { // Directory
				fin >> word;
				cout << word << " ";
				break;
			}
			default: { // File
				int filesize = stoi(word);
				fin >> word;
				cout << word << " ";
				current->fileSizes += filesize;
				break;
			}
		}
		cout << endl;
	}
	
	calcSizes(&root);
	cout << findSmallDirs(&root) << endl;
	return 0;
}