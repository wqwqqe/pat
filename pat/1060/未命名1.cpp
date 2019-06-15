#include<iostream>
#include<string>
using namespace std;
string func(string s,int a){
	int n=s.size();
	int point;
	int i=0;
	for(i=0;i<n;i++){
		if(s[i]=='.'){
			point=i;
			n--;
			break;
		}
	}
	if(i==n){
		point=i;
	}
	int count=1;
	int j;
	if(point==1&&s[0]=='0'){
		for(j=2;j<n;j++){
			if(s[j]!='0'){
				break;
			}else{
				count++;
			}
		}
		i=i-count-1;
		point=point-count-1;
		n=n-count-1;
		s=s.substr(j,s.size()-j);
	}
	if(n<a){
		for(j=0;j<a-n;j++){
			s=s+"0";
			point++;
		}
	}
	string s1=s;
	if(point>=a){
		s1=s.substr(0,a);
	}else if(point<a){
		s1=s.substr(0,i)+s.substr(i+1,a-i);
	}
	s1="0."+s1+"*10^"+to_string(i);
	return s1;
}
int main(){
	int n;
	string s1,s2;
	cin>>n>>s1>>s2;
	s1=func(s1,n);
	s2=func(s2,n);
	if(s1==s2){
		cout<<"YES "<<s1;
	}else{
		cout<<"NO "<<s1<<" "<<s2;
	}
	return 0;
}
