#include<iostream>
#include<cstdio>
using namespace std;
long long gcd(long long a,long long b){
	return b==0?abs(a):gcd(b,a%b);
} 
int func(long long a,long long b){
	if(b==0){
		printf("Inf");
		return 0;
	}
	bool flag=(a<0&&b>0)||(a>0&&b<0);
	a=abs(a);
	b=abs(b);
	long long k=a/b;
	a=a-k*b;
	long long gcdvalue=gcd(a,b);
	a=a/gcdvalue;
	b=b/gcdvalue;
	if(flag) printf("(-");
	if(k!=0&&a==0) printf("%lld",k);
	if(k!=0&&a!=0) printf("%lld %lld/%lld",k,a,b);
	if(k==0&&a!=0) printf("%lld/%lld",a,b);
	if(k==0&&a==0) printf("0");
	if(flag) printf(")");
	return 0;
}
int main(){
	long long a,b,c,d;
	scanf("%lld/%lld %lld/%lld",&a,&b,&c,&d);
	func(a,b);printf(" + ");func(c,d);printf(" = ");func(a*d+b*c,b*d);printf("\n");
	func(a,b);printf(" - ");func(c,d);printf(" = ");func(a*d-b*c,b*d);printf("\n");
	func(a,b);printf(" * ");func(c,d);printf(" = ");func(a*c,b*d);printf("\n");
	func(a,b);printf(" / ");func(c,d);printf(" = ");func(a*d,b*c);
	return 0;
}
