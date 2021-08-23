#include <iostream>
#include <cstring>
using namespace std;
int dp[2000][2000][5];
int LCS(int *s1,int * s2,int i,int j,int n,int m, int l){
	
	if(i>=n||j>=m){
		return 0;
	}
	
    if(dp[i][j][l]!=-1){
        int p= dp[i][j][l];
        return p;
    }
int k=0;
	if(s1[i]==s2[j]){
		 k=1+ LCS(s1,s2,i+1,j+1,n,m,l); 
		 dp[i][j][l]= max(dp[i][j][l],k);
		 return dp[i][j][l];

	}else{
		if(s1[i]!=s2[j]&&l>0){
			s1[i]=s2[j];
			int 	k=1+ LCS(s1,s2,i+1,j+1,n,m,l-1);
			int r = LCS(s1,s2,i+1,j+1,n,m,l);
			int ans = max(k,r);
			dp[i][j][l]=max(dp[i][j][l], ans);
			return dp[i][j][l];
		}
		else{
	int l=LCS(s1,s2,i+1,j,n,m,0);
	int r=LCS(s1,s2,i,j+1,n,m,0);
	int ans= max(l,r);
    dp[i][j][l]=max(dp[i][j][l],ans);
    int p=dp[i][j][l];
    return p;
    }
}
}
int main() {
    // for(int i=0;i<1000;i++){
    //     for(int j=0;j<1000;j++){
	// 		for (int l=0; l<5; l++){
    //         dp[i][j][l]=-1;}
    //     }
    // }
	memset(dp, -1, sizeof(dp));
	int n;
	cin>>n;
	int * s1=new int[n];
	int m;
	cin>>m;
	int k;
	cin>>k;
	int* s2=new int[m];
	for(int i=0;i<n;i++){
		cin>>s1[i];
	}
		for(int i=0;i<m;i++){
		cin>>s2[i];
	}
	cout<<LCS(s1,s2,0,0,n,m,k)<<endl;
}