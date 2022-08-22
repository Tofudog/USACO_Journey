#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

//use prefix sums
int main() {
	int n, q; cin >> n >> q;
	vector<int> a; int ai;
	vector<ll> prefix; ll total = 0;
	for (int i=0; i<n; i++) {
		cin >> ai; a.push_back(ai);
		total += ai; prefix.push_back(total);
	}
	int l_i, r_i;
	for (int i=0; i<q; i++) {
		//now we can simply output the sum given two indices
		cin >> l_i >> r_i;
		//cout << l_i << ' ' << r_i << '\n';
		if (l_i==0) {
			cout << prefix.at(r_i-1) << '\n';
		} else {cout << prefix.at(r_i-1) - prefix.at(l_i-1) << '\n';}
		//cout << prefix.at(r_i-1) - prefix.at(l_i) << '\n';
	}
	//for (ll num : prefix) {cout << num << endl;}
}

//naive solution with time complexity O(QN)
/*int main() {
	int n, q; cin >> n >> q;
	vector<int> a; int ai;
	for (int i=0; i<n; i++) {
		cin >> ai; a.push_back(ai);
	}
	int l_i, r_i;
	for (int i=0; i<q; i++) {
		ll sum_i = 0;
		cin >> l_i >> r_i;
		for (int j=l_i; j<r_i; j++) {
			sum_i += a[j];
		}
		cout << sum_i << '\n';
	}
}*/