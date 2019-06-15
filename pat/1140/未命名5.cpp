#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string countandsay(string s){
	int n=s.size();
	int flag=0;
	string s1="";
	string c;
	int i,j;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(s[i]==s[j]){
				flag++;
			}else{
				break;
			}
		}
		s1+=s[i];
		c=to_string(flag);
		s1+=+c;
		flag=0;
		i=j-1;
	}
	return s1;
}
int main(){
	string s;
	int n;
	cin>>s;
	cin>>n;
	for(int i=0;i<n-1;i++){
		s=countandsay(s);
	}
	cout<<s;
	return 0;
}
