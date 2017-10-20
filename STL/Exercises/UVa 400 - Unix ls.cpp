/**
 * Problem: UVa 400 - Unix ls
 * Author: sjsakib
 *
**/
#include <bits/stdc++.h>

using namespace std;

string lst[1010];

int n,max_len;

void read() {
    char buff[62];
    max_len = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s\n", buff);
        lst[i] = string(buff);
        max_len = max(max_len, (int) lst[i].length());
    }
    sort(lst, lst + n);
}

void print() {
    int cols = 62 / (max_len + 2);
    int rows = (int) ceil(n / (float) cols);
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int pos = j*rows + i;
            int len = ((j == cols-1)?max_len:max_len+2);
            if(pos < n) printf("%-*s", len, lst[pos].c_str());
        }
        printf("\n");
    }
}

int main() {
    while(scanf("%d", &n) != EOF) {
        read();
        print();
    }
}