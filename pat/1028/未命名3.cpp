#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
int flag;
struct node{
	int id;
	char name[10];
	int score;
};
int cmp(node a,node b){
	if(flag==1){
		return a.id<b.id;
	}else if(flag==2){
		if(strcmp(a.name,b.name)==0) return a.id<b.id;
		return strcmp(a.name,b.name)<=0;
	}else{
		if(a.score==b.score ) return a.id<b.id;
		return a.score<=b.score;
	}
}
int main(){
	int n;
	cin>>n>>flag;
	vector<node> p(n);
	for(int i=0;i<n;i++){
		scanf("%d %s %d",&p[i].id,p[i].name,&p[i].score);
	}
	sort(p.begin(),p.end(),cmp);
	for(int i=0;i<n;i++){
		printf("%06d %s %d\n",p[i].id,p[i].name,p[i].score);
	}
}
