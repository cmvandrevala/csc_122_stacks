#include <iostream>
#include <vector>
#include <string>

#include "my_stack.hpp"

using namespace std;

int main()
{
  vector<string> my_mathematical_expression = {"3", "4", "+", "2", "*", "28", "/"};
  // vector<string> my_mathematical_expression = {"3", "4", "+", "2", "3", "+", "+"};
  MyStack<int> stack;

  for (auto i = my_mathematical_expression.begin(); i < my_mathematical_expression.end(); i++)
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

  cout << stack.pop() << endl;
}
