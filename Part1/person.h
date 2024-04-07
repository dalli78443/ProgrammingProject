#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//prog71985-winter24-project-number1
//alli demilade, ansh dhunna, abhimanyu rajeevan
//calender  program

#define MAXNAME 50

typedef struct person {
    //
    char name[MAXNAME];
   
} PERSON;

PERSON CreatePerson(char* name);

bool ComparePerson(PERSON lhs, PERSON rhs);

void PrintPerson(PERSON p);

PERSON CopyPerson(PERSON src);

void SavePersonToDisk(PERSON p, FILE* fp);

PERSON LoadPersonFromDisk(FILE* fp);

void DisposePerson(PERSON p);