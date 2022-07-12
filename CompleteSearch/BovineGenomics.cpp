#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n, m; cin >> n >> m;
    map<int, set<char>> spots, plain;
    for (int i=0; i<n; i++) {
        string genome; cin >> genome;
        for (int j=0; j<m; j++) {
            char gene = genome[j];
            if (spots.find(j)==spots.end()) {spots[j]={gene}; continue;}
            spots[j].insert(gene);
        }
    }
    for (int i=0; i<n; i++) {
        string genome; cin >> genome;
        for (int j=0; j<m; j++) {
            char gene = genome[j];
            if (plain.find(j)==plain.end()) {plain[j]={gene}; continue;}
            plain[j].insert(gene);
        }
    }
    int ans=0; int i=0;
    while (i<m) {
        found:
        for (char gene : spots[i]) {
            if (plain[i].find(gene) != plain[i].end()) {
                if (i==m-1) {goto hop;}
                i++; goto found;
            }
        }
        ans++; i++;
    }
    hop:
    cout << ans << '\n';
}