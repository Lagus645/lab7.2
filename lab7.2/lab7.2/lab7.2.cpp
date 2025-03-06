#include <iostream>
#include <cstdarg> //Используется <cstdarg> для работы с переменным числом аргументов.
using namespace std;

// Функция для нахождения минимального значения среди переменного числа параметров
template<typename T>
T min(T count, ...) {
    va_list args;
    va_start(args, count);

    T minVal = va_arg(args, T);

    for (int i = 1; i < count; ++i) {
        T current = va_arg(args, T);
        if (current < minVal) {
            minVal = current;
        }
    }

    va_end(args);
    return minVal;
}

int main() {
    // Вызов функции min с 5 параметрами типа int
    int minInt = min<int>(5, 10, 3, 7, 2, 8);
    cout << "Min int: " << minInt << endl;

    // Вызов функции min с 10 параметрами типа double
    double minDouble = min<double>(10, 3.5, 1.2, 4.8, 2.1, 5.6, 0.9, 7.3, 6.4, 8.7, 9.0);
    cout << "Min double: " << minDouble << endl;

    // Вызов функции min с 12 параметрами типа int
    int minInt2 = min<int>(12, 15, 12, 18, 20, 11, 14, 13, 16, 17, 19, 10, 9);
    cout << "Min int: " << minInt2 << endl;

    return 0;
}
