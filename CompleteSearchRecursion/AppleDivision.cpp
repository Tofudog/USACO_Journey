#include <iostream>
using namespace std;
typedef long long ll;

int n;
ll weights[20];

ll solve(int k, ll x, ll y) {
	if (k==n) {
		return abs(x-y);
	}
	return min(solve(k+1, x+weights[k], y),
				solve(k+1, x, y+weights[k]));
}

int main() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> weights[i];
	}
	ll ans = solve(0, 0, 0);
	cout << ans;
}