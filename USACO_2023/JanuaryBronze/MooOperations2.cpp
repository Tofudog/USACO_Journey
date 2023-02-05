#include <iostream>
using namespace std;

void solve() {
    string X; cin >> X;
    int ans = 1000; int n = X.size();
    for (int j=0; j<=n-3; j++) {
        int curr = n-3;
        string seq = X.substr(j, 3);
        if (seq == "MOO") {ans = min(ans, curr);}
        else if (seq=="OOO"||seq=="MOM") {curr++; ans = min(ans, curr);}
        else if (seq=="OOM") {curr+=2; ans = min(ans, curr);}
        else {}
    }
    if (ans==1000) {cout << -1;}
    else {cout << ans;}
}

int main() {
    int T; cin >> T;
    for (int i=0; i<T; i++) {
        solve(); cout << '\n';
    }
}