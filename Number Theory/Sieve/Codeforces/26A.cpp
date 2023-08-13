#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define vi vector<int> 
const int N = 1e6 + 10;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, count = 0;
    cin >> n;

    vector<int> v(N, 1);
    v[0] = v[1] = 0;
    // sieve
    for (int i = 2; i * i <= N; i++)
    {
        if (v[i] == 1 && (long long)(i * i) <= N)
        {
            for (int j = i * i; j <= N; j += i)
            {
                v[j] = 0;
            }
        }
    }   
    // finding minimum primes
    for (int i = 2; i <= N; i++)
    {
        if (v[i] == 1)
        {
            v[i] = i;
            for (int j = i * i; j <= N; j += i)
            {
                if (v[j] == 0)
                    v[j] = i;
            }
        }
    }
    // counting primes
    set<int> s;
    for (int i = 6; i <= n; i++)
    {
        int x = i;
        while (x > 1)
        {
            s.insert(v[x]);
            x = x / v[x];
        }
        if (s.size() == 2) count++;
        s.clear();
    }
    cout << count << endl;
    return 0;
}