/*
программа реализует работу со словарём синонимов. Со стандартного ввода
программе поступают три вида запросов:
ADD word1 word2 — добавить пару слов-синонимов word1 и word2;
COUNT word — вывести в стандартный вывод количество синонимов для слова “word”;
CHECK word1 word2 — вывести YES, если слова word1 и word2 в данный момент будут синонимами.
Если не будут — вывести NO;
EXIT — завершить работу.

Пример входных и выходных данных:
ADD program code
ADD code cipher
COUNT cipher
1
CHECK code program
YES
CHECK program cipher
NO
EXIT

Из примера видно, что отношение «синонимичности» в этой программе:
- симметрично: если первое слово — синоним второго, то и второе — синоним первого.
- нетранзитивно: если A — синоним B, а B — синоним C, то A не будет синонимом C, 
если их не объявить синонимами явно.
*/
// #include <cassert>
#include <iostream>
#include <sstream>
#include "testing_fuctions.cpp"

int main()
{
    TestSynonyms();
    Synonyms synonyms;
    string line;

    // В случае ошибок чтения из cin произойдёт выход из цикла
    while (getline(cin, line))
    {
        istringstream command(line);
        string action;
        command >> action;
        
        if (action == "ADD"s)
        {
            string first_word, second_word;
            command >> first_word >> second_word;
            synonyms.Add(first_word, second_word);
            // добавляет пару синонимов first_word и second_word
        }
        else if (action == "COUNT"s)
        {
            string word;
            command >> word;
            cout << synonyms.GetSynonymCount(word) << endl;
            // выводит количество синонимов word
        }
        else if (action == "CHECK"s)
        {
            string first_word, second_word;
            command >> first_word >> second_word;
            if(synonyms.AreSynonyms(first_word, second_word)) {
                cout << "YES"s << endl;
            } else {
                cout << "NO"s << endl;
            }
            // проверяет, являются ли first_word и second_word синонимами
            // и выводит YES либо NO
        }
        else if (action == "EXIT"s)
        {
            break;
        }
    }
}