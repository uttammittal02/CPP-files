#include <bits/stdc++.h>

#define YES cout << "YES" << endl;
#define Yes cout << "Yes" << endl;
#define NO cout << "NO" << endl;
#define No cout << "No" << endl;
#define infinity 999999999999999999
#define float long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define MOD (int)1000000007
#define endl '\n'
#define sp ' '
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define umii unordered_map<int, int>
#define test_cases_loop \
	int t;              \
	cin >> t;           \
	loop(tc, 1, t + 1)
#define FIO                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);cout.tie(NULL);
#define find_ele(ele, set) set.find(ele) != set.end()
#define loop(var, initial, final) for (int var = initial; var < final; var++)
#define rloop(var, init, end) for (int var = init; var >= end; var--)
#define ff first
#define ss second
#define iter(itr, start, end) for (itr = start; itr != end; itr++)
#define yesno(var) cout << (var ? "YES" : "NO") << endl;
#define vpii vector<pii>
#define prt(x) cout << x.first << ' ' << x.second << endl;
#define vrt(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' ';
typedef long long ll;

using namespace std;
vi primes;
void sieve(int n){
	vector<int> prime(n+1, 1);
	for(int i = 2; i*i<=n; i++){
		if(prime[i]){
			for(int j = 2; j*i<=n; j++){
				prime[i*j] = 0;
			}
		}
	}
	// vector<int> ans;
	for(int i = 2; i<=n;i++){
		if(prime[i]) primes.pb(i);
	}
	return;
}

// int cnt = 0;
int divisors(int n)
{
	mii ans;
	// vi divs;
    // int x = n;
    // int len = 1;
	for (int i = 2; i * i <= n; i++)
	{
        // if (!(n % i)){
        //     divs.pb(i);
        // }
        int p = i;
		while (n % p == 0){
            n /= p;
            ans[p] ++;
            // cnt ++;
        }
        // cnt ++;
        // len = max(len, ans[p]);
        // assert(cnt <= 1e7);
	}
	// ans.pb(n);
    if (n != 1){ans[n] ++;}
    // vi nums(len, 1);
    int final = 0;
    mii::iterator itr;
    while(true){
        int tmp = 1;
        iter(itr, ans.begin(), ans.end()){
            if (itr -> ss > 0){
                tmp *= itr->ff;
                itr->ss --;
            }
        }
        if (tmp == 1) return final;
        final += tmp;
    }
	// return final;
}
 
void precision_print(float n, int p)
{
	cout << fixed << setprecision(p) << n << endl;
	return;
}

int ceil_(int n, int k)
{
	return n/k + (bool)(n%k);
}
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

void solve()
{
	int n; cin >> n;
	int ans = divisors(n);
    cout << ans << endl;
}

int32_t main()
{
	FIO
    // sieve(1e6);
		test_cases_loop
	{
		solve();
	}
	return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
// 1 5+4 2+1 5