#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
char name[40001][5];
vector<int> course[2501];
bool cmp1(int a,int b){
	return (strcmp(name[a],name[b])<0);
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int num;
		scanf("%s %d",name[i],&num);
		for(int j=0;j<num;j++){
			int b;
			scanf("%d",&b);
			course[b].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		int size=course[i].size();
		printf("%d %d\n",i,size);
		sort(course[i].begin(),course[i].end(),cmp1);
		for(int j=0;j<size;j++){
			printf("%s\n",name[course[i][j]]);
		}
	}
	return 0;
}
