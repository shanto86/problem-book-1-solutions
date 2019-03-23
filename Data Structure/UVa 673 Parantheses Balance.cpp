#include<bits/stdc++.h>

using namespace std;

void solve(string ex){

   /* if(ex.size()%2){
     cout<<"No\n";
        return;
    }*/

  stack<char> s;
  for (char c : ex) {
  //  cout<<c;
    if      (c == '{') s.push('}');
    else if (c == '[') s.push(']');
    else if (c == '(') s.push(')');
    else {
      if (s.empty() || c != s.top()){
        cout<<"No\n";
        return;
        }
      s.pop();
    }
  }
  cout<<((s.size()==0)?"Yes\n":"No\n");
}



int main(){
 	#ifndef ONLINE_JUDGE
 	    freopen("in.txt","r",stdin);
 	    freopen("out.txt","w",stdout);
 	#endif

 	ios::sync_with_stdio(false);
 	cin.tie(0);cout.tie(0);

	int tc;
    string s;
    cin>>tc;
   // cin>>s;
    getline(cin,s);
    while(tc--){
        //cout<<s<<endl;
        getline(cin,s);
        solve(s);
    }

    return 0;
}
