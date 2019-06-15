#include<iostream>
#include<vector>
using namespace std;
vector<int> m[100010];
vector<int> supply;
double total=0.0,p,r;
int depth=0;
void dfs(int index,double price){
	if(m[index].size()==0){
		total+=supply[index]*price;
		return ;
	}else{
		for(int i=0;i<m[index].size();i++){
			dfs(m[index][i],price*(1+r));
		}
	}
}
int main(){
	int n;
	scanf("%d %lf %lf",&n,&p,&r);
	supply.resize(n);
	r/=100;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(a==0){
			int b;
			scanf("%d",&b);
			supply[i]=b;
		}else{
			for(int j=0;j<a;j++){
				int b;
				scanf("%d",&b);
				m[i].push_back(b);
			}	
		}
	}
	dfs(0,p);
	printf("%0.1lf",total);
	return 0;
}
