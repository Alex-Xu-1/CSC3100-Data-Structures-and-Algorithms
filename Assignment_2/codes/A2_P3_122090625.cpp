#include <iostream>
#include <stack>
using namespace std;

char s[1000010], sout[1000010];
int m;

int main() {
    stack<char> monotone_stack;

    scanf("%s%d", s, &m);
    for (char *p = s; *p != '\0'; ++p) {
        while (!monotone_stack.empty() && m > 0 && *p < monotone_stack.top()) {
            monotone_stack.pop();
            --m;
        }
        monotone_stack.push(*p);
    };

    while (m > 0 && !monotone_stack.empty()) {
        monotone_stack.pop();
        --m;
    }
    int cnt, cnt2;
    cnt = cnt2 = monotone_stack.size();
    if (cnt == 0) {
        puts("0");
        return 0;
    }
    while (!monotone_stack.empty()) {
        sout[--cnt2] = monotone_stack.top();
        monotone_stack.pop();
    }
    

    bool flag = false;

    for (int i = 0; i < cnt; ++i) {
        if (flag || sout[i] != '0') {
            flag = true;
            cout << sout[i];
        }
    }
    if (!flag)
        puts("0");
    else
        puts("");
}