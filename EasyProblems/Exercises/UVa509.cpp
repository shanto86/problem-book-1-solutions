/**
 * Problem: UVa 509 - RAID!
 * Author: sjsakib
 *
**/
#include <bits/stdc++.h>

using namespace std;

char disks[8][6410];
int d, s, b;
bool parity;

bool read() {
    char p;
    scanf("%d %d %d\n%c\n", &d, &s, &b, &p);
    if (d == 0) return 0;

    parity = (p == 'O');

    for (int i = 0; i < d; i++) {
        scanf("%s", disks[i]);
    }
    return 1;
}

bool valid() {
    for (int i = 0; i < s*b; i++) {
        int k = 0, lost = -1;
        for (int j = 0; j < d; j++) {
            char &c = disks[j][i];
            if (c == '1') k ^= 1;
            else if ( c == 'x') {
                if (lost != -1) return 0;
                lost = j;
            }
        }
        if ( lost == -1 && k != parity ) return 0;
        if (lost != -1) disks[lost][i] = (parity != k) + '0';
    }
    return 1;
}

void printData() {
    int n = 0, cnt = 0;
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < d; j++) {
            if (j == i % d) continue;
            for (int k = 0; k < s; k++) {
                if (disks[j][i*s + k] == '1') n += 1;
                if(++cnt == 4) {
                    printf("%X", n);
                    n = 0;
                    cnt = 0;
                } else {
                    n <<= 1;
                }
            }
        }
    }
    if (cnt) {
        n <<= (3-cnt);
        printf("%X", n);
    }
    printf("\n");
}

int main() {
    int setno = 1;
    while ( read() ) {
        printf("Disk set %d is ", setno++);
        if ( valid() ) {
            printf("valid, contents are: ");
            printData();
        } else printf("invalid.\n");
    }
    return 0;
}