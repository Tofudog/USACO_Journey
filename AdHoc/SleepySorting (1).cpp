#include <iostream>
using namespace std;

//constraints: 1≤N≤100
//recent solution I came up with that works extremely well without help
int main() {
	int n; cin >> n;
	if (n==1) {
		cout << 0 << endl; return 0;
	}
	int nums[100];
	for (int i=0; i<n; i++) {
		cin >> nums[i];
	}
	int ldc = -1; //last descending pair
	for (int p=0; p<n-1; p++) {
		if (nums[p] > nums[p+1]) {ldc = p;}
	}
	cout << ldc+1 << endl;
}

//original and confusing solution that failed some test cases
// int main() {
// 	int n; cin >> n;
// 	int nums[100];
// 	for (int i=0; i<n; i++) {
// 		cin >> nums[i];
// 	}
// 	//first: find last descending pair
// 	int lastD = -1; //assume entire arr is sorted
// 	for (int j=1; j<n; j++) {
// 		if (nums[j] < nums[j-1]) {
// 			lastD = j;
// 		}
// 	}
// 	if (lastD < 0) {
// 		cout << 0 << endl;
// 		return 0;
// 	}
// 	//after finding last descending pair, find where to swap
// 	//either swap in between or after
// 	int swap;
// 	if (nums[lastD] < nums[0]) {swap = lastD;}
// 	else {swap = lastD-1;}
// 	int newNums[100];
// 	int i;
// 	for (i=1; i<swap+1; i++) {
// 		newNums[i-1] = nums[i];
// 	}
// 	newNums[i-1] = nums[0];
// 	//fill in the rest of the values
// 	while (i < n) {
// 		newNums[i] = nums[i]; i++;
// 	}
// 	//then just take each first value and
// 	//work backwards to placement
// 	int place = 0; int lastNums[100];
// 	while (place >= 0) {
// 		place = -1;
// 		for (int j=n-1; j>=0; j--) {
// 			if (newNums[j] < newNums[0]) {
// 				place = j+1;
// 				break;
// 			}
// 		}
// 		if (place < 0) {break;}
// 		for (i=1; i<place+1; i++) {
// 			lastNums[i-1] = newNums[i];
// 		}
// 		lastNums[i-1] = newNums[0];
// 		//fill in the rest of the values
// 		while (i < n) {
// 			lastNums[i] = newNums[i]; i++;
// 		}
// 		for (int x=0; x<n; x++) {
// 			newNums[x] = lastNums[x];
// 		}
// 	}
// 	for (int y=0; y<n; y++) {
// 		cout << lastNums[y] << ' ';
// 	}
// }

