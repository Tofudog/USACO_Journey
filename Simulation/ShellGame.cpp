#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;

//Overall time complexity is linear: O(N), beating linear 3*N
int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int N;
    cin >> N;
    int shells[] = {0, 1, 2};
    unordered_map<int, int> scores;
    scores[0] = 0;
    scores[1] = 0;
    scores[2] = 0;
    for (int L=0; L<N; L++) {
        int a, b, g;
        cin >> a >> b >> g;
        int temp = shells[b-1];
        shells[b-1] = shells[a-1];
        shells[a-1] = temp;
        scores[ shells[g-1] ]++;
    }
    cout << max(scores[0], max(scores[1], scores[2]));
    return 0;
}