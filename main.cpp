/*
Registro di attività che memorizza cosa si è fatto durante una giornata. 
Classe che rappresenta attività con descrizione, tempo inizio e fine, 
Classe registro che colleziona attività su base del giorno. 
Interfaccia semplice per mostrare il registro sulla base 
di un giorno fatta a scelta con:
nCurses
wxWidgets
QT
*/

#include "main.h"

using namespace std;

struct activity_list {
    Activity activity;
    activity_list* next;
};

string ActivityToString(Activity a);
void appendActivity(activity_list* head, Activity a);

int main ()
{
    // Get today's date
    time_t now = time(nullptr);
    tm* today = localtime(&now);
    int day = today->tm_mday;
    int month = today->tm_mon + 1;
    int year = today->tm_year + 1900;
    
    activity_list *head = nullptr;

    appendActivity(head, Activity("Test", {12, 30, day, month, year}, {13, 30, day, month, year}));
    appendActivity(head, Activity("Test2", {14, 30, day, month, year}, {15, 30, day, month, year}));

    activity_list *pointer = head;

    WINDOW *win = createInterface();

    while(pointer->next != nullptr)
    {
        string res = ActivityToString((*pointer).activity);
        addRowToWindow(win, res);
        pointer = pointer->next;
    }

    //listenForArrowKeys(win);

    getch();

    delete_window(win);    

    return 0;
}

string ActivityToString(Activity a)
{
    string result = "Description: " + a.description + "\n";
    result += "Start Time: " + to_string(a.startTime.hour) + ":" + to_string(a.startTime.minutes) + ":" + to_string(a.startTime.day) + "/" + to_string(a.startTime.month) + "/" + to_string(a.startTime.year) + "\n";
    result += "End Time: " + to_string(a.endTime.hour) + ":" + to_string(a.endTime.minutes) + ":" + to_string(a.endTime.day) + "/" + to_string(a.endTime.month) + "/" + to_string(a.endTime.year) + "\n";
    return result;
}

void appendActivity(activity_list* head, Activity a)
{
    activity_list* current = head;
    if(current == nullptr)
    {
        head = new activity_list{a, nullptr};
    }
    else
    {
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new activity_list{a, nullptr};
    }
}
