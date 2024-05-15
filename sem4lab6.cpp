#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


int main() {
    std::vector<int> numbers; // создаём вектор целых чисел
    std::ifstream input_file("C:\Users\Msi\Desktop\input.txt"); // открываем файл для чтения
    int input_value, total_numbers = 9; // переменные для хранения прочитанных чисел и их общего количества
        // читаем числа из файла и добавляем их в вектор
        for (int i = 0; i < total_numbers; ++i) {
            input_file >> input_value;
            numbers.push_back(input_value);
        }

    input_file.close(); // закрываем файл

    // выводим исходный вектор
    std::cout << "Initial vector:\n";
    for (const auto& element : numbers)
        std::cout << element << " ";
    std::cout << "\n";

    // реверсируем вектор
    std::reverse(numbers.begin(), numbers.end());
    std::cout << "Reversed vector:\n";
    for (const auto& element : numbers)
        std::cout << element << " ";
    std::cout << "\n";

    // находим минимальный элемент
    int minElement = *std::min_element(numbers.begin(), numbers.end());
    std::cout << "Minimum element: " << minElement << "\n";

    // удаляем чётные элементы
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](int n) { return n % 2 == 0; }), numbers.end());
    std::cout << "Vector after removing even elements:\n";
    for (const auto& element : numbers)
        std::cout << element << " ";
    std::cout << "\n";

    // сортируем вектор по убыванию
    std::sort(numbers.rbegin(), numbers.rend());
    std::cout << "Sorted vector (descending):\n";
    for (const auto& element : numbers)
        std::cout << element << " ";
    std::cout << "\n";

    // вставляем новый элемент в отсортированный вектор
    int insert_value = 42;
    auto position = std::upper_bound(numbers.begin(), numbers.end(), insert_value, std::greater<int>());
    numbers.insert(position, insert_value);
    std::cout << "Vector after inserting " << insert_value << ":\n";
    for (const auto& element : numbers)
        std::cout << element << " ";
    std::cout << "\n";

    // находим позицию заданного элемента
    int search_value = 42;
    auto search_result = std::find(numbers.begin(), numbers.end(), search_value);
    int index = (search_result != numbers.end()) ? std::distance(numbers.begin(), search_result) : -1;
    if (index != -1) {
        std::cout << "Index of " << search_value << ": " << index << "\n";
    }
    else {
        std::cout << search_value << " not found\n";
    }

    // удаляем дубликаты
    numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());
    std::cout << "Vector after removing duplicates:\n";
    for (const auto& element : numbers)
        std::cout << element << " ";
    std::cout << "\n";

    return 0;
}
