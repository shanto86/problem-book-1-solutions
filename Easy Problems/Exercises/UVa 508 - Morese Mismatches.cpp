/**
 * Problem: UVa 508 - Morse Mismatch
 * Author: sjsakib
 *
 * Tip: Just ignore the second sentence from the fourth paragraph
**/
#include <bits/stdc++.h>

using namespace std;

map<char, string> mp;
map<string, string> dict;

string get_code(string s) {
    int k = 0;
    string code;
    while(s[k] != '\0') {
        code += mp[s[k]];
        k++;
    }
    return code; 
}

void read() {
    string s1,s2;
    while(cin>>s1 && s1 != "*") {
        cin>>s2;
        mp[s1[0]] = string(s2);
    }
    while(cin>>s1 && s1 != "*") {
        dict[s1] = get_code(s1);
    }
}

int get_diff(string s1, string s2) {
    int k = 0;
    while(s1[k] == s2[k] && s1[k] != '\0' && s2[k] != '\0')  k++;
    
    if ( k < (int) min(s1.length(), s2.length())) return -1;
    
    return max(s1.length(), s2.length()) - k;
}

void answer() {
    string code;
    while(cin>>code && code != "*") {
        int mn = 1e8;
        string ans;
        for (auto w: dict) {

            int diff = get_diff(w.second, code);
            if (diff == -1) continue;
            if (diff < mn) {
                mn = diff;
                ans = w.first;
            } else if(mn == 0 && mn == diff) {
                ans += '!';
                break;
            }
        }
        if(mn) ans += '?';
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    read();
    answer();
    return 0;
}