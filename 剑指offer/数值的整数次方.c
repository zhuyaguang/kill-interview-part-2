 double Power(double base, int exponent) {
        
        if(exponent == 0)
            return 1;
        if(exponent == 1)
            return base;
        double result = Power(base,exponent >> 1);
        
        result = result * result ;
        
        if(exponent % 2 == 1)
            result = result *base ;
        
        return result;
    
    }


    int main{

        cout<<Power(2,4)<<endl;

        system("pause");


    }