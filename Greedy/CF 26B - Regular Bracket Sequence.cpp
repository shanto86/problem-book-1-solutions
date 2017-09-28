#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

int main(int argc, char const *argv[]) {
    #ifdef LOCAL_TESTING
        freopen("in", "r", stdin);
    #endif
    string s; cin >> s;
    int cnt = 0, ans = 0;
    for(char c : s) {
        if(c == '(') cnt++;
        else if(cnt) cnt--, ans += 2;
    } cout << ans << endl;
}   
