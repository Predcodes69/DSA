/*
 * 
 *@author - pred695
 * 
 */
/*弱い も
خاک سے آیا ہوں، خاک بنوں گا۔*/
/*-------------------------------------------****************-------------------------------------------------------****************----------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define vi                          vector<int>
#define vvi                         vector<vector<int>> 
#define pb                          push_back
#define eb                          emplace_back
#define pii                         pair<int, int>
#define vp                          vector<pii>
#define psi                         pair<string, int>
#define pis                         pair<int, string> 
#define ppb                         pop_back
#define pf                          push_front
#define ppf                         pop_front
#define all(x)                      x.begin(),x.end()
#define rep(i, a, b)                for(int i = a; i < b; i++)
#define repr(i, a, b)               for(int i = a; i >= b; i--)
#define read(a, n)                  rep(i, 0, n)    cin >> a[i]
#define readx(a, n, m)             rep(i, 1, n + 1){rep(j, 1, m + 1) cin >> a[i][j];}
#define print(a, n)                 rep(i, 0, n)    cout << a[i] << " "; cout << endl
#define printx(a, n, m)            rep(i, 1, n + 1){rep(j, 1, m + 1) cout << a[i][j] << " "; cout << endl;}
#define endl                        "\n"
#define ff                          first
#define ss                          second
#define yes                         cout << "YES" << endl
#define no                          cout << "NO" << endl
#define int                         long long
#define lld                         long long double
#define ull                         unsigned long long
#define si                          set<int>
#define sc                          set<char>
#define sti                         stack<int>
#define stc                         stack<char>
#define msi                         map<string, int>
#define mis                         map<int, string>
#define in                          insert
#define M                           1000000007
#define prec(x)                     cout << fixed << setprecision(x)
#define bpc(x)                      __builtin_popcountll(x)
const int N = 1e7 + 10;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<": "; deb(x); cerr << endl;
#else
#define debug(x)
#endif
 
void deb(int t) {cerr << t;}
void deb(string t) {cerr << t;}
void deb(char t) {cerr << t;}
void deb(double t) {cerr << t;}
void deb(ull t) {cerr << t;}
 
template <class T, class V> void deb(pair <T, V> p) {cerr << "{"; deb(p.ff); cerr << ","; deb(p.ss); cerr << "}";}
template <class T> void deb(vector <T> v) {cerr << "[ "; for (T i : v) {deb(i); cerr << " ";} cerr << "]";}
template <class T> void deb(set <T> v) {cerr << "[ "; for (T i : v) {deb(i); cerr << " ";} cerr << "]";}
template <class T> void deb(multiset <T> v) {cerr << "[ "; for (T i : v) {deb(i); cerr << " ";} cerr << "]";}
template <class T, class V> void deb(map <T, V> v) {cerr << "[ "; for (auto i : v) {deb(i); cerr << " ";} cerr << "]";}
int mul(int a, int b) {
    return ((a % M) * (b % M)) % M;
}
int minv(int a) {
    return pow(a, M - 2);
}
int mdiv(int a, int b) {
    return mul(a, minv(b));
}
int madd(int a, int b) {
    return (a % M + b % M) % M;
}
void fast()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
}
int ipow(int a, int b)
{
   int ans = 1;
   while(b)
   {
    if(b & 1)
    ans = (ans*a)%M;
    a = (a*a)%M;
    b>>=1;
   }
   return ans;
}
clock_t start;
vi primes(N, 1);
vi ans(N, 0);
void sieve()
{
    primes[0] = primes[1] = 0;
    primes[2] = 1;
    for (int i = 3; i * i <= N; i += 2)
    {
        if (primes[i])
            {for (int j = i * i; j <= N; j += 2 * i)
                primes[j] = 0;}
    }
    for (int x = 1; x <= 10000; x++)
    {
        for (int y = 1; y <= 100; y++)
        {   
            int curr = ipow(x, 2) + ipow(y, 4);
            if (curr >= N)
                break;
            else if (primes[curr] and ((curr & 1) or curr == 2))
                ans[curr] = primes[curr];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        ans[i] += ans[i - 1];
    }
}
/*----------------------------------------------------------------------MAIN CODE------------------------------------------------------------------------------------------------------------------------*/
void solve()
{
    int n;
    cin >> n;
    cout << ans[n] << endl;
}
/*----------------------------------------------------------------------ありがと-------------------------------------------------------------------------------------------------------------------------*/
signed main()
{
fast();
int t = 1;
cin >> t;
start = clock();
sieve();
rep(i, 0, t)
{
    // cout << "Case #" << i + 1 << ": ";
    solve();
}
return 0;
}