#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll before[4]; ll after[4];
	ll promotions[3];
	for (int i=0; i<4; i++) {
		cin >> before[i] >> after[i];
	}
	for (int p2=3; p2>0; p2--) {
		ll need = after[p2] - before[p2];
		promotions[p2-1] = need;
		before[p2-1] -= need;
	}
	for (ll ans : promotions) {
		cout << ans << endl;
	}
}