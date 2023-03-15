

#include <iostream>
#include <miniStack.h>
#include <map>
using namespace std;

int simple_cal(int op1, int op2, char op) {
    if (op == '+') return op1 + op2;

    else if (op == '-') return op1 - op2;
    
    else if (op == '*') return op1 * op2;

    else return op1 / op2;
}
int final_cal(miniStack<char> symbol, miniStack<int>  num)
{

    while (!symbol.empty()) {
        char op = symbol.get_top();
        symbol.pop();
        int op2 = num.get_top();
        num.pop();
        int op1 = num.get_top();
        num.pop();
        int result = simple_cal(op1, op2, op);
        num.push(result);
    }

    // 返回最终结果
    return num.get_top();
}
int int_process(string t, int &temp)//利用递归来判断数字位数大小并返回正确数字
{
    int result = t[temp] - '0';
    int tempp = temp;
    while (tempp +1 < t.size() && isdigit(t[tempp +1]))
    {

        result = result * 10 + (t[temp+1] - '0');
        temp++;
        tempp++;
    }


    return result;

}
int compare(miniStack<char> symbol, miniStack<int> num, string expression) {
    

    map<char, int> priority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };
    
    for (int i =0 ; i<expression.size(); i++)
    {
        char c = expression[i];
        if (isdigit(c)) {
            
            num.push(int_process(expression,i));
            
        }
        else if (c == '(') {
        
            symbol.push(c);
        }
        else if (c == ')') {
          
            while (!symbol.empty() && symbol.get_top() != '(') {
                char op = symbol.get_top();
                symbol.pop();
                int op2 = num.get_top();
                num.pop();
                int op1 = num.get_top();
                num.pop();
                int result = simple_cal(op1, op2, op);
                num.push(result);
            }
        
            symbol.pop();
        }
        else if (priority.count(c)) {
         
            while (!symbol.empty() && priority.count(symbol.get_top()) && priority[c] <= priority[symbol.get_top()]) {
                char op = symbol.get_top(); symbol.pop();
                int op2 = num.get_top(); num.pop();
                int op1 = num.get_top(); num.pop();
                int result = simple_cal(op1, op2, op);
                num.push(result);
            }
      
            symbol.push(c);
        }
    }
    return final_cal(symbol, num);

  

}



int main() {
    miniStack<char> symbol;
    miniStack<int> num;
    cout << "请输入想要计算的算式，支持+ - * / （ ）"<<endl;
    string expression;
    cin >> expression;
   
    cout << expression << "=" << compare(symbol, num, expression) << endl;
    return 0;
}

