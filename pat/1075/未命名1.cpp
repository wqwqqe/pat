#include<iostream>
#include<vector>
#include<algorithm>
struct stu{
	int id,numOfPerfect;
	int score[6]={-10,-10,-10,-10,-10,-10};
	int total=0;
	int rank;
	bool flag;
};
bool cmp1(struct stu a,struct stu b){
	if(a.total==b.total){
		return a.numOfPerfect==b.numOfPerfect?a.id<b.id:a.numOfPerfect>b.numOfPerfect;
	}else{
		return a.total>b.total;
	}
}
using namespace std;
int main(){
	int numOfStudent,numOfProblem,numOfSub;
	scanf("%d %d %d",&numOfStudent,&numOfProblem,&numOfSub);
	int total[numOfProblem+1];
	for(int i=1;i<=numOfProblem;i++){
		scanf("%d",&total[i]);
	}
	vector<struct stu> students(numOfStudent+1);
	for(int i=0;i<numOfSub;i++){
		int id,problem,goal;
		scanf("%d %d %d",&id,&problem,&goal);
		students[id].id=id;
		if(goal!=-1){
			students[id].flag=true;
		}
		if(goal>students[id].score[problem]){
			students[id].score[problem]=goal;
		}
	}

	for(int i=1;i<=numOfStudent;i++){
		for(int j=1;j<=numOfProblem;j++){
			if(students[i].score[j]!=-10&&students[i].score[j]!=-1){
				students[i].total+=students[i].score[j];
			}
			if(students[i].score[j]==total[j]){
				students[i].numOfPerfect++;
			}
		}
	}
	sort(students.begin()+1,students.end(),cmp1);
	int num=0,rank=1;
    for(int i = 1; i <= numOfStudent; i++) {
        students[i].rank = i;
        if(i != 1 && students[i].total == students[i - 1].total)
            students[i].rank = students[i - 1].rank;
    }
	for(int i=1;i<=numOfStudent;i++){
		if(students[i].flag==true){
			printf("%d %05d %d",students[i].rank,students[i].id,students[i].total);
			for(int j=1;j<=numOfProblem;j++){
				if(students[i].score[j]!=-10&&students[i].score[j]!=-1){
					printf(" %d",students[i].score[j]);
				}else if(students[i].score[j]==-10){
					printf(" -");
				}else if(students[i].score[j]==-1){
					printf(" 0");
				}
			}
			printf("\n");			
		}
	}
	return 0;
}
