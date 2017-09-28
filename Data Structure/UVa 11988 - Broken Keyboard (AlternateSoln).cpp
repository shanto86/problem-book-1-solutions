#include <bits/stdc++.h>
using namespace std;

// We keep a long string for all text inserted to end. 
// Whenever we go to first, we start start an empty string 
// and again when we go to last we end the string and store this piece of string.
// At last we print the beginning pieces of strings, then everything inserted t end
int main() {
    string str;
    while(getline(cin, str)) {
        string res = ""; bool go = 0;
        string tmp = ""; 
        vector<string> v;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '[') {
                if(go == 1) 
                    v.push_back(tmp), tmp = "";
                go = 1;
                continue;
            }
            if(str[i] == ']') {
                v.push_back(tmp);
                tmp = ""; go = 0;
                continue;
            }
            if(go) tmp += str[i];
            else res += str[i];
        } v.push_back(tmp);
        for(int i = v.size() - 1; i >= 0; i--)
            cout << v[i];
        cout << res << endl;
    }
}