#include<iostream>
#include<vector>
using namespace std;
int flag[10100];
vector<int> prime(15000,1);
int main(){
	for(int i=2;i<15000;i++){
		for(int j=2;i*j<15000;j++){
			prime[i*j]=0;
		}
	}
	int n,m;
	scanf("%d %d",&n,&m);
	int a;
	for(int i=n;i<12000;i++){
		if(i==1||i==0) i=2;
		if(prime[i]==1){
			a=i;
			break;
		}
	}
	for(int i=0;i<m;i++){
		int b,step;
		scanf("%d",&b);
		for(step=0;step<a;step++){
			int c=(b+step*step)%a;
			if(flag[c]==0){
				printf("%d",c);
				flag[c]=1;
				break;
			}	
		}
		if(step==a) printf("-");
		if(i!=m-1){
			printf(" ");
		}
	}
	return 0;
}
