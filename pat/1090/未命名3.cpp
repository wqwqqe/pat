#include<iostream>
#include<vector>
using namespace std;
vector<int> a[100010];
int n,maxn,root;
double p,r,maxp=0.0;
void dfs(int root,double price){
	if(a[root].size()==0){
		if(price>maxp){
			maxp=price;
			maxn=1;
		}else if(price==maxp){
			maxn++;
		}
		return ;
	}
	for(int i=0;i<a[root].size();i++){
		dfs(a[root][i],price*(1+r));
	}
}
int main(){
	scanf("%d %lf %lf",&n,&p,&r);
	r=r/100;
	for(int i=0;i<n;i++){
		int b;
		scanf("%d",&b);
		if(b!=-1){
			a[b].push_back(i);
		}else{
			root=i;
		}
	}
	dfs(root,p);
	printf("%.2lf %d",maxp,maxn);
	return 0;
}
