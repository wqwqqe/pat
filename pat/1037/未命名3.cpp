#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int m1;
	cin>>m1;
	vector<int> cou(m1);
	for(int i=0;i<m1;i++){
		cin>>cou[i];
	}
	int m2;
	cin>>m2;
	vector<int> pro(m2);
	for(int i=0;i<m2;i++){
		cin>>pro[i];
	}
	sort(cou.begin(),cou.end());
	sort(pro.begin(),pro.end());
	int p=0,q=0,total=0;
	while(p<m1 && q<m2 && cou[p]<0 && pro[q]<0){
		total+=cou[p]*pro[q];
		p++;
		q++;
	}
	p=m1-1;
	q=m2-1;
	while(p>=0&&q>=0&&cou[p]>0&&pro[q]>0){
		total+=cou[p]*pro[q];
		p--;
		q--;
	}
	cout<<total;
	return 0;
} 
