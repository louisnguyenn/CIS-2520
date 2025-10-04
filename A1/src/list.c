/*
Name: Louis Nguyen
Date: September 26, 2025
*/

#include "list.h"
#include "mem.h"

struct list *list_new( void )
{
    struct list *ptr = NULL;

    // creating a allocated linked list of size struct
    ptr = malloc(sizeof(struct list));

    // initializing head and current to 0
    ptr->head = 0;
    ptr->current = 0;

    return ptr;    // returning the linked list
}

void list_start( struct list *list )
{
    list->current = list->head; // set the current address to the head address
}

void list_next( struct list *list )
{
    int nextAddr = 0;

    // moving the pointer to the next address
    nextAddr = get_next(list->current);
    list->current = nextAddr;
}

int list_get( struct list *list )
{
    return get_value(list->current);    // return current address
}

void list_push( struct list *list, int value )
{
    int valueAddr = 0;

    valueAddr = mem_alloc(1);       // allocating memory for the value

    // setting the value in the allocated memory
    set_value(valueAddr, value);

    if (list->head == 0)
    {
        list->head = valueAddr;
        set_next(valueAddr, 0);
    }

    else
    {
        // setting the new node equal to the address of the head
        set_next(valueAddr, list->head);

        // moving the head to point at the new node
        list->head = valueAddr;
    }
}

void list_append( struct list *list, int value )
{
    int valueAddr = 0;
    int nextAddr = 0;

    valueAddr = mem_alloc(1);       // allocating memory for the value

    // setting the value in the allocated memory
    set_value(valueAddr, value);

    list->current = list->head;

    if (list->head == 0)
    {
        list->head = valueAddr;
    }

    else
    {
        // looping to the end of the list
        while (get_next(list->current) != 0)
        {
            nextAddr = get_next(list->current);
            list->current = nextAddr;
        }

        // setting the tail next to the new node
        set_next(list->current, valueAddr);
    }

    // setting the new node to the address of the original list
    set_next(valueAddr, 0);
}

void list_pop( struct list *list )
{
    int nextAddr = 0;

    list->current = list->head;

    // get the address of the node head is pointing at
    nextAddr = get_next(list->head);

    // make the head equal to the next node
    list->head = nextAddr;

    // free the current node
    mem_free(list->current);
}

void list_truncate( struct list *list )
{
    list->current = list->head;

    if (list->head == 0)
    {
        return;
    }

    else if (get_next(list->head) == 0)
    {
        mem_free(list->current);

        list->head = 0;
    }

    else
    {
        // looping to the end of the list
        while (get_next(get_next(list->current)) != 0)
        {
            list->current = get_next(list->current);
        }

        mem_free(get_next(list->current));
        
        // null terminate the list
        set_next(list->current, 0); 
    }
}

void list_free( struct list *list )
{
    int nextAddr = 0;

    // base case of when head is 0 (NULL)
    while (list->head != 0)
    {
        nextAddr = get_next(list->head);
        mem_free(list->head);   // freeing the node

        list->head = nextAddr;  // make head equal to the next node
    }

    free(list);
}
