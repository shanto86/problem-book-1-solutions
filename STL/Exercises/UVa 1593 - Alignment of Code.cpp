/**
 * Problem: UVa 1593 - Alignment of Code
 * Author: sjsakib
 * Approach: C++ STL
**/
#include <stdio.h>
#include <sstream>
#include <vector>

using namespace std;

vector<string> lines[1000];
int  width[185];

int main() {
    char buff[185];
    int i = 0;
    while(gets(buff) != NULL) {
        istringstream is(buff);
        string word;
        int k = 0;
        while(is >> word) {
            lines[i].push_back(word);
            width[k] = max(width[k], (int) word.length());
            k++;
        }
        i++;
    }
    for (int k = 0; k < i; k++) {
        for(int l = 0; l < (int) lines[k].size(); l++) {
            int w = l!=lines[k].size()-1?width[l]+1:lines[k][l].size();
            printf("%-*s",w, lines[k][l].c_str());
        }
        printf("\n");
    }
    return 0;
}