#include <iostream>
using namespace std;

// I take pride in this being completely my solution and though process; complete brute force
struct triangle {
    int x1, y1, x2, y2, x3, y3;
    pair<int, int> x_parallel, y_parallel;
    int x[3] = {x1, x2, x3}; int y[3] = {y1, y2, y3};
    bool isvalid() {
        bool xon=false; bool yon=false;
        for (int i=0; i<2; i++) {
            for (int j=i+1; j<3; j++) {
                if (y[i]==y[j]) {x_parallel.first=x[i]; x_parallel.second=x[j]; xon=true;}
                else if (x[i]==x[j]) {y_parallel.first=y[i]; y_parallel.second=y[j]; yon=true;}
            }
        } return xon&&yon;
    }
    int area() {return abs(x_parallel.first-x_parallel.second)*abs(y_parallel.first-y_parallel.second);}
};
int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n; cin >> n;
    int x[n], y[n];
    for (int i=0; i<n; i++) {cin >> x[i] >> y[i];}
    int ans = 0;
    for (int i=0; i<n-2; i++) {
        for (int j=i+1; j<n-1; j++) {
            for (int k=j+1; k<n; k++) {
                struct triangle tri = {x[i], y[i], x[j], y[j], x[k], y[k],
                                        {-1, -1}, {-1, -1}};
                if (tri.isvalid()) {
                    ans = max(ans, tri.area());
                }
            }
        }
    }
    cout << ans << endl;
}