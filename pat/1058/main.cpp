#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int a[3],b[3],c[3];
	int d[3]={100000000,17,29};
	scanf("%d.%d.%d",&a[0],&a[1],&a[2]);
	scanf("%d.%d.%d",&b[0],&b[1],&b[2]);
	int flag=0;
	for(int i=2;i>=0;i--){
		int n=a[i]+b[i]+flag;
		flag=n/d[i];
		c[i]=n%d[i];
	}
	for(int i=0;i<3;i++){
		cout<<c[i];
		if(i!=2) cout<<".";
	}
	return 0;
} 
