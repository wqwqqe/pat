#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool sort1(int a,int b){
	return a<b;
}
int main(){
	int a;
	cin>>a;
	int c=1;
	vector<int> b;
	while(c!=6174&&c!=0){
		for(int i=0;i<4;i++){
			b.push_back(a%10);
			a/=10;
		}
		sort(b.begin(),b.end(),sort1);
		int d=0,e=0;
		for(int i=0;i<4;i++){
			d=10*d+b[i];
			e=10*e+b[3-i];
		}
		b.clear();
		c=e-d;
		printf("%04d - %04d = %04d\n",e,d,c);
		a=c;
	}
	return 0;

	
}
