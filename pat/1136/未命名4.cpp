#include<iostream>
#include<cstdio>
using namespace std;
string sreverse(string s){
	string s1="";
	int n=s.size();
	for(int i=0;i<n;i++){
		s1=s1+s[n-1-i];
	}
	return s1;
}
string sadd(string s,string s1){
	int n=s.size();
	int a,b,flag=0;
	string s2="";
	char c;
	for(int i=n-1;i>=0;i--){
		a=s[i]-'0';
		b=s1[i]-'0';
		a=a+b+flag;
		flag=0;
		if(a>=10){
			a=a-10;
			flag=1;
		}
		c=a+'0';
		s2=s2+c;
	}
	if(flag==1){
		s2=s2+'1';
	}
	return sreverse(s2);
}
int main(){
	string s,s1,s2;
	cin>>s;
	int flag=0,n=s.size();
	for(flag=0;flag<11;flag++){
		s1=sreverse(s);
		if(s1==s){
			cout<<s<<" is a palindromic number.";
			break;
		}else if(flag!=10){
			s2=sadd(s,s1);
			cout<<s<<" + "<<s1<<" = "<<s2<<endl;
			s=s2;
		}else if(flag==10){
			printf("Not found in 10 iterations.");
		}
	}
	return 0;
} 
