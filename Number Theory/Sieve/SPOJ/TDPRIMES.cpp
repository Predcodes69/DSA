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
const int N = 1e8 + 10;

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
void binary(int n, string &s)
{   
    if(n <= 0)
    {
        return;
    }
    s = (char)((n & 1) + 48) + s;
    binary(n>>1, s);
}
void integer(string s, int &c, int i){
    if(i == s.length())
    return;
    char x = s[s.length() - 1 - i];
    c+=(x - '0')*(1<<i);
    integer(s, c, i + 1);
}
int nod(int n) // to calculate the number of distinct digits
{
    int a[10] = {0}; 
    int c = 0;
    while(n)
    {
        a[n%10] = 1;
        n/=10;
    }
    for (int i = 0; i < 10; i++)
    {
        if (a[i])
            c++;
    }
    return c;
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
            if ((long long)i * i <= (long long)N)
            {
                for (int j = i * i; j <= N; j += i)
                {
                    if (!primes[j])
                        primes[j] = i; // storing min primes
                }
            }
        }
    }
}
bool is_prime[N];
vi primenumbers;
void sieveModified()
{
    is_prime[0] = is_prime[1] = true;
    for(int i = 3; i <= N; i+=2)
    {
        if(!is_prime[i])
        {
            primenumbers.eb(i);
            for(int j = i*i; j <= N; j+=2*i)
            is_prime[j] = true;
        }
    }
}
/*----------------------------------------------------------------------MAIN CODE------------------------------------------------------------------------------------------------------------------------*/
void solve()
{
  print(primenumbers, primenumbers.size());
  debug(primenumbers);
}
/*----------------------------------------------------------------------ありがと-------------------------------------------------------------------------------------------------------------------------*/
signed main()
{
fast();
int t = 1;
// cin >> t;
sieveModified();
start = clock();
rep(i, 0, t)
{
    // cout << "Case #" << i + 1 << ": ";
    solve();
}
exectime();
return 0;
}