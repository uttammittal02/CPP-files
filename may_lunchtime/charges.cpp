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

int32_t main(){
    test_cases_loop{
        int n, k;
        string s;
        vi q;
        cin>>n>>k>>s;
        int dist = 0;
        loop(i, 1, n){
            if (s[i] == s[i-1]) dist+=2;
            else dist++;
        }
        loop(i, 0, k){
            int temp;
            cin>>temp;
            temp--;
            if (n==1) {cout<<0<<endl; continue;}
            if (s[temp] == '0') s[temp] = '1';
            else s[temp] = '0';
            if (temp == 0 And s[temp + 1] != s[temp]) dist--;
            else if (temp == 0 And s[temp + 1] == s[temp]) dist++;
            else if (temp == n-1 And s[temp - 1] == s[temp]) dist++;
            else if (temp == n-1 And s[temp - 1] != s[temp]) dist--;
            else if (s[temp+1] != s[temp] And s[temp - 1] != s[temp]) dist-=2;
            else if (s[temp+1] == s[temp] And s[temp - 1] == s[temp]) dist+=2;
            cout<<dist<<endl;             
        }

    }
}