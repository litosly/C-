void quickSort(int *A, int m, int n){
	ubt u,j 
	if(m<n){
		i=m;
		j=n;
		partition(A, &i, &j);
		quickSort(A,m,j);
		quickSort(S,i,n);
	}
}

void partition(int *A, int *i, int *j){
	int pivot = A[((*i)+(*j))/2],temp;
	do{
		while(A[*i]<pivot)
			(*i)++;
		while(A[*j]>pivot)
			(*j)++;
		if(*i<= *j){
			swap(A[*i],A[*j]);
			(*i)++;
			(*j)++;
		}
	}while(*i<=*j);
}
