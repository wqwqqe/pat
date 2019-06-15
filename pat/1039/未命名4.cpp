#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int getid(char *name){
	int id=0;
	for(int i=0;i<3;i++){
		id=id*26+(name[i]-'A');
	}
	return id=id*10+(name[3]-'0');
}
const int maxn=26*26*26*10+10;
vector<int> result[maxn];
int main(){
	char name[5];
	int numofstudent,numofcourse;
	scanf("%d %d",&numofstudent,&numofcourse);
	for(int i=0;i<numofcourse;i++){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int j=0;j<m;j++){
			scanf("%s",name);
			int a=getid(name);
			result[a].push_back(n);
		}
	}
	for(int i=0;i<numofstudent;i++){
		scanf("%s",name);
		int a=getid(name);
		sort(result[a].begin(),result[a].end());
		int n=result[a].size();
		if(n==0){
			printf("%s 0\n",name);
		}else{
			printf("%s %d",name,n);
			for(int j=0;j<n;j++){
				printf(" %d",result[a][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
