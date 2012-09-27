#include <iostream>

using namespace std;

enum State
{
    START, FIRST_WORD, LONG_WORD, WRITE_WORD, NEXT_WORD,
    TRY_NEXT, NEWLINE, DIRECT_EOF, STOP
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
                length = 0;
                state = (word.length() > max) ? State::LONG_WORD : 
                                                State::WRITE_WORD;
            }
            break;
            
            case State::LONG_WORD:
            {
                cout << word;
                cin >> word;
                state = State::NEWLINE;
            }
            break;
            
            case State::WRITE_WORD:
            {
                cout << word;
                length += word.length();
                state = State::NEXT_WORD;
            }
            break;
            
            case State::NEXT_WORD:
                state= (cin >> word).eof() ? State::STOP : 
                                             State::TRY_NEXT;
            break;
            
            case State::TRY_NEXT:
            {
                if (length + word.length() < max)
                {
                    cout << ' ';
                    length += 1;
                    state = State::WRITE_WORD;
                }
                else
                    state = State::NEWLINE;
            }
            break;
            
            case State::NEWLINE:
            {
                cout << '\n';
                state = State::FIRST_WORD;
            }
            break;
            
            case State::DIRECT_EOF:
            {
                cout << "No input text provided.\n";
                return 0;
            }
            
            case State::STOP:
            {
                cout << ' ' << word;
                return 0;
            }
        } // switch
    } // while
}