#include <iostream>
#include <algorithm>
using namespace std;
const int LEN=10+2;
int a[LEN];

void bubble_sort(int f,int len){
	int i,j=0;
	bool flag = true;
	while(flag){
	flag = false;
	j++;
	 	for(i=f;i<len-j;i++){
	 		if(a[i] > a[i+1]){
	 			swap(a[i],a[i+1]);
				flag=true;
			}
		}
	}
}


int main(){
	int len;
	cin>>len;
	for(int i=0;i<len;++i)
	    cin>>a[i];
	bubble_sort(0,len);
	for(int i=0;i<len-1;++i)
	    cout<<a[i]<<' ';
	cout<<a[len-1]<<endl;
	return 0;
}


