#include "queue.h"

void init(Queue* q) {
    q->front = q->data;
    q->rear  = q->data - 1;
}

bool isEmpty(const Queue* q) {
    return q->rear < q->front;
}

bool isFull(const Queue* q) {
    return q->rear >= q->data + MAX - 1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw "queue penuh, cannot enqueue";
    }
    q->rear++;
    *(q->rear) = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw "queue kosong, cannot dequeue";
    }
    q->front++;
}

int front(const Queue* q) {
    if (isEmpty(q)) {
        throw "queue kosong, elemen depan not found";
    }
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) {
        throw "queue kosong, elemen belakang not found";
    }
    return *(q->rear);
}