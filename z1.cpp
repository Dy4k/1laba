#include <iostream>
using namespace std;
// Функция вычисляет количество конечных нулей в факториале числа n, используя последовательное целочисленное деление на 5.
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
    cin >> N;  
    if (N < 0) {
        cout << "Ошибка: введите положительное число!" << endl;
        return 1;
    }    
    cout << "Количество конечных нулей: " << count_zeros(N) << endl;
    return 0;
}
