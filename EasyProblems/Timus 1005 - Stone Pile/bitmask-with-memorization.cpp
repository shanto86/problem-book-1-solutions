/**
 *    problem: Timus 1005 Stone Pile
 *    author: sjsakib
 *    approach: bitmask with memorization time: O(2^n), mem: O(2^n)
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
    int mem[(1<<n) + 10];
    mem[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int mask = 1<<i; mask < (1<<(i+1)); mask++) {
            mem[mask] = mem[mask ^ (1<<i)] + num[i];
            ans = min(ans, abs((sum - mem[mask]*2)));
        }
    }
    printf("%d\n",ans);
    return 0;
}