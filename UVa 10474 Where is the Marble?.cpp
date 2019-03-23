#include<bits/stdc++.h>

using namespace std;

int main(){
 	#ifndef ONLINE_JUDGE
 	    freopen("in.txt","r",stdin);
 	    freopen("out.txt","w",stdout);
 	#endif

 	ios::sync_with_stdio(false);
 	cin.tie(0);cout.tie(0);

 	int n,q,t,tc(1);
 	while(cin>>n>>q and n and q){
 		vector<int>lst;

 		cout<<"CASE# "<<tc++<<":\n";

 		for(int i=0; i<n; ++i)
 			cin>>t, lst.push_back(t);

 		sort(lst.begin(), lst.end());

 		while(q--){

 			cin>>t;

 			int pos = find(lst.begin(), lst.end(),t) - lst.begin() +1;

 			pos<=n?cout<<t<<" found at "<<pos<<endl:cout<<t<<" not found"<<endl;
 		}
 	}
 	
return 0;
}
