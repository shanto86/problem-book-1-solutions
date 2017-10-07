/**
 *    problem: Timus 1020 Rope
 *    author: sjsakib
 *    approach: 
**/
#include <bits/stdc++.h>

using namespace std;

float pi = 3.1415926;

float dist(float x1, float y1, float x2, float y2) {
    float dx = x1-x2;
    float dy = y1-y2;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    int n;
    float r;
    scanf("%d %f", &n, &r);
    float len=0, points[n][2];
    for (int i = 0; i < n; ++i) {
        scanf("%f %f", &points[i][0], &points[i][1]);
        if(i>0) len += dist(points[i][0], points[i][1], points[i-1][0], points[i-1][1]);
    }
    len += dist(points[0][0], points[0][1], points[n-1][0], points[n-1][1]);
    len += 2.0*pi*r;
    printf("%.2f\n", len);
    return 0;
}