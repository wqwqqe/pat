#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int address;
	int key;
	int next;
	bool flag;
}node[100000];
bool cmp1(struct node a,struct node b){
	return !a.flag||!b.flag?a.flag>b.flag:a.key<b.key;
}
int main(){
	int n,start;
	scanf("%d %d",&n,&start);
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		node[a]={a,b,c,false};
	}
	int count=0;
	for(int i=start;i!=-1;i=node[i].next){
		node[i].flag=true;
		count++;
	}
	if(count==0){
		printf("0 -1");
	}else{
		sort(node,node+100000,cmp1);
		printf("%d %05d\n",count,node[0].address);
		for(int i=0;i<count;i++){
			printf("%05d %d",node[i].address,node[i].key);
			if(i!=count-1) printf(" %05d\n",node[i+1].address);
			else printf(" -1");
		}
	}
	return 0;
}
