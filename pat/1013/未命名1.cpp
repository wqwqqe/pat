#include<iostream>
using namespace std;
int e[1001][1001]={0};
bool visit[1001]={false};
int n,m,k;
void dfs(int node){
	visit[node]=true;
	for(int i=1;i<=n;i++){
		if(visit[i]==false&&e[node][i]==1){
			dfs(i);
		}
	}
	return ;
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	int a,b;
	for(int i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		e[a][b]=e[b][a]=1;
	}
	int c;
	for(int i=1;i<=k;i++){
		scanf("%d",&c);
		int count=0;
		for(int j=1;j<=n;j++){
			visit[j]=false;
		}
		visit[c]=true;
		for(int j=1;j<=n;j++){
			if(!visit[j]){
				dfs(j);
				count++;
			}
		}
		cout<<count-1<<endl;
	}
	return 0;
} 
