#include <iostream>
#include <map>
using namespace std;
using ll = long long;
//constraints: (1≤N≤50,000); cow id's (0…1,000,000)
#define MAX_N (int)5e4 + 1
#define MAX_ID (int)1e6

int main() {
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	ll n; cin >> n;
	ll ans = 0;
	map<ll, ll> prefix_sum;
	prefix_sum[0] = 0;
	ll curr_sum = 0;
	ll ID;
	for (ll i=0; i<n; i++) {
		cin >> ID; curr_sum += ID;
		ll search = (curr_sum) % 7;
		if (prefix_sum.find(search) == prefix_sum.end()) {
			prefix_sum[search] = i+1;
		}
		ans = max(ans, (i+1)-prefix_sum[search]);
	}
	cout << ans << '\n';
}

//this solution finds # of subsequences that sum to 7
// int main() {
// 	freopen("div7.in", "r", stdin);
// 	freopen("div7.out", "w", stdout);
// 	ll n; cin >> n;
// 	ll ans = 0;
// 	map<ll, ll> prefix_sum;
// 	prefix_sum[0] = 1;
// 	ll curr_sum = 0;
// 	ll ID;
// 	for (ll i=0; i<n; i++) {
// 		cin >> ID; curr_sum += ID;
// 		ans += prefix_sum[(curr_sum-7)%7];
// 		++prefix_sum[curr_sum%7];
// 	}
// 	cout << ans << '\n';
// }



/* solution that obtained 7/10, with one TLE
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	vector<int> ids = {0}; vector<ll> psum = {0};
	int cow; int i = 0;
	while (cin >> cow) {
		ids.push_back(cow);
		psum.push_back(cow + psum.at(i));
		i++;
	}
	//now that we have the prefix sums, simply iterate in linear time
	//over sums to sevens. O(N + N-1 + N-2 +...+ 1) -> O(N)
	int temp; int size = 0;
	for (temp=0; temp<ids.size()-1; temp++) {
		for (int j=temp+1; j<ids.size(); j++) {
			ll diff = psum.at(j) - psum.at(temp);
			if (diff % 7 == 0) {
				size = max(size, j-temp);
			}
		}
	}
	cout << size << '\n';
}
*/