enum Flags
{
    QUIT=-1
};

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        cout << "No command line arguments were passed.\n";
        return 0;
    }
    
    cout << argv[0] << "'s arguments:\n";
    
    for (int idx = 1; idx != argc; ++idx)
        cout << argv[idx] << '\n';
        
    while (true)
    {
        cout << "Enter the number of a command line argument to "
                "capitalise (or -1 to quit): ";
        int nr;
        cin >> nr;
        if (nr == Flags::QUIT)
            break;
        else if (nr > argc -1)
        {
            cout << "This index doesn't correspond to a command line "
                    "argument.\n";
            continue;
        }
        
        cout << capitalise(argv[nr]) << '\n';
    }
    
    string reverse(argv[0]);
    size_t middle = reverse.length() / 2;
    
    for (size_t idx = 0; idx != middle; ++idx)
        swap(reverse[idx], reverse[reverse.length() - 1 - idx]);
        
    cout << reverse << '\n';
}