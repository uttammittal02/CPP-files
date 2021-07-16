#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define int long long
int32_t main()
{
    int n;
    cin >> n;
    
    int sum=0;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin >> temp;
        sum+=temp;
    }
    
    int q;
    cin >> q;
    int ans;
    for(int i=0; i<q; i++)
    {
        int x;
        cin >> x;
        sum+=sum;
        int sed = pow(10, 9) + 7;
        ans = sum % sed;
        cout << ans << endl;
    }
    return 0;
}