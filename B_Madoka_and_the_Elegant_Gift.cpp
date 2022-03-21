#include <stack>
#include <iomanip>
#include <ios>
#include <iterator>
#include <inttypes.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <climits>
#include <functional>

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
#define umii unordered map<int, int>
#define test_cases_loop \
	int t;              \
	cin >> t;           \
	while (t--)
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
typedef long long ll;

using namespace std;

vector<int> divisors(int n)
{
	vector<int> ans;
	ans.pb(1);
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			ans.pb(i);
			if (n / i != i)
				ans.pb(n / i);
		}
	}
	ans.pb(n);
	return ans;
}
void precision_print(float n, int p)
{
	cout << fixed << setprecision(p) << n << endl;
	return;
}

int ceil_(int n, int k)
{
	return (n + k - 1) / k;
}
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

void solve()
{
	int n, m;
	cin >> n >> m;
	// int k; cin >> k;
	// string s; cin >> s;
	vector <string > arr(n);
    vector <vi > vis(n, vi(m, 0));
	loop(i, 0, n)
	{
		cin >> arr[i];
	}
    // cout << arr[n][m];
    loop(i, 0, n){
        int j = 0;
        for(; j < m; j ++){
            if (vis[i][j])
                continue;
            if (arr[i][j] == '1' and ((i and arr[i - 1][j] == '1') or (j and arr[i][j - 1] == '1'))){
                // cout << i << sp << j << endl;
                NO
                return;
            }
                // cout << i << sp << j << endl;
            int col = j;
            while(col < m and arr[i][col] == '1'){
                col ++;
            }
            int row = i;
            while(row < n and arr[row][j] == '1'){
                row ++;
            }
            // cout << row << sp << col << endl << endl;
            loop(k, i, row){
                loop(l, j, col){
                    if (vis[k][l]){
                        NO
                        return;
                    }
                    vis[k][l] = 1;
                    // cout << k << sp << l << endl;
                    if(arr[k][l] == '0'){
                        cout << "NO" << endl;
                        return;
                    }
                }
            }
        }
    }
    YES
}

int32_t main()
{
	FIO
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
