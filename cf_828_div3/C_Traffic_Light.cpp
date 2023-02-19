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
typedef long long ll;

using namespace std;

void solve()
{
	int n; cin >> n;
    char x; cin >> x;
	string s; cin >> s;
    s += s;
    int i1 = -1;
    int ans = 0;
    if (x == 'g'){
        cout << ans << endl; return;
    }
    loop(i, 0, 2*n){
        if (i1 != -1 and s[i] == 'g'){
            ans = max(ans, i - i1);
            i1 = -1;
        }
        if (i1 == -1 and s[i] == x)
            i1 = i;
    }
    cout << ans << endl;
}

int32_t main()
{
	FIO
	test_cases_loop
		solve();
	
	return 0;
}
