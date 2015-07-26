
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int Caculate(string inputStr){
        string tempStr;
        stack<char> strStack;
        for(string::iterator iter = inputStr.begin(); iter != inputStr.end(); iter++)
        {
            if( *iter >= '0' && *iter <= '9' )
                tempStr.push_back(*iter);
            else{
                    if(strStack.empty() || *iter == '(')
                        strStack.push(*iter);
                    else{
                            if(*iter == ')')
                            {
                                stack<char>::size_type stackSize = strStack.size();
                                while(stackSize)
                                {
                                    char tmpChar = strStack.top();
                                    strStack.pop();
                                    if(tmpChar == '(')
                                        break;
                                    else tempStr.push_back(tmpChar);
                                    stackSize--;
                                }
                            }
                            else{
                                if( priority(*iter) < priority(strStack.top()) )
                                {
                                    stack<char>::size_type stackSize = strStack.size();
                                    while(stackSize)
                                    {
                                        tempStr.push_back(strStack.top());
                                        strStack.pop();
                                        stackSize--;
                                    }
                                    strStack.push(*iter);
                                }
                                else
                                    strStack.push(*iter);
                            }
                        }//end else
                }//end else
        }//end for

        while( !strStack.empty())
        {
            tempStr.push_back(strStack.top());
            strStack.pop();
        }

        stack<int> numStack;
        for(string::iterator iter = tempStr.begin(); iter != tempStr.end(); iter++)
        {
            if(*iter >= '0' && *iter <= '9')
                numStack.push(*iter - '0');
            else
            {
                int num1 = numStack.top();
                numStack.pop();
                int num2 = numStack.top();
                numStack.pop();
                switch(*iter)
                {
                case '+':
                    numStack.push(num1 + num2);
                    break;
                case '-':
                    numStack.push(num2 - num1);
                    break;
                case '*':
                    numStack.push(num1 * num2);
                    break;
                case '/':
                    numStack.push(num2 / num1);
                    break;
                default:
                    break;
                }
            }
        }
        return numStack.top();

    }
private:
    int priority(char inputChar)
    {
        switch(inputChar)
        {
            case '+':
            case '-': return 1;
            case '*':
            case '/': return 2;
            default: return 0;
        }
    }
};

int main()
{
    Solution A;
    cout << A.Caculate("9+(3-1)*3+8/2") << endl;
    return 0;
}
