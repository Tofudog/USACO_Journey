#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, x; cin >> n >> x;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	int time = 0;
	int counter;
	for (counter=0; counter<n; counter++) {
		if (time + a[counter] > x) {break;}
		time += a[counter];
	}
	cout << counter << endl;
}