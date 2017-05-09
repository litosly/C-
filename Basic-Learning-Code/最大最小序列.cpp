int max_increasing_list(int point){
	int ans=0;
	if(point == n){
		return 0;
	}
	
	if(b[point]!= -1){
		return b[point];
	}
	
	for(int i=1;i<n-point+1;i++){
		if(a[point]<a[point + i]){
			ans = max(ans,max_increasing_list(point+i) + 1);
		}
	}
	b[point] = ans;
	
	return ans;
}


int max_decreasing_list(int point){
	int ans = 1;
	if(point == n){
		return 0;
	}
	
	if(c[point]!= -1){
		return b[point];
	}
	
	for(int i=1;i<n-point+1;i++){
		if(a[point]>a[point + i]){
			ans = max(ans,max_decreasing_list(point+i) + 1);
		}
	}
	c[point] = ans;
	
	return ans;
}

