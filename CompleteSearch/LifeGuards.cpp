#include <iostream>
#include <map>
using namespace std;
typedef map<int, int> mmi;

//for true brute force, just find which pts are covered and add.
int main() {
    int N; cin >> N;
    mmi pts;
    for (int i=0; i<N; i++) {
        int start, end; cin >> start >> end;
        pts[start]=end;
    }
    int ans=0;
    //brute forcing through firing each guard
    for (int fire=0; fire<N; fire++) {
        int curr=0;
        mmi intervals;
        for (int x=0; x<N; x++) {
            if (x==fire) {continue;}
            auto iter = intervals.begin();
            while (iter != intervals.end()) {
                if ()
                ++iter;
            }
        }
    }
}