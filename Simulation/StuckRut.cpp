#include <cstdio>
#include <map>
#include <vector>
using namespace std;

/*
While the 2D grid is considered "infinite", I noticed that cows will only stop
within boundaries, such that the y boundary is the repeated max(y_max) as well as x

The data structures to be used are tentative, but I believe in using map<int, vector<int>> and arr of pairs for each cow
*/

//going to Church now... to be solved... made significant progress
int main() {
    int N; scanf("%d", &N);
    int x_max, y_max = 0;  //x, y <= 10**9, which still allows the use of ints
    for (int i=0; i<N; i++) {
        char dir; int x, y;
        scanf("%C %d %d", &dir, &x, &y);
        x_max = max(x_max, x); y_max = max(y_max, y)
    }
    int ans[N];

}