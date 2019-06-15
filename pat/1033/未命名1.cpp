#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct gasStation{
	double price;
	double distance;
};
bool cmp1(gasStation a,gasStation b){
	return a.distance<b.distance;
}
int main(){
	int dpg,num;
	double volumn,goal;
	scanf("%lf %lf %d %d",&volumn,&goal,&dpg,&num);
	vector<gasStation> gasstation(num+1);
	double a,total=0.0;
	double b;
	for(int i=0;i<num;i++){
		cin>>a>>b;
		gasstation[i].price=a;
		gasstation[i].distance=b;
	}
	gasstation[num]={0,goal};
	double maxdistance=volumn*dpg;
	double now=0.0;
	double remain=0.0;
	sort(gasstation.begin(),gasstation.end(),cmp1);
	if(gasstation[0].distance!=0){
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	double temp,nowprice,min=gasstation[0].price;
	int i,location=0;
	nowprice=min;
	while(now<goal){
		int first=location;
		i=location+1;
		temp=maxdistance+now;
		min=gasstation[i].price;
		while(temp>=gasstation[i].distance&&i<num+1){
			if(nowprice>=gasstation[i].price){
				total+=((gasstation[i].distance-now)/dpg-remain)*nowprice;
				remain=0.0;
				nowprice=gasstation[i].price;
				now=gasstation[i].distance;
				location=i;
				break;
			}
			if(min>=gasstation[i].price){
				min=gasstation[i].price;
				location=i;
			}
			i++;
		}
		if(location==first){
			now=temp;
			break; 
		}else if(location!=first){
				total+=(volumn-remain)*nowprice;
				remain=volumn-(gasstation[location].distance-now)/dpg;
				now=gasstation[location].distance;
				nowprice=gasstation[location].price;
		}
	}
	if(now!=goal){
		printf("The maximum travel distance = %.2f",now);
	}else if(now==goal){
		printf("%.2f",total);
	}
	return 0;
}
