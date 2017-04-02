//
//  main.c
//  CClass2
//
//  Created by MacBook Pro  on 3/23/17.
//  Copyright © 2017 Make School. All rights reserved.
//

#include <stdio.h>
#define NUM_ELEMENTS 3

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    double angle = 45.0;
    angle = angle * (3.1415 / 180.0);
    printf("sin of 45 degrees is %lf\n", sin(angle)); //convert degrees to radians
    
    int MyValue = 0b00111110; //0x3e
    int ShiftAndMask = 0b00111000 & (MyValue << 3);
    
    printf("masked and shifted = %x\n", ShiftAndMask);
    
    int Items [NUM_ELEMENTS] = {5, 4, 11, 20};
    
    printf("Second element of the array is %d\n", Items[99] );
    
    return 0;
}
