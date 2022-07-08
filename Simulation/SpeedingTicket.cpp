#include <iostream>
#include <cstdio>
using namespace std;

//completely my solution
//decided not to brute force to 100, which also would work
int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int N, M; cin >> N >> M;
    int rseg[N]; int limit[N];
    int bseg[M]; int speed[M];
    for (int i=0; i<N; i++) {cin >> rseg[i] >> limit[i];}
    for (int i=0; i<M; i++) {cin >> bseg[i] >> speed[i];}
    int p1=0; int p2=0;
    int ans=0;
    while (p1<N || p2<M) {
        ans = max(ans, speed[p2]-limit[p1]);
        if (rseg[p1] > bseg[p2]) {
            rseg[p1] = rseg[p1] - bseg[p2]; 
            p2++;
        }
        else if (bseg[p2] > rseg[p1]) {
            bseg[p2] = bseg[p2] - rseg[p1]; 
            p1++;
        }
        else {p1++; p2++;}
    }
    cout << ans;
}