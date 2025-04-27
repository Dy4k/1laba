#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Введите строку:" << endl;
    
    string sentence;
    getline(cin, sentence);

    // Используем битовую маску: каждый бит соответствует одной букве (a-z)
    int letters = 0;
    
    // Проходим по каждому символу строки
    for (char c : sentence) {
        if (c >= 'a' && c <= 'z') {
            // Устанавливаем бит, соответствующий букве c
            letters |= (1 << (c - 'a'));
        }
    }
    
    if (letters == (1 << 26) - 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
