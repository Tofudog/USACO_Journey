#include <iostream>
#include <vector>
using namespace std;

int amtLeft[101] = {0};
vector<int> conditioners[101]; //each with 4 vals
int M;
int ans = -1;

void recurse(int k, int money) {
	if (k==M) {
		//check if amtLeft is completely nonpositive
		bool nonPos = true;
		for (int A : amtLeft) {
			if (A > 0) {nonPos = false;}
		}
		if (!nonPos) {return;}
		//cout << money << '\n';
		if (ans==-1) {ans = money;}
		ans = min(ans, money);
		return;
	}
	recurse(k+1, money);
	for (int i=conditioners[k][0]; i<=conditioners[k][1]; i++) {
		amtLeft[i] -= conditioners[k][2];
	}
	recurse(k+1, money+conditioners[k][3]);
	for (int i=conditioners[k][0]; i<=conditioners[k][1]; i++) {
		amtLeft[i] += conditioners[k][2];
	}
}

int main() {
	int N; cin >> N >> M;
	int s, t, c;
	for (int i=0; i<N; i++) {
		cin >> s >> t >> c; --s; --t;
		for (int j=s; j<=t; j++) {amtLeft[j] = c;}
	}
	int a, b, p, m;
	for (int i=0; i<M; i++) {
		cin >> a >> b >> p >> m; --a; --b;
		conditioners[i] = {a, b, p, m};
	}
	recurse(0, 0);
	cout << ans << '\n';
	// for (int i=0; i<M; i++) {
	// 	for (int j=0; j<4; j++) {
	// 		cout << conditioners[i].at(j) << ' ';
	// 	} cout << '\n';
	// }
}