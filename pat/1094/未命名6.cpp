#include<iostream>
#include<vector>
using namespace std;
vector<int> a[110];
int num[110];
void dfs(int root,int depth){
	num[depth]++;
	if(a[root].size()==0) return;
	for(int i=0;i<a[root].size();i++)
		dfs(a[root][i],depth+1);
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int b,n1;
		scanf("%d %d",&b,&n1);
		for(int j=0;j<n1;j++){
			int c;
			scanf("%d",&c);
			a[b].push_back(c);
		}
	}
	dfs(1,1);
	int result,maxn=0;
	for(int i=1;i<=m;i++){
		if(num[i]>maxn){
			maxn=num[i];
			result=i;
		}
	}
	cout<<maxn<<' '<<result;
	return 0;
}
