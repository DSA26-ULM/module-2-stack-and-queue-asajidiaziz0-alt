#include <iostream>
#include "queue.h"

int main() {
    int n, k;
    std::cin >> n >> k;

    if (k <= 0 || k > n) {
        std::cout << "error" << std::endl;
        return 0;
    }

    Queue q;
    init(&q);

    int sum = 0;
    int x;

    try {
        int i = 0;
        while (i < k) {
            std::cin >> x;
            enqueue(&q, x);
            sum += x;
            i++;
        }

        std::cout << sum;

        while (i < n) {
            std::cin >> x;

            int depan = front(&q);
            dequeue(&q);
            sum -= depan;

            enqueue(&q, x);
            sum += x;

            std::cout << " " << sum;
            i++;
        }
        std::cout << std::endl;

    } catch (const char* msg) {
        std::cout << "error: " << msg << std::endl;
    }

    return 0;
}