// Author: Jony Bepary <sohelahmedjony@gmail.com>
//  2022
//  @jbeary
//  http://jony-blog.github.io/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    string t, p;
    while (cin >> t >> p)
    {

        int i = 0, j = 0;
        while (i < p.size() && j < t.size())
        {
            if (t[j] == p[i])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        // cout << j << " : " << t.size();
        if (j == t.size())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
