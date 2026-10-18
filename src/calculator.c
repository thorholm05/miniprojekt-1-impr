#include "calculator.h"
#include <stdio.h>
#include <math.h>

// Funktion til at udføre en regneoperation
void do_next_op(char operator, double operand, double* akkumulator) {

    // Vælg regneoperation ud fra operatoren
    switch (operator) {

        //Læg operand til akkumulatoren
        case '+':
            *akkumulator += operand;
            break;

        //Træk operand fra akkumulatoren
        case '-':
            *akkumulator -= operand;
            break;

        //Gang akkumulatoren med operand
        case '*':
            *akkumulator *= operand;
            break;

        //Divider akkumulatoren med operand
        case '/':
            // Undgå division med nul
            if (operand != 0.0) {
                *akkumulator /= operand;
            }
            break;

        //Opløft akkumulatoren i operand
        case '^':
            *akkumulator = pow(*akkumulator, operand);
            break;

        //Beregn kvadratroden af akkumulatoren
        case '#':
            // Kvadratroden af negative tal er ikke tilladt
            if (*akkumulator >= 0.0) {
                *akkumulator = sqrt(*akkumulator);
            }
            break;

        //Skift fortegn på akkumulatoren
        case '%':
            *akkumulator = -*akkumulator;
            break;

        //Divider 1 med akkumulatoren
        case '!':
            // Undgå division med nul
            if (*akkumulator != 0.0) {
                *akkumulator = 1.0 / *akkumulator;
            }
            break;

        // Ukendte operatorer ændrer ikke akkumulatoren
        default:
            break;
    }
}

// Funktion til at indlæse operator og eventuel operand
void scan_data(char* operator, double* operand) {

    // Bed brugeren om at indtaste en operator
    printf("Enter operator, and an optional operand: ");

    // Indlæs operatoren
    scanf(" %c", operator);

    // Undersøg om operatoren er binær
    if (*operator == '+' || *operator == '-' ||
        *operator == '*' || *operator == '/' ||
        *operator == '^') {

        // Indlæs operand, hvis operatoren er binær
        scanf("%lf", operand);
    }
    else {
        // Unære operatorer kræver ikke en operand
        *operand = 0.0;
    }
}

// Funktion til at styre regnemaskinen
double run_calculator(void) {

    // Opret akkumulator med startværdien 0.0
    double akkumulator = 0.0;
    double operand;
    char operator;

    // Gentag indtil brugeren indtaster q
    do {
        // Indlæs operator og eventuel operand
        scan_data(&operator, &operand);

        // Udfør beregningen, hvis brugeren ikke har valgt q
        if (operator != 'q') {
            do_next_op(operator, operand, &akkumulator);

            // Udskriv det aktuelle resultat
            printf("Result so far is %f.\n", akkumulator);
        }

    } while (operator != 'q');

    // Returner slutresultatet
    return akkumulator;
}
