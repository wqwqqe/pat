#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct student{
	string name;
	string id;
	int grade;
	int gender;
};
bool cmp1(student a,student b){
	return a.gender==b.gender?a.grade<b.grade:a.gender<b.gender;
}
int main(){
	int n;
	cin>>n;
	string s1,s2;
	char c;
	int a,b;
	vector<student> result(n);
	for(int i=0;i<n;i++){
		cin>>s1>>c>>s2>>a;
		if(c=='M'){
			b=1;
		}else{
			b=2;
		}
		result[i]={s1,s2,a,b};
	}
	sort(result.begin(),result.end(),cmp1);
	int flag=0;
	if(result[n-1].gender==2){
		cout<<result[n-1].name<<" "<<result[n-1].id<<endl;
		flag++;
	}else{
		cout<<"Absent"<<endl;
	}
	if(result[0].gender==1){
		cout<<result[0].name<<" "<<result[0].id<<endl;
		flag++;
	}else{
		cout<<"Absent"<<endl;
	}
	if(flag==2){
		cout<<result[n-1].grade-result[0].grade;
	}else{
		cout<<"NA";
	}
	return 0;
}
