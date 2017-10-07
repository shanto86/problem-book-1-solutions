/**
 *    problem: UVa 10815 Andy's First Dictionary
 *    author: sjsakib
**/
#include <bits/stdc++.h>

using namespace std;

void clean(char line[]) {
    int i = 0;
    while(line[i] != '\0') {
        line[i] = tolower(line[i]);
        if(!isalpha(line[i])) line[i] = ' ';
        i++;
    }
}


int main() {
    ios::sync_with_stdio(false);
    char line[210];
    string w;
    set<string> dict;
    while(gets(line)) {
        clean(line);
        istringstream iS(line);
        while(iS>>w) {
            dict.insert(w);
        }
    }
    for(auto w: dict) {
        cout<<w<<endl;
    }
    return 0;
}