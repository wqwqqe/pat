#include<iostream>
#include<vector> 
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int m;
		cin>>m;
		vector<int> a(m);
		bool result=true;
		for(int j=0;j<m;j++){
			cin>>a[j];
			for(int k=0;k<j;k++){
				if(a[k]==a[j]||abs(a[k]-a[j])==abs(k-j)){
					result =false;
					break;
				}
			}
		}
			cout<<(result?"YES\n":"NO\n");
	}
	return 0;
}
