/**
 * Problem: UVa 10763 - Foreign Exchange
 * Author: sjsakib
 * Approach: Map
 * Number of incoming and outgoing students of a location have to be equal.
**/
#include <cstdio>
#include <map>

using namespace std;

int main() {
    int n,h,d;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        map<int, int> in;
        map<int, int> out;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &h, &d);
            in[h]++;
            out[d]++;
        }
        if (in == out) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}