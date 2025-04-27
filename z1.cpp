#include <iostream>
using namespace std;

// Функция вычисляет количество конечных нулей в факториале числа n,
// используя последовательное целочисленное деление на 5.
int count_zeros(int n) {
    int zeros = 0;
    while (n > 0) {
        n /= 5;
        zeros += n;
    }
    return zeros;
}

int main() {
    int N;
    cout << "Введите число:" << endl;
    
    // Считываем первое число
    if (!(cin >> N)) {
        cout << "Ошибка ввода!" << endl;
        return 1;
    }
    
    // Если после первого числа есть ещё данные, выводим ошибку
    int extra;
    if (cin >> extra) {
        cout << "Ошибка: требуется только одно число!" << endl;
        return 1;
    }
    
    // Если введено отрицательное число, сообщаем об ошибке
    if (N < 0) {
        cout << "Ошибка: введите положительное число!" << endl;
        return 1;
    }    
    
    cout << "Количество конечных нулей: " << count_zeros(N) << endl;
    return 0;
}
