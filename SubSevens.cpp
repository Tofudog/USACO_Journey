#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

//constraints: 1≤N≤50000
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