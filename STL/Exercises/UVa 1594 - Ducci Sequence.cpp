/**
 * Problem: UVa 1594 - Ducci Sequence
 * Author: sjsakib
 * Approach: Simple Loop
 * We get our cycle in 50 steps if we are to get. But why? I just gave up. Please let me know if you find out.
**/
#include <stdio.h>
#include <stdlib.h>

int arr[16];

int main() {
    int t,n,head;
    int all;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
        for (int j = 0; j < 50; j++) {
            all = 1;
            head = arr[0];
            for (int k = 0; k < n-1; k++) {
                arr[k] = abs(arr[k] - arr[(k+1) % n]);
                all &= !arr[k];
            }
            arr[n-1] = abs(arr[n-1] - head);
            all &= !arr[n-1];
            if(all) break;
        }
        if(!all) printf("LOOP\n");
        else printf("ZERO\n");
    }

    return 0;
}