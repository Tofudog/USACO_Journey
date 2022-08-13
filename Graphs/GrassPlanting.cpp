#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

//constraints: 1≤N≤10^5
int main() {
	int n; cin >> n;
	//create an adj. list since mat. is too full (i.e. 10^10)
	map<int, set<int>> farm; int field_i, field_j;
	for (int i=0; i<n; i++) {
		cin >> field_i >> field_j;
		farm[field_i].insert(field_j);
		farm[field_j].insert(field_i);
	}
	bool reuse; int nextVal = 0;
	map<int, int> types; vector<int> used;
	for (int node=1; node<=n; node++) {
		reuse = false;
		//objective within is to reuse as much as possible
		for (int val : used) {
			//iterate through the connections
			for (int direct : farm[node]) {
				if (types[direct] == val) {
					//don't use this type of grass
					goto another;
				}
				//and iterate through the connections of the connections
				for (int indirect : farm[direct]) {
					if (types[indirect] == val) {
						//don't use this type of grass
						goto another;
					}
				}
			} reuse = true;
			another:
			if (reuse) {
				//reuse 'val' from 'used'
				types[node] = val;
				goto nextNode;
			}
		} nextNode:
		if (!reuse) {
			//insert a new value into used
			if (used.size()==0) {nextVal = 0;}
			else {nextVal = used.at(used.size()-1)+1;}
			used.push_back( nextVal );
		}
	}

	cout << used.size() << endl;
}
