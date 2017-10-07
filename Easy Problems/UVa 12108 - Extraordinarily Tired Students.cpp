/**
 *    problem: UVa 12108 Extraordinarily Tired Students
 *    author: sjsakib
 *    time: lcm(a[i]+b[i])*n
 *    mem: n   
**/
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if(a % b == 0) return b;
    else return gcd(b,a%b);
}

int lcm(int a, int b) {
    return a*b/gcd(a,b);
}

int n;
int arr[13][3];
int status[13];

//Checks how many students are awake and updates their status
//returns true if everyone is awake, false otherwise
bool update() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if(status[i] <= arr[i][0]) count++;
    }
    if(count == n) return true;
    for(int i = 0;i <= n; i++) {
        if(status[i] == arr[i][0]+arr[i][1] || (status[i] == arr[i][0] && n <= count*2)) status[i] = 1;
        else status[i]++;
    }
    return false;
}

int main() {
    int caseno = 1;
    while(1) {
        scanf("%d", &n);
        if(n == 0) break;

        int l = 1; //to hold lcm

        for(int i = 0; i < n; i++) {
            scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
            status[i] = arr[i][2];
            l = lcm(l, arr[i][0]+arr[i][1]);
        }
        
        bool found;
        for( int t = 1; t <= l; t++) {
            found = update();
            if(found) {
                printf("Case %d: %d\n", caseno++, t);
                break;
            }
        }
        if(!found) {
            printf("Case %d: -1\n", caseno++);
        }
    }
    return 0;
}