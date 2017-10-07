/**
 *    problem: UVa 253 Cube painting
 *    author: sjsakib
**/
#include <bits/stdc++.h>

using namespace std;

char s[14];

bool eq() {
    for(int i = 0;i<6;i++) {
        if(s[i] != s[i+6]) return false;
    }
    return true;
}
void rotateZ() {
    char tmp = s[1];
    s[1] = s[3];
    s[3] = s[4];
    s[4] = s[2];
    s[2] = tmp;
}
void rotateX() {
    char tmp = s[0];
    s[0] = s[1];
    s[1] = s[5];
    s[5] = s[4];
    s[4] = tmp;
}

int main() {
    while(scanf("%s\n", s) != EOF) {
        bool same;
        for(int i = 0; i < 6; i++) {
            same = eq();
            if(same) break;
            else if(i < 4) rotateX();
            else if(i == 4) {
                rotateZ();
                rotateX();
            } else {
                rotateX();
                rotateX();
            }
            for(int j = 0;j < 4; j++) {
                same = eq();

                if(same) break;
                else rotateZ();
            }
            if(same) break;
        }
        if(same) printf("TRUE\n");
        else printf("FALSE\n");
    }
    return 0;
}