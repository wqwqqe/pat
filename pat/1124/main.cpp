#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int main(){
	int n,m,s;
	scanf("%d %d %d",&m,&n,&s);
	map<string,int> mapp;
	string s1;
	bool flag=false;
	for(int i=1;i<=m;i++){
		cin>>s1;
		if(i==s&&mapp[s1]==0){
			mapp[s1]=1;
			flag=true;
			cout<<s1<<endl;
			s=s+n;
		}else if(i==s&&mapp[s1]==1){
			s++;
		}
	}
	if(!flag){
		cout<<"Keep going...";
	}
	return 0;
}
