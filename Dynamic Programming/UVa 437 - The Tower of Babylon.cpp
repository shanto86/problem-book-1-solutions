//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

struct box {
	int x,y,z;
	bool operator < ( const box &p) const {
		return pair<ii,int>{{x,y},{z}} < pair<ii,int>{{p.x,p.y},p.z};
	}
}; 

ll dp[111111];
int main(int argc, char const *argv[]) {
	int n, co = 0; 
	while(cin >> n && n) {
		vector<box> v; 
		for(int i = 0; i < n; i++) {
			vector<int> tmp(3);
			cin >> tmp[0] >> tmp[1] >> tmp[2];
			sort(tmp.begin(), tmp.end());
			do{
				v.push_back({tmp[0], tmp[1], tmp[2]});
			} while(next_permutation(tmp.begin(), tmp.end()));
		} sort(v.begin(), v.end()); 
		n = v.size(); ll ans = 0;
		for(int i = 0; i < n; i++) {
			dp[i] = v[i].z;
			for(int j = 0; j < i; j++) 
				if((v[i].x > v[j].x && v[i].y > v[j].y) || 
					(v[i].y > v[j].x && v[i].x > v[j].y))
					dp[i] = max(dp[i], dp[j] + v[i].z);
			ans = max(ans, dp[i]);
		} cout << "Case " << ++co << ": maximum height = " << ans << endl;
	}
}