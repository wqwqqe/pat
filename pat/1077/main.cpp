#include<iostream>
#include<sstream>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	int n;
	stringstream ss;
	ss<<s;
	ss>>n;
	string a[n];
	for(int i=0;i<n;i++){
		getline(cin,a[i]);
	}
	int min=a[0].length(),len1=a[0].length();
	for(int i=1;i<n;i++){
		int m=a[i].length();
		if(min>m){
			min=m;
		}
	}
	int result=0;
	for(int i=1;i<=min;i++){
		int flag=1;
		for(int j=1;j<n;j++){
			int len2=a[j].length();
			if(a[0][len1-i]==a[j][len2-i]){
				flag++;
			}else{
				break;
			}
		}
		if(flag!=n){
			break;
		}else{
			result++;
		}
	}
	if(result!=0){
		for(int i=result;i>=1;i--){
			cout<<a[0][len1-i];
		}
	}else{
		cout<<"nai";
	}
	return 0;
}
