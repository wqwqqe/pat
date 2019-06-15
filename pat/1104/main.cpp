#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	double a,sum=0.0;
	for(int i=0;i<n;i++){
		cin>>a;
		sum=sum+a*(i+1)*(n-i);
	}
	printf("%.2f",sum);
	return 0;
}
