#include <iostream>
#include<string>
using namespace std;
int main(){
	string a,b;
	getline(cin,a);
	getline(cin,b);
	int n,m;
	n=a.size();
	m=b.size();
	bool flag[256]={false};
	for(int i=0;i<m;i++){
		flag[b[i]]=true;
	}
	for(int i=0;i<n;i++){
		if(!flag[a[i]]){
			cout<<a[i];
		}
	}
	return 0;
}
