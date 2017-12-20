/**
 * Problem: UVa 822 - Queue and A
 * Author: sjsakib
 * Approach: Bruteforce
**/
#include <cstdio>
#include <vector>

using namespace std;

struct topic {
    int id;
    int reqs;  // Total number of requests
    int next;  // When next request will come
    int time; // Time required to handle a request
    int gap;  // Gap between requests
    int active;  // Active tilL
    int waiting;  // Number of requests waiting to be handled

    topic(int id_, int num_reqs_, int start_, int time_, int gap_) {
        id = id_;
        reqs = num_reqs_;
        next = start_;
        time = time_;
        gap = gap_;
        waiting = 0;
        active = 0;
    }

};

struct staff {
    int id;
    vector<int> topics;
    int busy;  // Busy till

    staff(int id_) {
        id = id_;
        busy = 0;
    }
};
vector<topic> topics;
vector<staff> staffs;

void assign(topic& tp, int t, bool is_wait) {
    int idx = -1;
    int pr = 100;  // priority
    for (int i = 0; i < (int) staffs.size(); i++) {
        if(staffs[i].busy > t) continue;
        int tpidx = -1;
        for (int k = 0; k < (int) staffs[i].topics.size(); k++) {
            if (staffs[i].topics[k] == tp.id) {
                tpidx = k;
                break;
            }
        }
        if(tpidx == -1) continue;
        if (tpidx < pr) {
            pr = tpidx;
            idx = i;
        } else if (tpidx == pr) {
            if (staffs[i].busy < staffs[idx].busy) {
                idx = i;
            }
        }
    }
    if(!is_wait) {
        tp.next += tp.gap;
        tp.reqs--;
    }
    if(idx == -1 && !is_wait) {
        tp.waiting++;
    }
    if (idx != -1) {
        staffs[idx].busy = t + tp.time;
        tp.active = t + tp.time;
        if(is_wait) tp.waiting--;
    }
}

int main() {
    int n;
    int id,reqs,start,time,gap,x,tid;
    int sen = 1;
    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d %d", &id, &reqs, &start, &time, &gap);
            topics.push_back(topic(id, reqs, start, time, gap));
        }
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &id, &x);
            staffs.push_back(staff(id));
            for (int j = 0; j < x; j++) {
                scanf("%d", &tid);
                staffs.back().topics.push_back(tid);
            }
        }
        int t = 0;
        while (1) { 
            int active = 0;
            for (auto &tp: topics) {
                if(tp.waiting) {
                    for (int k = 0; k < tp.waiting; k++) {
                        assign(tp, t, 1);
                    }
                }
                if (tp.next == t && tp.reqs > 0) {
                    assign(tp, t, 0);
                }
                if (tp.reqs > 0 || tp.active > t) {
                    active++;
                }
            }
            if(!active) {
                printf("Scenario %d: All requests are serviced within %d minutes.\n", sen++, t);
                staffs.clear();
                topics.clear();
                break;
            }
            t++;
        }
    }
    return 0;
}