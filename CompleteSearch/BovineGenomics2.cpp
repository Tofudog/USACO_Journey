#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

//time complexity: O(n*m^3)
//last case times out (same with solution)
bool isUnique(int p1, int p2, int p3, vector<string>& v1, vector<string>& v2) {
	set<ll> visited;
	for (int s=0; s<v1.size(); s++) {
		ll x = 676 * (v1[s][p1] - 'A');
		x += 26 * (v1[s][p2] - 'A');
		x += (v1[s][p3] - 'A');
		visited.insert(x);
	}
	for (int r=0; r<v2.size(); r++) {
		ll x = 676 * (v2[r][p1] - 'A');
		x += 26 * (v2[r][p2] - 'A');
		x += (v2[r][p3] - 'A');
		if (visited.count(x)) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> spotted; vector<string> plain;
	for (int i=0; i<n; i++) {
		string s; cin >> s; spotted.push_back(s);
	}
	for (int i=0; i<n; i++) {
		string s; cin >> s; plain.push_back(s);
	}
	ll ans = 0;
	for (int i=0; i<m-2; i++) {
		for (int j=i+1; j<m-1; j++) {
			for (int k=j+1; k<m; k++) {
				if (isUnique(i, j, k, spotted, plain)) {
					ans++;
				}
			}
		}
	}
	cout << ans << '\n';
}
