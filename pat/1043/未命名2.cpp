#include<iostream>
#include<vector>
using namespace std;
vector<int> pre,post;
bool ismirror=false;
void getpos(int root,int end){
	if(root>end) return;
	int i=root+1,j=end;
	if(!ismirror){
		while(i<=end&&pre[root]>pre[i]) i++;
		while(j>root&&pre[root]<=pre[j]) j--;
	}else{
		while(i<=end&&pre[root]<=pre[i]) i++;
		while(j>root&&pre[root]>pre[j]) j--;
	}
	if(i-j!=1) return;
	getpos(root+1,j);
	getpos(i,end);
	post.push_back(pre[root]);
}
int main(){
	int n;
	scanf("%d",&n);
	pre.resize(n);
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	getpos(0,n-1);
	if(post.size()!=n){
		ismirror=true;
		post.clear();
		getpos(0,n-1);
	}
	if(post.size()==n){
		cout<<"YES"<<endl;
		cout<<post[0];
		for(int i=1;i<post.size();i++){
			cout<<" "<<post[i];
		}
	}else{
		cout<<"NO";
	}
	return 0;
}
