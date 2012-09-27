#include <iostream>

using namespace std;

enum State
{
    START, FIRST_WORD, LONG_WORD, WRITE_WORD, NEXT_WORD,
    TRY_NEXT, NEWLINE, SEPARATOR, DIRECT_EOF, STOP
};

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        cout << "Please provide max line length as arg. 1, "
                "and input text on stdin.\n";
        return 1;
    }
    
    size_t max = atoi(argv[1]);
    
    size_t length;
    string word;
    State state = State::START;
    
    while (true)
    {
        switch (state)
        {
            case State::START:
                state = (cin >> word) ? State::FIRST_WORD : 
                                        State::DIRECT_EOF;
            break;
            
            case State::FIRST_WORD:
            {
                length = word.length();
                state = (length < max) ? State::WRITE_WORD : 
                                        State::LONG_WORD;
            }
            break;
            
            case State::NEXT_WORD:
            {
                cin >> word;
                length += word.length();
                state = (length < max - word.length()) ? 
                                        State::WRITE_WORD : 
                                        State::NEWLINE;
            }
            break;
            
            case State::TRY_NEXT:
            break;
                
            case State::WRITE_WORD:
            {
                cout << word << " ";
                state = State::NEXT_WORD;
            }
            break;
            
            case State::LONG_WORD:
            {
                cout << word << '\n';
                state = State::NEWLINE;
            }
            break;
            
            case State::NEWLINE:
            {
                length = 0;
                state = State::FIRST_WORD;
            }
            break;
            
            case State::SEPARATOR:
            break;
            
            case State::STOP:
            break;
            
            case State::DIRECT_EOF:
                return 0;
            break;
        }
    }
}