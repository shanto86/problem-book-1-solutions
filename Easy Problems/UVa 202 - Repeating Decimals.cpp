/**
 *    problem: UVa 202 Repeating Decimals
 *    author: sjsakib
 *    approach: 
**/
#include <bits/stdc++.h>

using namespace std;

int mem[30007];
vector<int> v;

void repeating(int a, int x) {
    memset(mem, -1, sizeof(mem[0])*3007);
    v.clear();

    printf("%d/%d = ", a, x);
    printf("%d.", a/x);

    a = a % x;
    mem[a] = 1;

    while(1) {
        a *= 10;
        bool found = false;
        while(a && a/x == 0) {
            v.push_back(0);
            if(mem[a] == -1) mem[a] = v.size() + 1;
            else {
                found = true;
                break;
            }
            a *= 10;
        }
        if(found) break;
        v.push_back(a/x);
        a = a % x;
        if(mem[a] != -1) {
            break;
        } else mem[a] = v.size() + 1;
    }

    for (int i = 0; i < v.size(); ++i) {
        if(i == mem[a]-1) printf("(");
        printf("%d",v[i]);
        if(i == 49 && v.size() != 50) {
            printf("...)\n");
            break;
        } else if(i == v.size()-1) printf(")\n");
    }
    printf("   %d = number of digits in repeating cycle\n\n", (int) v.size()-mem[a]+1);
}

int main() {
    int a, x;
    while(scanf("%d %d", &a, &x) != EOF) {
        repeating(a, x);
    }
    return 0;
}