#include <stack>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void checkBrac (string input) {
    stack<char> st;
    for (char i:input){
        if (!st.empty()){
            switch (st.top()){
            case '(':
                if (i == ')'){
                    st.pop();
                }
                break;

            case '[':
                if (i == ']'){
                    st.pop();
                }
                break;

            case '{':
                if (i == '}'){
                    st.pop();
                }
                break;
            
            default:
                st.push(i);
            }
        }
        else {
            st.push(i);
        }
    }
    if (st.empty()){
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }
}

int main() {
    int num;
    string i;
    cin >> num; getline(cin, i);
    while (num > 0){
        getline (cin, i);
        checkBrac (i);
        num --;
    }
    return 0;
}
