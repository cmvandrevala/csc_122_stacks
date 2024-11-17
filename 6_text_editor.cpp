#include <fstream>
#include <string>

// https://www.mattduck.com/undo-redo-text-editors

class Document
{
private:
  string text = "";

public:
  void append(string new_text)
  {
    text += new_text;
  }

  void delete_last_char()
  {
    text.pop_back();
  }
};

class UndoableCommand
{
public:
  virtual void execute() = 0;
  virtual void undo() = 0;
}

class AddText : public UndoableCommand
{
private:
  Document *document;
  string text;

public:
  AddText(Document *d, string t) : document(d), text(t) {}
  void execute() override
  {
    document->append(text);
  }

  void undo() override
  {
    for (int i = 0; i < text.length(); i++)
    {
      document->delete_last_char();
    }
  }
};

using namespace std;

int main()
{
  Document document;
  MyStack<UndoableCommand *> stack;
  bool in_progress = true;
  int option;
  string text;

  while (in_progress)
  {
    cout << "Do you want to (1) add some text or (2) undo your changes?" << endl;
    cin >> option;

    if (option == 1)
    {
      cout << "Enter your text: ";
      getline(cin, text);
      AddText command(document, text);
      stack.push(&command);
      cin.ignore(1000, "\n");
    }
  }

  return 0;
}
