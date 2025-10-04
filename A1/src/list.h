/*
Name: Louis Nguyen
Date: September 26, 2025
*/

#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdlib.h>

struct list
{
    int head;
    int current;
};

struct list *list_new( void );
void list_start( struct list *list );
void list_next( struct list *list );
int list_get( struct list *list );
void list_push( struct list *list, int value );
void list_append( struct list *list, int value );
void list_pop( struct list *list ); 
void list_truncate( struct list *list );
void list_free( struct list *list );

#endif
