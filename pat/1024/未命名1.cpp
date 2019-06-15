#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool ifEqual(string s){
	string s1=s;
	reverse(s.begin(),s.end());
	return s1==s;
}
string stringAdd(string s){
	string s1=s;
	reverse(s.begin(),s.end());
	int n=s.size();
	int a,b,flag=0;
	string result="";
	for(int i=n-1;i>=0;i--){
		a=s[i]-'0';
		b=s1[i]-'0';
		a=a+b+flag;
		flag=0;
		if(a>=10){
			a-=10;
			flag=1;
		}
		result+=to_string(a);
	}
	if(flag==1){
		result+="1";
	}
	reverse(result.begin(),result.end());
	return result;
}
int main(){
	string s;
	int m;
	cin>>s>>m;
	int i=0;
	do{
		if(ifEqual(s)){
			break;
		}
		s=stringAdd(s);
		i++;
	}while(i<m);
	cout<<s<<endl;
	cout<<i;
	return 0;
}
