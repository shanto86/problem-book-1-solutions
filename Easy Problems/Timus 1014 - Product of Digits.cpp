/**
 *    problem: Timus 1014 Product of Digits
 *    author: sjsakib
 *    approach: Greedy, time: O(n)
**/
#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    vector<int> ans;
    if(n == 1) {
        printf("1\n");
        return 0;
    } else if(n == 0) {
        printf("10\n");
        return 0;
    }
    for(int i = 9;i >= 2;--i) {
        while(n % i == 0) {
            n /= i;
            ans.push_back(i);
        }
    }
    if(n == 1) {
        for (int i = ans.size()-1; i >= 0; --i) {
            printf("%d", ans[i]);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }
    return 0;
}