#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<long long> prime(500000,0);
int main(){
	for(int i=2;i<500000;i++){
		for(int j=2;j*i<500000;j++){
			prime[i*j]=1;
		}
	}
	long long a;
	scanf("%ld",&a);
	vector<long long> result;
	printf("%ld=",a);
	if(a==1) printf("1");
	bool first=false;
	for(int i=2;a>=2;i++){
		int count=0,flag=0;
		while(prime[i]==0&&a%i==0){
			count++;
			a/=i;
			flag=1;
		}
		if(flag){
			if(first) printf("*");
			printf("%ld",i);
			first=true;
		}
		if(count>=2){
			printf("^%d",count);
		}
	}
	return 0;
}
