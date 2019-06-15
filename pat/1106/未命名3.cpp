#include<iostream>
#include<vector>
using namespace std;
double p,r,maxn=10000000000.0;
vector<int> a[100010];
int num=0;
void dfs(int root,double p){
	if(a[root].size()==0){
		if(p<maxn){
			num=1;
			maxn=p;
		}else if(p==maxn){
			num++;
		}
	}
	for(int i=0;i<a[root].size();i++){
		dfs(a[root][i],p*r);
	}
}
int main(){
	int n;
	scanf("%d %lf %lf",&n,&p,&r);
	r=r/100+1;
	for(int i=0;i<n;i++){
		int m;
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			int b;
			scanf("%d",&b);
			a[i].push_back(b);
		}
	}
	dfs(0,p);
	printf("%.4lf %d",maxn,num);
	return 0;
}
