bool isPopOrder(int pushStack[],int popList[])
{
	if (pushStack.length == 0 || popList.length == 0)
	{
		return false;
	}

	Stack<int> stack  = new Stack<int>();
	int j = 0;
	for (int i = 0; i < pushStack.length; ++i)
	{
		stack.push(pushStack[i]);

		while(j<pushStack.length && pushStack.top ==popList[j])
		{
			pushStack.pop();
			j++;
		}
	}
}