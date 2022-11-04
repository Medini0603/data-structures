#include<stdio.h>

int main(){
    int x,*px;
    float y,*py;
    char c,*pc;

    printf("The sizeof int pointer is %lu\n",sizeof(px));
    printf("The sizeof float pointer is %lu\n",sizeof(py));
    printf("The sizeof char pointer is %lu\n",sizeof(pc));
    return 0;
}