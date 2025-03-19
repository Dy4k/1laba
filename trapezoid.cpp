#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Вводим данные
    double base1, base2, height, side1, side2;
    cout << "Введите длину первого основания: ";
    cin >> base1;
    cout << "Введите длину второго основания: ";
    cin >> base2;
    cout << "Введите высоту трапеции: ";
    cin >> height;
    cout << "Введите длину первой боковой стороны: ";
    cin >> side1;
    cout << "Введите длину второй боковой стороны: ";
    cin >> side2;

    // Проверка на неотрицательные значения
    if (base1 <= 0 || base2 <= 0 || height <= 0 || side1 <= 0 || side2 <= 0 || height > side1 || height > side2) {
        cout << "Ошибка." << endl;
        return 1;
    }

    // Проверка: сумма любых трёх сторон должна быть больше четвёртой
    if ((base1 + base2 + side1 <= side2) ||
        (base1 + base2 + side2 <= side1) ||
        (base1 + side1 + side2 <= base2) ||
        (base2 + side1 + side2 <= base1)) {
        cout << "Ошибка: сумма любых трёх сторон должна быть больше длины четвёртой стороны." << endl;
        return 1;
    }

    // Средняя линия
    double midline = (base1 + base2) / 2;

    // Периметр
    double perimeter = base1 + base2 + side1 + side2;

    // Площадь
    double area = midline * height;

    // Вывод
    cout << "Длина средней линии: " << midline << endl;
    cout << "Периметр трапеции: " << perimeter << endl;
    cout << "Площадь трапеции: " << area << endl;
    return 0;
}
