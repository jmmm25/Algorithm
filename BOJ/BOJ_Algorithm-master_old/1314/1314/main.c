//
//  main.c
//  1314
//
//  Created by JEONGMIN on 2016. 11. 28..
//  Copyright © 2016년 JEONGMIN. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i,j,n;
    int arr[101][101] = {0,};
    char alpa='A';
    
    scanf("%d", &n);
    
    for (i=0; i<n; i++) {
        if (i%2 == 0) {
            for (j=0; j<n; j++) {
                if(alpa > 90)
                    alpa = 65;
                arr[j][i] = alpa;
                alpa++;
            }
        }
        else{
            for (j=n-1; j>=0; j--) {
                if(alpa > 90)
                    alpa = 65;
                
                arr[j][i] = alpa;
                alpa++;
            }
        }
    }
    
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
