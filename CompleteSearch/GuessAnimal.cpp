#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

bool comp(pair<string, int>& a, pair<string, int>& b) {
    return a.second > b.second;
}

//time taken: 33m 24s + debug for ~1hr 10m
int main() {
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    int n; cin >> n;
    map<string, int> feasible;
    for (int i=0; i<n; i++) {
        string animal; int k; cin >> animal >> k;
        string attr; int j=0;
        //this was a stupid bug... fixed it by placing j<k before cin >> attr
        while (j<k && cin >> attr) {
            if (feasible.find(attr)==feasible.end()) {
                feasible[attr] = 0; //cout << "attr "<<attr << " is new\n";
            }
            feasible[attr]++;
            j++;
        }
    }
    int ans = 0; set<string> visited;
    bool unique = false;
    while (!unique) {
        unique = true;
        for (const auto &A : feasible) {
            if (A.second>1 && visited.find(A.first)==visited.end()) {
                unique = false; visited.insert(A.first); goto found;
            }
        } found:
        ans++;
    }
    //ideally another alternative solution
    // sort(feasible.begin(), feasible.end(), comp);
    // for (const auto &A : feasible) {
    //     ans++;
    //     if (A.second == 1) {goto end;}
    // } end:
    cout << ans << '\n';
}