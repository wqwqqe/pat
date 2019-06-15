#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int add,data,next;
}node[100010];
int main(){
	int sta,n,m;
	int flag;
	scanf("%d %d %d",&sta,&n,&m);
	for(int i=0;i<n;i++){
		int add,data,next;
		scanf("%d %d %d",&add,&data,&next);
		struct node temp={add,data,next};
		node[add]=temp;
	}
	vector<struct node> result;
	int i=sta;
	while(i!=-1){
		result.push_back(node[i]);
		i=node[i].next;
	}
	n=result.size();
	vector<struct node> final=result;
	for(int i=0;i<(n-n%m);i++){
		final[i]=result[i / m * m + m - 1 - i % m];
	}
	for(int i=0;i<n-1;i++){
		printf("%05d %d %05d\n",final[i].add,final[i].data,final[i+1].add);
	}
	printf("%05d %d -1",final[n-1].add,final[n-1].data);
	return 0;
}
