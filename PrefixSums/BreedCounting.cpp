#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	//ifstream fin("bcount.in");
	//ofstream fout("bcount.out");
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	int n, q; cin >> n >> q;
	ll breeds[n+1][3];
	//first, all breed values must be initialized to 0
	for (int i=0; i<=n; i++) {
		for (int j=0; j<3; j++) {
			breeds[i][j] = 0;
		}
	}
	int id;
	for (int i=1; i<=n; i++) {
		cin >> id;
		for (int j=0; j<3; j++) {
			breeds[i][j] = breeds[i-1][j];
		}
		breeds[i][id-1] = breeds[i-1][id-1]+1;
	}
	//now simply process each query
	int a, b;
	for (int i=0; i<q; i++) {
		cin >> a >> b;
		for (int j=0; j<3; j++) {
			//annoying I had to limit the extra space!
			if (j==2) { cout << breeds[b][j] - breeds[a-1][j]; continue;}
			cout << breeds[b][j] - breeds[a-1][j] << ' ';
		} cout << endl;
	}
}