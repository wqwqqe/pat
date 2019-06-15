#include<iostream>
#include<cstdio> 
using namespace std;
long long gcd(long long a,long long b){
	return b==0? abs(a):gcd(b,a%b);
} 
int main(){
	long long n,a,b,gcdvalue,num=0,deno=1;
	scanf("%lld",&n);
	/*
	if(n==0){
		printf("0");
		return 0;
	}
	*/
	for(int i=0;i<n;i++){
		scanf("%lld/%lld",&a,&b);
		gcdvalue=gcd(a,b);
		a=a/gcdvalue;
		b=b/gcdvalue;
		num=num*b+a*deno;
		deno=deno*b;
		gcdvalue=gcd(num,deno);
		num=num/gcdvalue;
		deno=deno/gcdvalue;
	}
	long long integer=num/deno;
	num=num-(integer*deno);
	if(integer!=0){
		printf("%lld",integer);
		if(num!=0) printf(" ");
	}
	if(num!=0) printf("%lld/%lld",num,deno);
	if(integer==0&&num==0) printf("0");
	return 0;
}
