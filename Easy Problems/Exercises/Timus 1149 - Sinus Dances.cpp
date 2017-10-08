/**
 * Problem: Timus 1149 - Sinus Dances
 * Author: sjsakib
 *
**/
#include <bits/stdc++.h>

#define MAX 100

using namespace std;

string a[MAX+5];

string get_a(int n) {
    string ret = "sin(" + to_string(n) + ")";
    while(--n) {
        ret = "sin(" + to_string(n) + (n&1?"-":"+") + ret + ")";
    }
    return ret;
}

string get_s(int n) {
    string ret = "sin(1)+" + to_string(n);
    for (int i = 2,j = n-1; i <= n; i++,j--) {
        ret = "(" + ret + ")" + get_a(i) + "+" + to_string(j);
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%s\n", get_s(n).c_str());
}