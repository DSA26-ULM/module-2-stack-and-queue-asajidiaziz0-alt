#include "queue.h"
#include <stdexcept>

void init(Queue* q) {
    q->front = 0;
    *q->rear = -1;
}

bool isEmpty(const Queue* q) {
    return q->rear < q->front;
}

bool isFull(const Queue* q) {
    return *q->rear == MAX - 1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw std::overflow_error("queue penuh, cannot enqueue");
    }
    (*q->rear)++;
    q->data[*q->rear] = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("queue kosong, cannot dequeue");
    }
    q->front++;
}

int front(const Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("queue kosong, elemen depan not found");
    }
    return q->data[*q->front];
}

int back(const Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("queue kosong, elemen belakang not found");
    }
    return q->data[*q->rear];
}