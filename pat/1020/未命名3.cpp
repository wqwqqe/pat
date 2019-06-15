#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int index,value;
};
vector<int> pos,in;
vector<node> ans;
bool cmp(node a,node b){
	return a.index<b.index;
}
void pre(int root,int start,int end,int index){
	while(start>end) return;
	int i=start;
	while(i<end&&in[i]!=pos[root]) i++;
	ans.push_back({index,pos[root]});
	pre(root-1-end+i,start,i-1,2*index+1);
	pre(root-1,i+1,end,2*index+2);
}
int main(){
	int n;
	cin>>n;
	pos.resize(n);
	in.resize(n);
	for(int i=0;i<n;i++){
		cin>>pos[i];
	}
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	pre(n-1,0,n-1,0);
	sort(ans.begin(),ans.end(),cmp);
	for(int i=0;i<n;i++){
		cout<<ans[i].value;
		if(i!=n-1){
			cout<<' ';
		}
	}
	return 0;
}

