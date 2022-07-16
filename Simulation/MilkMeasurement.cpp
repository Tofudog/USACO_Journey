#include <iostream>
#include <map>
using namespace std;

//time taken: 2h 24m 26s
/* Thing I wish I knew:
    ***if a cow drops lead or gains lead, no matter
        if there is a tie or not, score increments.
        I thought two or more cows yields the same score!
        But now this works. Difficulty: Hard.
*/
int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n; cin >> n;
    map<int, int> days;
    int change[101]; int scores[3] = {7, 7, 7};
    bool tie = true; int high = 7; //int hi = -1;
    for (int i=0; i<n; i++) {
        int d, c; string n; cin >> d >> n >> c;
        if (n=="Bessie") {days[d] = 0;}
        else if (n=="Elsie") {days[d] = 1;}
        else {days[d] = 2;}
        change[d] = c;
    }
    int ans = 0;
    bool bOn = true; bool eOn = true; bool mOn = true;
    bool bOnNext = true; bool eOnNext = true; bool mOnNext = true;
    for (const auto &cow : days) {
        scores[cow.second] += change[cow.first];
        high = max( scores[0], max(scores[1], scores[2]) );
        bOnNext = (scores[0] >= high);
        eOnNext = (scores[1] >= high);
        mOnNext = (scores[2] >= high);
        if (bOnNext + eOnNext + mOnNext > 1) {tie = true;}
        if (tie) {
            if (bOn==bOnNext && eOn==eOnNext && mOn==mOnNext) {}
            else if (bOnNext + mOnNext + eOnNext == 1) {
                ans++; tie = false;
            }
            else {ans++;}
        }
        else {
            if ((bOn||bOnNext) + (eOn||eOnNext) + (mOn||mOnNext) > 1) {
                ans++;
            }
        }
        bOn = bOnNext; eOn = eOnNext; mOn = mOnNext;
    }
    cout << ans << '\n';
}