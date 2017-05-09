#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int a[120];
int b[120];

int main(){
	string s1,s2;
	int ggwp;
	
	cin>>s1>>s2;
	a[0] = s1.length();
	for(int i=0;i<a[0];i++)		a[i] = s1[a[0]-i] - '0';
	for(int j=0;j<b[0];j++)		b[j] = s2[b[0]-j] - '0';
	ggwp = a[0]>b[0]?a[0]:b[0];
	for(int i=1;i<=ggwp;i++){
		a[i]+=b[i];
		a[i+1]+=a[i]/10; 
		a[i]%=10;
	}
	ggwp++;
	while((a[ggwp] == 0)&&(ggwp>1)) ggwp--;
	for(int i=ggwp;i>=1;i--) cout<<a[i];
}
