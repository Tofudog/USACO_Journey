#include <iostream>
using namespace std;

//declare this globally to be able to modify it
int n;
bool grid[100][100];

void untip(int toRow, int toCol) {
	for (int i=0; i<=toRow; i++) {
		for (int j=0; j<=toCol; j++) {
			grid[i][j] = !grid[i][j];
		}
	}
}

//I had to create this helper method to visualize my bug, which I fixed
void printGrid() {
	for (int r=0; r<n; r++) {
		for (int c=0; c<n; c++) {
			cout << grid[r][c] << ' ';
		} cout << endl;
	}
}

//constraints are very nice: 1≤N≤10
int main() {
	cin >> n;
	//read in the n*n farmland
	string cow;
	for (int i=0; i<n; i++) {
		cin >> cow;
		for (int j=0; j<n; j++) {
			if (cow.at(j)=='0') {grid[i][j] = 0;}
			else {grid[i][j] = 1;}
		}
	}
	int ans = 0;
	for (int currRow=n-1; currRow>=0; currRow--) {
		for (int currCol=n-1; currCol>=0; currCol--) {
			if (grid[currRow][currCol]) {
				untip(currRow, currCol);
				ans++;
			}
		}
	}
	cout << ans << endl;
}