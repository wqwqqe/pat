#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	int n=s.size();
	int max=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			string s1=s.substr(i,j-i+1);
			string s2=s1;
			reverse(s1.begin(),s1.end());
			if(s1==s2){
				if(s1.size()>max){
					max=s1.size();
				}
			}
		}
	}
	cout<<max;
	return 0;
}
