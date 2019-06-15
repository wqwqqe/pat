#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string change(string s){
	replace(s.begin(),s.end(),'1','@');
	replace(s.begin(),s.end(),'0','%');
	replace(s.begin(),s.end(),'l','L');
	replace(s.begin(),s.end(),'O','o');
	return s;
}
int main(){
	int n;
	scanf("%d",&n);
	int n1=n,n2=n;
	string name,pass;
	vector<string> result;
	for(int i=0;i<n2;i++){
		cin>>name>>pass;
		if(pass.find('1')==-1&&pass.find('0')==-1&&pass.find('l')==-1&&pass.find('O')==-1){
			n-=1;
		}else{
			pass=change(pass);
			string temp=name+" "+pass;
			result.push_back(temp);
		}
	}
	if(n==0){
		if(n1==1){
			printf("There is 1 account and no account is modified");
		}else{
			printf("There are %d accounts and no account is modified",n1);
		}
	}else{
		printf("%d\n",n);
		for(int i=0;i<result.size();i++){
			cout<<result[i]<<endl;
		}
	}
	return 0;
}

