// remove duplicate element from sorted array
int removeDuplicates(vector<int> &arr, int n) {
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=arr[j])
			arr[++j]=arr[i];
	}
	return j+1;
}