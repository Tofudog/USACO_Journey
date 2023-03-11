#include <iostream>
#include <map>
using namespace std;
using ll = long long;

#excuse my laziness in substituting ll for all int
int main() {
	ll T; cin >> T;
	while (T--) {
		ll n; cin >> n;
		string x; cin >> x;
		ll ps[n+1]; ps[0] = 0; map<ll, ll> mp; mp[0] = 1;
		for (ll i=1; i<=n; i++) {
			ps[i] = ps[i-1] + (ll)x.at(i-1)-49;
			mp[ps[i]]++;
		}
		//now we just look for # of subsums to zero
		ll ans = 0;
		for (const auto &prefix : mp) {
			ll b = prefix.second;
			ans += b * (b-1) / 2;
		}
		cout << ans << '\n';
	}
}