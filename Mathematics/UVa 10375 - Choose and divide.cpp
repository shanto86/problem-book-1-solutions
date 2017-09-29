#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	int p, q, r, s;
	while(scanf("%d %d %d %d", &p, &q, &r, &s) != EOF) {
		long double ans = 1.0;
		q = min(q, p - q); p = p - q + 1;
		s = min(s, r - s); r = r - s + 1;
		for(int i = 1; i <= q; i++, p++) 
			ans *= (double) p, 
			ans /= (double) i;
		for(int i = 1; i <= s; i++, r++) 
			ans *= (double) i,
			ans /= (double) r;
		cout << fixed << setprecision(5) << ans << endl;
	}
}
 
