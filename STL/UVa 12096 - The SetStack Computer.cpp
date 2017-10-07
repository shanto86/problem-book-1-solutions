/**
 *    problem: UVa 12096 The SetStack Computer
 *    author: sjsakib
 *    approach: 
**/
#include <bits/stdc++.h>

using namespace std;

set<int> operator|(set<int> s1, set<int> s2) {
    set<int> ret;
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), ::inserter(ret,ret.begin()));
    return ret;
}

set<int> operator&(set<int> s1, set<int> s2) {
    set<int> ret;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), ::inserter(ret,ret.begin()));
    return ret;
}


map<int, set<int> > mp;
map<set<int>, int> rmp;
stack<int> stc;

int idCount;

void push() {
    if(idCount == 0) {
        set<int> s;
        mp[0] = s;
        rmp[s] = 0;
    }
    stc.push(0);
}

void dup() {
    stc.push(stc.top());
}

void exec(int op) {
    int id1 = stc.top();
    stc.pop();
    int id2 = stc.top();
    stc.pop();
    set<int> s1 = mp[id1];
    set<int> s2 = mp[id2];
    set<int> s;
    if (op == 1)  s = s1 | s2;
    else if (op == 2) s = s1 & s2;
    else {
        s2.insert(id1);
        s = s2;
    }
    if(rmp.find(s) == rmp.end()) {
        stc.push(++idCount);
        mp[idCount] = s;
        rmp[s] = idCount;
    } else {
        stc.push(rmp[s]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n,k;
    string cmd;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>k;
        for (int j = 0; j < k; j++) {
            cin>>cmd;
            if(cmd == "PUSH") push();
            else if(cmd == "DUP") dup();
            else if(cmd == "UNION") exec(1);
            else if(cmd == "INTERSECT") exec(2);
            else exec(3);
            cout<<mp[stc.top()].size()<<endl;
        }
        cout<<"***"<<endl;

    }
    return 0;
}