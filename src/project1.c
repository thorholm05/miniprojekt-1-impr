#include "calculator.h"
#include <stdio.h>

int main(void) {

    // Start regnemaskinen og gem slutresultatet
    double result = run_calculator();

    // Udskriv det endelige resultat
    printf("Final result is: %f\n", result);

    return 0;
}
