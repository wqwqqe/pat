#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int dis[n+1];
	int sum=0;
	for(int i=1;i<n+1;i++){
		cin>>dis[i];
		sum+=dis[i];
	}
	int m;
	cin>>m;
	int result[m];
	int a[m],b[m],c;
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<m;i++){
		if(a[i]>b[i]){
			c=a[i];
			a[i]=b[i];
			b[i]=c;
		}
		int sum1=0;
		for(int j=a[i];j<b[i];j++){
			sum1+=dis[j];
		}
		if(sum1>sum/2){
			result[i]=sum-sum1;
		}else{
			result[i]=sum1;
		}
	}
	for(int i=0;i<m;i++){
		printf("%d",result[i]);
		if(i!=m-1) printf("\n");
	}
	return 0;
}
