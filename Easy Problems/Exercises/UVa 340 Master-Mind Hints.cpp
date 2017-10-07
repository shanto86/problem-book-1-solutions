/**
 * Problem: UVa 340 - Master-Mind Hints
 * Author: sjsakib
 *
**/
#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        int g;
        map<int, int> mp;
        bool strong[n];
        memset(strong, 0, sizeof(strong[0])*n);
        int s=0,w=0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &g);
            if(g == arr[i]) {
                s += 1;
                strong[i]++;
            }
            else mp[g]++;
        }
        if (g == 0) return;
        for (int i = 0; i < n; i++) {
            if(!strong[i] && mp.find(arr[i]) != mp.end() && mp[arr[i]]) {
                mp[arr[i]]--;
                w++;
            }
        }
        printf("    (%d,%d)\n", s, w);
    }
}

int main() {
    int t=1,n;
    while(scanf("%d", &n) && n != 0) {
        printf("Game %d:\n", t++);
        solve(n);
    }
    return 0;
}