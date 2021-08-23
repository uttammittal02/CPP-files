#include <iostream>
#include <cmath>
#define loop(j,n) for(int i = j; i < n; i++)
using namespace std;

int main(){
	int n, k;
	cin>>n>>k;
	// int arr[n];
	int cnt = 0;
	loop(0, n){
		int temp;
		cin>>temp;
		if (temp + k <= 5) cnt ++;
	}
	// cout<<2/3<<endl;
	cout<<cnt/3<<endl;
	return 0;
}
