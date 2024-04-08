// menu.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "menu.h"
#include "calender.h"

void printWelcome() {
    printf(" **********************\n");
    printf("**     Welcome to     **\n");
    printf("**   Calendar Manager  **\n");
    printf(" **********************\n");
}

char printMainMenu() {
    char menuChoice;

    printf("a) Open Calendar Menu\n");
    printf("b) Quit\n");

    printf("Enter your choice: ");
    scanf(" %c", &menuChoice);

    return menuChoice;
}

char printMenu() {
    char menuChoice;

    printf("\nCalendar Menu:\n");
    printf("a) Add a new event\n");
    printf("b) Delete an event\n");
    printf("c) Update an event\n");
    printf("d) Display a single event\n");
    printf("e) Display events within a range\n");
    printf("f) Display all events\n");
    printf("g) Search for an event\n");
    printf("h) Save calendar to disk\n");
    printf("i) Load calendar from disk\n");
    printf("j) Return to Main Menu\n");

    printf("Enter your choice: ");
    scanf(" %c", &menuChoice);

    return menuChoice;
}

void executeMenuChoice(char choice) {
    switch (choice) {
    case 'a':
        // Add a new event
    {
        CALENDER newEvent = createCalenderEventFromInput();
        if (addCalender(newEvent)) {
            printf("Event added successfully!\n");
        }
        else {
            printf("Failed to add event. Calendar is full.\n");
        }
    }
    break;
    case 'b':
        // Delete an event
    {
        CALENDER eventToDelete = createCalenderEventFromInput();
        if (deleteCalender(eventToDelete)) {
            printf("Event deleted successfully!\n");
        }
        else {
            printf("Event not found or failed to delete.\n");
        }
    }
    break;
    case 'c':
        // Update an event
    {
        char description[MAXDESCRIPTION];
        char newDescription[MAXDESCRIPTION];
        printf("Enter description of event to update: ");
        scanf(" %s\n", description);
        printf("Enter new description: ");
        scanf(" %s\n", newDescription);
        PERSON newPerson = createPersonFromInput();
        if (updateCalender(description, newDescription, newPerson)) {
            printf("Event updated successfully!\n");
        }
        else {
            printf("Event not found or failed to update.\n");
        }
    }
    break;
    case 'd':
        // Display a single event
    {
        CALENDER eventToDisplay = createCalenderEventFromInput();
        displayCalender(eventToDisplay);
    }
    break;
    case 'e':
        // Display events within a range
    {
        int eventType;
        printf("Enter event type (0-3): ");
        scanf("%d", &eventType);
        displayRangeOfCalender((TYPE)eventType);
    }
    break;
    case 'f':
        // Display all events
       // displayAllCalender();
        break;
    case 'g':
        // Search for an event
    {
        CALENDER eventToSearch = createCalenderEventFromInput();
        PERSON personToSearch = createPersonFromInput();
        PERSON* foundPerson = searchPersonInCalender(eventToSearch, personToSearch);
        if (foundPerson != NULL) {
            printf("Person found in calendar!\n");
            PrintPerson(*foundPerson);
        }
        else {
            printf("Person not found in calendar.\n");
        }
    }
    break;
    case 'h':
        // Save calendar to disk
    {
        char filename[100];
        printf("Enter filename to save: ");
        scanf(" %s\n", filename);
        saveCalenderToDisk(filename);
    }
    break;
    case 'i':
        // Load calendar from disk
    {
        char filename[100];
        printf("Enter filename to load: ");
        scanf(" %s\n", filename);
        if (loadCalenderFromDisk(filename)) {
            printf("Calendar loaded successfully!\n");
        }
        else {
            printf("Failed to load calendar.\n");
        }
    }
    break;
    case 'j':
        // Return to main menu (do nothing)
        break;
    case 1:
        // if user did not input a character
        printf("Invalid character entered.\n");
        break;
    default:
        printf("Invalid choice. Please try again.\n");
    }
}
