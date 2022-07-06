#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

// int* close_range(int arr[2], int low, int high) {
//     int nlow = max(low, arr[0]);
//     int nhigh = min(high, arr[1]);
//     return new int[2]{nlow, nhigh};
// }

int main() {
    // freopen("traffic.in", "r", stdin);
    // freopen("traffic.out", "w", stdout);
    int N;
    cin >> N;
    vector<string> ramps;
    vector<int> low, high;
    for (int i=0; i<N; i++) {
        string R;
        int L, H;
        cin >> R >> L >> H;
        ramps.push_back(R);
        low.push_back(L);
        high.push_back(H);
    }
    int before[2] = {-1, -1};
    int after[2] = {-1, -1};
    int on_add[2] = {0, 0};
    int off_sub[2] = {0, 0};
    // for 'before', we use current and previous on/off values to calculate range until last segment w/o a ramp
    // for 'after', we neglect on/off until reaching first segment w/o a ramp.
    for (int seg=0; seg<N; seg++) {
        if (ramps[seg].compare("on") == 0) {
            on_add[0] += low[seg];
            on_add[1] += high[seg];
        }
        else if (ramps[seg].compare("off") == 0) {
            off_sub[0] += low[seg];
            off_sub[1] += high[seg];
        }
        else {
            if (after[0]==-1) {
                after[0] = low[seg];
                after[1] = high[seg];
                // subject to error.
                before[0] = low[seg]-off_sub[0]+on_add[0];
                before[1] = high[seg]-off_sub[1]+on_add[1];
            }
            else {
                after[0] = max(after[0], low[seg]);
                after[1] = min(after[1], high[seg]);
                before[0] = max(before[0], low[seg]);
                before[1] = min(before[1], high[seg]);
            }
        }
    }
    after[0] += (on_add[0] - off_sub[0]);
    after[1] += (on_add[1] - off_sub[1]);

    cout << before[0] << ' ' << before[1] << '\n';
    cout << after[0] << ' ' << after[1] << '\n';

    return 0;
}