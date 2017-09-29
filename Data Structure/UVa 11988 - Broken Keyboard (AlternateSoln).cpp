#include <bits/stdc++.h>
using namespace std;

// We keep a long string 'res', this will store everything inserted to end. 
// When we go to beginning, we satar another small string, and grow that untill
// we go to end. Store these pieces of string and at last print them first. Then 
// Print the long string. 

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