#include <iostream>
using namespace std;

int main(){
	int length_of_199s_array; 
    cin>>length_of_199s_array;

    int arr199[length_of_199s_array];

    for(int i = 0; i < length_of_199s_array; i++) {
        cin>>arr199[i];
    }

    
    for(int i = 0; i < length_of_199s_array - 1; i++){

        int min_ = INT16_MAX;
        int idx = i;

        for(int j = i; j < length_of_199s_array; j++){
            
            if (arr199[j] < min_){
                min_ = arr199[j];
                idx = j;
            }
        }

        // idx gives index of element from range i to n and places it at i-th position.

        swap(arr199[i], arr199[idx]);
        for(int i = 0; i < length_of_199s_array; i++){

            //This loop prints the array after each operation
            cout<<arr199[i]<<' ';
            
        }
        
        cout<<endl;
    }
    if (length_of_199s_array == 1){
        cout<<arr199[0]<<' '; // since the array length is 1 so, the only element in the array is 0th element.
    }
    return 0;
}

