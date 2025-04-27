#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Функция для вычисления суммы цифр числа
int sumDigits(int n) {
    n = abs(n);
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {

    cout << "Введите числа:" << endl;
    string line;
    getline(cin, line);
    istringstream iss(line);
    
    int num;
    vector<int> Numbers;
    

    while(iss >> num) {
        // Рассматриваем только числа с минимум двумя цифрами, и с суммой цифр однозначной (меньше 10)
        if (abs(num) >= 10 && sumDigits(num) < 10) {
            Numbers.push_back(num);
        }
    }
    
    if (!Numbers.empty()) {
        sort(Numbers.begin(), Numbers.end());
        cout << "Числа, сумма цифр которого состоит из одного десятичного разряда:" << endl;
        for (int number : Numbers) {
            cout << number << " ";
        }
        cout << endl;
    }
    else {
        cout << "Нет подходящих чисел" << endl;
    }
    
    return 0;
}
