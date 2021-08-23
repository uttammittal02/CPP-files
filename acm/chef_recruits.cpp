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

#define And &&
#define oOr ||
#define endl '\n'
#define sp " "
#define int long long
#define infinity 999999999999999999
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD 1000000007;
#define pii pair<int, int>
#define usi unordered_set<int>
#define osi set<int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;

int32_t main(){
  int n;
  cin>>n;
  int arr[n];
  loop(i, 0, n){
      cin>>arr[i];
  }
  int k;
  cin>>k;
//   sort(arr, arr+n);
  int i = 0;
  int cnt = 0;
  int term; 
  if (n%k == 0) term = n;
  else term = n-k;
  while(i < term){
      if (cnt%2 == 0){sort(arr+i, arr+i+k);}
      else sort(arr + i, arr+i+k, greater<int>());
      i += k;
      cnt++;
  }
  if (cnt%2 == 0){sort(arr+i, arr+n);}
  else sort(arr + i, arr+n, greater<int>());
  loop(i, 0, n){
      cout<<arr[i]<<sp;
  }
  cout<<endl;
  return 0;
}
