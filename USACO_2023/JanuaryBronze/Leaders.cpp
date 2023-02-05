#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    string cows; cin >> cows;
    vector<int> E; int firstG = -1; int firstH = -1;
    int lastG = 0; int lastH = 0;
    int ei;
    for (int i=0; i<n; i++) {
        if (cows.at(i)=='G') {
            if (firstG==-1) {firstG = i;}
            lastG = i;
        } else {
            if (firstH==-1) {firstH = i;}
            lastH = i;
        }
        cin >> ei; --ei;
        E.push_back(ei);
    }
    int ans = 0;
    if (firstH > firstG) {
        if (E.at(firstH) < lastH) {
            //this solution contains no pairs
            cout << 0 << '\n'; return 0;
        }
        if (E.at(0) >= firstH || E.at(0) >= lastG) {++ans;}
        //now either G must have all G's or G gets firstH
        for (int i=1; i<firstH; i++) {
            if (E.at(i) >= firstH) {++ans;}
        }
    }
    else if (firstG > firstH) {
        if (E.at(firstG) < lastG) {
            //this solution contains no pairs
            cout << 0 << '\n'; return 0;
        }
        if (E.at(0) >= firstG || E.at(0) >= lastH) {++ans;}
        //now either G must have all G's or G gets firstH
        for (int i=1; i<firstG; i++) {
            if (E.at(i) >= firstG) {++ans;}
        }
    }
    cout << ans << '\n';

    //cout << firstG << ' ' << firstH;
    //cout << lastG << ' ' << lastH;
}