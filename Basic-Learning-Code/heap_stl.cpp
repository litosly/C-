#include <queue>
#include <iostream>
using namespace std;

int main(){
	priority_queue<int> heap;
   	heap.push(3);
   	heap.push(1);
   	heap.push(2);
   	heap.push(5);
   	
    while(!heap.empty()){
 	   cout<<heap.top();
       heap.pop();
	}    
}

