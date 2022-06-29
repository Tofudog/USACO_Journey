#include <iostream>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        int n, c0, c1, h;
        cin >> n >> c0 >> c1 >> h;
        string S;
        cin >> S;
        if (c1 - c0 + h < 0) {
            // track number of changes
            int changes = 0;
            for (char& c : S) {if (c=='0') {changes++;}}
            cout << n*c1 + h*changes << "\n";
        }
        else if (c0 - c1 + h < 0) {
            int changes = 0;
            for (char& c : S) {if (c=='1') {changes++;}}
            cout << n*c0 + h*changes << "\n";
        }
        else {
            int coins = 0;
            for (char& c : S) {
                if (c=='0') {coins+=c0;}
                else {coins+=c1;}
            }
            cout << coins << "\n";
        }
    }
}