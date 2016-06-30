 void replaceSpace(char *str,int length) {
        int oldstrlength =0;
        int space_number =0;
        int i=0;
        while(str[i]!='\0')
            {
            oldstrlength++;
            if(str[i]==' ')
                {
                space_number++;
            }
            i++;
        }
        int newstrlength = oldstrlength+space_number*2;
        while(oldstrlength>=0)
            {
            if(str[oldstrlength] ==' ')
                {
                str[newstrlength--]='0';
                str[newstrlength--]='2';
                str[newstrlength--]='%';
            }else
                {
                str[newstrlength--]=str[oldstrlength];
            }
            oldstrlength--;
        }
         
    }