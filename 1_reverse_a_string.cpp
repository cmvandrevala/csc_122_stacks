#include <iostream>

#include "my_stack.hpp"

using namespace std;

string reverse(string str)
{
  string output = "";
  MyStack<char> stack;

  for (int i = 0; i < str.length(); i++)
  {
    stack.push(str.at(i));
  }

  while (!stack.is_empty())
  {
    output += stack.pop();
  }

  return output;
}

int main()
{
  cout << reverse("Panda") << endl;
  cout << reverse("This is my awesome string!") << endl;
  cout << reverse("This would have been really useful in the palindrome lab...") << endl;
}
