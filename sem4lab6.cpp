#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    setlocale(LC_ALL, "RUS");
    // 1. Организация чтения из файла целочисленного одномерного вектора
    std::ifstream inputFile("vector.txt");
    std::vector<int> vector;
    int number;
    int minka;
    while (inputFile >> number) {
        vector.push_back(number);
    }
    inputFile.close();

    // 2. Реверсирование последовательности элементов вектора
    std::reverse(vector.begin(), vector.end());
    

    // 3. Поиск минимального элемента
    //minka = *std::min_element(vector.begin(), vector.end());
    //std::cout << "Минимальный элемент: " << minka << std::endl;

    // 4. Удаление из вектора всех четных элементов
    vector.erase(std::remove_if(vector.begin(), vector.end(), [](int element) { return element % 2 == 0; }), vector.end());

    // 5. Сортировка вектора в убывающей или возрастающей последовательности
    std::sort(vector.begin(), vector.end(), std::greater<>());  // Сортировка в убывающей последовательности

    // 6. Вставка в вектор произвольного элемента, не нарушая сортировку
    int elementToInsert = 9;
    auto insertPosition = std::lower_bound(vector.begin(), vector.end(), elementToInsert);
    vector.insert(insertPosition, elementToInsert);

    // 7. Определение индекса заданного элемента
    int elementToFind = 9;
    auto found = std::find(vector.begin(), vector.end(), elementToFind);
    if (found != vector.end()) {
        std::cout << "Индекс заданного элемента: " << std::distance(vector.begin(), found) << std::endl;
    }
    else {
        std::cout << "Заданный элемент не найден" << std::endl;
    }

    // 8. Удаление из вектора дублированных элементов
    std::sort(vector.begin(), vector.end());
    vector.erase(std::unique(vector.begin(), vector.end()), vector.end());

    // Вывод отсортированного вектора
    std::cout << "Отсортированный вектор: ";
    std::vector<int>::iterator it;
    for (it = vector.begin(); it != vector.end(); ++it) {
        std::cout << *it << " ";
    }


    return 0;
}