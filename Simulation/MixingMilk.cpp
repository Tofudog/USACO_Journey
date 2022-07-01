#include <iostream>
#include <cstdio>
using namespace std;

// best solution I came up with
int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int C[3];
    int M[3];
    for (int b=0; b<3; b++) {cin >> C[b] >> M[b];}
    for (int i=0; i<100; i++) {
        int pour = min(M[i%3], C[(i+1)%3] - M[(i+1)%3]);
        M[i%3] -= pour;
        M[(i+1)%3] += pour;
    }
    for (int amt : M) {cout << amt << '\n';}
    return 0;
}

// decent, but not general- i.e. for more bottles- solution; also a bit slower
/*int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int c1, c2, c3;
    int m1, m2, m3;
    cin >> c1 >> m1;
    cin >> c2 >> m2;
    cin >> c3 >> m3;
    for (int i=0; i<100; i++) {
        if (i%3==0) {
            int pour = min(m1, c2-m2);
            m2+=pour;
            m1-=pour;
        }
        else if (i%3==1) {
            int pour = min(m2, c3-m3);
            m3+=pour;
            m2-=pour;
        }
        else {
            int pour = min(m3, c1-m1);
            m1+=pour;
            m3-=pour;
        }
    }
    cout << m1 << '\n' << m2 << '\n' << m3 << '\n';
}*/