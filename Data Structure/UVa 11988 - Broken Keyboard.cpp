#include <bits/stdc++.h>
using namespace std;
int main() {
    char line[100100];
    while(scanf("%s",line) != EOF) {
        list<char> l;
        list<char>::iterator it = l.begin();
        int len = strlen(line);
        for(int i = 0; i < len; i++) {
            if(line[i] == '[') it = l.begin();
            else if (line[i] == ']') it = l.end();
            else l.insert(it,line[i]);
        }
        for(it = l.begin(); it!=l.end(); it++) 
        	printf("%c",*it);
        puts("");
    }
}
