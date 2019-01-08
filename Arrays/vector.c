#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

// default start with size 16
const int DEFAULT_START = 16;
// minimium size to allocate or deallocate
const int MIN_UNIT = 4;

// number of items
int vector_size(Vector* v){
    return v->size;
}

// number of items it can hold
int vector_capacity(Vector* v){
    return v->capacity;
}

// empty
bool is_empty(Vector* v){
    return v->size == 0;
}

// returns item at given index, blows up if index out of bounds
int* vector_at(Vector* v, int index){
    if(index < 0 || index >= v->size){
        return NULL;
    }

    return v->items[index];
}

// push item to the end
void vector_push(Vector* v, int* item){
    vector_insert(v, v->size, item);
}

// inserts item at index, shifts that index's value and trailing elements to the right
void vector_insert(Vector* v, int index, int* item){
    if(index < 0 || index > v->size){
        printf("index out of bound\n");
        return;
    }

    if(v->size == v->capacity){
        vector_resize(v, v->capacity + MIN_UNIT);
    }

    for(int i = v->size - 1; i >= index; i--){
        v->items[i+1] = v->items[i];
    }
    v->items[index] = item;
    v->size ++;

}

// inset item at the beginning
void vector_prepend(Vector* v, int* item){
    vector_insert(v, 0, item);
}

// remove from end, return value
int* vector_pop(Vector* v){
    return vector_delete(v, v->size - 1);
}

// delete item at index, shifting all trailing elements left
int* vector_delete(Vector* v, int index){
    if(index < 0 || index >= v->size){
        printf("index out of bound\n");
        return NULL;
    }

    int* ret_ = v->items[index];
    for(int i = index; i < v->size - 1; i++){
        v->items[i] = v->items[i+1];
    }
    v->size--;

    if(v->capacity > DEFAULT_START && (v->capacity - v->size) / MIN_UNIT == 1){
        vector_resize(v, v->capacity - MIN_UNIT);
    }

    return ret_;
}

// looks for value and removes index holding it (even if in multiple places)
void vector_remove(Vector* v, int* item){
    for(int i=0; i < v->size; i++){
        if(*(v->items[i]) == *item){
            vector_delete(v, i);
        }
    }
}

// looks for value and returns first index with that value, -1 if not found
int vector_find(Vector* v, int* item){
    for(int i=0; i < v->size; i++){
        if(*(v->items[i]) == *item){
            return i;
        }
    }
    return -1;
}


void vector_resize(Vector* v, int new_capacity){
    int** items = (int**)realloc(v->items, new_capacity);
    if(items){
        v->items = items;
        v->capacity = new_capacity;
    }else{
        printf("Unable to reallocate memory");
    }
}

void print_vector(Vector* v){
    printf("Vector size:     %d\n", v->size);
    printf("Vector capacity: %d\n", v->capacity);
    printf("Content:\n");
    for(int i=0; i < v->size; i++){
        printf("%d\n", *(v->items[i]));
    }
}

void test_push(){
    Vector* v = malloc(sizeof(Vector));
    v->items = (int**)malloc(sizeof(int*) * DEFAULT_START);
    v->size = 0;
    v->capacity = DEFAULT_START;
    int a = 10;
    vector_push(v, &a);
    print_vector(v);
}