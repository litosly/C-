#include <iostream>
#include <fstream> 
#include <stdlib.h>
#include <iomanip>
#include<cstring>
#include<windows.h> 
using namespace std;
int n,sum=0;
int *x;


bool check(int r){//r'th row    bring x[n] to know the location of the queens on the table
	int i;
	for(i=0;i<r ;i++){
 		if( (x[r]==x[i])) || abs(r-i)==abs(x[r]-x[i])){
			//decide whether they are in the same column, the same corner line
			//  x[r]==x[i] || abs(r-i)==abs(x[r]-x[i])
			return false;
		}
	}
	return true;
}

void recursion_method(int r){
	int i;
	if(r>=n){
		output();
		sum++;
	}
	else{
		for(i=0;i<n;i++){
			x[r] = i;
			if(check(r)){
				recursion_method(r+1);
			}
		}
	}
}


void Nqueens(){
	recursion_method(0);
} 

void output(){
	int i,j;
	cout<<"number "<<sum<<"'s plan";
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j==x[i]){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
	}
	cout<<endl;
}

int main(){
	cout<< "the number of the queens is: ";
	cin>>n;
	
	x=(int *)malloc(sizeof(int)*n);
	Nqueens();
	
}
