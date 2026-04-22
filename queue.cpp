#include "queue.h"
#include <stdexcept>

void init(Queue* q) {
    q->front = nullptr;
    q->rear = nullptr;
}

bool isEmpty(const Queue* q) {
    return q->front == nullptr;
}

bool isFull(const Queue* q) {
    if (isEmpty(q)) return false;
    int frontIndex = q->front - q->data;
    int rearIndex  = q->rear  - q->data;

    return (rearIndex + 1) % MAX == frontIndex;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw std::runtime_error("Queue full");
    }

    if (isEmpty(q)) {
        q->front = q->rear = &q->data[0];
        *q->rear = value;
    } else {
        int rearIndex = (q->rear - q->data + 1) % MAX;
        q->rear = &q->data[rearIndex];
        *q->rear = value;
    }
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw std::runtime_error("Queue empty");
    }

    if (q->front == q->rear) {
        init(q);
    } else {
        int frontIndex = (q->front - q->data + 1) % MAX;
        q->front = &q->data[frontIndex];
    }
}

int front(const Queue* q) {
    if (isEmpty(q)) {
        throw std::runtime_error("Queue empty");
    }
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) {
        throw std::runtime_error("Queue empty");
    }
    return *(q->rear);
}