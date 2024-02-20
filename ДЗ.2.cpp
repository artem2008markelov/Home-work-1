#include <iostream>
#include <algorithm>  // Для функции std::sort
#include <vector>  // Для использования std::vector
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <unordered_set>
#include <chrono>
#include <cstdlib>


using namespace std;

struct Human{
    int age = 0; 
    int weight = 0;

    int get_age() {
        return age;
    }

    int get_weight() {
        return weight;
    }
};


float average_weight_of_age(vector<Human> district, int what_age) {
    float sum_of_all = 0;
    int number_of_humans = 0;
    for (auto i : district) {
        if (i.get_age() == what_age) {
            sum_of_all += i.get_weight();
            number_of_humans++;
        }
    }
    if (sum_of_all == 0)
        return 0;
    else
        return sum_of_all / number_of_humans;
}

int main() {
    setlocale(LC_ALL, "rus");

    vector<Human> first;
    int n = 0, min_age = 1, max_age = 2, min_weight = 1, max_weight = 2;

    for (int i = 0; i < n; i++) {
        Human Person;
        Person.age = rand() % max_age + min_age;
        Person.weight = rand() % max_weight + min_weight;
        first.push_back(Person);
    }
}
