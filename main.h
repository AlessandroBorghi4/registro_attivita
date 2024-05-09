#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <iostream>
#include <ctime>
#include "ncurses_interface.h"

using namespace std;

struct Time {
    int hour;
    int minutes;
    int day;
    int month;
    int year;
};

class Activity {
public:
    string description;
    Time startTime;
    Time endTime;

    // Constructor
    Activity(const std::string& desc, const Time& start, const Time& end)
        : description(desc), startTime(start), endTime(end) {}

    void printActivity() {
        cout << "Description: " << description << endl;
        cout << "Start Time: " << startTime.hour << ":" << startTime.minutes << ":" << startTime.day << "/" << startTime.month << "/" << startTime.year << endl;
        cout << "End Time: " << endTime.hour << ":" << endTime.minutes << ":" << endTime.day << "/" << endTime.month << "/" << endTime.year << endl;
    }
};

#endif