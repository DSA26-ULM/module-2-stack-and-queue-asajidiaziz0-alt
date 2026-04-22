#include "stack.h"

void init(Stack* s) {
    s->top = s->data - 1;
}

bool isEmpty(const Stack* s) {
    return s->top < s->data;
}

bool isFull(const Stack* s) {
    return s->top >= s->data + MAX - 1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        throw "stack penuh, tidak bisa push";
    }
    s->top++;
    *(s->top) = value;
}

void pop(Stack* s) {
    if (isEmpty(s)) {
        throw "stack kosong, tidak bisa pop";
    }
    s->top--;
}

int peek(const Stack* s) {
    if (isEmpty(s)) {
        throw "stack kosong, tidak ada elemen";
    }
    return *(s->top);
}