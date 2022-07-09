/************************************************************/
/** author  :Hashim Sobhy                                  **/
/** Date    :18.5.2021                                      **/
/** Version :1.0                                           **/
/** Title   :Assignment #2 File Analysis using inorder List                                 **/
/************************************************************/
#include <iostream>
#include <string>
#include <fstream>

#include "inorderList.h"
using namespace std;
extern long int words, chars;
typedef string ListElemType;

inorderList::inorderList() { head = current = prev = NULL; }
bool inorderList::insert(const ListElemType& e, const int& l) {
    node* addednode;
    node* pred; //pointer of inorder
    addednode = new node;
    if (addednode == NULL) { return false; }
    addednode->elem = e; // data
    words++; // words_counter
    addednode->line = l; // line number of word
    addednode->next = NULL;
    if (head == NULL || e <= head->elem) {
        addednode->next = head;
        head = addednode;
    }
    else {
        pred = head;
        while (pred->next != NULL && pred->next->elem <= e) {
            pred = pred->next;
        }
        addednode->next = pred->next;
        pred->next = addednode;
    }
    return true;
}
bool insertDataFile(string dataFile, inorderList& list)
{
    ifstream file(dataFile);
    if (!file.good()) { cout << "File not found"; return false; }
    string line;
    int line_counter = 1;
    while (!file.eof())
    {
        getline(file, line);
        // split sentence into lower words then Send Data to LinkedList
        if (line != "")
        {
            string word = "";
            for (auto x : line)
            {
                chars++;
                //delimiters
                if (x == ' ' || x == ',' || x == '.' || x == ':' || x == '(' || x == ')' || x == '{' || x == '}' || x == '[' || x == ']')
                {
                    if (word != "")
                    {
                        list.insert(word, line_counter);
                    }
                    word = "";
                }
                else
                {
                    //save all as lower chars
                    word += tolower(x);
                }
            }
            if (word != "")
                list.insert(word, line_counter);
        }
        line_counter++;
    }
    chars += line_counter - 2;
    file.close();
    return true;
}
bool insertCommandFile(string dataFile, inorderList& list) {
    ifstream file(dataFile);
    if (!file.good()) { cout << "File not found"; return false; }
w:
    while (!file.eof()) {
        string line = "";
        string command = "";
        string target = "";
        getline(file, line);
        if (line != "") {
            int i = 0;
            string word = "";
            for (auto x : line)
            {
                if (x == ' ')
                {
                    if (word != "") {
                        i++;
                        if (i > 1)
                            break;
                        command = word;
                    }
                    word = "";
                }
                else
                    word += x;
            }
            switch (i) {
            case 0:
                command = word;
                break;
            case 1:
                target = word;
                break;
            default:
                cout << "Incorrect number of arguments" << endl;
                goto w;
            }
            if (command == "wordCount" || command == "distWords" || command == "charCount" || command == "frequentWord" || command == "countWord" || command == "starting" || command == "containing" || command == "search")
            {
                if (command == "wordCount") {
                    if (i == 0)
                        list.wordCount();
                    else
                        cout << "Incorrect number of arguments" << endl;
                }
                if (command == "distWords") {
                    if (i == 0)
                        list.distWords();
                    else
                        cout << "Incorrect number of arguments" << endl;
                }
                if (command == "charCount") {
                    if (i == 0)
                        list.charCount();
                    else
                        cout << "Incorrect number of arguments" << endl;
                }
                if (command == "frequentWord") {
                    if (i == 0)
                        list.frequentWord();
                    else
                        cout << "Incorrect number of arguments" << endl;
                }
                if (command == "countWord")
                {
                    if (i == 1)
                        list.countWord(target);
                    else
                        cout << "Incorrect number of arguments" << endl;
                }
                if (command == "starting")
                {
                    if (i == 1)
                        list.starting(target);
                    else
                        cout << "Incorrect number of arguments" << endl;
                }
                if (command == "containing")
                {
                    if (i == 1)
                        list.containing(target);
                    else
                        cout << "Incorrect number of arguments" << endl;
                }
                if (command == "search")
                {
                    if (i == 1)
                        list.search(target);
                    else
                        cout << "Incorrect number of arguments" << endl;
                }
            }
            else
                cout << "Undefined command" << endl;
        }
    }
}
void inorderList::show() {
    if (head == NULL) { cout << "the list is empty"; exit(0); }
    else {
        current = head;
        while (current != NULL)
        {
            cout << current->elem << " ";
            current = current->next;
        }
    }
    cout << endl;
}
void inorderList::wordCount() {
    cout << words << " " << "words" << endl;
}
void inorderList::distWords() {
    int count, distWordsCount = 0;
    current = head;
    while (current != NULL)
    {
        count = 0;
        node* temp = head;
        while (temp != NULL)
        {
            if ((current != temp) && (temp->elem == current->elem))
            {
                count++;
            }
            temp = temp->next;
        }
        if (count == 0)
            distWordsCount++;
        current = current->next;
    }
    cout << distWordsCount << " " << "distinct words" << endl;
}
void inorderList::charCount() {
    cout << chars << " " << "characters" << endl;
}
void inorderList::frequentWord() {
    string frequentWord_arr[10];
    int max = 0, count = 0, arr_count = 0;
    string cmp;
    current = head;
    while (current != NULL)
    {
        count = 0;
        node* temp = head;
        while (temp != NULL)
        {
            if ((current != temp) && (temp->elem == current->elem))
            {
                count++;
            }
            temp = temp->next;
        }
        if (count > max)
        {
            max = count;
            for (int i = 0; i < 10; i++) {
                frequentWord_arr[i] = "\0";
            }
            arr_count = 0;
            frequentWord_arr[arr_count] = cmp = current->elem;
        }
        else if (count == max) {
            if (current->elem != cmp)
            {
                cmp = current->elem;
                arr_count++;
                frequentWord_arr[arr_count] = current->elem;
            }
        }
        current = current->next;
    }
    cout << "Most frequent word is: ";
    for (int i = 0; frequentWord_arr[i] != "\0"; i++)
    {
        if (frequentWord_arr[i] != "a" && frequentWord_arr[i] != "an" && frequentWord_arr[i] != "the" &&
            frequentWord_arr[i] != "in" && frequentWord_arr[i] != "on" && frequentWord_arr[i] != "of" &&
            frequentWord_arr[i] != "and" && frequentWord_arr[i] != "if" && frequentWord_arr[i] != "are")
            cout << frequentWord_arr[i] << " ";
    }
    cout << endl;
}
void inorderList::countWord(ListElemType& s) {
    string word;
    for (int i = 0; s[i] != '\0'; i++) {
        word += tolower(s[i]);
    }
    int count = 0;
    current = head;
    while (current != NULL)
    {
        if (current->elem == word) { count++; }
        current = current->next;
    }
    cout << word << " " << "is repeated" << " " << count << " " << "times" << endl;
}
void inorderList::starting(ListElemType& s) {
    int count_arr = 0;
    int count = 0;
    bool check = true;
    string target; //stating with
    string element;//element in list
    string starting_arr[10];
    for (int i = 0; s[i] != '\0'; i++) {
        target += tolower(s[i]);
    }
    current = head;
w:
    while (current != NULL)
    {
        element = current->elem;
        if (target.size() > element.size())
        {
            current = current->next;
            goto w;
        }
        for (int i = 0; i < target.size(); i++)
        {
            if (target[i] != element[i])
            {
                current = current->next;
                goto w;
            }
        }
        for (int i = 0; starting_arr[i] != "\0"; i++)
        {
            if (element == starting_arr[i])
            {
                current = current->next;
                goto w;
            }
        }
        count = 0;
        node* temp = head;
        while (temp != NULL)
        {
            if (temp->elem == element)
            {
                count++;
            }
            temp = temp->next;
        }
        starting_arr[count_arr] = element;
        cout << element << ":" << " " << count << "\t";
        current = current->next;
    }
    if (starting_arr[0] == "\0")
        cout << "Word not found";
    cout << endl;
}
void inorderList::containing(ListElemType& s) {
    int count_arr = 0;
    int count = 0;
    bool check = true;
    string target; //containing
    string element;//element in list
    string containing_arr[100];
    for (int i = 0; s[i] != '\0'; i++) {
        target += tolower(s[i]);
    }
    current = head;
w:
    while (current != NULL)
    {
        element = current->elem;
        if (target.size() > element.size())
        {
            current = current->next;
            goto w;
        }
        for (int i = 0; (element.size() - target.size()) >= i; i++)
        {
        l1:;
            check = false;
            if (element[i] == target[0])
            {
                int x = i;
                for (int j = 0; j < target.size(); j++)
                {
                    if (element[x] != target[j])
                    {
                        if ((element.size() - i) > target.size())
                        {
                            i++;
                            goto l1;
                        }
                        else
                        {
                            current = current->next;
                            goto w;
                        }
                    }
                    x++;
                }
                check = true;
                break;
            }
        }
        if (!check) {
            current = current->next;
            goto w;
        }
        for (int i = 0; containing_arr[i] != "\0"; i++)
        {
            if (element == containing_arr[i])
            {
                current = current->next;
                goto w;
            }
        }
        count = 0;
        node* temp = head;
        while (temp != NULL)
        {
            if (temp->elem == element)
            {
                count++;
            }
            temp = temp->next;
        }
        containing_arr[count_arr] = element;
        cout << element << ": " << count << "\t";
        current = current->next;
    }
    if (containing_arr[0] == "\0")
        cout << "Word not found";
    cout << endl;
}
void inorderList::search(ListElemType& s) {
    int count_arr = 0;
    int count = 0;
    bool check = true;
    string target; //containing
    string element;//element in list
    string containing_arr[10000];
    int lines_arr[10000];
    int lines_count;
    for (int i = 0; s[i] != '\0'; i++) {
        target += tolower(s[i]);
    }
    current = head;
w:
    while (current != NULL)
    {
        element = current->elem;
        if (target.size() > element.size())
        {
            current = current->next;
            goto w;
        }
        for (int i = 0; (element.size() - target.size()) >= i; i++)
        {
        l1:;
            check = false;
            if (element[i] == target[0])
            {
                int x = i;
                for (int j = 0; j < target.size(); j++)
                {
                    if (element[x] != target[j])
                    {
                        if ((element.size() - i) > target.size())
                        {
                            i++;
                            goto l1;
                        }
                        else
                        {
                            current = current->next;
                            goto w;
                        }
                    }
                    x++;
                }
                check = true;
                break;
            }
        }
        if (!check) {
            current = current->next;
            goto w;
        }
        for (int i = 0; containing_arr[i] != "\0"; i++)
        {
            if (element == containing_arr[i])
            {
                current = current->next;
                goto w;
            }
        }
        for (int i = 0; lines_arr[i] != '\0'; i++) {
            lines_arr[i] = '\0';
        }
        count = 0;
        lines_count = 0;
        node* temp = head;
        int cmp = 0;
        while (temp != NULL)
        {
            if (temp->elem == element)
            {
                count++;
                if (cmp != temp->line)
                {
                    cmp = temp->line;
                    lines_arr[lines_count] = temp->line;
                    lines_count++;
                }
            }
            temp = temp->next;
        }
        containing_arr[count_arr] = element;
        cout << element << ":" << '\t' << "lines";
        for (int i = 0; i < lines_count; i++)
        {
            cout << " " << lines_arr[i];
        }
        cout << endl;
        current = current->next;
    }
    if (containing_arr[0] == "\0")
    {
        cout << "Word not found";
        cout << endl;
    }
}
