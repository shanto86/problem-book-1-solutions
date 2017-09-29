#include <bits/stdc++.h>
using namespace std;

int N;
bool flag = false;

int main() {
    while(cin >> N && N) {
        if(flag) puts(""); flag = true;
        bool found = false;
        for(int fghij = 1234; fghij <= 98765 / N; fghij++) {
            int used = (fghij < 10000), tmp;
            int abcde = fghij*N;
            tmp = abcde; 
            while(tmp > 0) {
                used |= 1 << (tmp % 10); 
                tmp /= 10; 
            }
            tmp = fghij; 
            while(tmp > 0) {
                used |= 1 << (tmp % 10); 
                tmp /= 10;
            }
            if(used == (1 << 10) - 1) {
                found = true;
                printf("%0.5d / %0.5d = %d\n", abcde, fghij, N);
            }
        }
        if(!found) printf("There are no solutions for %d.\n", N);
    }
}
