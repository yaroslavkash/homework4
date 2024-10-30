#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool ismatching(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
        (opening == '[' && closing == ']') ||
        (opening == '{' && closing == '}');
}

void checkbrackets(const string& x) {
    stack<char> bracketStack;
    int errorPosition = -1;

    for (size_t i = 0; i < x.size(); ++i) {
        char ch = x[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            bracketStack.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (bracketStack.empty() || !ismatching(bracketStack.top(), ch)) {
                errorPosition = i; 
                break;
            }
            bracketStack.pop();
        }
        else if (ch == ';') {
            break;
        }
    }

    if (errorPosition == -1 && bracketStack.empty()) {
        cout << "The string is correct." << endl;
    }
    else {
        cout << "The string is incorrect: ";
        cout << x.substr(0, errorPosition + 1) << endl;
    }
}

int main() {
    string x;
    cout << "Enter the expression ending with ';': ";
    getline(cin, x);

    checkbrackets(x);

    return 0;
}
