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
#include <functional>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;



// A utility funtion to find maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// A utility funtion to find maximum of three integers
int max(int a, int b, int c) { return max(max(a, b), c); }

// Find the maximum possible sum in arr[] auch that arr[m]
// is part of it
int maxCrossingSum(int arr[], int l, int m, int h)
{
	// Include elements on left of mid.
	int sum = 0;
	int left_sum = INT_MIN;
	for (int i = m; i >= l; i--) {
		sum = sum + arr[i];
		if (sum > left_sum)
			left_sum = sum;
	}

	// Include elements on right of mid
	sum = 0;
	int right_sum = INT_MIN;
	for (int i = m + 1; i <= h; i++) {
		sum = sum + arr[i];
		if (sum > right_sum)
			right_sum = sum;
	}

	// Return sum of elements on left and right of mid
	// returning only left_sum + right_sum will fail for
	// [-2, 1]
	return max(left_sum + right_sum, left_sum, right_sum);
}

// Returns sum of maxium sum subarray in aa[l..h]
int maxSubArraySum(int arr[], int l, int h)
{
	// Base Case: Only one element
	if (l == h)
		return arr[l];

	// Find middle point
	int m = (l + h) / 2;

	/* Return maximum of following three possible cases
			a) Maximum subarray sum in left half
			b) Maximum subarray sum in right half
			c) Maximum subarray sum such that the subarray
	crosses the midpoint */
	return max(maxSubArraySum(arr, l, m),
			maxSubArraySum(arr, m + 1, h),
			maxCrossingSum(arr, l, m, h));
}

/*Driver program to test maxSubArraySum*/
int32_t main()
{
	test_cases_loop{
	    int n, k;
        cin>>n>>k;
        int arr[n];
        loop(i, 0, n){
            cin>>arr[i];
        }
	int max_sum = maxSubArraySum(arr, 0, n - 1);
	cout<<max_sum<<endl;
	}
	return 0;
}

