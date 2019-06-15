#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
	int weight,rank,index,index0;
};
bool cmp1(node a,node b){
	return a.index0<b.index0;
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	vector<int> num(n);
	vector<node> t(n);
	queue<node> q;
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	int a;
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		t[i].weight=num[a];
		t[i].index=i;
		t[i].index0=a;
		q.push(t[i]);
	}
	int max=-1;
	while(!q.empty()){
		int size=q.size();
		if(size==1){
			node temp=q.front();
			t[temp.index].rank=1;
			break;
		}
		int group=size/k;
		if(size%k!=0) group++;
		node maxnode;
		int count=0;
		for(int i=0;i<size;i++){
			node temp=q.front();
			t[temp.index].rank=group+1;
			q.pop();
			count++;
			if(temp.weight>max){
				max=temp.weight;
				maxnode=temp;
			}
			if(count==k||i==size-1){
				q.push(maxnode);
				count=0;
				max=-1;
			}
		}	
	}
	sort(t.begin(),t.end(),cmp1);
	for(int i=0;i<n;i++){
		if(i!=0) printf(" ");
		printf("%d",t[i].rank);
	}
	return 0;
}
