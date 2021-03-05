#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[], char ** envp) {

    int offset = 48;
    int digit;
    int retval;
    int number = 0;
    char ascii_value;
    int returnValue=0;
    retval = read(0, &ascii_value, 1);
    while (retval == 1){
          // printf("%c\n",ascii_value);//remove this later
        if (ascii_value == 10){
         break;
        }
        if (ascii_value != '0' && ascii_value != '1'){
         returnValue=1;
         break;
        }
     
        digit = ascii_value - offset;
        number = (number << 1) + digit;  
        retval = read(0, &ascii_value, 1);
    }
    if(returnValue==0){
        printf("%u\n", number);
    }
    return returnValue;



}