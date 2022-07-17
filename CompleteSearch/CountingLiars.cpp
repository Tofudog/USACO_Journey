#include <iostream>
using namespace std;
typedef pair<int, int> ppi;

int main() {
	int n; cin >> n;
	ppi info[n];
	for (int i=0; i<n; i++) {
		char L_G; int loc; cin >> L_G >> loc;
		if (L_G=='L') {info[i] = {0, loc};}
		else {info[i] = {1, loc};}
	}
	int ans = 1001;
	for (int i=0; i<n; i++) {
		int liars = 0;
		int curr = info[i].second;
		for (int j=0; j<n; j++) {
			ppi cow = info[j];
			if (cow.first==0) {
				if (cow.second < curr) {liars++;}
			}
			else {
				if (cow.second > curr) {liars++;}
			}
		}
		ans = min(ans, liars);
	}
	cout << ans << endl;
}