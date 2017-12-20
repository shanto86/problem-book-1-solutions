/**
 * Problem: UVa 12100 - Printer Queue
 * Author: sjsakib
 * Approach: priority queue
**/
#include <cstdio>
#include <queue>

using namespace std;

struct Job {
    int i;
    int p;

    Job(int i_, int p_) {
        i = i_;
        p = p_;
    }
};

bool operator<(Job a, Job b) {
    return a.p < b.p;
}

priority_queue<Job> pq;
queue<Job> q;

int main() {
    int t,n,m,p;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &n, &m);
        for (int k = 0; k < n; k++) {
            scanf("%d", &p);
            Job j(k, p);
            q.push(j);
            pq.push(j);
        }
        int t = 0;
        while (1) {
            if(q.front().p == pq.top().p) {
                if(q.front().i == m) break;
                q.pop();
                pq.pop();
                t++;

            } else {
                q.push(q.front());
                q.pop();
            }
        }
        printf("%d\n", t+1);
        q = queue<Job>();
        pq = priority_queue<Job>();
    }
    return 0;
}