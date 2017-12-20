/**
 * Problem: UVa 212 - Use of Hospital Facilities
 * Author: sjsakib
 * Approach: OOP/Bruteforce
 * Description provided in UVa in a little unclear. A clearer description in available
 * [here](spoj.com/problems/HOSPITAL/)
**/
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Patient {
    string name;
    int i;        // Index
    int surg;     // surgery time
    int rec;      // recovery time
    int op_r;     // operation room
    int rec_r;    // recovery room
    int op_s;     // operation start time

    Patient() { }
    Patient(int i_, string name_, int surg_, int rec_) {
        i = i_;
        name = name_;
        surg = surg_;
        rec = rec_;
        op_s = -1;
    }

    bool operator<(Patient rhs) {
        return op_r < rhs.op_r;
    }
};

struct Room {
    int used;    // Number of minutes used
    int busy;    // busy until
    Room() {
        used = 0;
        busy = -1;
    }
};

vector<Patient> v;
Patient pats[110];
Room oprooms[15];
Room recrooms[35];

int op_rs, rec_rs, s_hour, o2r, pre_op, pre_rec, n_pat;

void assign_room(Patient &pat, int t) {
    for(int i = 0; i < op_rs; i++) {
        Room &room = oprooms[i];
        if(room.busy <= t) {
            room.used += pat.surg;
            room.busy = t + pat.surg + pre_op;
            pat.op_s = t;
            pat.op_r = i+1;
            break;
        }
    }
}

void assign_bed(Patient &pat, int t) {
    for(int i = 0; i < rec_rs; i++) {
        Room &room = recrooms[i];
        if(room.busy <= t) {
            room.used += pat.rec;
            room.busy = t + pat.rec + o2r + pre_rec;
            pats[pat.i].rec_r = i+1;
            break;
        }
    }
}

int main() {
    while(scanf("%d %d %d %d %d %d %d", &op_rs, &rec_rs, &s_hour, &o2r, &pre_op, &pre_rec, &n_pat) == 7) {
        char name[15];
        int surg, rec;
        for (int i = 0; i < n_pat; i++) {
            scanf("%s %d %d", name, &surg, &rec);
            pats[i] = Patient(i, name, surg, rec);
        }
        int t = s_hour*60;  // Current time
        int finished = 0;
        while (1) {
            for(int i = 0; i < n_pat; i++) {
                Patient &pat = pats[i];
                if(pat.op_s == -1) {
                    assign_room(pat, t);
                } else if (pat.op_s != -1 && pat.op_s + pat.surg == t) {
                    v.push_back(pat);
                } else if (pat.op_s != -1 && pat.op_s + pat.surg + o2r + pat.rec == t) {
                    finished++;
                }
            }
            sort(v.begin(), v.end());
            for(auto p: v) {
                assign_bed(p, t);
            }
            v.clear();
            if ( finished == n_pat) break;
            t+=1;
        }


        puts(" Patient          Operating Room          Recovery Room");
        puts(" #  Name     Room#  Begin   End      Bed#  Begin    End");
        puts(" ------------------------------------------------------");
        for (int i = 0; i < n_pat; i++) {
            Patient &pat = pats[i];
            int op_end = pat.op_s + pat.surg;
            int rec_start = op_end + o2r;
            int rec_end = rec_start + pat.rec;
            printf("%2d  %-9s %2d  %3d:%02d  %3d:%02d    %3d  %3d:%02d  %3d:%02d\n", i+1, pat.name.c_str(),
                   pat.op_r, pat.op_s / 60, pat.op_s % 60, op_end / 60, op_end % 60,
                   pat.rec_r, rec_start / 60, rec_start % 60, rec_end / 60, rec_end % 60);
        }
        int t_m = t -  s_hour*60;
        puts("\nFacility Utilization");
        puts("Type  # Minutes  % Used");
        puts("-------------------------");
        for (int i = 0; i < op_rs; i++) {
            printf("%-4s %2d %7d %7.2lf\n","Room", i+1, oprooms[i].used, (double) oprooms[i].used*100/t_m);
            oprooms[i].used = 0;
            oprooms[i].busy = -1;
        }
        for (int i = 0; i < rec_rs; i++) {
            printf("%-4s %2d %7d %7.2lf\n","Bed", i+1, recrooms[i].used, (double) recrooms[i].used*100/t_m);
            recrooms[i].used = 0;
            recrooms[i].busy = -1;
        }
        puts("");
    }
    return 0;
}