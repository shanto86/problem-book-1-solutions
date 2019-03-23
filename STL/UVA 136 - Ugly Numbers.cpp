#include<bits/stdc++.h>

using namespace std;

int main(){
 	#ifndef ONLINE_JUDGE
 	    freopen("in.txt","r",stdin);
 	    freopen("out.txt","w",stdout);
 	#endif

 	ios::sync_with_stdio(false);
 	cin.tie(0);cout.tie(0);

 	set<long>number;
 	
 	number.insert(1);
 	int cnt(1);
 	long i;
 	while(cnt<=1500){
 		cnt++;
 		i = *number.begin();
 	//	cout<<i<<endl;
 		number.erase(i);
 		number.insert(i*2), number.insert(i*3), number.insert(i*5);
 	}

 	//for(auto x: number)
 	//	cout<<x<<"\t";

 	cout<<"The 1500'th ugly number is "<<i<<"."<<endl;
return 0;
}
