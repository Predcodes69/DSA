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
const int N = 1e5 + 10;

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
            for (int j = i * i; j <= N; j += i)
            {
                if (!primes[j])
                    primes[j] = i; // storing min primes
            }
        }
    }
}
vector<bool> state(N, false);
vi conflict(N, 1);
/*----------------------------------------------------------------------MAIN CODE------------------------------------------------------------------------------------------------------------------------*/
void solve()
{
    /*Thinking:
    Case +:
        initially deactivated: just turn the state on, and all the prime factors on as well, assign the value of the numbers to the prime factors.
        already on: just print already on
        conflict with a number that's already on but has a common prime factor: spit out the value of the number given to the index of the prime factor
    Case -:
        initially activated: turn off the number and remove the number from the vectors of the number that is assigned to the prime factors.
        already deactivated: no tension
    */
  int n, m;
  cin >> n >> m;
  while(m--)
  {
    char x;
    int num;
    cin >> x >> num;
    int temp = num;
    if(x == '+')
    {
        if(state[primes[num]] == true and primes[num] != conflict[primes[temp]])
        {
            cout << "Conflict with " << conflict[primes[num]] << endl;
        }
        else if(state[num] == true)
        {
            cout << "Already on" << endl;
        }
        else
        {
            cout << "Success" << endl;
            while (temp > 1)
            {
                    state[temp] = state[primes[temp]] = true;
                    conflict[primes[temp]] = num;
                    temp /= primes[temp];
            }
        }
    }
    else
    {
        if(state[num] == false)
        {
            cout << "Already off" << endl;
        }
        else
        {
            cout << "Success" << endl;
            while (temp > 1)
            {
                    state[temp] = state[primes[temp]] = false;
                    conflict[primes[temp]] = 1;
                    temp /= primes[temp];
            }
        }
    }
  }
}
/*----------------------------------------------------------------------ありがと-------------------------------------------------------------------------------------------------------------------------*/
signed main()
{
fast();
int t = 1;
sieve();
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