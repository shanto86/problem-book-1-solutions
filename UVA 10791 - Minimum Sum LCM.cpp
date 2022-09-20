//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;


int main(){ 

    ll n, cs = 1;
    
    while(1){
        cin >> n;
        if(n == 0) break;

        vector < ll > pf; // prime factors

        ll nn = n;

        for(ll i = 2; i*i <= n; i++){
            if(n % i == 0){
                ll x = 1;
                while(n % i == 0){
                    n /= i;
                    x *= i;
                }
                pf.push_back(x);
            }
        }
        if(n > 1){
            pf.push_back(n);
        }

        ll ans = 0;
        for(auto x: pf){
            ans += x;
        }
        
        cout << "Case "<<cs<<": ";
        cs++;
        if(pf.size() == 1){
            cout << ans+1 << endl;
        }
        else (ans != 0) ? cout << ans << endl : cout << 2 << endl;

    }



    return 0;
}