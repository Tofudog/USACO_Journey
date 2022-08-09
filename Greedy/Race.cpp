#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll k; int n; cin >> k >> n;
	//array of test cases
	ll X[n];
	for (int i=0; i<n; i++) {cin >> X[i];}

	for (ll x : X) {
		int curr_s = 0;
		int time = 0;
		bool decr = false;
		while (k > 0) {
			if (curr_s < x) {
				curr_s++;
				k -= curr_s;
			}
			else if (decr) {
				if (curr_s==x) {k-=x;}
				else {curr_s--; k-=curr_s;}
			}
			else {
				//check whether to incr. curr_s
				//for loop from curr_s+1 to x and calc. sum
				//if sum is greater than k, start decreasing
				int sum = 0;
				for (int next=curr_s+1; next>x; next--) {
					sum += next;
				}
				if (sum > k) {
					//need to start decrementing
					decr = true;
				}
				else {curr_s++;}
				k -= curr_s;
			}
			time++;
		}
		cout << time << endl;
	}
}