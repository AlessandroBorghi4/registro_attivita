#ifndef NCURSES_INTERFACE_H
#define NCURSES_INTERFACE_H

#include <ncurses.h>
#include <iostream>
#include <string>

using namespace std;

WINDOW* createInterface();
void addRowToWindow(WINDOW* win, const string text);
void delete_window(WINDOW* win);
void listenForArrowKeys(WINDOW* win);

#endif