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
#include "matplotlibcpp.h"

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
using namespace plt = 
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
	int n;
	cin >> n;
	// int k; cin >> k;
	// string s; cin >> s;
	vi arr(n);
	loop(i, 0, n)
	{
		cin >> arr[i];
	}
}

int32_t main()
{
	FIO
	int cpu, proc;
    cin >> cpu >> proc;
    vpii processes(proc);
    loop(i, 0, proc) cin >> processes[i].ff;
    loop(i, 0, proc) cin >> processes[i].ss;
    sort(all(processes));
    vi arr(cpu);
    vector <string> cpus(cpu, "");
    char x = '!';
    loop(i, 0, proc){
        int j = min_element(all(arr)) - arr.begin();
        if (processes[i].ff >= arr[j]){
            char a = ' ';
            loop(k, 0, -arr[j] + processes[i].ff)
                cpus[j]+=a;

            loop(k, 0, processes[i].ss)
                cpus[j]+=x;
            arr[j] = processes[i].ff + processes[i].ss;
            x ++;
        }
        else{
            char a = ' ';
            loop(k, 0, arr[j] - processes[i].ff)
                cpus[j]+=a;
            loop(k, 0, processes[i].ss)
                cpus[j]+= x;
            arr[j] += processes[i].ss;
            x ++;   
        }
    }
    loop(i, 0, cpu){
        loop(j, 0, cpus[i].size())
            cout << cpus[i][j];
        cout << endl;
    }

	return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
