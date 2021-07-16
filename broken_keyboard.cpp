#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#define loop(j, n, i) for(int i = j; i < n; i++)
#define int long long
using namespace std;

int32_t main(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    set <char> charac_list;
    loop(0, k, i){
        char temp;
        cin>>temp;
        charac_list.insert(temp);
    }
    vector <int> result;
    int cnt = 0;
    loop(0, n, i){
        if (charac_list.find(s[i]) != charac_list.end()){
            cnt++;
            if (i == n-1){result.push_back(cnt*(cnt+1)/2);}
            }
        else result.push_back(cnt*(cnt+1)/2), cnt = 0;
    }
    
    int ans = 0;
    loop(0, result.size(), i){
        ans += result[i];
    }
    cout<<ans<<endl;
    return 0;
}