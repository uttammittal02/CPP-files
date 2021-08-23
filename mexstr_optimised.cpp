#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
constexpr int maxi = (int)1e6;
typedef long long ll;
typedef long double ld;
using cmplx = complex<ld>;
int dp[maxi+2], dp1[maxi+2];
int next0[maxi], next1[maxi];
#define const complex
#define pb push_back
#define endl '\n'
using ld=long double;
typedef unsigned long long ull;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll>   vl;
#define f(i,n)  for(i=0;i<n;i++)
#define f1(i,n)  for(i=1;i<n;i++)
#define fr(i,n) for(i=n-1;i>=0;i--)
#define em emplace_back
#define mp make_pair
#define in insert
#define fi first
#define sc second
#define b begin
#define e end
#define er erase
#define l length
#define c clear
#define si size
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);

bool isPrime(int n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
    return true;
}

void solve();
int main(int argc, char *argv[]) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(argc>1) 
        freopen(argv[1], "r", stdin);
    if(argc>2)
        freopen(argv[2], "w", stdout);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
int nextPrime(int N)
{
    if (N <= 1)
        return 2;
    int prime = N;
    bool found = false;
    while (!found) {
        prime++;
        if (isPrime(prime))
            found = true;
    }
 
    return prime;
}
void solve() {
    string s;
    cin>>s;
    int n = s.length();
    int last_pos = -1;
    for(int i=0; i<n; ++i) {
        if(s[i]=='0') {
            for(int j = last_pos+1; j<=i; ++j) {
                next0[j] = i;
            }
            last_pos = i;
        }
    }
    for(int i=last_pos+1; i<n; ++i)
        next0[i] = n;

    if(next0[0] == n) {
        cout<<"0\n";
        return;
    }

    last_pos = -1;
    for(int i=0; i<n; ++i) {
        if(s[i] == '1') {
            for(int j=last_pos+1; j<=i; j++) 
                next1[j] = i;
            last_pos = i;
        }
    }
    for(int i=last_pos+1; i<n; ++i) {
        next1[i] = n;
    }
    dp[n] = dp[n+1] = 0;
    dp1[n] = dp1[n+1] = 0;
    for(int i= n-1; i>=0; --i) {
        dp[i] = dp[i+1];
        if(s[i] == '0' && next1[i] < n) 
            dp[i] = max(dp[i], dp[next1[i] + 1]+1);
        if(s[i] == '1' && next0[i] < n) 
            dp[i] = max(dp[i], dp[next0[i] + 1]+1);
        dp1[i] = dp[i+1];
        if(next1[i] < n) 
            dp1[i] = max(dp1[i], dp[next1[i]+1]+1);
    }
    int len = dp1[0]+1;
    int curr = next1[0] + 1;
    string ans = "1";
    for(int i=1; i<len; ++i) {
        if(curr >= n) {
            ans.push_back('0');
            continue;
        }
        if(next0[curr] >= n) {
            ans.push_back('0');
            curr = next0[curr] + 1;
            continue;
        }
        if(dp[next0[curr]+1] < len-i-1) {
            ans.push_back('0');
            curr = next0[curr] + 1;
        }
        else {
            ans.push_back('1');
            curr = next1[curr]+1;
        }
    }
    cout<<ans<<'\n';
}