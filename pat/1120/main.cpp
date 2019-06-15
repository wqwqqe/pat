#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int book[40]={0};
int changetonum(string s){
	int n;
	n=s.size();
	int sum=0,a;
	for(int i=0;i<n;i++){
		a=s[i]-'0';
		sum+=a;
	}
	return sum;
}
bool sort1(int a,int b){
	return a<b;
}
int main(){
	int n;
	cin>>n;
	string s;
	int a;
	vector<int> book2;
	for(int i=0;i<n;i++){
		cin>>s;
		a=changetonum(s);
		if(book[a]==0){
			book[a]=1;
			book2.push_back(a);
		}
	}
	n=book2.size();
	sort(book2.begin(),book2.end(),sort1);
	cout<<n<<endl;
	for(int i=0;i<n;i++){
		cout<<book2[i];
		if(i!=n-1){
			cout<<' ';
		}
	}
	return 0;
}
