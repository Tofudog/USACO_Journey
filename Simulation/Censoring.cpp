//this problem is an old Bronze; difficulty: hard
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    string S, T;
    cin >> S; cin >> T;
    int idx=0;
    while (idx+T.length() <= S.length()) {
        if ( S.substr(idx, T.length()) == T ) {
            S.erase(idx, T.length());
            int back = T.length()-1;
            idx = idx - min(back, idx);
        }
        else {idx++;}
    }
    cout << S;
}