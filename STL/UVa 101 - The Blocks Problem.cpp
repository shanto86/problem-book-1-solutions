/**
 *    problem: UVa 101 The Blocks Problem
 *    author: sjsakib
 *    approach: simulation
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> v[28];
int n, a, b;

void clearUp(int idx, int pos) {
    while(v[idx].size() != pos+1) {
        if(v[idx].back() != idx) v[v[idx].back()].push_back(v[idx].back());
        v[idx].pop_back();
    }
}

void moveOnto(int aIdx, int aPos, int bIdx, int bPos) {
    clearUp(aIdx, aPos);
    clearUp(bIdx, bPos);
    v[aIdx].pop_back();
    v[bIdx].push_back(a);
}

void moveOver(int aIdx, int aPos, int bIdx, int bPos) {
    clearUp(aIdx, aPos);
    v[aIdx].pop_back();
    v[bIdx].push_back(a);
}

void pileOnto(int aIdx, int aPos, int bIdx, int bPos) {
    clearUp(bIdx, bPos);
    for (int i = aPos; i < v[aIdx].size(); i++) {
        v[bIdx].push_back(v[aIdx][i]);
    }
    while (v[aIdx].size() != aPos) {
        v[aIdx].pop_back();
    }
}

void pileOver(int aIdx, int aPos, int bIdx, int bPos) {
    for (int i = aPos; i < v[aIdx].size(); i++) {
        v[bIdx].push_back(v[aIdx][i]);
    }
    while (v[aIdx].size() != aPos) {
        v[aIdx].pop_back();
    }
}

int find(int x, int &pos) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if(v[i][j] == x) {
                pos = j;
                return i;
            }
        }
    }
    pos = -1;
    return -1;
}

void printStatus() {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        if(v[i].size()) printf(" ");
        for (int j = 0; j < v[i].size(); j++) {
            printf("%d", v[i][j]);
            if(j != v[i].size()-1) printf(" ");
        }
        printf("\n");
    }
}

int main() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        v[i].push_back(i);
    }
    char x[5],y[5];
    while(1) {
        scanf("%s %d %s %d\n", x, &a, y, &b);
        if (strcmp(x, "quit") == 0) break;
        int aPos, bPos;
        int aIdx = find(a, aPos);
        int bIdx = find(b, bPos);

        if(a == b || aIdx == bIdx) continue;

        if(strcmp(x, "move") == 0) {
            if(strcmp(y, "onto") == 0) {
                moveOnto(aIdx, aPos, bIdx, bPos);
            } else {
                moveOver(aIdx, aPos, bIdx, bPos);
            }
        } else if(strcmp(x, "pile") == 0) {
            if(strcmp(y, "onto") == 0) {
                pileOnto(aIdx, aPos, bIdx, bPos);
            } else {
                pileOver(aIdx, aPos, bIdx, bPos);
            }
        }
        //printStatus();
    }
    printStatus();
    return 0;
}