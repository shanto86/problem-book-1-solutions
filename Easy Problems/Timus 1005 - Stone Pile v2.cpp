/**
 *    problem: Timus 1005 Stone Pile
 *    author: sjsakib
 *    approach: coin change dp time: O(total*n)
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int arr[22];
    int sum = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int ans = sum;
    bool dp[sum+1];
    memset(dp, 0, sum);
    dp[0] = 1;
    for (int j = 1; j < n; j++) {
        for (int i = sum; i >= 1; i--) {
            if(i >= arr[j] && dp[i - arr[j]]) {
                dp[i] = 1;
                ans = min(ans, abs(sum- i*2));
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}