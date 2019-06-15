#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct student{
	string id;
	int group;
	int rank[3];
	int score;
};
vector<student> stu2;
bool cmp(student a,student b){
	return a.score==b.score?a.id<b.id:a.score>b.score;
}
int main(){
	int n,m,size=0;
	cin>>n;
	student temp;
	for(int i=1;i<=n;i++){
		cin>>m;
		vector<student> stu1(m);
		for(int j=0;j<m;j++){
			cin>>stu1[j].id>>stu1[j].score;
			stu1[j].group=i;
		}
		sort(stu1.begin(),stu1.end(),cmp);
		stu1[0].rank[1]=1;
		stu2.push_back(stu1[0]);
		for(int j=1;j<m;j++){
			if(stu1[j].score==stu1[j-1].score){
				stu1[j].rank[1]=stu1[j-1].rank[1];
			}else{
				stu1[j].rank[1]=j+1;
			}
			stu2.push_back(stu1[j]);
		}
	}
	size=stu2.size();
	sort(stu2.begin(),stu2.end(),cmp);
	stu2[0].rank[2]=1;
	for(int j=1;j<size;j++){
			if(stu2[j].score==stu2[j-1].score){
				stu2[j].rank[2]=stu2[j-1].rank[2];
			}else{
				stu2[j].rank[2]=j+1;
			}
	}
	cout<<size<<endl;
	for(int i=0;i<size;i++){
		cout<<stu2[i].id;
		printf(" %d %d %d\n",stu2[i].rank[2],stu2[i].group,stu2[i].rank[1]);
	}
	return 0;
}

