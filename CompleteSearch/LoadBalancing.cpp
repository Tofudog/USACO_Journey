#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef map<int, int> mmi;
typedef long long ll;

//going through the xbounds
/*
for q1, x1=1 and x2=xans; y1=1 and y2=yans
for q2, x1=xans and x2=xmax; y1=1 and y2=yans
for q3, x1=1 and x2=xans; y1=yans and y2=ymax
for q1, x1=xans and x2=xmax; y1=yans and y2=ymax
*/
//this only works for quad 1 and 2
int quadScore(int x1, int x2, int y1, int y2, mmi pos) {
    int score = 0;
    for (int i=x1; i<x2; i+=2) {
        if (pos.find(i)==pos.end()) {continue;}
        else {
            for (const auto &j : xtoY[i]) {
                if (j > y2) {break;}
                score++;
            }
        }
    }
}

// took me three hours to make my own solution!
int main() {
    int n, b; cin >> n >> b;
    mmi xtoY, ytoX;
    int xmin = b; int ymin = b; int xmax = 1; int ymax = 1;
    for (int i=0; i<n; i++) {
        int xi, yi; cin >> xi >> yi;
        if (xtoY.find(xi)==xtoY.end()) {
            xtoY[xi]=0;
        }
        if (ytoX.find(yi)==ytoX.end()) {
            ytoX[yi]=0;
        }
        xtoY[xi]++; ytoX[yi]++;
        xmin = min(xmin, xi); ymin = min(ymin, yi);
        xmax = max(xmax, xi); ymax = max(ymax, yi);
    }
    int left = xtoY[xmin]; int right = n-left;
    int res = abs(right-left);
    int xans = xmin+1;
    for (int x=xmin+1; x<xmax; x+=2) {
        left += xtoY[x-1]; right -= xtoY[x-1];
        if (res > abs(right-left)) {
            res = abs(right - left);
            xans = x+2;
        }
    }
    int down = ytoX[ymin]; int up = n-down;
    res = abs(up-down);
    int yans = ymin+1;
    for (int y=ymin+1; y<ymax; y+=2) {
        down += ytoX[y-1]; up -= ytoX[y-1];
        if (res > abs(up - down)) {
            res = abs(up - down);
            yans = y+2;
        }
    }
    int q1 = 0; int q2 = 0; int q3 = 0; int q4 = 0;
    q1 = quadScore(1, xans, 1, yans, xtoY);
    //fix for the other quadrants...


    cout << min( min(q1, q2), min(q3, q4) );
}