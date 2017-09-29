#include  <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int g[105][105];

int main() {
    bool flag = false; int co=0;
    while(1) {
    	int c, l, q;
    	scanf("%d %d %d", &c, &l, &q); 
        if(!c && !l && !q) break;
        
        for(int i = 0; i <= c; i++){
        	for(int j = 0; j <= c; j++){
        		g[i][j] = inf;
        	}
        }
        int a, b, cost;
        for(int i = 0; i < l; i++) {
        	scanf("%d %d %d", &a, &b, &cost);
            g[a][b] = g[b][a] = cost;
        }

        for(int k = 1;k <= c; k++) 
            for(int i = 1;i <= c; i++) 
                for(int j = 1;j <= c; j++) 
                    g[i][j] = min(g[i][j], max(g[i][k], g[k][j]));
        
        if(flag) puts("");
        flag = true;

        printf("Case #%d\n",++co);

        for(int i = 0;i < q; i++) {
        	scanf("%d %d", &a, &b);
            if(g[a][b] == inf) puts("no path");
            else printf("%d\n", g[a][b]);
        }
    }
}
