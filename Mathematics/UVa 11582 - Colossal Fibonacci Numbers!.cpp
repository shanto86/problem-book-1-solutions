/**
 * Author: sjsakib
 * Problem: UVa 11582 - Colossal Fibonacci Numbers!
 * Approach: Cycle + Matrix Exponent + DP
 * এখানে ম্যাট্রিক্স এক্সপোনেন্টের বদলে একটি ফর্মুলা ব্যবহার করা হয়েছে যেটি ম্যাট্রিক্স এক্সপোনেন্ট থেকে পাওয়া যায়।
 * কম্প্লেক্সিটি এক হলেও এটার কোড অনেক সিম্পল।
**/
#include <stdio.h>
#include <string.h>
#include <vector>

#define MAX 1000

using namespace std;

vector<int> cycles[MAX+10];

int mem[3009][1009];

int bigmod(unsigned long long a, unsigned long long b, int n) {
    a = a % n;
    int ret = 1;
    while (b > 0) {
        if (b & 1) ret = (ret * a) % n;
        a = (a*a) % n;
        b /= 2;
    }
    return ret;
}

int fib(int i, int n) {
    if(i == 0) return 0;
    if (i<3) return 1;
    if (mem[i][n] != -1) return mem[i][n];
    int k;
    int ret;
    if(!(i&1)) {
        k = i/2;
        int fk = fib(k, n);
        ret = ((2*fib(k-1, n) + fk)*fk) % n;
    } else {
        k = (i+1)/2;
        int fk1 = fib(k-1, n);
        int fk = fib(k, n);
        ret = (fk*fk + fk1*fk1) % n;
    }
    mem[i][n] = ret;
    return ret;
}

void gen_cycles() {
    memset(mem, -1, sizeof(mem[0])*3009);
    cycles[1].push_back(0);
    for (int n = 2; n <= MAX; n++) {
        int i = 0;
        cycles[n].push_back(fib(i++, n));
        cycles[n].push_back(fib(i++, n));
        cycles[n].push_back(fib(i++, n));
        while(!(cycles[n][0] == cycles[n][cycles[n].size()-2] && cycles[n][1] == cycles[n].back())) {
            cycles[n].push_back(fib(i++, n));
        }
        cycles[n].pop_back();
        cycles[n].pop_back();
    }
}

int main() {
    int t,n;
    unsigned long long a,b;
    gen_cycles();
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%llu %llu %d", &a, &b, &n);
        int c = cycles[n].size();
        printf("%d\n", cycles[n][bigmod(a, b, c)]);
    }
    return 0;
}
