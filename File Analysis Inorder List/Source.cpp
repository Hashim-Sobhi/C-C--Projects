/************************************************************/
/** author  :Hashim Sobhy                                  **/
/** Date    :18.5.2021                                      **/
/** Version :1.0                                           **/
/** Title   :Assignment #2 File Analysis using inorder List                                 **/
/************************************************************/
#include <iostream>
#include "inorderList.h"
using namespace std;
/******global variables******/
long int words = 0, chars = 0;
/****************************/

int main(int argc, char** argv) {
    if (argc != 3) { cout << "Incorrect number of arguments"; return 0; }
    inorderList list;
    if (!insertDataFile(argv[1], list))  return 0;
    if (!insertCommandFile(argv[2], list))  return 0;
    return 0;
}
