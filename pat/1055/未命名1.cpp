#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
	char name[9];
	int age;
	int money;
};
int minn,maxn;
bool cmp1(struct node a,struct node b){
	if(a.money!=b.money) {
		return a.money>b.money;
	}else{
		if(a.age!=b.age){
			return a.age<b.age;
		}else{
			return strcmp(a.name,b.name)<0;
		}
	}
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	vector<node> people(n),v;
	vector<int> book(255,0);
	for(int i=0;i<n;i++){
		scanf("%s %d %d",people[i].name,&people[i].age,&people[i].money);
	}
	int x=1;
	sort(people.begin(),people.end(),cmp1);
	for(int i=0;i<n;i++){
		if(book[people[i].age]<100){
			v.push_back(people[i]);
			book[people[i].age]++;
		}
	}
	for(int i=0;i<k;i++){
		int num;
		scanf("%d %d %d",&num,&minn,&maxn);
		printf("Case #%d:\n",x);
		vector<node> t;
		for(int j=0;j<v.size();j++){
			if(v[j].age>=minn&&v[j].age<=maxn){
				t.push_back(v[j]);
			}
		}
		int flag=0;
		for(int j=0;j<num&&j<t.size();j++){
			printf("%s %d %d\n",t[j].name,t[j].age,t[j].money);
			flag=1;
		}
		if(flag==0) printf("None\n");
		x++;
	}
	return 0;
}
