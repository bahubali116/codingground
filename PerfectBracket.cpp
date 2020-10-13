
//program to detect if the given sequence is perfect bracket    [{}{()[]}()]
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isLeftBracket (char c) {
    if((c == '[') || (c == '{') || (c == '(')) 
        return true;
    else
        return false;
}

bool isComplimentary (char left, char right) {
    char tmp;
    switch(left) {
        case '[':
            tmp = ']';
            break;
        case '{':
            tmp = '}';
            break;
        case '(':
            tmp = ')';
            break;
        default:
            return false;
    }
    return(tmp == right);
}

int main()
{
    stack<char> mStack;
    /*cout<<"enter the string";*/
    string str = "{{(){}[]({[](){()}{}[{}]()})}";
    /*cin >> str;*/
    string::iterator itr = str.begin();
    while(itr != str.end()) {
        if(isLeftBracket(*itr)) {
            mStack.push(*itr);
        } else {
            if(mStack.empty()) {
                cout << "1 - not a perfect bracket\n";
                return 0;
            }
            char tmp = mStack.top();
            if(!isComplimentary(tmp, *itr)) {
                cout << "2 - not a perfect bracket\n";
                return 0;
            }
            mStack.pop();
        }
        itr++;
    }
    if(mStack.empty()) {
        cout << "is a perfect bracket\n";
    } else {
        cout << "3 - is not a perfect bracket\n";
    }
    
    return 0;
}
