#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct student{
	int id,best;
	int score[4],rank[4];
}stu[2001];
int exist[1000000],flag=-1;
bool sort1(student a,student b){
	return a.score[flag]>b.score[flag];
}
int main(){
	int n,m,id;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&stu[i].id,&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
		stu[i].score[0]=(stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3;
	}
	for(flag=0;flag<=3;flag++){
		sort(stu,stu+n,sort1);
		stu[0].rank[flag]=1;
		for(int i=1;i<n;i++){
			stu[i].rank[flag]=i+1;
			if(stu[i].score[flag]==stu[i-1].score[flag]){
				stu[i].rank[flag]=stu[i-1].rank[flag];
			}
		}
	}
	for(int i=0;i<n;i++){
		exist[stu[i].id]=i+1;
		int best=0;
		int min=stu[i].rank[0];
		for(flag=1;flag<=3;flag++){
			if(stu[i].rank[flag]<min){
				min=stu[i].rank[flag];
				stu[i].best=flag;
			}
		}
	}
	char c[5]={'A','C','M','E'};
	for(int i=0;i<m;i++){
		cin>>id;
		int temp=exist[id];
		if(temp){
			int best=stu[temp-1].best;
			cout<<stu[temp-1].rank[best]<<" "<<c[best]<<endl;
		}else{
			cout<<"N/A"<<endl;
		}
	}
	return 0;
}
