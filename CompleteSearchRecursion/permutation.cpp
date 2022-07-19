#include <iostream>
#include <set>
using namespace std;

set<string> permuations;
string process = "abcd";
string curr = "";
int n = 4;
bool visited[4];

//my implementation of string permutations
void search(int k) {
	if (k==n) {
		permuations.insert(curr);
		return;
	}
	for (int i=0; i<n; i++) {
		if (visited[i]) {continue;}
		curr += process.at(i);
		visited[i] = true;
		search(k+1);
		curr.pop_back();
		visited[i] = false;
	}
}

int main() {
	search(0);
	for (string i : permuations) {
		cout << i << endl;
	}
}