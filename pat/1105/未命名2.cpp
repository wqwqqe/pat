#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp1(int a,int b){
	return a>b;
}
int main(){
	int N,n,m,level,t=0;
	scanf("%d",&N);
	for(n=sqrt(N);n>=1;n--){
		if(N%n==0){
			m=N/n;
			break;
		}
	}
	vector<int> a(N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	level=m/2+m%2;
	sort(a.begin(),a.end(),cmp1);
	vector<vector<int>> result(m,vector<int>(n));
	for(int i=0;i<level;i++){
		for(int j=i;j<=n-i-1&&t<=N-1;j++){
			result[i][j]=a[t++];
		}
		for(int j=i+1;j<=m-2-i&&t<=N-1;j++){
			result[j][n-i-1]=a[t++];
		}
		for(int j=n-i-1;j>=i&&t<=N-1;j--){
			result[m-1-i][j]=a[t++];
		}
		for(int j=m-2-i;j>=i+1&&t<=N-1;j--){
			result[j][i]=a[t++];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(j!=0) printf(" ");
			printf("%d",result[i][j]);
		}
		printf("\n");
	}
	return 0;
}
