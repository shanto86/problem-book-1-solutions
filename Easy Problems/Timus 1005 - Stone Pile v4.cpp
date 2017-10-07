/**
 *    problem: Timus 1005 Stone Pile
 *    author: sjsakib
 *    approach: bitmask time: O(n * 2^n)
**/
#include <bits/stdc++.h>

using namespace std;

int n, num[22], sum=0, ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    ans = sum;
    for (int mask = 0; mask < (1<<n); mask++) {
        int s = 0;
        for (int j = 0; j < n; ++j) {
            if((1<<j)&mask) s += num[j];
        }
        ans = min(ans, abs(sum-s*2));
    }
    printf("%d\n",ans);
    return 0;
}