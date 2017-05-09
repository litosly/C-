#include <iostream>
using namespace std;
const int LEN=10+2;
int a[LEN];


void merge(int f, int m, int len){

	int n1 = len-m+1;
	int n2 = m-f;
	int a1[n1],a2[n2];
	int i,j,k;

	for(i=f;i<n1;i++){
		a1[i]=a[i+f];
	}
	
	for(i=f;i<n2;i++){
		a2[i]=a[i+m+1];
	}
	k=0;
	i=0;
	j=0;
	
	while(i<n1 && j<n2){

		if(a1[i]<a2[j]){
			a[k]=a1[i];
			i++;
		}
		else{
			a[k]=a2[j];
			j++;
		}
		k++;
	}
	
	while(i<n1){
		a[k++]=a1[i++];
	}
	while(j<n2){
		a[k++]=a2[j++];
	}
}


void merge_sort(int f, int len){
	int m =(len+f)/2;
	
	if(!(len-m<2)){
		merge_sort(f,m);
		merge_sort(m+1,len);
		merge(f,m,len);
	}
}

int main(){
	int len;
	cin>>len;
	for(int i=0;i<len;++i)
	    cin>>a[i];
	merge_sort(0,len);
	for(int i=0;i<len-1;++i)
	    cout<<a[i]<<' ';
	cout<<a[len-1]<<endl;
	return 0;
}


