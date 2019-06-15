#include<iostream>
using namespace std;
struct node{
	char c;
	int next;
	bool flag;
}node[100000];
int main(){
	int n,m,num;
	scanf("%d %d %d",&n,&m,&num);
	int temp,b;
	char name;
	for(int i=0;i<num;i++){
		scanf("%d %c %d",&temp,&name,&b);
		node[temp]={name,b,false};
	}
	for(int i=n;i!=-1;i=node[i].next){
		node[i].flag=true;
	}
	for(int i=m;i!=-1;i=node[i].next){
		if(node[i].flag){
			printf("%05d",i);
			return 0;
		}
	}
	cout<<-1;
	return 0;
}
