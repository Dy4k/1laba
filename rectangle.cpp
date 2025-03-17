#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Вводим длину и ширину прямоугольника
    double length, width;
    cout << "Введите длину прямоугольника: ";
    cin >> length;
    cout << "Введите ширину прямоугольника: ";
    cin >> width;
    if (lenght < 0 || width < 0) {
        cout<< "Ошибка" << endl;
        return 1;
    }


    //Периметр
    double perimeter = 2 * (length + width);

    //Площадь
    double area = (length * width);

    //Диагональ
    double diagonal = sqrt(length * length + width * width);

    cout << "Периметр прямоугольника: " << perimeter << endl;
    cout << "Площадь прямоугольника: " << area << endl;
    cout << "Длина диагонали прямоугольника: " << diagonal << endl;

    return 0;
}
