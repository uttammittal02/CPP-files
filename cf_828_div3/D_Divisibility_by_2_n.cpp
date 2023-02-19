#include <bits/stdc++.h>
#define test_cases_loop \
	int t;              \
	cin >> t;           \
	loop(tc, 1, t + 1)
#define FIO                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);cout.tie(NULL);
#define loop(var, initial, final) for (int var = initial; var < final; var++)
#define endl '\n'
#define vi vector <int>

using namespace std;

int ceil_(int n, int k)
{
	return n/k + (bool)(n%k);
}
void solve()
{
	int n; cin >> n;
    int x = 1, p = 0;
    while (x <= n){
        x *= 2; p ++;
    }
    x /= 2; p --;
    int pow = 0;
	vi arr(n);
	loop(i, 0, n)
	{
		cin >> arr[i];
        while (!(arr[i] % 2)){
            arr[i] /= 2; pow ++;
        }
	}
    int ops = 0;
    while (x > 1 and pow < n){
        ops += min(ceil_(n / x, 2), ceil_(n - pow, p));
        pow = min(n, pow + ceil_(n / x, 2) * p);
        x /= 2, p --;
    }
    cout << (pow >= n? ops : -1) << endl;

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

