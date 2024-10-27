//learning pointers...

#include <stdio.h>

int main()
{
    int a=10;
   
    int b=20;
    
    int *p;//a pointer to integer type data.
    p=&a;
    
 
    int **q;//a pointer to a integer pointer.
    q=&p;
 
    printf("\naddress of a(&a) : %p\n",&a);
    
    printf("\naddress of a(p) : %p\n",p);

    printf("\nvalue of a(a): %d\n",a);
    
    printf("\nvalue of p(p): %p\n",p);
    
    printf("\nvalue of a(*p) by derefering p: %d\n",*p);
    
    printf("\naddress of p(&p) : %p\n",&p);
    
    printf("\nvalue of q(q) : %p\n",q);
    
    printf("\naddress of a(*q) : %p\n",*q);
    
    printf("\nValue of a by dereferencing q(**q): %d\n",**q);
    
    *q=&b;
    printf("\nvalue of b by dereferencing q(**q): %d\n",**q);
    return 0;
}