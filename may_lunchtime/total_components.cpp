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

#define And &&
#define Or ||
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

vi ans(10000001);
vector <int32_t> primes(10000001);
vi prime_nos;

void no_of_primes(){
    loop(i, 2, 10000001){
        // cout<<primes;
        if (primes[i] == 0){
            if (i!=2) prime_nos.pb(i);
            for(int j = 2*i; j < 10000001; j+=i){
                primes[j] = 1;
            }
        }
    }
    loop(i, 0, prime_nos.size()){
        ans[prime_nos[i]] ++;
        if (2*prime_nos[i] < 10000001)
        {ans[2*prime_nos[i]] --;}
    }
    loop(i, 1, 10000001){
        ans[i] += ans[i-1];
        // cout<<i<<" "<<ans[i]<<endl;
    }
}

int32_t main(){
    no_of_primes();
    test_cases_loop{
        int n;
        cin>>n;
        cout<<ans[n]+1<<endl;
    }
    return 0;
}
