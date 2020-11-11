//
//  main.c
//  1707
//
//  Created by JEONGMIN on 2016. 11. 28..
//  Copyright © 2016년 JEONGMIN. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

int main( )
{
    int bCheck = 0;
    char strTemp[] = " \n\t5";
    
    bCheck = isspace( strTemp[0] );
    printf( "%s\n", bCheck ? "True" : "False" );
    
    bCheck = isspace( strTemp[1] );
    printf( "%s\n", bCheck ? "True" : "False" );
    
    
    bCheck = isspace( strTemp[2] );
    printf( "%s\n", bCheck ? "True" : "False" );
    
    bCheck = isspace( strTemp[3] );
    printf( "%s\n", bCheck ? "True" : "False" );
    
    bCheck = isspace( '\n' );
    printf( "%s\n", bCheck ? "True" : "False" );
    
    return 0;
}
