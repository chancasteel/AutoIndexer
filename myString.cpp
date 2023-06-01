#include "myString.h"

myString::myString() : str(nullptr), length(0) {}

myString::myString(const char* arg) : length((int)strlen(arg)), str(new char [strlen(arg) + 1]){
    if (str != nullptr)
        strcpy(str, arg);
}

myString::myString(const myString& arg) : length(arg.length), str(new char [arg.length + 1]) {
    strcpy(str, arg.str);
    str[arg.length] = '\0';
}

myString::~myString() {
    delete[] str;
}

myString &myString::operator=(const char* arg) {
    if (*this == arg)
        return *this;
    delete[] str;
    str = new char[strlen(arg) + 1];
    strcpy(str, arg);
    length = (int)strlen(arg);
    return *this;
}

myString &myString::operator=(const myString& arg) {
    if (this == &arg)
        return *this;
    delete[] str;
    str = new char[arg.length + 1];
    strcpy(str, arg.str);
    length = arg.length;
    return *this;
}

myString myString::operator+(const myString& arg) {
    if (str == nullptr)
        return arg;
    length = (int)(strlen(str) + strlen(arg.str));
    char* temp = new char[length + 1];
    strcpy(temp, str);
    strcat(temp, arg.str);
    temp[length] = '\0';
    myString newString(temp);
    delete[] temp;
    return newString;
}

bool myString::operator==(const char* arg) const {
    if (!arg)
        return false;
    return strcmp(str, arg) == 0;
}

bool myString::operator==(const myString& arg) const {
    if (!arg.str)
        return false;
    return strcmp(str, arg.str) == 0;
}

bool myString::operator>(const myString& arg) {
    return strcmp(str, arg.str) > 0;
}

bool myString::operator>(const char* arg) {
    return strcmp(str, arg) > 0;
}

bool myString::operator<(const myString& arg) const {
    return strcmp(str, arg.str) < 0;
}

bool myString::operator<(const char* arg) {
    return strcmp(str, arg) < 0;
}

char& myString::operator[](const int arg) {
    return str[arg];
}

int myString::getLength() const {
    return length;
}

myString myString::substring(int start, int numChars) {
    char* temp = new char[numChars + 1];
    for (int i = 0; i < numChars; i++)
        temp[i] = str[start + i];
    temp[strlen(temp)] = '\0';
    myString newString(temp);
    delete[] temp;
    return newString;
}

char* myString::c_str() {
    return str;
}

myString myString::token(char* del) {
    char* token = strtok(str, del);
    if (token == nullptr)
        return *this;
    return myString(token);
}

int myString::toInt() {
    char* pEnd;
    int num = (int)strtol(str, &pEnd, 10);
    return num;
}

myString& myString::toLower() {
    for (int i = 0; i < length; i++)
        str[i] = (char)tolower(str[i]);
    return *this;
}

char* myString::find(char* arg) {
    return strstr(str, arg);
}

myString myString::operator+(char arg) {
    if (str == nullptr) {
        str = new char[1]{arg};
        length++;
    }
    else {
        char* temp = new char[length + 2];
        strcpy(temp, str);
        temp[length] = arg;
        temp[length + 1] = '\0';
        myString newString(temp);
        delete[] temp;
        return newString;
    }
}