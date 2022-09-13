#include <iostream>
#include <vector>
//#include <algorithm>

using namespace std;
using ll = long long;  //guess this was unecessary
#define MAX_N 100000+1

int main() {
	char cows[MAX_N];
	int n; cin >> n;
	string breeds; cin >> breeds;
	vector<bool> flipped;
	for (int i=0; i<n-1; i+=2) {
		if (breeds.at(i)==breeds.at(i+1)) {
			continue;
		}
		else if (breeds.at(i)=='G') {
			//then need to flip
			flipped.push_back(true);
		} else {flipped.push_back(false);}
	}
	int ans = 0;
	for (int i=flipped.size()-1; i>=0; i--) {
		if (flipped.at(i) && ans%2==0) {
			++ans;
		}
		if (!flipped.at(i) && ans%2==1) {
			++ans;
		}
	}
	cout << ans << '\n';
}


