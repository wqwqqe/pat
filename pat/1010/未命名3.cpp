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
long long find(string s,long long n){
	char c=*max_element(s.begin(),s.end());
	long long low=(isdigit(c)?c-'0':c-'a'+10)+1;
	long long high=max(low,n);
	while(low<=high){
		long long mid=(low+high)/2;
		long long d=changeRadix(s,mid);
		if(d<0||d>n) high=mid-1;
		else if(d==n) return mid;
		else low=mid+1;
	}
	return -1;
}
int main(){
	string s[3];
	int n;
	long long m;
	cin>>s[1];
	cin>>s[2];
	cin>>n>>m;
	long long result=n==1?find(s[2],changeRadix(s[1],m)):find(s[1],changeRadix(s[2],m));
	if(result!=-1) cout<<result;
	else cout<<"Impossible";
	
	return 0;
}
