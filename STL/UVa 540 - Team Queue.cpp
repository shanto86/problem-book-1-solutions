#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(int argc, char const *argv[]) {
	int n, co = 0; 
	while(cin >> n && n) {
		queue<int> teamQ[n+1], mainQ;
		map<int,int> teamNo;
		for(int i=0; i<n; i++) {
			int m, num; cin>>m; 
			while(m--) {
				cin>>num;
				teamNo[num] = i;
			}
		} 
		cout << "Scenario #" << ++co << endl;
		string cmd; 
		while(cin >> cmd) {
			if(cmd[0] == 'S') break;
			else if(cmd[0] == 'E') {
				int id; cin >> id;
				int tm = teamNo[id];
				teamQ[tm].push(id);
				if(teamQ[tm].size() == 1) 
					mainQ.push(tm);
			} else {
				int tm = mainQ.front();
				cout << teamQ[tm].front() << endl;
				teamQ[tm].pop();
				if(!teamQ[tm].size())
					mainQ.pop();
			}
		} cout << endl;
	}
} 
