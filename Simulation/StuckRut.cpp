#include <cstdio>
#include <map>
#include <vector>
#include <set>
using namespace std;

/*
While the 2D grid is considered "infinite", I noticed that cows will only stop
within boundaries, such that the y boundary is the repeated max(y_max) as well as x

The data structures to be used are tentative, but I believe in using map<int, vector<int>> and arr of pairs for each cow
*/

typedef pair<int, int> ppi;

bool allVisited(bool arr[]) {
    bool allTrue = true;
    for (bool x : arr) {
        if (x==false) {return false;}
    }
    return true;
}
//debug now!
int main() {
    int N; scanf("%d", &N);
    int x_max, y_max = 0;  //x, y <= 10**9, which still allows the use of ints
    ppi positions[N]; set<ppi> visited;
    char sides[N];  //or maybe change to int for faster computation
    for (int i=0; i<N; i++) {
        char dir; int x, y;
        scanf("%C %d %d", &dir, &x, &y);
        x_max = max(x_max, x); y_max = max(y_max, y);
        sides[i]=dir;
        positions[i] = {x, y};
    }
    int steps[N]; bool done[N];
    while (!allVisited(done)) {
        //later erase visited to make program run faster

        for (int c=0; c<N; c++) {
            steps[c]++;
            if (sides[c]=='N') {positions[c].second++;}
            else if (sides[c]=='E') {positions[c].first++;}
            if (positions[c].first>x_max || positions[c].second>y_max) {steps[c]=-1; done[c]=true;} //which will print as Infinity
            if (visited.find(positions[c]) != visited.end()) {done[c]=true;}
        }
        //need to update visited after for loop, so two cows can graze at the same time
        for (ppi pos : positions) {
            visited.insert(pos);
        }
    }
    for (int i : steps) {
        if (i<0) {printf("Infinity\n"); continue;}
        printf("%d", i); printf("\n");
    }
}