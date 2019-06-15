#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<k;i++){
		stack<int> result;
		vector<int> in(m+1);
		for(int j=1;j<=m;j++){
			scanf("%d",&in[j]);
		}
		int count=1;
		bool flag=false;
		for(int j=1;j<=m;j++){
			result.push(j);
			if(result.size()>n) break;
			while(!result.empty()&&result.top()==in[count]){
				result.pop();
				count++;
			}
		}
		if(count==m+1) flag=true;
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 
