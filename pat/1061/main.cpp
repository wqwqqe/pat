#include<iostream>
#include<cctype>
using namespace std;
int main(){
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	char e[2];
	int i=0;
	while(i<a.length()&&i<b.length()){
		if(a[i]==b[i]&&(a[i]>='A'&&a[i]<='G')){
			e[0]=a[i];
			break;
		}
		i++;
	}
	i++;
	while(i<a.length()&&i<b.length()){
		if(a[i]==b[i]&&((a[i]>='A'&&a[i]<='N')||isdigit(a[i]))){
			e[1]=a[i];
			break;
		}
		i++;
	}
	i=0;
	int f;
	while(i<c.length()&&i<d.length()){
		if(c[i]==d[i]&&isalpha(c[i])){
			f=i;
			break;
		}
		i++;
	}
	string week[7]={"MON ","TUE ","WED ","THU ","FRI ","SAT ","SUN "};
	cout<<week[e[0]-'A'];
	int m=isdigit(e[1])?e[1]-'0':e[1]-'A'+10;
	printf("%02d:%02d",m,f);
	return 0;
}
