#include <iostream>
using namespace std;

int main(){
	int n; 
    cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    
    for(int i = 0; i < n - 1; i++){

        int min_ = INT16_MAX;
        int idx = i;

        for(int j = i; j < n; j++){
            
            if (arr[j] < min_){
                min_ = arr[j];
                idx = j;
            }
        }

        // idx gives index of element from range i to n and places it at i-th position.

        swap(arr[i], arr[idx]);
        for(int i = 0; i < n; i++){

            //This loop prints the array after each operation
            cout<<arr[i]<<' ';
            
        }
        
        cout<<endl;
    }
    if (n == 1){
        cout<<arr[0]<<' '; // since the array length is 1 so, the only element in the array is 0th element.
    }
    return 0;
}

