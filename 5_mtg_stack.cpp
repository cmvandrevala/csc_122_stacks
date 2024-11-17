#include <iostream>

#include "my_stack.hpp"

using namespace std;

class Target
{
public:
  int power;
  int toughness;
  bool indestructible = false;

  explicit Target(int p, int t) : power(p), toughness(t) {}

  void stats()
  {
    cout << power << " / " << toughness << endl;
    if (indestructible)
    {
      cout << "Indestructible: true" << endl;
    }
    else
    {
      cout << "Indestructible: false" << endl;
    }
  }
};

class Card
{
public:
  virtual void play() = 0;
};

class GiantGrowth : public Card
{
private:
  Target *target;

public:
  GiantGrowth(Target *t) : target(t) {}

  virtual void play() override
  {
    this->target->power += 3;
    this->target->toughness += 3;
  }
};

class ArmorOfShadows : public Card
{
private:
  Target *target;

public:
  ArmorOfShadows(Target *t) : target(t) {}

  virtual void play() override
  {
    this->target->power += 1;
    this->target->indestructible = true;
  }
};

class Counterspell : public Card
{
private:
  MyStack<Card *> *stack;

public:
  Counterspell(MyStack<Card *> *s) : stack(s) {}

  virtual void play() override
  {
    stack->pop();
  }
};

int main()
{
  MyStack<Card *> stack;

  Target target(1, 1);

  GiantGrowth gg_one(&target);
  GiantGrowth gg_two(&target);
  ArmorOfShadows as(&target);
  Counterspell cs(&stack);

  target.stats();
  stack.push(&gg_one);
  stack.push(&gg_two);
  stack.push(&cs);
  stack.push(&as);

  while (!stack.is_empty())
  {
    stack.pop()->play();
  }

  target.stats();
}
