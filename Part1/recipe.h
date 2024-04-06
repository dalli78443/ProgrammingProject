#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//prog71985-winter24-project-number1
//alli demilade, ansh dhunna, abhimanyu rajeevan
//recipe  program
#define MAXNAME 100
#define MAXINGREDIENT 1000
#define MAXINSTRUCTIONS 1000

typedef struct recipe {
	char name[MAXNAME];
	char ingredient[MAXINGREDIENT];
	char instructions[MAXINSTRUCTIONS];
}RECIPE;

/*
create new recipe
add a new  recipe
 delete an existing recipe 
 update an existing recipe 
 display single recipe 
 display range  recipe 
 display all recipe 
search for  recipe 
 friendly / easy to use UI(or menu system)
 save accumulated data to disk
 load accumulated data from disk
*/