/*
Name: Louis Nguyen
Date: September 26, 2025
*/

#ifndef _ARRAY_H
#define _ARRAY_H

#include <stdio.h>
#include <stdlib.h>

struct array
{
    int elements;
    int addr;
};

struct array *array_new( int size );
int array_get( struct array *ptr, int index );
void array_push( struct array *ptr, int value );
void array_append( struct array *ptr, int value );
void array_pop( struct array *ptr );
void array_truncate( struct array *ptr );
void array_free( struct array *ptr );

#endif
