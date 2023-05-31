#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>
using namespace std;

class myString {
    private:
        char* str;
        int length;
    public:
        myString();
        explicit myString(const char* arg);
        myString(const myString&);
        ~myString();

        myString& operator= (const char*);
        myString& operator= (const myString&);

        myString operator+ (char);
        myString operator+ (const myString&);

        bool operator== (const char*) const;
        bool operator== (const myString&) const;
        bool operator> (const myString&);
        bool operator> (const char*);
        bool operator< (const myString&) const;
        bool operator< (const char*);

        char& operator[] (int);

        int getLength() const;

        myString substring(int start, int numChars);

        char* c_str();

        friend ostream& operator<< (ostream& os, const myString& arg) {
            os << arg.str;
            return os;
        }

        char* find(char*);

        myString token(char*);

        int toInt();

        myString& toLower();

};