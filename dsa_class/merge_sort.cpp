#include <bits/stdc++.h>
using namespace std;

vector <int> arr;
vector <int> merge(vector <int> &left, vector <int> &right){
    vector <int> ans;
    int i = 0, j = 0;
    int n = left.size(), m = right.size();
    while(i < n && j < m){
        if(left[i] <= right[j]){
            ans.push_back(left[i]); i++; 
        }
        else{
            ans.push_back(right[j]); j++; 
        }
    }
    while (i < n){
        ans.push_back(left[i]); i++; 
    }
    while (j < m){
        ans.push_back(right[j]); j++; 
    }
    return ans;
}

vector <int> merge_sort(vector <int> &arr, int l, int r){
    if(l == r) return vector <int>(1, arr[l]);
    int mid = (l + r) / 2;
    vector <int> left = merge_sort(arr, l, mid);
    vector <int> right = merge_sort(arr, mid + 1, r);
    vector <int> ans = merge(left, right);
    return ans;
}

int32_t main()
{
	int n; cin >> n;
    arr = vector <int>(n);

    for(int i = 0; i < n; i ++)
        cin >> arr[i];
    cout << "Array before sorting: ";
    for(int i = 0; i < n; i ++){
        cout << arr[i] << ' ';
    }
    arr = merge_sort(arr, 0, n - 1);
    cout << endl << "Array after sorting: ";
    for(int i = 0; i < n; i ++){
        cout << arr[i] << ' ';
    }
    

	return 0;
}

//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
