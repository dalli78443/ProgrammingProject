#define _CRT_SECURE_NO_WARNINGS

//prog71985-winter24-project-number1
//alli demilade, ansh dhunna, abhimanyu rajeevan
//calender  program

#include "person.h"

static void removeNewline(char* string) {
    for (int i = 0; i < strlen(string); i++)
        if (string[i] == '\n')
            string[i] = '\0';
}


PERSON CreatePerson(char* name) {
    PERSON p;
    strncpy(p.name, name, MAXNAME);
    removeNewline(p.name);
   
    return p;
}

bool ComparePerson(PERSON lhs, PERSON rhs) {
    return(strncmp(lhs.name, rhs.name, MAXNAME) == 0);
}

void PrintPerson(PERSON p) {
   
    fprintf(stdout, "PERSON: %s\n", p.name);
}
PERSON CopyPerson(PERSON src) {
    return CreatePerson(src.name);
}

void SavePersonToDisk(PERSON p, FILE* fp) {
    fprintf(fp, "PERSON\n");
    fprintf(fp, "%s\n", p.name);
   
}

PERSON LoadPersonFromDisk(FILE* fp) {
    char buffer[MAXNAME] = { 0 };
    fgets(buffer, MAXNAME, fp);

  
    return CreatePerson(buffer);
}

void DisposePerson(PERSON P) {
    // nothing to be done in this implementation
}