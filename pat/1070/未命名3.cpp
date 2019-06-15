#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	double price,amount;
};
bool cmp(node a,node b){
	return a.price>b.price;
}
int main(){
	int n;
	double m;
	scanf("%d %lf",&n,&m);
	vector<node> result(n);
	for(int i=0;i<n;i++){
		double a;
		scanf("%lf",&a);
		result[i].amount=a;
	}
	for(int i=0;i<n;i++){
		double a;
		scanf("%lf",&a);
		result[i].price=a/result[i].amount;
	}
	sort(result.begin(),result.end(),cmp);
	int i=0;
	double money=0.0;
	while(m!=0.0){
		if(m>=result[i].amount){
			m-=result[i].amount;
			money+=result[i].amount*result[i].price;
			i++;
			if(i>n) break;
		}else{
			money+=m*result[i].price;
			m=0.0;
		}
	}
	printf("%.2f",money);
	return 0;
}
