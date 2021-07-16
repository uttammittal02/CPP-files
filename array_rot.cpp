#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#def mod const int 1e9 + 7
#define loop(j, n) for(int i = j; i < n; i++)
using namespace std;

int main(){
    long long n, q;
    long long sum;
    cin>>n;
    sum = 0;
    long long arr[n];
    loop(0, n){
        cin>>arr[i];
        sum += arr[i];
    }
    cin>>q;
    mod = 10**9 + 7;
    loop(0, q){
        int x;
        cin>>x;
        sum *= 2;
        sum = sum%mod;
        cout<<sum%(mod)<<endl;
    }
    return 0;
}