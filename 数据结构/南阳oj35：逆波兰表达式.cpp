#include <bits/stdc++.h>
using namespace std;

int Rank(char op)
{
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    else return 0;
}

bool compare(char a, char b)
{
    return Rank(a) > Rank(b);
}

void caculate(stack<double> &S1, stack<char> &S2)
{
    double x = S1.top();S1.pop();
    double y = S1.top();S1.pop();
    switch(S2.top()) {
        case '+': S1.push(x + y); break;
        case '-': S1.push(y - x); break;
        case '*': S1.push(y * x); break;
        case '/': S1.push(y / x); break;
    }
    S2.pop();
}

void arrange(char x, stack<double> &S1, stack<char> &S2)
{
    if(S2.empty()) S2.push(x);
    else {
        while(!S2.empty() && compare(x, S2.top()) == 0) caculate(S1, S2);
        S2.push(x);
    }
}

int main()
{
    int T;
    char s[1001];
    stack<double>S1;
    stack<char> S2;
    cin >> T;
    while(T--) {
        cin >> s;
        int len = strlen(s);
        for(int i = 0; i < len; ++i) {
            if(isdigit(s[i])) {
                double n = atof(&s[i]);
                while(i < len && (isdigit(s[i]) || s[i] == '.')) i++;
                i--;
                S1.push(n);
            }
            else {
                if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') arrange(s[i], S1, S2);
                else if(s[i] == '(') S2.push(s[i]);
                else if(s[i] == ')') {
                    while(S2.top() != '(') caculate(S1, S2);
                    S2.pop();
                }
                else while(!S2.empty()) caculate(S1, S2);
            }
        }
        if(S1.size() == 1) cout << S1.top() << endl;
        S1.pop();
    }
    return 0;
}
