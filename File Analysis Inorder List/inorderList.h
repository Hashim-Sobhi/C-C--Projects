/************************************************************/
/** author  :Hashim Sobhy                                  **/
/** Date    :18.5.2021                                      **/
/** Version :1.0                                           **/
/** Title   :Assignment #2 File Analysis using inorder List                                 **/
/************************************************************/
#ifndef A2_INORDERLIST_H
#define A2_INORDERLIST_H
#include <string>
using namespace std;
typedef string ListElemType;
class inorderList {
public:
    inorderList(); //constructor
    bool insert(const ListElemType& e, const int& l);
    void show();
    void wordCount();
    void distWords();
    void charCount();
    void frequentWord();
    void countWord(ListElemType& s);
    void starting(ListElemType& s);
    void containing(ListElemType& s);
    void search(ListElemType& s);

private:
    struct node {
        ListElemType elem;
        int line;
        node* next;
    };
    node* head;
    node* current;
    node* prev;
};
bool insertDataFile(string dataFile, inorderList& list);
bool insertCommandFile(string dataFile, inorderList& list);

#endif //A2_INORDERLIST_H