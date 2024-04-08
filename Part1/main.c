#include <stdio.h>
#include "menu.h"

int main() {
    printWelcome();

    char mainMenuChoice;
    do {
        mainMenuChoice = printMainMenu();

        switch (mainMenuChoice) {
        case 'a':
        {
            char menuChoice;
            do {
                menuChoice = printMenu();
                executeMenuChoice(menuChoice);
            } while (menuChoice != 'j');
        }
        break;
        case 'b':
            printf("Exiting Calendar Manager. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (mainMenuChoice != 'b');

    return 0;
}
