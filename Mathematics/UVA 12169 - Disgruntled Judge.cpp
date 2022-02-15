#include<bits/stdc++.h>

using namespace std;


#define int long long

int mul(int a, int b, int M) {return ((a % M) * (b % M)) % M;}
// ax + by = g
int egcd(int a, int b, int &x, int &y) {

    if ( b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int d = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

signed main() {
    int n; cin >> n;

    vector<int> v(2 * n + 1);
    for (int i = 1; i <= 2 * n - 1; i += 2) {
        cin >> v[i];
    }
    if (n == 1) {
        // a = 0
        // b = 0
        cout << 0 << endl;
        return 0;
    }
    for (int a = 0; a <= 10000; a++) {
        // v[3] = a^2*v[1] + b(a + 1) + 10001c
        // b(a + 1) + 10001c = v[3] - a^2*v[1]
        // bp + cq = r
        // x = b, y = c
        // px + qy = r

        // smallest linear combination of p and q
        // px_ + qy_ = g ---> g = gcd(p, q)
        // kpx_ + kqy_ = r ---> k = r / g
        // b = kx_ = (r / g)*x_

        // we can find x_ from extented gcd
        int p = a + 1;
        int q = 10001;
        int r = v[3] - (a * a * v[1]);

        int x , y;

        int g = egcd(p, q, x, y);

        int b = x;
        b *= (r / g);
        bool ok = 1;


        for (int i = 5; i <= 2 * n; i += 2) {
            int tmp = (mul(mul(a, a, q), v[i - 2], q) + mul(b, p, q)) % q;
            if (tmp != v[i]) {
                ok = 0;
                // it is not valid (a, b)
                break;
            }
        }
        if (ok) {
            // found valid a , b for all given v[1], v[3],... v[2*n-1]

            // cout << r << " " << g << endl;
            // cout << a << " " << b << endl;

            // printing v[2], v[4], ... v[2*n]
            for (int i = 2; i <= 2 * n; i += 2) {
                int tmp = (mul(a, v[i - 1], q) + b) % 10001;
                cout << tmp << endl;

            }
            return 0;
        }


    }

}
