#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;
long long changeRadix(string s,long long n){
	int m=s.size();
	long long temp,sum=0;
	int i=0;
	do{
		temp=isalpha(s[i])? s[i]-'a'+10:s[i]-'0';
		sum*=n;
		sum+=temp;
		i++;
	}while(i<m);
	return sum;
}
int main(){
	string s[3];
	int n;
	long long m;
	cin>>s[1];
	cin>>s[2];
	cin>>n>>m;
	long long a=changeRadix(s[n],m);
	if(n==1){
		n=2;
	}else{
		n=1;
	}
	char c=*max_element(s[n].begin(),s[n].end());
	long long j=isdigit(c)?c-'0':c-'a'+10;
	long long e=max(a/2,j+1);
	for(long long i=j+1;i<=e;i++){
		long long d=changeRadix(s[n],i);
		if(d==a){
			cout<<i;
			return 0;
		}
	}
	cout<<"Impossible";
	return 0;
}
