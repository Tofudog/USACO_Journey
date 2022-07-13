#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef set<int> si;

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int n, b; cin >> n >> b;
    map<int, si> pos; si left, right, down, up;
    int xmin, ymin = b; int xmax, ymax = 0;
    for (int i=0; i<n; i++) {
        int xi, yi; cin >> xi >> yi;
        xmin = max(xmin, xi); ymin = max(ymin, yi);
        xmax = max(xmax, xi); ymax = max(ymax, yi);
        if (pos.find(xi)==pos.end()) {pos[xi]={y1}; continue;}
        pos[xi].insert(yi);
    }
    //filling left and right, then down and up
    left={xmin};
    for (const auto &item : pos) {
        if (item.first > xmin) {right.insert(item.first);}
    }
    //for down/up, iterate through both left and right and find < or > curr.
    int xbound=xmin; int ybound=ymin;
    for (int i=1; i<xbound; i+=2) {
        
    }
}