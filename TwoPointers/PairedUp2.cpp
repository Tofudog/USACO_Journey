#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
using ppi = pair<int, int>;
#define MAX_M (int)1e9 + 1
#define MAX_N (int)1e5 + 1

int main() {
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);
	int n; cin >> n;
	ppi A[MAX_N]; ll x, y;
	for (int i=0; i<n; i++) {
		cin >> x >> y;
		A[i] = {y, x};
	}
	sort(A, A+n);
	ll ans = -1;
	int p1 = 0; int p2 = n-1;
	while (p1 < p2) {
		if (A[p1].first+A[p2].first > ans) {ans = A[p1].first+A[p2].first;}
		ll delta = min(A[p1].second, A[p2].second);
		A[p1].second -= delta; A[p2].second -= delta;
		if (A[p1].second==0) {p1++;}
		if (A[p2].second==0) {p2--;} 
	}
	//account the cases where p1==p2
	if (p1==p2) {
		if (A[p1].first+A[p2].first > ans) {ans = A[p1].first+A[p2].first;}
	}
	cout << ans << '\n';
}