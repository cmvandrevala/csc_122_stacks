#include <iostream>

#include "my_stack.hpp"

using namespace std;

void nge_naive(int *arr, int n)
{
  int next, i, j;
  for (i = 0; i < n; i++)
  {
    next = -1;
    for (j = i + 1; j < n; j++)
    {
      if (arr[i] < arr[j])
      {
        next = arr[j];
        break;
      }
    }
    cout << arr[i] << " --> " << next << endl;
  }
}

void nge_stack(int *arr, int n)
{
  MyStack<int> s;
  s.push(arr[0]);

  for (int i = 1; i < n; i++)
  {
    if (s.is_empty())
    {
      s.push(arr[i]);
      continue;
    }
    while (s.is_empty() == false && s.peek() < arr[i])
    {
      cout << s.peek() << " --> " << arr[i] << endl;
      s.pop();
    }
    s.push(arr[i]);
  }

  while (s.is_empty() == false)
  {
    cout << s.peek() << " --> " << -1 << endl;
    s.pop();
  }
}

int main()
{
  int arr[] = {11, 13, 21, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  nge_naive(arr, n);
  nge_stack(arr, n);
  return 0;
}
