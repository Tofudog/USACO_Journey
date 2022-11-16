#include <iostream>
using namespace std;

int main() {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	int n; cin >> n;
	int numH, numP, numS; numH = numP = numS = 0;
	int game[100001];
	char gesture;
	for (int i=0; i<n; i++) {
		cin >> gesture;
		if (gesture == 'H') {++numH; game[i] = 0;}
		else if (gesture == 'P') {++numP; game[i] = 1;}
		else {++numS; game[i] = 2;}
	}
	int left[3] = {numH, numP, numS};
	//arbitrarily start with p counter
	int res = 0;
	int ans = 0;
	int curr = 0;
	for (int first=0; first<3; first++) {
		for (int i=0; i<n; i++) {
			if (game[i] == first) {
				ans++;
			}
			left[game[i]]--;
			//if gestures do not change
			curr = max(left[0], max(left[1], left[2]));
			res = max(res, curr+ans);
		}
		ans = 0;
		//reinitialize left
		left[0] = numH; left[1] = numP; left[2] = numS;
	}
	cout << res;
}