//
// Created by 陈桐 on 2020/4/15.
//

#ifndef LEETCODE_VALIDPARENTHESE_H
#define LEETCODE_VALIDPARENTHESE_H

#include <stack>
#include <string>
#include <iostream>

using namespace std;

/*
 *
 * 括号匹配问题
 * stack
 * @author chentong
 * 后进先出
 * 实现递归用栈
 */
class ValidParenthese {

public:

    bool isMatch(char left, char right) {
        if (left == '(' && right == ')') return true;
        if (left == '{' && right == '}') return true;
        if (left == '[' && right == ']') return true;
        return false;
    }

    bool isLeft(char input) {
        if (input == '(' || input == '{' || input == '[') return true;
        return false;
    }

    bool isRight(char input) {
        if (input == ')' || input == '}' || input == ']') return true;
        return false;
    }

    bool isCheck(char input) {
        if (isLeft(input) || isRight(input)) return true;
        return false;
    }

    //栈顶反应最近的匹配元素
    bool isVaild(string s) {

        stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
            if (isLeft(s[i])) {
                stack.push(s[i]);
            } else {
                if (stack.size() == 0) return false;
                char c = stack.top();
                stack.pop();
                bool isOk = isMatch(c, s[i]);
                if (!isOk) return false;
            }

        }
        if (stack.size() != 0) return false;
        return true;
    }

};


#endif //LEETCODE_VALIDPARENTHESE_H
