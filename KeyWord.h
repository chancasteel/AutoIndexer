#include "myVector.h"
#include "myString.h"
class KeyWord {
    private:
        myVector<int> pageNumbers;
        myString term;
    public:
        KeyWord();
        explicit KeyWord(const myString&);
        myString getTerm() {
            return term;
        }
        myVector<int> getPageNumbers() {
            return pageNumbers;
        }
        void addPageNumber(int);
        friend ostream& operator<< (ostream& os, const KeyWord& arg) {
            os << arg.term << ": ";
            for (auto itr = arg.pageNumbers.begin(); itr != arg.pageNumbers.end(); itr++) {
                if (itr == arg.pageNumbers.begin())
                    os << itr.operator*();
                else
                    os << ", " << itr.operator*();
            }
            os << endl;
            return os;
        }
};