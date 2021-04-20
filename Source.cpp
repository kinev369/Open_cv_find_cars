#include "Header.h"
using namespace std;

Dict::Dict () {
	for (int i = 0; i < 250; i++) {
		lists_finder.push_back(i);
	}
}
void Dict::Writeln(int i){
	cout << "detection qr_code "<< lists_finder[i];
}
void Dict::Finder(int i) {
	for (int j = 0; j < lists_finder.size(); j++) {
		if (lists_finder[j] == i) {
			Writeln(i);
			break;
		}
	}
}