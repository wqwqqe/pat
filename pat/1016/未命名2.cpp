#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct customer{
	string name;
	int status,month,time,day,hour,minute;
};
bool cmp(customer a,customer b){
	return a.name!=b.name?a.name<b.name:a.time<b.time;
}
double moneyFromZero(customer a,int *money){
	double total=a.minute*money[a.hour]+a.day*money[24]*60;
	for(int i=0;i<a.hour;i++){
		total+=money[i]*60;
	}
	return total/100;
}
int main(){
	int money[25];
	map<string,int> name;
	for(int i=0;i<24;i++){
		cin>>money[i];
		money[24]+=money[i];
	}
	int n;
	cin>>n;
	vector<customer> data(n);
	for(int i=0;i<n;i++){
		cin>>data[i].name;
		scanf("%d:%d:%d:%d",&data[i].month,&data[i].day,&data[i].hour,&data[i].minute);
		string s2;
		cin>>s2;
		data[i].status=(s2=="on-line")?1:0;
		data[i].time=data[i].day*24*60+data[i].hour*60+data[i].minute;
	}
	sort(data.begin(),data.end(),cmp);
	map<string,vector<customer>> result;
	for(int i=1;i<n;i++){
		if(data[i].name==data[i-1].name&&data[i].status==0&&data[i-1].status==1){
			result[data[i-1].name].push_back(data[i-1]);
			result[data[i].name].push_back(data[i]);
		}
	}
	for(auto it:result){
		vector<customer> temp=it.second;
		cout<<it.first;
		printf(" %02d\n",temp[0].month);
		double total=0.0;
		for(int i=1;i<temp.size();i+=2){
			double t=moneyFromZero(temp[i],money)-moneyFromZero(temp[i-1],money);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",temp[i-1].day,temp[i-1].hour,temp[i-1].minute,temp[i].day,temp[i].hour,temp[i].minute,temp[i].time-temp[i-1].time,t);
			total+=t;
		}
		printf("Total amount: $%.2f\n",total);
	}
	return 0;
}
