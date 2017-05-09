#include <iostream>
//#include <algorithm>
using namespace std;
const int LEN=10+2;
int a[LEN];

void sele_sort(int f,int len){
	 int i,j;
	 for(i=f;i<len-1;++i) {
	 	int min=i;
	 	for(j=i+1;j<len;++j)
	 	   if (a[min]>a[j]) min=j;
	 	int temp=a[i];
		a[i]=a[min];
		a[min]=temp;  //swap(a[i],a[min]);    
	 }
}

int main(){
	int len;
	cin>>len;
	for(int i=0;i<len;++i)
	    cin>>a[i];
	sele_sort(0,len);
	for(int i=0;i<len-1;++i)
	    cout<<a[i]<<' ';
	cout<<a[len-1]<<endl;
	return 0;
}






