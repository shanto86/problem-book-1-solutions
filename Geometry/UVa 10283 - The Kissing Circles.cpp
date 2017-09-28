#include<bits/stdc++.h>
using namespace std;

#define PI 2.0*acos(0.0)
#define SIN(x) sin(x * PI / 180.0)
#define COS(x) cos(x * PI / 180.0)

int main() {
    int R, n; while( cin >> R >>n ) {
        if(n == 1) {
            printf("%.10f %.10f %.10f\n", (double) R, 0, 0);
            continue;
        }
        double theta = 180.0 / n;
        double r = R * SIN(theta) / (1.0 + SIN(theta));
        double blue = n * ( (R - r) * COS(theta) * r - (90-theta) / 180 * PI * r * r);
        double rest = PI * R * R - blue - n * PI * r * r;
        printf("%.10f %.10f %.10f\n", r, blue, rest);
    }
}
