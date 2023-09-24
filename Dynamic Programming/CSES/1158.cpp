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
// #define int                         long long
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
void exectime()
{
    clock_t end=clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    #ifndef ONLINE_JUDGE
    cout << endl;
    cout << endl;
    cout << "Executed in "<< fixed << time_taken << setprecision(10);
    cout << " secs " << endl;
    #endif
}
vi primes(N, 1);
void sieve()
{
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= N; i++)
    {
        if (primes[i])
            for (int j = i * i; j <= N; j += i)
                primes[j] = 0;
    }
    for (int i = 2; i < N; i++)
    {
        if (primes[i] == 1)
        {
            primes[i] = i;
            for (int j = i * i; j <= N; j += i)
            {
                if (!primes[j])
                    primes[j] = i; // storing min primes
            }
        }
    }
}
/*----------------------------------------------------------------------MAIN CODE------------------------------------------------------------------------------------------------------------------------*/
void solve()
{
    int n, x;
    cin >> n >> x;
    vi prices(n), pages(n);
    read(prices, n);
    read(pages, n);
    vvi dp(n + 1, vi(x + 1, 0));
    debug(prices);
    debug(pages);
    //our state can be like this:
    //base case is (0 based indexing is dp[-1][j] = 0 where j can be from 0 to x(inclusive))
    /*dp[i][j] = maximum number of pages read while choosing among the first i books such that we are allowed to spend j coins thereafter(after making our choices among the first i - 1 books)
    therefore transition according to the defined state can be
    dp[i][j] = dp[i][j] (if we didn't pick the i-th book)
    dp[i][j] = dp[i][j - prices[i]]] + pages[i] (if we decide to pick the i-th book), now the left amount that we can spend at max is nothing but j - prices[i]*/
    for(int i = 0; i <= x; i++){
        dp[0][i] = 0;   //since without any books we can read 0 pages.(1-based indexing)(since in 0 based indexing dp[i - 1][j] would be the required base case, but negative indices are not allowed)
    }
    /*keep in mind, our dp[i][j] is 1 - based, not 0 based, the first dimension is denoting the humber of books, therefore adjusting the indexing by decreasing the first dimension in every state
    i.e. replacing i with i - 1 while establishing the relation between states.*/
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= prices[i - 1]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - prices[i - 1]] + pages[i - 1]);
            }
        }
    }
    cout << dp[n][x] << endl;       //final subproblem.
}
/*----------------------------------------------------------------------ありがと-------------------------------------------------------------------------------------------------------------------------*/
signed main()
{
fast();
int t = 1;
// cin >> t;
start = clock();
rep(i, 0, t)
{
    // cout << "Case #" << i + 1 << ": ";
    solve();
}
exectime();
return 0;
}