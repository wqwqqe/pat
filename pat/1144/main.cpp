#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool sort1(int a,int b){
	return a<b;
}
int main(){
	int n,m;
	cin>>n;
	vector<int> book;
	for(int i=0;i<n;i++){
		cin>>m;
		if(m>0){
			book.push_back(m);
		}
	}
	sort(book.begin(),book.end(),sort1);
	n=book.size();
	int flag=1;
	for(int i=0;i<n;i++){
		if(book[i]>flag){
			break;
		}else if(book[i]==flag){
			flag++;
		}
	}
	cout<<flag;
	return 0;
}
