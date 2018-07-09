#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

//clears the console
void clear_screen(char fill = ' ') {
    COORD tl = {0,0};
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

using namespace std;

char getChoice()
{
    char choice;
    while(true)
    {
        cin >> choice;
        cin.ignore(32767, '\n');
        if(choice == 'y' || choice == 'n')
            break;
        cout << "Incorrect choice. Try again. ";
    }
    return choice;
}

class DELETE_PAGE_REQUEST
{
    bool m_dontAskAgain = false;  //if the user wants to skip the request next time

public:
    bool checkBoolean()
    {
        return m_dontAskAgain;
    }

    void setBooleanTrue()
    {
        m_dontAskAgain = true;
    }

    char print_message(int pageNumber)
    {
        if(!m_dontAskAgain)
        {
            cout << "Page number " << pageNumber << " will be deleted so that you can rewrite it. Continue? y/n ";
            char choice = getChoice();
            cout << "Don't ask me again y/n ";
            if(getChoice() == 'y')
            {
                setBooleanTrue();
            }
            return choice;
        }
    }
};

class BookPage
{
    string m_line[10];
public:
    BookPage():
        m_line{""}
        {
        }

    void print()
    {
        for (int line = 1; line <=10; ++line)
        {
            cout << m_line[line - 1] << "\n";
        }
    }

    string write()
    {
        for (int line = 1; line <= 10; ++line)
            {
                string x;   //temporary variable for input
                getline(cin, x);    //get input
                if (x == "xxx")
                    return "xxx";
                else
                    m_line[line - 1] = x;
            }
    }
};

class Book
{
    int m_pages = 1;      //default book pages: 1
    string m_name;
    std::vector<BookPage> m_page{m_pages};  //book has minimum 1 page
    DELETE_PAGE_REQUEST message;

public:

    void setTitle()
    {
        cout << "Enter a book-title: ";
        getline(cin, m_name);
    }

    void printTitle()
    {
        cout << m_name << "\n";
    }

    void read()
    {
        cout << "\n\nBook-Title: " << m_name << "\n\n";
        for (int page = 1; page <= m_pages; ++page) //iterates through all pages of the book
        {
            m_page[page - 1].print();   //prints one page
            cout << "           " << page << "\n";
        }
    }

    void write()
    {
        setTitle();
        m_page.resize(m_pages);
        cout << "Enter 'xxx' to exit the writing-mode.\n";
        int page = 1;
        while(true)
        {
            //write on the page and check, whether the user wants to exit the writing-mode
            if (m_page[page - 1].write() == "xxx")
                break;

            cout << "           " << page << "\n";
            ++page; //next page
            ++m_pages;
            m_page.resize(m_pages);

        }
    }

    string edit()   //string, because the function has to return "DELETE" if the user wants to delete this book
    {
        cout << "Do you want to delete the book? y/n ";

        if (getChoice() == 'y')
            return "DELETE";

        cout << "Do you want to change the title? y/n ";
        if(getChoice() == 'y')
            setTitle();

        read();
        cout << "Which page would you like to edit? Enter the page number. Enter 'e' to exit the editing-mode. ";
        int pageNumber;
        char choice;

        while(true)
        {
            cin >> choice;
            if(choice == 'e')
                return "";  //there is no relevant information to return
            else pageNumber = choice - '0'; //- '0' to convert from char to int (e.g. char '1' to int 1)

            if(cin.fail())
            {
                cin.clear();
                cin.ignore(32767, '\n');
                pageNumber = -1;
            }
            if(pageNumber - 1 >= 0 && pageNumber - 1 < m_pages) //-1 to get array-index, not the page-number
                break;
            cout << "Invalid page-number. Try again. ";
        }


        if(message.print_message(pageNumber) == 'n')
            return "something, so that the edit() function terminates";

        m_page[pageNumber - 1].write();
    }
};




char homescreen()
{
    cout << "Enter 'r' to read a book or 'w' to write one.\nIf you want to edit an existing book, enter 'e'.\n";
    char choice;
    do
    {
        cin >> choice;
        if (choice != 'r' && choice != 'w' && choice != 'e')
        {
            cout << "Invalid choice. Try again: ";
            cin.ignore(32767, '\n');
        }

    }while(choice != 'r' && choice != 'w' && choice != 'e');
    cin.ignore(32767, '\n');
    clear_screen();

    return choice;
}



int main()
{
    std::vector<Book> books{};

    cout << "Welcome to the book-writing-program! You can manage your saved books here.\n" <<
    "We wish you much fun!\n";

    while (true)    //program will only end by closing it manual
    {
        switch (homescreen())
        {
        case 'r':
            cout << "BOOKSHELF\n";
            int number;
            if(books.size() > 0)
            {
                for(int iii = 0; iii <= books.size() - 1; ++iii)   //iterate through each element of the vector
                {
                    cout << iii + 1 << " ";
                    books[iii].printTitle();
                }

                cout << "\nWhich book would you like to read? Enter the Number. ";
                while(true)
                {
                    cin >> number;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(32767, '\n');
                        number = -1;   //some impossible value for 'number'
                    }
                    if(number - 1 >= 0 && number - 1 <= books.size() - 1)   //check weather 'number - 1' is a valid index for 'books'
                    {
                        books[number - 1].read();
                        break;
                    }
                    else
                        cout << "Invalid number. Try again. ";
                }
            }
            else
                cout << "<There is no book in your bookshelf>\n\n";

            break;
        case 'w':
            books.resize(books.size() + 1); //add one book to the vector
            books[books.size() - 1].write();  //access the newest book (-1 to get index)

            break;
        case 'e':
            cout << "BOOKSHELF\n";
            if(books.size() > 0)
            {
                for (int iii = 0; iii < books.size(); ++iii)
                {
                    cout << iii + 1 << " ";
                    books[iii].printTitle();
                }
                cout << "Which book would you like to edit?\n";

                while(true)
                {
                    cin >> number;
                    if(cin.fail())
                        cin.clear();
                    cin.ignore(32767, '\n');
                    if(number - 1 >= 0 && number - 1 <= books.size() - 1)   //check weather 'number - 1' is a valid index for 'books'
                        break;
                    cout << "Invalid number. Try again. ";
                }
                if(books[number - 1].edit() == "DELETE")
                    {
                        books.erase(books.begin() + (number)); //example: if number = 2, erase the second element
                    }
            }
            else
                cout << "You have no books in your bookshelf\n\n";
            break;
        }
    }
}
