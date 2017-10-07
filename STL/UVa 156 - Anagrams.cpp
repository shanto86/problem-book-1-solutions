/**
 *    problem: UVa 156 Anagrams
 *    author: sjsakib
 *    approach: 
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    map<string, int> count;
    string w;
    vector<string> words;
    while (cin>>w) {
        if(w == "#") break;
        words.push_back(w);
        transform(w.begin(), w.end(), w.begin(), ::tolower);
        sort(w.begin(), w.end());
        count[w]++;
    }
    vector<string> ans;
    for(auto word: words) {
        string w = word;
        transform(w.begin(), w.end(), w.begin(), ::tolower);
        sort(w.begin(), w.end());
        if(count[w] == 1) {
            ans.push_back(word);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto w: ans) {
        cout<<w<<endl;
    }
    return 0;
}