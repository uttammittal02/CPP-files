#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <set>
#include <algorithm>
#define loop(j, n, i) for(int i = j; i < n; i++)
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin>>t;
    loop(0, t, test){
        int n, l, r;
        cin>>n>>l>>r;
        int arr[n];
        loop(0, n, i){
            cin>>arr[i];
        }
        sort(arr, arr+l);
        sort(arr+l+1, arr+n);
        
    }
}