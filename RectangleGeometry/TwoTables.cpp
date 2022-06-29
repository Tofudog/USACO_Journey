#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        int W, H;
        int x1, y1, x2, y2;
        int w, h;
        cin >> W >> H;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> w >> h;
        int ans = LONG_MAX;
        // test cases where new table placed starting on the bottom left
        if (W - (w + x2-x1) >= 0) {
            // left/right same for bottom and top
            ans = min(ans, max(0, w-x1));
            ans = min(ans, max(0, x2-(W-w)));
        }
        if (H - (h + y2-y1) >= 0) {
            // bottom/top same for left and right
            ans = min(ans, max(0, h-y1));
            ans = min(ans, max(0, y2-(H-h)));
        }
        if (ans==LONG_MAX) {cout << -1 << "\n";}
        else {cout << ans << "\n";}
    }
}