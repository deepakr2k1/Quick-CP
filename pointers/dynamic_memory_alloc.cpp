#include<bits/stdc++.h>
using namespace std;

int main() {

// “malloc” or “memory allocation” method in C is used to dynamically allocate 
// a single large block of memory with the specified size. It returns a pointer
// of type void which can be cast into a pointer of any form. It initializes each 
// block with default garbage value.
// cast-type *ptr = (cast-type*) malloc(byte-size)

    int *ptr = (int*) malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
    }
    else {
        cout<<*ptr<<" ";
        *ptr = 12;
        cout<<ptr[0]<<endl;
    }

// “calloc” or “contiguous allocation” method in C is used to dynamically allocate
// the specified number of blocks of memory of the specified type. It initializes 
// each block with a default value ‘0’.
// ptr = (cast-type*)calloc(n, element-size);

    int *ptr2 = (int*) calloc(10, sizeof(int));
    if (ptr2 == NULL) {
        printf("Memory not allocated.\n");
    }
    else {
        for(int i=0; i<8; i++) {
            ptr2[i] = (i+1)*(i+1);
        }
        for(int i=0; i<10; i++) {
            cout<<ptr2[i]<<" ";
        }
    }

// “free” method in C is used to dynamically de-allocate the memory. The memory 
// allocated using functions malloc() and calloc() is not de-allocated on their own. 
// Hence the free() method is used, whenever the dynamic memory allocation takes place. 
// It helps to reduce wastage of memory by freeing it.
// free(ptr);

    free(ptr2);

// “realloc” or “re-allocation” method in C is used to dynamically change the memory allocation 
// of a previously allocated memory. In other words, if the memory previously allocated with 
// the help of malloc or calloc is insufficient, realloc can be used to dynamically re-allocate 
// memory. re-allocation of memory maintains the already present value and new blocks will be 
// initialized with default garbage value.
// ptr = realloc(ptr, newSize);

    ptr = (int*)realloc(ptr, 2*sizeof(int));
    ptr[5]=2;
    cout<<endl<<ptr[0]<<" "<<ptr[5]<<endl;
}