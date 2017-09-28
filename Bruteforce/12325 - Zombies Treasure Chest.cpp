#include <bits/stdc++.h>
using namespace std;

long long n, s1, v1, s2, v2;

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; tc++)
    {
        scanf("%lld %lld %lld %lld %lld", &n, &s1, &v1, &s2, &v2);

        if(s2 > s1){
            swap(s1, s2);
            swap(v1, v2);
        }

        long long ans = 0;

        if(s1 > sqrt(n)){
            for(int i = 0; i*s1 <= n; i++)
                ans = max(ans, (n - s1*i)/s2 * v2 + v1 * i);
        }

        else{
            if(v1*s2 < v2*s1)
                swap(s1, s2), swap(v1, v2);

            for(int i = 0; i <= s1 && n - s2*i >= 0; i++)
                ans = max(ans, (n - i * s2)/s1 * v1 + i * v2);
        }

        printf("Case #%d: %lld\n", tc, ans);
    }
    return 0;
}
