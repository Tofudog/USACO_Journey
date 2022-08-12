#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

//constraints: 1≤rF≤10^6 as well as rB and L, with 1≤N≤10^5
//Idea: Let Bessie roam to the tastiest, then the tastiest after that (not going backwards);
//record score until done.
//Finally debuged! The problem was using ints instead of long longs... I assumed only 'score' needed it.
int main() {
	ll L, n, rf, rb; cin >> L >> n >> rf >> rb;
	if (rf == rb) {
		cout << 0 << endl; return 0;
	}
	map<ll, ll> stops; ll x[n]; ll c[n]; ll x_i, c_i;
	for (ll i=0; i<n; i++) {
		cin >> x_i >> c_i;
		stops[x_i] = c_i;
	} ll idx = 0;
	for (const auto &STOP : stops) {
		x[idx] = STOP.first; c[idx] = STOP.second;
		idx++;
	}
	ll lbound = -1; ll from = 0; ll to; ll tastiest = 0;
	ll score = 0; ll iter = 0;
	while (lbound < n-1) {
		//lbound = findTastiest(lbound);  //ideal solution
		//calculate the next lbound
		for (int i=lbound+1; i<n; i++) {
			if (c[i] > tastiest) {
				tastiest = c[i];
				lbound = i;
			}
		} tastiest = 0;
		to = x[lbound];
		score += (c[lbound] * ( (to-from)*rf - (to-from)*rb ));
		from = x[lbound];
	}
	cout << score + (c[lbound] * ( (to-from)*rf - (to-from)*rb )) << endl;
}