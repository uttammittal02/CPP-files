#include <stack>
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
#include <climits>
#include <functional>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using namespace std;

// int gcd(int a,int b,int &x,int &y)
// {
//     int maxi=max(a,b);
//     int mini=min(a,b);
//     if(maxi%mini==0)
//     {
//         x=0;
//         y=1;
//         return mini;
//     }
//     int x1,y1;
//     int ans= gcd(maxi%mini,mini,x1,y1);
//     x=y1;
//     y=x1-(maxi/mini)*y1;
//     return ans;
// }

// int main()
// {
//     FIO
//     int a,b;
//     cin>>a>>b;
//     int x,y;
//     int ans=gcd(a,b,x,y);
//     if(a>b) cout<<ans<<"\n"<<x<<" "<<y<<"\n";
//     else cout<<ans<<"\n"<<y<<" "<<x<<"\n";
//     return 0;
// }

int binarySearch(int input[], int size, int x){
    // Write your code here
    // int ans;
    // if(size == 1)
    //         return (*input == x ? 0 : -1);
    // // 1 2 3 
    // // *(input + mid) = 2;
    
    // int mid = size/2;
    // if(*(input + mid) == x)
    //         ans = mid;
            
    // if(*(input + mid - 1) >= x)
    //         ans = binarySearch(input, (size)/2, x);
    // else{
    //         int ret = binarySearch(input + mid, (size + 1)/2, x);
    //         ans = (ret == -1 ? -1 : mid + ret);
    // }
    // return ans;
}

int32_t main(){
    int n; cin>>n;
    int input[n];
    for(int i = 0; i < n; i++) cin>>input[i];
    int x; cin>>x;
    cout<<binarySearch(input, n, x)<<endl;
    
}