#include <iostream>
#include <cstdio>
using namespace std;
typedef pair<int, int> ppi;

int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    int N; cin >> N;
    int traffic[N][3];
    for (int i=0; i<N; i++) {
        string ramp;
        int low; int high;
        cin >> ramp >> low >> high;
        if (ramp=="none") {traffic[i][0]=0;}
        else if (ramp=="on") {traffic[i][0]=1;}
        else {traffic[i][0]=2;}
        traffic[i][1] = low; traffic[i][2] = high;
    }
    //before mile 1 solution
    int startidx=0; int endidx=N-1;
    while (traffic[startidx][0]!=0) {startidx++;}
    while (traffic[endidx][0]!=0) {endidx--;}
    ppi before = {traffic[startidx][1], traffic[startidx][2]};
    ppi after = {traffic[endidx][1], traffic[endidx][2]};
    for (int i=startidx+1; i<N; i++) {
        if (traffic[i][0]==0) {
            before.first = max(before.first, traffic[i][1]);
            before.second = min(before.second, traffic[i][2]);
        }
        else if (traffic[i][0]==1) {
            before.first += traffic[i][1];
            before.second += traffic[i][2];
        }
        else {
            before.first = max(0, before.first-traffic[i][2]);
            before.second = max(0, before.second-traffic[i][1]);
        }
    }
    //after mile N solution
    for (int i=endidx-1; i>=0; i--) {
        if (traffic[i][0]==0) {
            after.first = max(after.first, traffic[i][1]);
            after.second = min(after.second, traffic[i][2]);
        }
        else if (traffic[i][0]==1) {
            after.first = max(0, after.first-traffic[i][2]);
            after.second = max(0, after.second-traffic[i][1]);
        }
        else {
            after.first += traffic[i][1];
            after.second += traffic[i][2];
        }
    }
    cout << after.first << ' ' << after.second << '\n' << before.first << ' ' << before.second << '\n';
}