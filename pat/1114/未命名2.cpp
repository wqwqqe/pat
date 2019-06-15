#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int id;
	vector<int> r;
	double set,area;
};
vector<node> person(10000);
bool visit[10000];
double totalset=0.0,totalarea=0.0;
int num,minid=10000;
vector<int> index;
void dfs(int root){
	visit[root]=true;
	num+=1;
	totalarea+=person[root].area;
	totalset+=person[root].set;
	if(person[root].id<minid){
		minid=person[root].id;
	}
	for(int i=0;i<person[root].r.size();i++){
		if(!visit[person[root].r[i]]){
			dfs(person[root].r[i]);
		}
	}
}
struct result{
	int id,num;
	double avset,avarea;
};
bool cmp1(result a,result b){
	return a.avarea==b.avarea?a.id<b.id:a.avarea>b.avarea;
}
int main(){
	int n;
	scanf("%d",&n);
	index.resize(n);
	for(int i=0;i<n;i++){
		int id,a,b,m;
		scanf("%d %d %d %d",&id,&a,&b,&m);
		index[i]=id;
		person[id].id=id;
		if(a!=-1){
			person[a].id=a;
			person[id].r.push_back(a);
			person[a].r.push_back(id);
		}
		if(b!=-1){
			person[b].id=b;
			person[b].r.push_back(id);	
			person[id].r.push_back(b);
		}
		for(int j=0;j<m;j++){
			int l;
			scanf("%d",&l);
			person[id].r.push_back(l);
			person[l].id=l;
			person[l].r.push_back(id);			
		}
		double d,e;
		cin>>d>>e;
		person[id].set=d;	
		person[id].area=e;	
	}
	vector<result> c;
	for(int i=0;i<n;i++){
		if(!visit[person[index[i]].id]){
			dfs(index[i]);
			result temp;
			temp={minid,num,totalset/num,totalarea/num};
			c.push_back(temp);
			num=0;
			totalset=0.0;
			totalarea=0.0;
			minid=10000;
		}
	}
	sort(c.begin(),c.end(),cmp1);
	int m=c.size();
	printf("%d\n",m);
	for(int i=0;i<m;i++){
		printf("%04d %d %.3lf %.3lf\n",c[i].id,c[i].num,c[i].avset,c[i].avarea);
	}
	return 0;	
}
