#include <iostream>
#include <vector>
using namespace std;

vector <int> ans;

bool fun(vector <int> &a, int i, int sum, int rem, int target){
    if (sum > target or (rem + sum) < target){
        return false;
    }
    if (sum == target)
        return true;
    ans.push_back(a[i]);
    sum += a[i];
    rem -= a[i];
    if (fun(a, i + 1, sum, rem, target))
        return true;
    ans.pop_back();
    sum -= a[i];
    return fun(a, i + 1, sum, rem, target);

}

vector <int> solve(){
    int n, k; cin >> n >> k;
    vector <int> arr(n);
    int sum = 0;
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
        sum += arr[i];
    }
    if (fun(arr, 0, 0, sum, k)){
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        return ans;
    }
    ans = vector <int>(1, 0);
    cout << "NULL\n";
    return ans;
}

int main(){
    
    solve();
    return 0;
}