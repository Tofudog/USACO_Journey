#include <iostream>
#include <set>
#include <vector>
using namespace std;

//times out on O(n^4), where n<=100, so this one takes xvals and yvals
//already to render time complexity to O(n^3). Overall, this works.
int main() {
    int N, B; cin >> N >> B;
    vector<int> xvals;
    vector<int> yvals;
    set<int> vfence;
    set<int> hfence;
    int xi; int yi;
    for (int i=0; i<N; i++) {
        cin >> xi >> yi;
        xvals.push_back(xi);
        yvals.push_back(yi);
        vfence.insert(xi);
        hfence.insert(yi);
    }
    int lowest = 101;
    for (int x : vfence) {
        for (int y : hfence) {
            int q1=0; int q2=0; int q3=0; int q4=0;
            for (int c=0; c<N; c++) {
                if (xvals.at(c) < x) {
                    if (yvals.at(c) < y) {q1++;}
                    else {q3++;}
                }
                else {
                    if (yvals.at(c) < y) {q2++;}
                    else {q4++;}
                }
            }
            lowest = min(lowest, max( q1, max(q2, max(q3, q4)) ) );
        }
    }
    cout << lowest << endl;
}