#include <iostream>
#include <vector>
using namespace std;

int lin_srch(vector <int> &arr, int x){

    int n = arr.size();
    for(int i = 0; i < n; i ++) {
        if (arr[i] == x){
            return i;
        }
    }
    return -1;
}

int bin_srch(vector <int> &arr, int x){
    int l = 0, r = arr.size();
    while (l <= r){
        int mid = (l + r) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

void bble_sort(vector <int> &arr){
    int n = arr.size();
    for (int i = 0; i < n - 1; i ++){
        bool swapped = false;
        for (int j = 0; j < n - 1; j ++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) return;
    }
    return;
}

int main(){
    int n, x; cin >> n >> x;
    vector <int> arr(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];
    cout << "linear search result: " << lin_srch(arr, x) << endl;
    bble_sort(arr);
    cout << "Array after sorting:\n";
    for (int i = 0; i < n; i ++) cout << arr[i] << ' ';
    cout << '\n';
    cout << "Binary search result: " << bin_srch(arr, x) << endl;
}