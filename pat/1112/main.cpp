#include<iostream>
#include<vector>
using namespace std;
bool book[256]={false};
bool book2[256]={false};
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<char> c1;
	vector<char> c2;
	int n1=s.size();
	for(int i=0;i<n1-n+1;i++){
		int j;
		for( j=1;j<n;j++){
			if(s[i]!=s[i+j]){
				book[s[i]]=true;
				break;
			}
		}
		i=i+j-1;
	}

	for(int i=0;i<n1;i++){
		int flag=1;
		for(int j=1;j<n;j++){
			if(s[i]!=s[i+j]){
				break;
			}
			flag++;
		}
		if(flag==n){
			if(!book[s[i]]){
				c1.push_back(s[i]);
				i=i+n-1;
			}
		}
		c2.push_back(s[i]);
	}
	for(int i=0;i<c1.size();i++){
		if(!book2[c1[i]]){
			cout<<c1[i];
			book2[c1[i]]=true;
		}
	}
	cout<<endl;
	for(int i=0;i<c2.size();i++){
		cout<<c2[i];
	}
	return 0;
} 
