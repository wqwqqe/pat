#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
bool isPrime(int n){
	int a=sqrt(n)+1;
	if(n==2) return true;
	if(n==0||n==1) return false;
	for(int i=2;i<a;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	int n,m,a;
	string s,s1;
	cin>>n>>m;
	cin>>s;
	int flag=0;
	for(int i=0;i<=n-m;i++){
		s1=s.substr(i,m);
		a=stoi(s1);
		if(isPrime(a)){
			flag=1;
			break;
		}
	}
	if(flag){
		cout<<s1;
	}else{
		cout<<"404";
	}
	return 0;
}
