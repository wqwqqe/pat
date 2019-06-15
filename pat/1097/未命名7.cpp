#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool flag[10001];
struct node{
	int add,val,next;
}node[100010];
int main(){
	int start,n;
	scanf("%d %d",&start,&n);
	vector<struct node> a,b;	
	for(int i=0;i<n;i++){
		int c;
		scanf("%d",&c);
		scanf("%d %d",&node[c].val,&node[c].next);
		node[c].add=c;
	}
	for(int i=start;i!=-1;i=node[i].next){
		if(!flag[abs(node[i].val)]){
			flag[abs(node[i].val)]=true;
			a.push_back(node[i]);
		}else{
			b.push_back(node[i]);
		}
	}
	if(a.size()!=0){
		for(int i=0;i<a.size()-1;i++){
			printf("%05d %d %05d\n",a[i].add,a[i].val,a[i+1].add);
		}
		printf("%05d %d -1\n",a[a.size()-1].add,a[a.size()-1].val);
	}
	if(b.size()!=0){
		for(int i=0;i<b.size()-1;i++){
			printf("%05d %d %05d\n",b[i].add,b[i].val,b[i+1].add);
		}
		printf("%05d %d -1\n",b[b.size()-1].add,b[b.size()-1].val);	
	}
	return 0;	
}
