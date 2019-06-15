#include<iostream>
#include<cstring>
using namespace std;
int main(){
	string s,result;
	cin>>s;
	int n=s.size(),m;
	int i;
	for(i=n-6;i<n;i++){
		if(s[i]=='E'){
			m=i;
			break;
		}
	}
	if(i==n){
		if(s[0]=='-'){
			cout<<s;
		}else{
			cout<<s.substr(1,n-1);
		}
		return 0;
	}
	string temp=s.substr(m+2,n-m-2);
	int a=stoi(temp);
	bool flag,flag1;
	if(s[m+1]=='-') flag=false;
	else if(s[m+1]=='+') flag=true;
	if(!flag){
		result=s.substr(1,1)+s.substr(3,m-3);
		if(a!=0){
			for(int i=0;i<a-1;i++){
			result="0"+result;
		}
		result="0."+result;
		}else{
			result=s.substr(1,m-1);
		}
	}else{
		if(n-6<=a){
			result=s.substr(1,1)+s.substr(3,m-3);
			for(int i=1;i<a-m+4;i++){
				result=result+"0";
			}
		}else{
			result=s.substr(1,1)+s.substr(3,a)+"."+s.substr(3+a,m-a-3);
		}
	}
	if(s[0]=='-'){
		result=s[0]+result;
	}
	cout<<result;
	return 0;
}
