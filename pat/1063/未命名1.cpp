#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> a[n+1];
	vector<map<int,bool> > flag;
	for(int i=1;i<=n;i++){
		int m;
		scanf("%d",&m);
		map<int,bool> temp;
		for(int j=0;j<m;j++){
			int b;
			scanf("%d",&b);
			if(!temp[b]){
				a[i].push_back(b);
				temp[b]=true;
			}
		}
		flag.push_back(temp);
	}
	int c;
	scanf("%d",&c);
	for(int i=0;i<c;i++){
		int d,e;
		scanf("%d %d",&d,&e);
		int count1=0,count2=a[d].size();
		map<int,bool> temp=flag[d-1];
		for(int j=0;j<a[e].size();j++){
			int f=a[e][j];
			if(!temp[f]){
				count2++;
			}else{
				count1++;
			}
		}
		float result=(float)count1/(float)count2*100;
		printf("%0.1f%%\n",result);
	}
	return 0;	
}
