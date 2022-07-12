#include <iostream>
#include <map>
#include <vector>
using namespace std;

//theoretically, an unordered map is faster, but this easily works
int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int k, n; cin >> k >> n;
    map<int, vector<int>> scores;
    for (int i=0; i<n; i++) {
        int rnk=0; int val;
        while (cin >> val) {
            if (scores.find(val)==scores.end()) {
                scores[val] = {rnk}; rnk++; continue;
            }
            scores[val].push_back(rnk); rnk++;
        }
    } int ans=0;
    for (int c=1; c<n+1; c++) {
        for (int k=1; k<n+1; k++) {
            if (c==k) {continue;}
            bool greater=true;
            for (int i=0; i<n; i++) {
                if (scores[c+1][i]>scores[k+1][i]) {greater=false; goto jump;}
            } jump:
            if (greater) {ans++;}
        }
    }
    cout << ans << '\n';
}