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
#include <tuple>
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
	return n/k + (bool)(n%k);
}
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//

void solve()
{
	string s, t; cin >> s >> t;
    mii fs, ft;
    int qns(0);
    loop(i, 0, sz(s)){
        if (s[i] != '?')
            fs[s[i] - 'a'] ++;
        else
            qns ++;
    }
    set <pii > elements;
    loop(i, 0, sz(t)){
        ft[t[i] - 'a'] ++;
        elements.insert(make_pair(fs[t[i] - 'a'], t[i] - 'a'));
    }
    string temp = "";
    set <pii >::iterator itr;
    int q = qns;
    while (qns > 0){
        set <pii > cpy;
        iter(itr, elements.begin(), elements.end()){
            char ele = 'a' + itr -> ss;
            int freq = itr -> ff;
            while (freq < ft[ele - 'a']){
                temp += ele, freq ++, qns --;
            }
            cpy.insert(make_pair(freq - ft[ele - 'a'], ele - 'a'));
        }
        elements = cpy;
    }
    assert(sz(temp) >= q);
    int j = 0;
    loop(i, 0, sz(s)){
        if (s[i] == '?'){
            s[i] = temp[j];
            j ++;
            // j %= sz(t);
        }
    }
    cout << s << endl;

}

int32_t main()
{
	FIO
		// test_cases_loop
	{
		// cout << "Case #" << tc << ": ";
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