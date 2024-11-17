#include <iostream>

#include "my_stack.hpp"

using namespace std;

int main()
{
  string my_string = "This is my awesome string!";
  string output = "";
  MyStack<char> stack;

  for (int i = 0; i < my_string.length(); i++)
  {
    stack.push(my_string[i]);
  }

  while (!stack.is_empty())
  {
    output += stack.pop();
  }

  cout << output << endl;
}
