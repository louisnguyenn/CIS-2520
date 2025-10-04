/*
Name: Louis Nguyen
Date: September 26, 2025
*/

#include "array.h"
#include "mem.h"

struct array *array_new( int size )
{
    struct array *array_new = NULL;
    int addr;

    // creating a allocated array using calloc (initializes to 0)
    array_new = malloc(sizeof(struct array));

    addr = mem_alloc(size);         // setting the address using mem_alloc
    array_new->addr = addr;         // setting the address to the first struct array
    array_new->elements = 0;        // initalize the element to 0

    return array_new;
}

int array_get( struct array *ptr, int index )
{
    int element = 0;
    int arrayIndex = 0;

    /* 
    finding the array index by adding the index argument to the  
    address stored in the struct that points at the first element of the array
    */
    arrayIndex = ptr->addr + index;

    element = get_value(arrayIndex);    // call get value function from mem function

    return element;
}

void array_push( struct array *ptr, int value )
{
    int i = 0, e = 0;

    // for loop will run and shift all of the elements down by 1 index
    for (i = ptr->elements-1; i >= 0; i--)
    {
        e = get_value(ptr->addr+i);    // store the element at the index
        set_value(ptr->addr+i+1, e);   // set the element to the next index
    }

    set_value(ptr->addr, value);      // after the for loop ends we push the value to index 0

    ptr->elements++;
}

void array_append( struct array *ptr, int value )
{
    // use the number of elements to find the next index after the last element
    set_value(ptr->addr+ptr->elements, value);

    ptr->elements++;
}

void array_pop( struct array *ptr )
{
    int i = 0, e = 0;

    // for loop will run and shift all of the elements up by 1 index
    for (i = 1; i <= ptr->elements-1; i++)
    {
        e = get_value(ptr->addr+i);
        set_value(ptr->addr+i-1, e);
    }

    ptr->elements--;
}

void array_truncate( struct array *ptr )
{
    // decrement number of elements
    ptr->elements--;
}

void array_free( struct array *ptr )
{
    mem_free(ptr->addr);  // free the entire block at once

    free(ptr);  // freeing the struct pointer
}
