/**
 * Problem: UVa 1595 - Symmetry
 * Author: sjsakib
 * Approach: Vector
 *
**/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t,n,x,y;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        vector<pair<int, int> > v(n);
        for (int j = 0; j < n; j++) {
            scanf("%d %d", &x, &y);
            v[j] = make_pair(x*2, y);  // multiplying by 2 to avoid fraction later
        }
        sort(v.begin(), v.end());
        int mid = v[0].first + (v[n-1].first - v[0].first)/2;
        int mx = v[n-1].first;
        int mn = v[0].first;
        vector<pair<int, int> > vl,vr;
        for (int j = 0; j < n; j++) {
            if(v[j].first < mid) vl.push_back(make_pair(v[j].first-mn, v[j].second));
            else if(v[j].first > mid) vr.push_back(make_pair(mx-v[j].first, v[j].second));
        }
        sort(vr.begin(), vr.end());
        if(vl == vr) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
