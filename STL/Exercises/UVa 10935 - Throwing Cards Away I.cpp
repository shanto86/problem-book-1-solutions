/**
 * Problem: UVa 10935 - Throwing Cards Away I
 * Author: sjsakib
 * Approach: Deque
**/
#include <cstdio>
#include <deque>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            dq.push_back(i+1);
        }
        printf("Discarded cards:");
        while (dq.size() > 1) {
            printf(" %d", dq.front());
            dq.pop_front();
            if(dq.size() != 1) printf(",");
            dq.push_back(dq.front());
            dq.pop_front();
        }
        printf("\nRemaining card: %d\n", dq.front());
    }
    return 0;
}