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

#define ll long long int
using namespace std;

ll getMinOperations(vector<int> &a, int median_or_mean)
{

      int n = a.size();
      ll sum = 0;

      for (int i = 0; i < a.size(); i++)
      {
            sum += a[i];
      }

      ll cost_for_mean = 1ll * n * median_or_mean - sum;
      if (cost_for_mean < 0)
      {
            return -1;
      }

      // Exactly ceil(n/2) + 1 elements must be >= median

      ll min_cost_for_median = 0;
      int start = (n / 2);
      if (n % 2 == 0)
            start--;

      for (int i = start; i < n; i++)
      {
            min_cost_for_median += max(median_or_mean - a[i], 0);
      }

      if (min_cost_for_median > cost_for_mean)
      {
            return -1;
      }

      // Else we can add (cost_for_mean - min_cost_for_median) operations
      // on the greatest element to accommodate for mean

      return cost_for_mean;
}

int main()
{
      int tests;
      cin >> tests;
      while (tests--)
      {
            int n;
            cin >> n;
            vector<int> a(n);
            for (int i = 0; i < n; i++)
                  cin >> a[i];

            sort(a.begin(), a.end());

            int median_ind = (n / 2);
            if (n % 2 == 0)
                  median_ind--;

            int median_or_mean = 1e9;
            ll min_operations = -1;

            // Performing binary search on final median/mean value
            int l = a[median_ind], r = 1e9;

            while (l <= r)
            {
                  int mid = (l + r) / 2;
                  ll val = getMinOperations(a, mid);
                  if (val != -1)
                  {
                        median_or_mean = mid;
                        min_operations = val;
                        r = mid - 1;
                  }
                  else
                  {
                        l = mid + 1;
                  }
            }

            cout << min_operations << endl;
      }
      return 0;
}