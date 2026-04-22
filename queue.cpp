#include "queue.h"
#include <stdexcept>

void init(Queue* q) {
    q->front = nullptr;
    q->rear  = nullptr;
}

bool isEmpty(const Queue* q) {
    return q->front == nullptr;
}

bool isFull(const Queue* q) {
    if (isEmpty(q)) return false;
    int* nextRear = q->rear + 1;
    if (nextRear == q->data + MAX) 
    return nextRear == q->front;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw std::overflow_error("queue penuh, cannot enqueue");
    }
    if (isEmpty(q)) {
        q->front = q->rear = q->data;
    } else {
        q->rear++;
        if (q->rear == q->data + MAX) q->rear = q->data;
    }
    *(q->rear) = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("queue kosong, cannot dequeue");
    }
    if (q->front == q->rear) {
        q->front = q->rear = nullptr;
        return;
    }
    q->front++;
    if (q->front == q->data + MAX) q->front = q->data;
}

int front(const Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("queue kosong, elemen depan not found");
    }
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("queue kosong, elemen belakang not found");
    }
    return *(q->rear);
}