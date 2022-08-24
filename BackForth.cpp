#include <iostream>
#include <set>
#include <vector>
using namespace std;

//Just like to say, I solved this Hard problem in roughly 1hr
//and on my first run, I passed ALL test cases
//time complexity: O(1) for 10*11^4 operations < 2*10^8

//possible storage values for barn 1
set<int> storage;
vector<int> barn1; vector<int> barn2;

//initially, tank1 and tank2 are both set to 1000
void search(int tank1, int tank2, bool forward, int day) {
	if (day==4) {
		storage.insert(tank1);
		return;
	}
	if (forward) {
		int nbuckets = 10;
		if (day>0) {nbuckets--;}
		for (int i=0; i<nbuckets; i++) {
			int temp = barn1.at(i);
			barn2.push_back(temp);
			barn1.erase(barn1.begin()+i);
			search(tank1-temp, tank2+temp, false, day+1);
			barn2.pop_back();
			barn1.insert(barn1.begin()+i, temp);
		}
	}
	else {
		for (int i=0; i<11; i++) {
			int temp = barn2.at(i);
			barn1.push_back(temp);
			barn2.erase(barn2.begin()+i);
			search(tank1+temp, tank2-temp, true, day+1);
			barn1.pop_back();
			barn2.insert(barn2.begin()+i, temp);
		}
	}
}
int main() {
	freopen("backforth.in", "r", stdin);
	freopen("backforth.out", "w", stdout);
	int M;
	for (int i=0; i<10; i++) {
		cin >> M; barn1.push_back(M);
	}
	for (int i=0; i<10; i++) {
		cin >> M; barn2.push_back(M);
	}
	search(1000, 1000, true, 0);
	cout << storage.size() << endl;
}