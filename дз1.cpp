#include <iostream>
#include <algorithm>  // Для функции std::sort
#include <vector>  // Для использования std::vector
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <unordered_set>
#include <chrono>

using namespace std;

/* Написать две функции : первая для рандомной генерации N строк длинной l и создании из них массива,
вторая для поиска и исключения повторяющихся строк в массиве.
N = 10_000
l = 3
*/

// Функция для генерации одной случайной строки длиной l
string RandomString(int l) {
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    string result;
    for (int i = 0; i < l; ++i) {
        result.push_back(charset[rand() % charset.length()]);
    }
    return result;
}

// Функция для генерации N случайных строк длиной l и помещения их в массив
vector<string> RandomVector(int N, int l) {
    vector<string> strings;
    for (int i = 0; i < N; ++i) {
        strings.push_back(RandomString(l));
    }
    return strings;
}

// Функция для поиска и исключения повторяющихся строк в массиве
vector<string> removeDuplicate(const vector<string>& strings) {
    vector<string> Strings;
    unordered_set<string> Set;
    for (const auto& str : strings) {
        if (Set.find(str) == Set.end()) {
            Set.insert(str);
            Strings.push_back(str);
        }
    }
    return Strings;
}
// Функция для генерации хэш-кода строки
size_t HashCode(const string& str) {
    size_t hash = 0;
    for (char c : str) {
        hash = (hash * 131) + c; // Простое хэширование строки
    }
    return hash;
}

int main() {
    int N = 10000; // Количество строк
    int length = 3; // Длина каждой строки
    setlocale(LC_ALL, "RUS");

    // Генерируем случайные строки и помещаем их в массив
    vector<string> randomStrings = RandomVector(N, length);

    // Измеряем время выполнения для поиска и исключения повторяющихся строк в массиве
    auto start = chrono::steady_clock::now();
    vector<string> Strings = removeDuplicate(randomStrings);
    auto end = chrono::steady_clock::now();
    chrono::duration<double> TimeStrings = end - start;

    // Генерируем хэш-коды
    vector<size_t> hashCodes;
    for (const auto& str : randomStrings) {
        hashCodes.push_back(HashCode(str));
    }

    // Измеряем время выполнения для поиска и исключения повторяющихся хэш-кодов
    start = chrono::steady_clock::now();
    unordered_set<size_t> HashCodes(hashCodes.begin(), hashCodes.end());
    end = chrono::steady_clock::now();
    chrono::duration<double> TimeHashCodes = end - start;

    cout << "Время для удаления повторов по строкам: " << TimeStrings.count() << " секунд" << endl;
    cout << "Время для удаления дубликатов по хеш кодам: " << TimeHashCodes.count() << " секунд" << endl;
    // Делаем вывод, что хеш коды быстрее почти в 5 раз!!!
    return 0;
}
