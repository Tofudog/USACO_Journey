#include <iostream>
#define MAX_N (int) 1e5 + 1
using namespace std;
using ll = long long;

//solution using two pointers: O(N).
int main() {
	ll n, t; cin >> n >> t;
	int p1, p2; p1 = p2 = 0;
	ll x = 0; //the current subsum
	ll a[MAX_N];
	ll ans = 0;
	for (ll i=0; i<n; i++) {
		cin >> a[i];
	}
	while (p2 < n) {
		if (x + a[p2] > t) {
			p1++;
			x -= a[p1-1];
			if (p2-p1+1 > ans) {
				ans = p2-p1+1;		
			}
		}
		else {
			x += a[p2];
			p2++;
		}
	}
	if (p2-p1 > ans) {
		ans = p2-p1;
	}
	cout << ans << '\n';

}