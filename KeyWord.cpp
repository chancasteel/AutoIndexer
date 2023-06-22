#include "KeyWord.h"

KeyWord::KeyWord() = default;

KeyWord::KeyWord(const myString& arg) : term(arg) {}

void KeyWord::addPageNumber(int arg) {
    pageNumbers.push_back(arg);
}