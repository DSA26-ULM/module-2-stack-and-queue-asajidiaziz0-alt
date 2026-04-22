#include <iostream>
#include <string>
#include "stack.h"
#include "stack.cpp"

int main() {
    int n;
    std::cin >> n;

    Stack s;
    init(&s);

    try {
        for (int i = 0; i < n; i++) {
            std::string A;
            std::cin >> A;

            if (A == "+" || A == "-" || A == "*" || A == "/") {
                int b = peek(&s); pop(&s);
                int a = peek(&s); pop(&s);

                int hasil;

                if (A == "+") hasil = a + b;
                else if (A == "-") hasil = a - b;
                else if (A == "*") hasil = a * b;
                else hasil = a / b;

                push(&s, hasil);
            }

            else {
                int angka = std::stoi(A);
                push(&s, angka);
            }
        }
        std::cout << peek(&s) << std::endl;

    } catch (const char* msg) {
        std::cout << "error: " << msg << std::endl;
    }

    return 0;
}