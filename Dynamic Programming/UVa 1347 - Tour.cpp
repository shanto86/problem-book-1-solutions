#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

struct point {
	double x, y; 
	double dist(point &p) {
		return hypot(x - p.x, y - p.y);
	}
} p[1111];

double dp[1010][1010];
bool vis[1010][1010];
int n; 

double call(int i, int j) {
	if(i == n-1 && j == n-1) return 0;
	if(j == n - 1) 
		return call(i + 1, j) + p[i].dist(p[i + 1]);
	if(i == n - 1) 
		return call(i, j + 1) + p[j].dist(p[j + 1]);
	if(vis[i][j]) return dp[i][j];

	int k = max(i, j) + 1;
	vis[i][j] = 1; 
	return dp[i][j] = min(call(k, j) + p[i].dist(p[k]),
						  call(i, k) + p[j].dist(p[k])); 
	
}
int main(int argc, char const *argv[]) {
	while(scanf("%d", &n) == 1) {
		for(int i = 0; i < n; i++){
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		memset(vis, 0, sizeof vis);
		printf("%.2f\n", call(0, 0));
	}

}