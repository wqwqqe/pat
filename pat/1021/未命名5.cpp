#include<iostream>
#include<algorithm>
#include<vector>;
using namespace std;
bool visit[10001];
vector<int> e[10001];
int maxdepth;
void dfs(int index,int depth){
	visit[index]=true;
	if(depth>maxdepth){
		maxdepth=depth;
	}
	for(int i=0;i<e[index].size();i++){
		if(!visit[e[index][i]]){
			dfs(e[index][i],depth+1);
		}
	}
	return;
}
int main(){
	int n;
	cin>>n;
	int a,b;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	int i=1,count=1;
	int max=0;
	vector<int> result;
	do{
		fill(visit,visit+10001,false);
		maxdepth=0;
		dfs(i,0);
		for(int j=1;j<=n;j++){
			if(!visit[j]){
				dfs(j,0);
				count++;
			}
		}
		if(count>1){
			printf("Error: %d components",count);
			return 0;
		}else{
			if(maxdepth>max){
				max=maxdepth;
				result.clear();
				result.push_back(i);
			}else if(maxdepth==max){
				result.push_back(i);
			}
		}
		i++;
	}while(i<=n);
	for(int j=0;j<result.size();j++){
		cout<<result[j];
		if(j!=(result.size()-1)) cout<<endl;
	}
	return 0;
}
