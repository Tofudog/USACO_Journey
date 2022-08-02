#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> w;
	int wi; while (cin >> wi) {w.push_back(wi);}
	sort(w.begin(), w.end());
	int instability = -1;
	for (int i=0; i<2*n; i++) {
		for (int j=i+1; j<2*n; j++) {
			vector<int> currW;
			for (int x=0; x<2*n; x++) {
				if (x==i || x==j) {continue;}
				currW.push_back(w.at(x));
			}
			int curr = 0;
			for (int y=0; y<2*n-3; y+=2) {
				curr += (currW.at(y+1) - currW.at(y));
			} if (instability < 0) {instability = curr; continue;}
			instability = min(instability, curr);
		}
	}
	cout << instability << endl;
}