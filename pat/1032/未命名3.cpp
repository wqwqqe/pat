#include<iostream>
#include<map>
using namespace std;
struct node{
	char c;
	int next;
}node[100000];
int main(){
	int n,m,num;
	scanf("%d %d %d",&n,&m,&num);
	map<char,node> result;
	int temp,b;
	char name;
	for(int i=0;i<num;i++){
		scanf("%d %c %d",&temp,&name,&b);
		node[temp]={name,b};
		result[node[temp].c]=node[temp];
	}
	string s1="",s2="";
	for(int i=n;i!=-1;i=node[i].next){
		s1+=node[i].c;
	}
	for(int i=m;i!=-1;i=node[i].next){
		s2+=node[i].c;
	}
	n=s1.size();
	m=s2.size();
	int a;
	num=n<m?n:m;
	for(int i=1;i<=num;i++){
		a=i;
		if(s1[n-i]!=s2[m-i]){
			break;
		}
	}
	if(a==1){
		cout<<-1;
	}else if(a!=num){
		printf("%05d",result[s1[n-a+1]]);
	}else if(a==num&&num==n){
		printf("%05d",result[s1[n-a]]);
	}else if(a==num&&num==m){
		printf("%05d",result[s2[m-a]]);
		}
	return 0;
}
