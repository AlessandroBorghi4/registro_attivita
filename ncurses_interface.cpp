#include "ncurses_interface.h"

using namespace std;

WINDOW* createInterface() 
{
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Create a window
    WINDOW* win = newwin(10, 30, 0, 0);
    //box(win, 0, 0);

    /*
    // Print some text in the window
    printw("Hello, world!");

    // Refresh the window
    wrefresh(win);

    // Wait for user input
    getch();
    */

    return win;
}

void addRowToWindow(WINDOW* win, const string text) 
{
    printw("%s\n", text.c_str()); // Add a newline character after printing the text
    wrefresh(win);
}

void delete_window(WINDOW* win) 
{
    // Clean up and exit
    delwin(win);
    endwin();
}

void listenForArrowKeys(WINDOW* win)
{
    int ch;
    while ((ch = getch()) != 'q') // Exit the loop when 'q' is pressed
    {
        switch (ch)
        {
            case KEY_UP:
                printf("su");
                break;
            case KEY_DOWN:
                printf("giu");
                break;
            case KEY_LEFT:
                printf("sinistra");
                break;
            case KEY_RIGHT:
                printf("destra");
                break;
        }
    }
    printf("\n");
}