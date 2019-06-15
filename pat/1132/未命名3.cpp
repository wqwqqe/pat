#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s1,s2;
	int a1,a2;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int a;
		int m=s.size()/2;
		s1=s.substr(0,m);
		s2=s.substr(m,s.size());
		a1=stoi(s1);
		a2=stoi(s2);
		a=stoi(s);
		a1=a1*a2; 
		if(a1!=0){
			if(a%a1==0){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
} 
