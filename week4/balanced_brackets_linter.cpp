#include <iostream>

#include "../src/ArrayStack.hpp"

void isBalancedBracketsWithArrayStack(std::string str, int len);

int main(void)
{
    std::string str;
    std::cout << "Enter string: ";
    std::getline(std::cin, str);

    isBalancedBracketsWithArrayStack(str, str.size());

    return 0;
}

void isBalancedBracketsWithArrayStack(std::string str, int len)
{
    ArrayStack<char> st(len);

    int firstOpeningPos = 0;
    int lastClosingPos = 0;
    int mismatchPos;
    bool hasMismatch = false;
    bool hasExtra = false;

    for (int i = 0; i < len; ++i)
    {
        char c1 = str[i];
        // opening found -> push to stack
        if (c1 == '{' || c1 == '(' || c1 == '[')
        {
            if (st.isEmpty())
            {
                firstOpeningPos = i + 1;
            }
            st.push(c1);
        }
        // skip ''
        else if (c1 == '\'')
        {
            if (i + 1 < len)
            {
                if (str[i + 1] == '\'') // ''
                    i++;
                else if (i + 2 < len && str[i + 2] == '\'') // '{'
                    i += 2;
                else
                {
                    // case single '
                }
            }
        }
        // closing found
        else if (c1 == '}' || c1 == ')' || c1 == ']')
        {
            // extra closing
            if (st.isEmpty())
            {
                hasExtra = true;
                lastClosingPos = i + 1; // save the last closing position
            }
            // matching bracket
            else if ((c1 == '}' && st.peek() == '{') || (c1 == ')' && st.peek() == '(') || (c1 == ']' && st.peek() == '['))
            {
                st.pop();
            }
            // mismatch
            else
            {
                hasMismatch = true;
                mismatchPos = i + 1;
                break;
            }
        }
        else
        {
            // ignore other character
        }
    }

    // extra closing
    if (hasExtra)
    {
        std::cout << "Error pos=" << lastClosingPos << " reason=extra-closing\n";
    }
    // mismatch
    else if (hasMismatch)
    {
        std::cout << "Error pos=" << mismatchPos << " reason=mismatch\n";
    }
    else if (st.isEmpty())
    {
        std::cout << "Ok\n";
    }
    // unclosed
    else
    {
        std::cout << "Error pos=" << firstOpeningPos << " reason=unclosed\n";
    }
}