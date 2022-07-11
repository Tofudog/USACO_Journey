#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> x; vector<int> y; int temp;
    for (int i=0; i<N; i++) {cin >> temp; x.push_back(temp);}
    for (int i=0; i<N; i++) {cin >> temp; y.push_back(temp);}
    int high = 0;
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            int curr = pow((x[j]-x[i]),2) + pow((y[j]-y[i]),2);
            high = max(curr, high);
        }
    }
    cout << high << '\n';
}