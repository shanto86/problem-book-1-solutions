/**
 * Problem: UVa 10763 - Foreign Exchange
 * Author: sjsakib
 * Approach: Vector
 * Number of incoming and outgoing students of a location have to be equal.
**/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,h,d;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        vector<pair<int, int> > v;
        vector<pair<int, int> > rv;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &h, &d);
            v.push_back(make_pair(h, d));
            rv.push_back(make_pair(d,h));
        }
        sort(v.begin(), v.end());
        sort(rv.begin(), rv.end());
        if (v == rv) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}