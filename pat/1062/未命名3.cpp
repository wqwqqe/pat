#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int num;
	int virtue,talen,total;
	int rank;
};
vector<node> result;
bool cmp1(node a,node b){
	if(a.rank!=b.rank){
		return a.rank<b.rank;
	}else{
		if(a.total!=b.total){
			return a.total>b.total;
		}else{
			return a.virtue==b.virtue? a.num<b.num:a.virtue>b.virtue;
		}
	}
}
int main(){
	int n,l1,l2;
	int s;
	int a,b;
	scanf("%d %d %d",&n,&l1,&l2);
	int count=0;
	for(int i=0;i<n;i++){
		node temp;
		int rank;
		cin>>s>>a>>b;
		if(a<l1||b<l1){
			continue;
		}
		if(a>=l2&&b>=l2){
			rank=1;
		}else if(a>=l2&&b<l2){
			rank=2;
		}else if(a<l2&&b<l2&&a>=b){
			rank=3;
		}else{
			rank=4;
		}
		int total=a+b;
		temp={s,a,b,total,rank};
		result.push_back(temp);
	}
	sort(result.begin(),result.end(),cmp1);
	n=result.size();
	printf("%d\n",n);
	for(int i=0;i<n;i++){
		printf("%08d %d %d\n",result[i].num,result[i].virtue,result[i].talen);
	}
	return 0;
}
