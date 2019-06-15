#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> pre,in,pos;
void postorder(int root,int start,int end){
	if(start>end) return;
	int i=start;
	while(i<end&&in[i]!=pre[root]) i++;
	postorder(root+1,start,i-1);
	postorder(root+1+i-start,i+1,end);
	pos.push_back(pre[root]);
}
int main(){
	int n;
	scanf("%d",&n);
	stack<int> a;
	for(int i=0;i<2*n;i++){
		string s;
		cin>>s;
		if(s.size()==4){
			int b;
			scanf("%d",&b);
			pre.push_back(b);
			a.push(b);
		}else{
			in.push_back(a.top());
			a.pop();
		}
	}
	postorder(0,0,n-1);
	printf("%d",pos[0]);
	for(int i=1;i<n;i++){
		printf(" %d",pos[i]);
	}
	return 0;
}
