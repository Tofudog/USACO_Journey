#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	char answers[3][3];
	char guesses[3][3];
	string row;
	for (int i=0; i<6; i++) {
		if (i >= 3) {
			cin >> guesses[i-3];
			continue;
		}
		cin >> answers[i];
	}
	//first check for exact alignments in O(1)
	bool greens[3][3] = {false};
	int num_greens = 0;
	for (int r=0; r<3; r++) {
		for (int c=0; c<3; c++) {
			if (answers[r][c] == guesses[r][c]) {
				greens[r][c] = true;
				num_greens++;
			}
		}
	}
	map<char, int> squares;
	for (int r=0; r<3; r++) {
		for (int c=0; c<3; c++) {
			if (greens[r][c]) {continue;}
			++squares[answers[r][c]];
		}
	}
	int num_yellows = 0;
	for (int r=0; r<3; r++) {
		for (int c=0; c<3; c++) {
			if (greens[r][c]) {continue;}
			char sqr_rc = guesses[r][c];
			if (squares[sqr_rc] > 0) {
				num_yellows++;
				--squares[sqr_rc];
			}
		}
	}
	// for (const auto &X : squares) {
	// 	cout << X.first << ' ' << X.second << '\n';
	// }

	cout << num_greens << '\n' << num_yellows << '\n';
}