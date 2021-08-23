#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
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
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
void fastscan_integer(int &number)      // for fastest possible integer input
{   
    bool negative = false; register int c; number = 0; c = getchar();
    if (c=='-') negative = true, c = getchar();
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;      
}
using namespace std;

#define ff              first
#define ss              second
// #define int             long long
// #define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
// #define vi              vector<int>
// #define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
// #define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void printMaxValuesMap(vi a, int k)
{
	int n = a.size();
	mii m;

	for (int i = 0; i < k; ++i)
		m[a[i]]++;

	cout << (--m.end())->ff << ' ';

	for (int i = k; i < n; ++i) //[i-k+1...i]
	{
		m[a[i]]++;

		m[a[i - k]]--;

		if (m[a[i - k]] == 0)
			m.erase(a[i - k]);

		cout << (--m.end())->ff << ' ';
	}
}

void printMaxValuesDeque(vi a, int k)
{
	int n = a.size();

	deque<int> q;

	for (int i = 0; i < k; ++i)
	{
		while (q.size() and a[q.back()] <= a[i])
			q.pop_back();

		q.push_back(i);
	}

	cout << a[q.front()] << ' ';

	for (int i = k; i < n; ++i)
	{
		if (q.front() == i - k)
			q.pop_front();

		while (q.size() and a[q.back()] <= a[i])
			q.pop_back();

		q.push_back(i);

		cout << a[q.front()] << ' ';
	}
}

int32_t main()
{
	FIO;

	int n, k; cin >> n >> k;

	vi a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	printMaxValuesDeque(a, k);

	return 0;
}