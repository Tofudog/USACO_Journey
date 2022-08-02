#include <iostream>
using namespace std;

// both attempts get 180/200 points
int main() {
	int n; cin >> n;
	int counters[101];
	int i = n-1;
	for (int c=0; c<n; c++) {
		cin >> counters[c];
	}
	int minDays = 0; int maxDays = 0;
	while (i > 0) {
		if (counters[i] < 0) {
			maxDays++; i--;
			continue;
		} if (i==0) {goto done;}
		i -= counters[i]; if (i==0) {goto done;}
		maxDays++; minDays++; i--;
	}

	done: minDays++; maxDays++;
	cout << minDays << ' ' << maxDays;
}


// #include <iostream>
// using namespace std;

// int main() {
// 	int n; cin >> n;
// 	int counters[101];
// 	int i = n-1;
// 	for (int c=0; c<n; c++) {
// 		cin >> counters[c];
// 	}
// 	int minDays = 0; int maxDays = 0;
// 	while (i > 0) {
// 		if (counters[i] < 0) {
// 			maxDays++; i--; if (i==0) {minDays++; maxDays++;}
// 			continue;
// 		}
// 		i -= counters[i];
// 		maxDays++; minDays++; i--;
// 		if (i==0) {minDays++; maxDays++;}
// 	}
// 	cout << minDays << ' ' << maxDays;
// }