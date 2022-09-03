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


int32_t main()
{
	FIO
	int cpu, proc;
    cin >> cpu >> proc;
    // priority = arrival time
    vector <vi > processes(proc, vi(3)); // stores {priority, burst time, index}
    loop(i, 0, proc) cin >> processes[i][1];
    loop(i, 0, proc) cin >> processes[i][0];
    loop(i, 0, proc) processes[i][2] = i;
    sort(all(processes)); // lesser the priority value, more is its priority
    vi arr(cpu);
    vector <string> cpus(cpu, "");
    
    loop(i, 0, proc){
        int j = min_element(all(arr)) - arr.begin();
        char a = ' ';
        string s = to_string(processes[i][2] + 1);
        char x = s[0];
        if (processes[i][0] >= arr[j]){
            loop(k, 0, -arr[j] + processes[i][0])
                cpus[j]+=a;

            loop(k, 0, processes[i][1])
                cpus[j]+=x;
            arr[j] = processes[i][0] + processes[i][1];
            
        }
        else{
            loop(k, 0, processes[i][1])
                cpus[j]+= x;
            arr[j] += processes[i][1];
            
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
