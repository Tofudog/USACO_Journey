#include <iostream>
#include <set>
using namespace std;

//Yes! This was solved and deserves modest celebration. Difficulty: Very Hard!
//constraints: 1 <= N <= 10
int main() {
	int n; cin >> n;
	if (n == 1) {cout << 1; return 0;}
	int canvas[10][10];
	for (int r=0; r<n; r++) {
		string rboard; cin >> rboard;
		for (int c=0; c<n; c++) {
			canvas[r][c] = (int) rboard.at(c) - 48;
		}
	}
	set<int> colors;
	set<int> covers;
	int minRows[9] = {10, 10, 10, 10, 10, 10, 10, 10, 10};
	int minColumns[9] = {10, 10, 10, 10, 10, 10, 10, 10, 10};
	int maxRows[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int maxColumns[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int r=0; r<n; r++) {
		for (int c=0; c<n; c++) {
			int value = canvas[r][c];
			if (value > 0) {
				minRows[value-1] = min(minRows[value-1], r);
				minColumns[value-1] = min(minColumns[value-1], c);
				maxRows[value-1] = max(maxRows[value-1], r);
				maxColumns[value-1] = max(maxColumns[value-1], c);
			}
		}
	}
	//below, 'curr' represents the current color to access min/max rows/columns
	for (int curr=0; curr<9; curr++) {
		if (minRows[curr]==10) {
			continue;
		} colors.insert(curr);
		//cout << minRows[curr] << ' ' << maxRows[curr] << endl;
		for (int r=minRows[curr]; r<=maxRows[curr]; r++) {
			for (int c=minColumns[curr]; c<=maxColumns[curr]; c++) {
				if (canvas[r][c]-1 != curr && canvas[r][c]-1 != 0) {
					covers.insert(canvas[r][c]);
				}
			}
		}
	}
	cout << colors.size() - covers.size() << endl;
}
