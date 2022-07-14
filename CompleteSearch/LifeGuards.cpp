#include <iostream>
using namespace std;

//time taken to solve: 25m 32s + ~10m to debug
int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n; cin >> n;
    int start[n]; int end[n];
    int low = 1000; int high = 0;
    for (int i=0; i<n; i++) {
        int s, e; cin >> s >> e;
        low = min(low, s); high = max(high, e);
        start[i] = s; end[i] = e;
    }
    int ans = 0;
    for (int f=0; f<n; f++) {
        int curr = 0;
        bool shift[high+1] = {false};
        for (int c=0; c<n; c++) {
            if (f==c) {continue;}
            //marking true at each pos at least 1 cow appears in
            for (int x=start[c]; x<end[c]; x++) {
                shift[x]=true;
            }
        }
        //if true at loc. in shift, then add one to the score
        for (bool cow : shift) {
            if (cow) {curr++;}
        }
        ans = max(ans, curr);
    }
    cout << ans;
}