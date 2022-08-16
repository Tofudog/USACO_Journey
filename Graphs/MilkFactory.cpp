#include <iostream>
#include <vector>
using namespace std;

vector<int> factory[101];
int score[101];

void allConnections( int j ) {
	//base case: no more connections
	if (factory[j].size()==0) {
		return;
	}
	for (int conn : factory[j]) {
		score[conn]++;
		allConnections(conn);
	}
}

int main() {
	int n; cin >> n;
	//create an undirected graph of stations
	int from, to;
	for (int i=1; i<n; i++) {
		cin >> from >> to;
		factory[from].push_back(to);
		score[i] = 0;
	} score[n] = 0;
	//iter. through src locations and paths and add to score[j]
	for (int i=1; i<n+1; i++) {
		score[i]++;
		//look while there is a connection
		allConnections(i);
	}
	for (int i=1; i<n+1; i++) {
		if (score[i] >= n) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}