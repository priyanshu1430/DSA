string read(int n, vector<int> book, int target)
{
   sort(book.begin(),book.end());
   int left=0,right=n-1;
   int sum=0;
   while(left<right)
   {
       sum=book[left]+book[right];
       if(sum==target)
        return("YES");
       if(sum>target)
        right--;
        else
            left++;
   }
   return("NO");
}

