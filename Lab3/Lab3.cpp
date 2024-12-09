#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

namespace Color {
    // ANSI escape codes для изменения цвета текста
    const string RESET = "\033[0m"; //сброс
    const string RED = "\033[1m\033[31m"; //красный 
    const string GREEN = "\033[1m\033[32m";//зеленый
    const string YELLOW = "\033[1m\033[33m"; //желтый
    const string BLUE = "\033[1m\033[34m";//синий
    const string MAGENTA = "\033[1m\033[35m";// пурпурный
    const string CYAN = "\033[1m\033[36m";// голубой
    const string BLACK = "\033[1m\033[30m";// черный
    const string WHITE = "\033[1m\033[37m"; // белый

    void Red(const string& text) {
        cout << RED << text << RESET << endl;
    }
    void Green(const string& text) {
        cout << GREEN << text << RESET << endl;
    }
    void Yellow(const string& text) {
        cout << YELLOW << text << RESET << endl;
    }
    void Blue(const string& text) {
        cout << BLUE << text << RESET << endl;
    }
    void Magenta(const string& text) {
        cout << MAGENTA << text << RESET << endl;
    }
    void Cian(const string& text) {
        cout << CYAN << text << RESET << endl;
    }
    void Black(const string& text) {
        cout << BLACK << text << RESET << endl;
    }
    void White(const string& text) {
        cout << WHITE << text << RESET << endl;
    }

}
using namespace Color;

//boyerMoore
char to_lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

void boyerMoore(string A, string B) {
    int n = 0;
    while (A[n] != '\0') n++;
    int m = 0;
    while (B[m] != '\0') m++;

    bool found = false;
    for (int i = 0; i <= n - m; i++) 
    {
        int j;
        for (j = 0; j < m; j++) 
        {
            if (to_lower(A[i + j]) != to_lower(B[j]))
            {
                break;
            }
        }
        if (j == m) 
        {
            cout << "Подстрока найдена в позиции: " << i << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Подстрока не найдена" << endl;
    }
}


//Удалить все ненужное
string editText(string inputText) {
    string result;
    bool lastWasSpace = false;
    char lastChar = '0';

    for (char current : inputText) {
        if (current == ' ') {
            if (!lastWasSpace) {
                result += current;
                lastWasSpace = true;
            }
            continue;
        }


        if ((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z') || (current >= '0' && current <= '9'))
        {
            if (lastChar == current) {
                continue; 
            }
        }


        if ((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z')) 
        {
            if (current >= 'A' && current <= 'Z')
            {
                if(current )
                if (result[result.length() - 1] >= 'a' && result[result.length() - 1] <= 'z') 
                {
                    current = current + 32;
                }
            }
            else if (current >= 'a' && current <= 'z') 
            {
                if (result.length() == 0) 
                {
                    current = current - 32;
                }
            }
        }


        result += current;
        lastWasSpace = false;
        lastChar = current;
    }
    return result;
}

//Слова в обратном порядке
void reverse(string editedText)
{
    const int maxWords = 500; // Максимальное количество слов
    string words[maxWords];
    int wordCount = 0;

    // Разделение строки на слова
    stringstream ss(editedText);
    string word;

    while (ss >> word && wordCount < maxWords) {
        words[wordCount] = word;
        wordCount++;
    }

    // Вывод слов в обратном порядке
    for (int i = wordCount - 1; i >= 0; i--) {
        cout << words[i] << " ";
    }

    cout << endl;
}

//Кол символов в каждом слове исходной посл.
void countChar(string inputText) 
{
    const int maxWords = 500; // Максимальное количество слов
    string words[maxWords];
    int wordCount = 0;

    // Разделение строки на слова
    stringstream ss(inputText);
    string word;

    while (ss >> word && wordCount < maxWords) 
    {
        words[wordCount] = word;
        wordCount++;
    }
    for (int i = 0; i <= wordCount - 1; i++) {
        cout << words[i].length() << " ";
    }

    cout << endl;

}

void print_reverse(string editedText) {
    int length = 0;
    while (editedText[length] != '\0') {
        length++;
    }

    for (int i = length - 1; i >= 0; i--) {
        cout << editedText[i];
    }
    cout << endl;
}

int main() 
{
    bool first = false;
    string editedText;
    string inputText1 ="";
    string inputText2 = "";
    setlocale(LC_ALL, "RU");
    while (true)
    {
        //Меню
        Red("Выберите пункт (1-4) или 0 для выхода\n");
        cout << "1. Пункт 1. Ввод последовательности слов\n";
        cout << "2. Пункт 2. Отредактировать входной текст \n";
        cout << "3. Пункт 3. Вывести на экран слова последовательности в обратном порядке.\n";
        cout << "4. Пункт 4. Вывести на экран количество символов в каждом слове исходной последовательности.\n";
        cout << "5. Пункт 5. Алгоритм Бойера-Мура\n";
        cout << "0. Выход\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Green("1 пункт.");
            Red("\nВвыберите как вы хотите передавать данные");
            cout << "1. Ввод с клавиатуры\n";
            cout << "2. Ввод с файла(input.txt)\n";
            int file_or_text;
            cin >> file_or_text;
            inputText1.clear();
            inputText2.clear();
            if (file_or_text == 2)
            {
                ifstream inputFile("input.txt");
                if (inputFile.is_open()) {
                    string line;
                    while (getline(inputFile, line)) {
                        inputText2 += line + "\n";
                    }
                    inputFile.close();
                }
                else
                {
                    cout << "Не удалось открыть файл." << endl;
                    return 1;
                }
                break;
            }
            if (file_or_text == 1)
            {
                system("cls");
                string line;
                first = true;
                cout << "Введите текст: " << endl;
                getline(cin, line, '.');
                inputText1 += line;
            }
            break;
        }
        case 2:
        {
            while (true)
            {
                system("cls");
                Green("2 пункт.");
                if (first)
                {
                    string result;
                    bool lastWasSpace = false;
                    char lastChar = '0';

                    for (char current : inputText1) {
                        if (current == ' ') {
                            if (!lastWasSpace) {
                                result += current;
                                lastWasSpace = true;
                            }
                            continue;
                        }


                        if ((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z') || (current >= '0' && current <= '9'))
                        {
                            if (lastChar == current) {
                                continue;
                            }
                        }


                        if ((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z'))
                        {
                            if (current >= 'A' && current <= 'Z')
                            {
                                if (current)
                                    if (result[result.length() - 1] >= 'a' && result[result.length() - 1] <= 'z')
                                    {
                                        current = current + 32;
                                    }
                            }
                            else if (current >= 'a' && current <= 'z')
                            {
                                if (result.length() == 0)
                                {
                                    current = current - 32;
                                }
                            }
                        }


                        result += current;
                        lastWasSpace = false;
                        lastChar = current;
                    }

                    //##########################
                    string editedText = result; /*editText(inputText1);*/
                    cout << "Отредактированный текст: " << result  << endl;
                    break;
                }
                else
                {
                    string editedText = editText(inputText2);
                    cout << "Отредактированный текст: " << editedText << endl;
                    break;
                }
            }
        }
        case 3:
        {
            while (true)
            {
                Green("3 пункт.");
                if (first)
                {
                    editedText = editText(inputText1);
                }
                else
                    editedText = editText(inputText2);
                Cian("Последовательность в обратном порядке: ");
                /*print_reverse(editedText);*/
                //cout << endl;
                reverse(editedText);

                int n;
                Red("Если хотите перейти в следующий пункт, введите 0");
                cout << "Введите число: ";
                cin >> n;
                cout << endl;
                if (n == 0)
                {
                    break;
                }
            }
        }
        case 4:
        {
            Green("4 пункт.");
            system("cls");
            Yellow("Исходная последовательность: ");
            cout << inputText1 << inputText2 << endl;
            Cian("Количество символов в каждом слове исходной последовательности: ");
            countChar(inputText1);
            countChar(inputText2);
            break;
        }
        case 5:
        {
            Green("5 пункт.");
            if (first)
            {
                editedText = editText(inputText1);
            }
            else
                editedText = editText(inputText2);
            Yellow("Алгоритм Бойера-Мура");
            string text;
            Blue("Введите подстроку, которую необходимо найти в строке: ");
            cin >> text;
            cout << endl;
            Cian("В данной строке происходит поиск: ");
            cout << editedText;
            cout << endl;
            boyerMoore(editedText, text);
            break;
        }
        }
        if (choice == 0)
        {
            cout << "\nПрограмма завершила свою работу" << endl;
            break;
        }
    }
}