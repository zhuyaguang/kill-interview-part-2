void Reverse(char *start,char *end){
	if (start == NULL || end == NULL)
	{
		return;
	}

	while(start < end ){
		char temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}

char * leftRotateString(char *ptr,int n){
	int length = strlen(ptr);

	char *start1 = ptr;
	char *end1 = ptr+n-1;
	char *start2 = ptr+n;
	char *end2 = ptr+length-1;

	Reverse(start1,end1);
	Reverse(start2,end2);
	Reverse(start1,end2);
}