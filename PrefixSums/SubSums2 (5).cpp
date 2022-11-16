#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
#define MAX_N (int)1e9 + 1

int main() {
	int n; ll x; cin >> n >> x;
	ll curr = 0;
	map<ll, int> ps; ps[0] = 1; ll a;
	int ans = 0;
	for (int i=0; i<n; i++) {
		cin >> a; curr += a;
		ll find = curr - x;
		ans += ps[find];
		++ps[curr];
	}
	cout << ans << '\n';
}