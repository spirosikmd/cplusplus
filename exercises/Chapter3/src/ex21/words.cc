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
        cout << "Please provide max line length as first argument, "
                "and input text on stdin.\n";
        return 1;
    }
    
    size_t max = atoi(argv[1]);
    
    size_t length;                  // the length so far
    string word;                    // the last read word
    State state = State::START;     // the current state we are in
    
    while (true)
    {
        switch (state)
        {
            case State::START:
                state = (cin >> word).eof() ? State::DIRECT_EOF : 
                                              State::FIRST_WORD;
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
                                    // update the length of the 
                                    // current line with the length of 
                                    // the last shown word
                length += word.length();
                state = State::NEXT_WORD;
            }
            break;
            
            case State::NEXT_WORD:
                state = (cin >> word).eof() ? State::STOP : 
                                              State::TRY_NEXT;
            break;
            
            case State::TRY_NEXT:
                                    // if with the new word the length 
                                    // goes more than max then newline
                                    // else add separator (add space)
                state = length + word.length() < max ? 
                                            State::SEPARATOR : 
                                            State::NEWLINE;
            break;
            
            case State::NEWLINE:
            {
                cout << '\n';
                state = State::FIRST_WORD;
            }
            break;
            
            case State::SEPARATOR:
            {
                cout << ' ';
                length += 1;        // add `1' cause of the space
                state = State::WRITE_WORD;
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