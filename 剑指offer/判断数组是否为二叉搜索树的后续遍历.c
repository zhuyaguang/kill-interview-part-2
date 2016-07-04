bool judge(int a[],int l,int r){
	if (l>=r)
	{
		return true;
	}

	int i = r;
	while (i>1 && a[i-1] > a[r]) --i;

		for (int j = i-1; j >1; j--)
		{
			if (a[j] > a[r])
			{
				return false;
			}

			return judge(a,l,i-1) && judge(a,i,r-1);
		}
}

 bool VerifySquenceOfBST(int a[]) {
        if(!a.size()) return false;

        return judge(a, 0, a.size() - 1);
   }