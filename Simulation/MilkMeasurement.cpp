#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef pair<int, int> ppi;

//at most, there are 100 days.
//time complexity being linear at O(2N), at most 200 iterations occur, which should be OK
int main() {
    // freopen("measurement.in", "r", stdin);
    // freopen("measurement.out", "w", stdout);
    int N; cin >> N;
    map<int, ppi> measurements;
    int days[N];
    for (int i=0; i<N; i++) {
        int day, change; string cow;
        cin >> day >> cow >> change;
        days[i]=day;
        if (cow=="Bessie") {measurements[day] = {0, change};}
        else if (cow=="Elsie") {measurements[day] = {1, change};}
        else {measurements[day] = {2, change};}
    }
    //consider: how to check if multiple ties for first
    int amt=0; int ties=3; int prev=0; int scores[3] = {7, 7, 7};
    for (int day : days) {
        ppi attr = measurements[day];
        if (scores[attr.first]+attr.second > max(scores[0], max(scores[1], scores[2])) ) {
            if (attr.first!=prev) {prev=attr.first; amt++;}
        }
        if (scores[attr.first]+attr.second == max(scores[0], max(scores[1], scores[2])) ) {
            if ( scores[(attr.first+1)%3] != scores[(attr.first+2)%3] ) {amt++;}
        }
        else {
            if ( scores[(attr.first+1)%3] != scores[(attr.first+2)%3] ) {amt++;}
        }
        scores[attr.first]+=attr.second;
    }
    cout << amt;
}