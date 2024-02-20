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

const vector<string> Gibbet{

    {
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      /   \\           $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      / | \\           $\n"
        "        |             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      / | \\           $\n"
        "        |             $\n"
        "       / \\            $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    }
};

int main() {

    setlocale(LC_ALL, "rus");
    vector<string> words = { "mama", "human", "coputer", "language" };

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());

    const string THE_WORD = words[0];
    int wrongGuesses = 0;
    int Gibet = 0;
    string soFar(THE_WORD.size(), '-');
    string used = "";

    cout << "Добро пожаловать в игру виселица! Удачи выжить!\n";

    while ((wrongGuesses < 7) && (soFar != THE_WORD)) {
        cout << "\n\nУ вас есть " << 7 - wrongGuesses << " попыток на отгадку. Вы можете использовать только английские буквы!\n";
        cout << "\nВы использовали следующие буквы:\n" << used << endl;
        cout << "\nПока что это слово звучит так:\n" << soFar << endl;

        char guess;
        cout << "\nВведите свой вариант: ";
        cin >> guess;
        guess = tolower(guess);

        while (used.find(guess) != string::npos) {
            cout << "\nВы уже использовали эту букву" << guess << endl;
            cout << "Введите свой вариант: ";
            cin >> guess;
            guess = tolower(guess);
        }

        used += guess;

        if (THE_WORD.find(guess) != string::npos) {
            cout << "Верно! " << guess << " есть в этом слове!.\n";
            for (unsigned int i = 0; i < THE_WORD.length(); ++i) {
                if (THE_WORD[i] == guess) {
                    soFar[i] = guess;
                }
            }
        }
        else {
            cout << "Увы, " << guess << " нет в этом слове.\n";
            if (Gibet != 6) {
                cout << Gibbet[Gibet];
                Gibet++;
            }
            ++wrongGuesses;
        }
    }

    if (wrongGuesses == 7) {
        cout << "\nВы были повешаны)))!\n";
        cout << Gibbet[6];
    }
    else {
        cout << "\nВы отгадали слово! Молодец!";
    }

    cout << "\nЗагаданное слово было - " << THE_WORD << endl;

    return 0;
}
