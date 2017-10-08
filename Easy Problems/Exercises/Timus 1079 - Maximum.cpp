/**
 * Problem: Timus 1079 - Maximum
 * Author: sjsakib
 *
**/
#include <bits/stdc++.h>

#define MAX 99999

using namespace std;

int arr[MAX+5];

void cal() {
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <= MAX; i++) {
        if(i&1) arr[i] = arr[i/2] + arr[i/2 + 1];
        else arr[i] = arr[i/2];
    }
    for (int i = 2; i <= MAX; i++) arr[i] = max(arr[i], arr[i-1]);
}

int main() {
    cal();
    int n;
    while(scanf("%d", &n) && n != 0) printf("%d\n", arr[n]);
}