#include<iostream>
#include<vector>
using namespace std;
vector<int> num;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		num.push_back(a);
	}
	int count=0;
	for(int i=1;i<n;i++){
		if(i!=num[i]){
			while(num[0]!=0){
				swap(num[0],num[num[0]]);
				count++;
			}
			if(i!=num[i]){
				swap(num[0],num[i]);
				count++;
			}
		}
	}
	printf("%d",count);
	return 0;
}
