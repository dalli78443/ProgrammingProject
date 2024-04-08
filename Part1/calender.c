#include "calender.h"

static int numCalenderItems = 0;
static CALENDER calender[MAX_CALENDAR_ITEMS];

CALENDER CreateCalender(TYPE type, char* description, DATE date, PERSON person) {
    CALENDER c;
    c.type = type;
    c.date = date;
    strncpy(c.description, description, MAXDESCRIPTION);
    c.person = person;
    return c;
}

void displayCalender(CALENDER c) {
    printf("Type: ");
    switch (c.type) {
    case APPOINTMENT:
        printf("Appointment\n");
        break;
    case BIRTHDAY:
        printf("Birthday\n");
        break;
    case DEADLINES:
        printf("Deadline\n");
        break;
    case OTHER:
        printf("Other\n");
        break;
    default:
        printf("Unknown\n");
        break;
    }
    printf("Date: %d/%d/%d\n", c.date.day, c.date.month, c.date.year);
    printf("Description: %s\n", c.description);
    printf("Associated Person: ");
    PrintPerson(c.person);
}

bool addCalender(CALENDER c) {
    if (numCalenderItems < MAX_CALENDAR_ITEMS) {
        calender[numCalenderItems++] = c;
        return true;
    }
    return false; // Calendar is full
}

bool deleteCalender(CALENDER c) {
    for (int i = 0; i < numCalenderItems; i++) {
        if (calender[i].type == c.type &&
            calender[i].date.day == c.date.day &&
            calender[i].date.month == c.date.month &&
            calender[i].date.year == c.date.year &&
            strcmp(calender[i].description, c.description) == 0 &&
            ComparePerson(calender[i].person, c.person)) {
            // Found the calendar item to delete
            for (int j = i; j < numCalenderItems - 1; j++) {
                calender[j] = calender[j + 1];
            }
            numCalenderItems--;
            return true;
        }
    }
    return false; // Calendar item not found
}

bool updateCalender(char* description, char* newDescription, PERSON newPerson) {
    bool updated = false;
    for (int i = 0; i < numCalenderItems; i++) {
        if (strcmp(calender[i].description, description) == 0) {
            strncpy(calender[i].description, newDescription, MAXDESCRIPTION);
            calender[i].person = newPerson;
            updated = true;
        }
    }
    return updated;
}

void saveCalenderToDisk( char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp != NULL) {
        for (int i = 0; i < numCalenderItems; i++) {
            SavePersonToDisk(calender[i].person, fp); // Save associated person
            fprintf(fp, "%d %d %d\n", calender[i].date.day, calender[i].date.month,
                calender[i].date.year);
            fprintf(fp, "%d\n", calender[i].type);
            fprintf(fp, "%s\n", calender[i].description);
        }
        fclose(fp);
    }
}

bool loadCalenderFromDisk(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp != NULL) {
        while (!feof(fp) && numCalenderItems < MAX_CALENDAR_ITEMS) {
            PERSON person = LoadPersonFromDisk(fp);
            DATE date;
            fscanf(fp, "%d %d %d\n", &date.day, &date.month, &date.year);
            int type;
            fscanf(fp, "%d\n", &type);
            char description[MAXDESCRIPTION];
            fgets(description, MAXDESCRIPTION, fp);
            

            CALENDER c = CreateCalender(type, description, date, person);
            addCalender(c);
        }
        fclose(fp);
        return true;
    }
    return false;
}

void displayRangeOfCalender(TYPE type) {
    for (int i = 0; i < numCalenderItems; i++) {
        if (calender[i].type == type) {
            displayCalender(calender[i]);
        }
    }
}

void displayAllCalender(CALENDER c) {
    for (int i = 0; i < numCalenderItems; i++) {
        displayCalender(calender[i]);
    }
}

PERSON* searchPersonInCalender(CALENDER c, PERSON p) {
    for (int i = 0; i < numCalenderItems; i++) {
        if (ComparePerson(calender[i].person, p)) {
            return &(calender[i].person);
        }
    }
    return NULL; // Person not found in calendar
}

CALENDER createCalenderEventFromInput() {
    int type;
    printf("Enter event type (0 for Appointment, 1 for Birthday, 2 for Deadline, 3 for Other): ");
    scanf("%d", &type);
    char description[MAXDESCRIPTION];
    printf("Enter description: ");
    scanf(" %s\n", description);
    DATE date = createDateFromInput();
    PERSON person = createPersonFromInput();
    return CreateCalender((TYPE)type, description, date, person);
}

DATE createDateFromInput() {
    DATE date;
    printf("Enter day: ");
    scanf("%d", &date.day);
    printf("Enter month: ");
    scanf("%d", &date.month);
    printf("Enter year: ");
    scanf("%d", &date.year);
    return date;
}

PERSON createPersonFromInput() {
    char name[MAXNAME];
    printf("Enter person's name: ");
    scanf(" %s\n", name);
    return CreatePerson(name);
}