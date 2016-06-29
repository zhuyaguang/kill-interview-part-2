//用8个2X1的小矩形去覆盖一个2X8的大矩形，总共有多少种办法

//迭代
 int rectCover(int number) {
        if(number==0) return 0;
        else if(number==1) return 1;
        else if(number==2) return 2;
        else {
            int i=3;
            int num1=1,num2=2,num3=0;
            while(i<=number){
              num3=num1+num2;
                num1=num2;num2=num3;
                i++;
            }
            return num3;
        }
             
    }

//递归
int rectCover(int number) {
if (number == 1 || number == 2)
	{
		return number;
	}else {
		return rectCover(number-1)+rectCover(number-2);
	}

}