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
vi factors;

void find_factors(int num){
  int i = 2;
//   cout<<i<<endl;
  while (i*i <= num){
      if (num % i == 0) factors.pb(i), factors.pb(num/i);
      if ((float) i == (float) num/i) factors.pop_back();
      i++;
    //   cout<<i<<endl;
  }
  return;
}

bool isprime(int num){
    int i = 2;
//   cout<<i<<endl;
  while (i*i <= num){
      if (num % i == 0) return false;
    //   if ((float) i == (float) num/i) factors.pop_back();
      i++;
    //   cout<<i<<endl;
  }
  return true;
}

int32_t main(){
    test_cases_loop{
        factors.clear();
        int k;
        cin>>k;
        if (k == 1) {cout<<6<<endl; continue;}
        find_factors(4*k + 1);
        // cout<<k;
        int ans = 5*k + 1;
        if (isprime(4*k+1)){cout<<6*k<<endl; continue;}
        loop(i, 0, factors.size()){
            // cout<<factors[i]<<endl;
            ans += factors[i] * (k/factors[i] + 1);
        }
        cout<<ans<<endl;
    }
}