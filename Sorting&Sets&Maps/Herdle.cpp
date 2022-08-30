#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
	char A[3][3];
	char B[3][3];
	map<char, int> actual, guess;
	for (int i=0; i<3; i++) {
		cin >> A[i];
		for (char x : A[i]) {
			actual[x]++;
		}
	}
	for (int i=0; i<3; i++) {
		cin >> B[i];
		for (char x : B[i]) {
			guess[x]++;
		}
	}
	//first search all the greens and record visited
	set<pair<int, int>> visited;
	int greens = 0;
	for (int r=0; r<3; r++) {
		for (int c=0; c<3; c++) {
			if (A[r][c] == B[r][c]) {
				visited.insert({r, c});
				++greens;
				--actual[A[r][c]]; --guess[A[r][c]];
			}
		}
	}
	//reiterate through 2D arr, neglecting visited terms
	int yellows = 0;
	for (const auto &letter : actual) {
		yellows += min(guess[letter.first], letter.second);
	}

	cout << greens << '\n' << yellows << endl;
}
