#include <iostream>
#include <algorithm>
using namespace std;


/*
Originally, I knew A and B were idx 0 and 1 sorted respectively,
but did not realize element 6 was A+B+C. Here is my o.g. solution
    for (int i=2; i<nums.size(); i++) {
        int p1 = i-2;
        int p2 = i-1;
        while (nums[p1]+nums[p2] != nums[i] && p2>1) {
            if ( nums[p1] + nums[p2] < nums[i] ) {
                // then no way lowering p1 or p2 will equal curr. val
                cout << A << " " << B << " " << nums[i];
                break;
            }
            if (p1==0) {
                p2--;
                p1 = p2-1;
            }
        }
    }
*/

int main() {
    int nums[7];
    int A, B, C;
    for (int o=0; o<7; o++) {cin >> nums[o];}
    sort(nums, nums+7);
    A = nums[0], B = nums[1];
    C = nums[6] - A - B;
    cout << A << " " << B << " " << C << "\n";
    return 0;
}