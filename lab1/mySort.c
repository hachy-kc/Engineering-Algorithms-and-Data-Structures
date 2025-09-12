void mySort(int d[], unsigned int n)
{
	int j;
	int tempnum;
	int index;
	for(int i = 0; i < n; i++){
		index = i;
		for(j = i+1; j < n; j++) {
			if(d[j] < d[index]){
				index = j;
			}
		}
		tempnum = d[index];
		d[index] = d[i];
		d[i] = tempnum;
	}
}
