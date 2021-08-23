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

int32_t main(){
    test_cases_loop{
        int n;
        cin>>n;
        if (n < 10) cout<<n<<endl;
        else if (n <= 100) cout<<(9 + n/11)<<endl;
        else if (n <= 1000) cout<<(18 + n/111)<<endl;
        else if (n <= 10000) cout<<(27 + n/1111)<<endl;
        else if (n <= 100000) cout<<(36 + n/11111)<<endl;
        else if (n <= 1000000) cout<<(45 + n/111111)<<endl;
        else if (n <= 10000000) cout<<(54 + n/1111111)<<endl;
        else if (n <= 100000000) cout<<(63 + n/11111111)<<endl;
        else if (n <= 1000000000) cout<<(72 + n/111111111)<<endl;
        
    }
    return 0;
}