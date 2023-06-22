#include "myVector.h"
#include "KeyWord.h"
#include <iostream>
#include <fstream>
#include <algorithm>

class AutoIndexer
{
private:
    myVector<KeyWord> Index;
public:
    explicit AutoIndexer(char**);
    void readBook(char*);
    void readKeyWords(char*);
    static int getPageNumber(char*);
    void readPage(myString, int);
    void PrintIndex(char*);
};
