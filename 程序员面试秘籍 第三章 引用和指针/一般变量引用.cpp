//
//  main.cpp
//  code
//
//  Created by 朱亚光 on 16/9/25.
//  Copyright © 2016年 朱亚光. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;


int main(int argc, const char * argv[]) {
    
    int a = 10;
    int b = 20;
    
    int &rn = a;
    int rqual;
    
    rn =b;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    
    rn  =100;
    
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    
    rqual = (&a == &rn)?1:0;
    
    cout<<"equal="<<rqual<<endl;
    
    
    return 0;
    
  
}



