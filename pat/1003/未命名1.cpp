#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int e[500][500],dis[500],weight[500],num[500],w[500];
bool visit[500]={false};
const int inf=99999999;
int main(){
	int n,m,start,end;
	scanf("%d %d %d %d",&n,&m,&start,&end);
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);
	}
	fill(e[0],e[0]+500*500,inf);
	fill(dis,dis+500,inf);
	int a,b,c;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&c);
		e[a][b]=e[b][a]=c;
	}
	num[start]=1;
	dis[start]=0;
	w[start]=weight[start];
	for(int i=0;i<n;i++){
		int u=-1,min=inf;
		for(int j=0;j<n;j++){
			if(!visit[j]&&dis[j]<min){
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) break;
		visit[u]=true;
		for(int j=0;j<n;j++){
			if(!visit[j]&&e[u][j]!=inf){
				if(dis[u]+e[u][j]<dis[j]){
					dis[j]=dis[u]+e[u][j];
					num[j]=num[u];
					w[j]=w[u]+weight[j];
				}else if(dis[u]+e[u][j]==dis[j]){
					num[j]=num[u]+num[j];
					if(w[u]+weight[j]>w[j]){
						w[j]=w[u]+weight[j];
					}
				}
			}
		}
	}
	printf("%d %d",num[end],w[end]);
	return 0;
}
