#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int key){
    //cout<<n<<endl;
    int lo = 0;
    int hi = n;
    int ans = -1;
    while (lo <= hi){
      //  cout<<j<<endl;
      int mid = lo + (hi - lo)/2;
        if (arr[mid] == key){
             ans = mid;
             hi = mid -1;
            }
        else if (arr[mid] < key){
            lo = mid+1;
        }
        else if (arr[mid] > key){
            lo = mid+1;
        }
    
    }
return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        arr[i] = temp;
    }
    int key;
    cin>>key;
    cout<<binary_search(arr, n, key)<<endl;
}