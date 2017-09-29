#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

int main() {
    int n; while(scanf("%d", &n) && n) {
        ll ans = 0, x, y;
        priority_queue<int, vector<int>, greater<int> > q;
        for(int i = 0; i < n; ++i) scanf("%d", &x), q.push(x);
        while(q.size() > 1){
            x = q.top(); q.pop();
            y = q.top(); q.pop();
            ans += (x += y);
            if(q.empty()) break;
            q.push(x);
        }
        printf("%lld\n", ans);
    }
}
