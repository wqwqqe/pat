#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	char name[10];
	int t;
};
bool cmp1(node a,node b){
	return a.t==b.t?strcmp(a.name,b.name)<0:a.t>b.t;
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	vector<node> a;
	for(int i=0;i<n;i++){
		node temp;
		cin>>temp.name>>temp.t;
		a.push_back(temp);
	}
	sort(a.begin(),a.end(),cmp1);
	int b=0;
	vector<node> result[k];
	for(int i=0;i<k;i++){
		int m;
		if(i==0)  m=n/k+n%k;
		else  m=n/k;
		int mid=m/2+1;
		result[i].resize(m);
		result[i][mid-1]=a[b];
		int c=0;
		for(int j=mid-2;j>=0;j--){
			result[i][j]=a[b+2*c+1];
			c++;
		}
		c=1;
		for(int j=mid;j<m;j++){
			result[i][j]=a[b+2*c];
			c++;
		}
		b+=m;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<result[i].size();j++){
			if(j!=0) cout<<" ";
			cout<<result[i][j].name;
		}
		cout<<endl;
	}
	return 0;
}
