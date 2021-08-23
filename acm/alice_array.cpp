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
  int index = n;
  int brr[n];
  loop(i, 0, n){
      int temp;
      cin>>temp;
      arr[i] = temp;
      brr[i] = temp;
    //   if (arr[i] < arr[i-1]) index = min(index, i);
  }
  sort(brr, brr+n);
  bool var = true;
  int start = n;
  int end;
  loop(i, 0, n){
    //   cout<<arr[i]<<sp<<brr[i]<<endl;
    if (arr[i] != brr[i]) start = min(start, i), var = false;
    if (!var And arr[i]==brr[i]) end = i, var = true;
    if (!var And i == n-1) end = n;
  }
  if (start == n){cout<<-1<<endl; exit(0);}
  cout<<start+1<<sp<<end<<endl;
  return 0;
}
