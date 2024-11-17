#include <iostream>
#include <vector>
#include <string>

#include "my_stack.hpp"

using namespace std;

vector<string> parse(string expression)
{
  vector<string> output;
  for (int i = 0; i < expression.length(); i++)
  {
    if (expression[i] != '(' && expression[i] != ')' && expression[i] != ' ')
    {
      string s;
      s.push_back(expression[i]);
      output.push_back(s);
    }
  }
  return output;
}

int postfix_calculator(vector<string> math_expression)
{
  MyStack<int> stack;

  for (auto i = math_expression.begin(); i != math_expression.end(); i++)
  {
    if (*i == "+")
    {
      int sum = stack.pop() + stack.pop();
      stack.push(sum);
    }
    else if (*i == "-")
    {
      int difference = stack.pop() - stack.pop();
      stack.push(difference);
    }
    else if (*i == "*")
    {
      int product = stack.pop() * stack.pop();
      stack.push(product);
    }
    else if (*i == "/")
    {
      int division = stack.pop() / stack.pop();
      stack.push(division);
    }
    else
    {
      stack.push(stoi(*i));
    }
  }

  return stack.pop();
}

int main()
{
  string expression = "(* (+ 1 2) (- 7 4))";

  vector<string> parsed_expression = parse(expression);
  std::reverse(parsed_expression.begin(), parsed_expression.end());
  cout << postfix_calculator(parsed_expression) << endl;
}
