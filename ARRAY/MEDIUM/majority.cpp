int majorityElement(vector<int> v) {
	int n = v.size();//moore voting algo
	int cnt=0;
	int el;
	for(int i=0;i<n;i++)//checking the most occured element
	{
		if(cnt==0)
		{
			el=v[i];
		}
		if(el==v[i])
			cnt++;
		else
			cnt--;
	}
	cnt=0;
	for(int i=0;i<n;i++)
	{
		if(v[i]==el)// counting the occurence of most occured element
			cnt++;
		if(cnt>n/2)
			return el;
			
	}
	return -1;
}