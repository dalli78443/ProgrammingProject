#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "person.h" // Include the person file

/*Your program must have the following mandatory features :
1. add a new appt / task / recipe / other
2. delete an existing appt / task / recipe / other
3. update an existing appt / task / recipe / other
4. display single appt / task / recipe / other//
5. display range appt / task / recipe / other
6. display all appt / task / recipe / other
7. search for appt / task / recipe / other//
8. friendly / easy to use UI(or menu system)//
9. save accumulated data to disk//
10. load accumulated data from disk//
11. you may add additional features, increasing your group’s overall
mark to a maximum of 100 %
/**/
#define MAXDESCRIPTION 100
#define MAX_CALENDAR_ITEMS 1000

typedef enum {
    APPOINTMENT,
    BIRTHDAY,
    DEADLINES,
    OTHER
} TYPE;

typedef struct date {
    int day;
    int month;
    int year;
} DATE;

typedef struct calender {
    TYPE type;
    DATE date;
    char description[MAXDESCRIPTION];
  
    PERSON person; // Each person can be associated with a person
} CALENDER;

CALENDER CreateCalender(TYPE type,  char* description, DATE date ,PERSON person);

void displayCalender(CALENDER c);

bool addCalender(CALENDER c);

bool deleteCalender(CALENDER c);

bool updateCalender( char* description,  char* newDescription, PERSON newPerson);

void saveCalenderToDisk(CALENDER c, char* filename);

bool loadCalenderFromDisk(CALENDER c, char* filename);


void displayRangeOfCalender( TYPE type);

void displayAllCalender(CALENDER c);

PERSON* searchPersonInCalender(CALENDER c, PERSON p);

