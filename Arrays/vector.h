#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdbool.h>
typedef struct Vector{
    int size;
    int capacity;
    int** items;
}Vector;

// number of items
int vector_size(Vector*);

// number of items it can hold
int vector_capacity(Vector*);

// empty
bool is_empty(Vector*);

// returns item at given index, blows up if index out of bounds
int* vector_at(Vector*, int);

// push item to the end
void vector_push(Vector*, int*);

// inserts item at index, shifts that index's value and trailing elements to the right
void vector_insert(Vector*, int, int*);

// inset item at the beginning
void vector_prepend(Vector*, int*);

// remove from end, return value
int* vector_pop(Vector*);

// delete item at index, shifting all trailing elements left
int* vector_delete(Vector*, int);

// looks for value and removes index holding it (even if in multiple places)
void vector_remove(Vector*, int*);

// looks for value and returns first index with that value, -1 if not found
int vector_find(Vector*, int*);


void vector_resize(Vector*, int);

void print_vector(Vector*);
void test_push();
#endif