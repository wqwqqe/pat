#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct stu{
	char name[11];
	char id[11];
	int grade;
};
bool cmp1(struct stu a,struct stu b){
	return a.grade>b.grade;
}
int main(){
	int n;
	scanf("%d",&n);
	vector<struct stu> result(n);
	for(int i=0;i<n;i++){
		scanf("%s %s %d",&result[i].name,&result[i].id,&result[i].grade);
	}
	sort(result.begin(),result.end(),cmp1);
	int a=0;
	int d,u;
	scanf("%d %d",&d,&u);
	for(int i=0;i<n;i++){
		if(result[i].grade>=d&&result[i].grade<=u){
			printf("%s %s\n",result[i].name,result[i].id);
			a++;
		}else if(result[i].grade<d){
			break;
		}
	}
	if(a==0){
		printf("NONE");
	}
	return 0;
}
