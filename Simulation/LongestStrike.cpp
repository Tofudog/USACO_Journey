#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
 
int main() {
    int t; cin >> t;
    for (int test=0; test<t; test++) {
        int n, k; cin >> n >> k;
        vector<int> a;
        int temp; while (cin >> temp) {a.push_back(temp);}
        sort(a.begin(), a.end());
        vector<int> A; map<int, int> sizes;
        for (int num : a) {
            if (sizes.find(num)==sizes.end()) {
                sizes[num]=1;
                A.push_back(num);
            } else {sizes[num]++;}}
        int p1=0; int p2=1;
        int score = -1;
        pair<int, int> ans;
        while (p2<A.size()) {
            if (sizes[A.at(p2)]<k) {p1=p2+1; p2+=2;}
            else if (sizes[A.at(p1)]<k) {p1=p2; p2++;}
            else {
                if (A.at(p2)-A.at(p1) > score) {ans.first=A.at(p1); ans.second=A.at(p2); score=A.at(p2)-A.at(p1);}
                p2++;}
        }
        if (score<0) {cout << -1 << '\n'; continue;}
        cout << ans.first << ' ' << ans.second << '\n';
    }
}