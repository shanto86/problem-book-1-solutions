/**
 * Problem: UVa 1596 - Bug Hunt
 * Author: sjsakib
 * Approach: Implementation
**/
#include <cstdio>
#include <map>
#include <string>
#include <cctype>

using namespace std;

struct arr { int len; map<long, long> values; };

map<char, arr> all;

long evaluate(char* line, int &i) {
    if(isdigit(line[i])) {
        int n = line[i++] - '0';
        while(isdigit(line[i])) {
            n = n*10 + (line[i++] - '0');
        }
        return n;
    }
    char sym = line[i];
    i+=2;
    long n = evaluate(line, i);
    i++;
    if(all[sym].len > n && all[sym].values.find(n) != all[sym].values.end()) return all[sym].values[n];
    else return -1;
}

int main() {
    char line[85];
    int l=1,err=0;
    while(fgets(line, 84, stdin)) {
        if (line[0] == '.') {
            if(l == 1) break;
            printf("%d\n", err);
            all.clear();
            l=1;
            err=0;
            continue;
        }
        if(err) continue;
        char sym = line[0];
        int i = 2;
        long n = evaluate(line, i);
        if(n == -1) {
            err = l;
            continue;
        }
        if (line[++i] == '=') {
            if(n >= all[sym].len) {
                err = l;
                continue;
            }
            long val = evaluate(line, ++i);
            if(val == -1) {
                err = l;
                continue;
            }
            all[sym].values[n] = val;
        }
        else {
            all[sym] = arr();
            all[sym].len = n;
        }
        l++;
    }
    return 0;
}
