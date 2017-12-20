/**
 * Problem: UVa 12333 - Revenge of Fibonacci
 * Author: sjsakib
 * Approach: Bruteforce
 * Takes almost a minute on my own machine, but somehow manages to get ac
**/
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

map<string, int> fibs;

string add(string& a, string& b) {
    int i = (int) a.length() - 1;
    int j = (int) b.length() - 1;
    int k = max(i,j);
    int x,y,rem=0;
    string res(k+1, '0'); 
    while(i >= 0 && j >= 0) {
        x = a[i] - '0';
        y = b[j] - '0';
        res[k] = (char) ((x+y+rem)%10 + '0');
        rem = (x+y+rem)/10;
        i--;
        j--;
        k--;
    }
    while (i >= 0) {
        x = a[i] - '0';
        res[k] = (char) ((x+rem)%10 + '0');
        rem = (x+rem)/10;
        i--;
        k--;
    }
    while (j >= 0) {
        x = b[j] - '0';
        res[k] = (char) ((x+rem)%10 + '0');
        rem = (x+rem)/10;
        j--;
        k--;
    }
    if(rem) res = (char) (rem + '0') + res;
    return res;

}

void gen_fibs() {
    string a = "1", b = "1";
    string f;
    fibs["1"] = 0;
    for (int i = 2; i < 100000; i++) {
        f = add(a, b);
        a = b;
        b = f;
        for (int j = 0; j < 51; j++) {
            if(j > (int) f.length()) break;
            string sub = f.substr(0,j);
            if(fibs.count(sub) == 0) fibs[sub] = i;
        }
    }
}

int main() {
    gen_fibs();
    int t;
    scanf("%d", &t);
    char s[55];
    for (int i = 0; i < t; i++) {
        printf("Case #%d: ", i+1);
        scanf("%s", s);
        if(fibs.count(s) != 0) printf("%d\n", fibs[s]);
        else printf("-1\n");
    }
    return 0;
}