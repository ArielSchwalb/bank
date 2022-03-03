/******************************************************************************

Program file: aschwal4.c
Author: Ariel Schwalb
Date: March 2, 2022
Assignment: #4
Objective: This program allows the user to make some simple banking transactions.

*******************************************************************************/
#include <stdio.h>
#define DEPOSITS 5
#define WITHDRAWALS 5

int main(void)
{

    /* Declare variables. */
    /* ------------------ */

    int num_deposits, num_withdrawals, x;
    float deposits[DEPOSITS], withdrawals[WITHDRAWALS];
    float balance;
    char c;

    /* Welcome the user. */
    /* ----------------- */

    printf("Welcome to the Computer Banking System.\n\n");

    /* Prompt the user for the current balance. */
    /* ---------------------------------------- */

    printf("Enter your current balance in dollars and cents: ");
    scanf("%f", &balance);

    /* Ensure that the current balance is a positive number. If it is not, display an error message. */
    /* --------------------------------------------------------------------------------------------- */

    while (balance < 0) {
        printf ("\n*** Beginning balance must be at least zero, please re-enter. ***\n\n");
        printf("Enter your current balance in dollars and cents: ");
        scanf("%f", &balance);
    }

    /* Prompt the user for the number of deposits and withdrawals. If given an invalid number, display an error message and ask to reenter. */
    /* ------------------------------------------------------------------------------------------------------------------------------------ */

    printf("\nEnter the number of deposits(0-5): ");
    scanf("%i", &num_deposits);

    while (num_deposits < 0 || num_deposits > 5){
        printf ("\n*** Invalid number of deposits, please re-enter: \n");
        printf("\nEnter the number of deposits(0-5): ");
        scanf("%i", &num_deposits);
    }

    printf("\nEnter the number of withdrawals(0-5): ");
    scanf("%i", &num_withdrawals);

    while (num_withdrawals < 0 || num_withdrawals > 5){
        printf ("\n*** Invalid number of withdrawals, please re-enter: \n");
        printf("\nEnter the number of withdrawals(0-5): ");
        scanf("%i", &num_withdrawals);
    }

    /* Use for loops to prompt the user for each deposit and withdrawal.----------------------------------*/
    /* Use if statements to ensure that each deposit and withdrawal amount is greater than zero.----------*/
    /* ---------------------------------------------------------------------------------------------------*/

    for (x = 0; x < num_deposits; x++) {
        printf("\nEnter the amount of deposit #%x: ", x + 1);
        scanf("%f", &deposits[x]);

           if (deposits[x] < 0)

            {printf ("\n*** Deposit amount must be greater than zero, please re-enter. \n");
             x--;
             continue;
            }

            while ( (c = getchar() != '\n') && c != EOF); /* clear input buffer */


            /* Add the deposits to the balance. */
            /* -------------------------------- */

            balance = balance + deposits[x];
    }


    for (x = 0; x < num_withdrawals; x++) {
        printf("\nEnter the amount of withdrawal #%x: ", x + 1);
        scanf("%f", &withdrawals[x]);

           if (withdrawals[x] < 0)

            {printf ("\n*** Withdrawal amount must be greater than zero, please re-enter. \n");
             x--;
             continue;
            }

            if (withdrawals[x] > balance)

            {printf ("\n*** Withdrawal amount exceeds current balance. \n");
             x--;
             continue;
            }

            while ( (c = getchar() != '\n') && c != EOF); /* clear input buffer */

            /* Subtract the withdrawals from the balance. */
            /* ------------------------------------------ */

            balance = balance - withdrawals[x];

    }


    /* Print the new balance. Use an if statement to output a message based on the balance amount.*/
    /*--------------------------------------------------------------------------------------------*/


    printf("\nThe closing balance is %0.2f", balance);

    if (balance >= 50000.00) {

        printf("\n*** It is time to invest some money! ***");

    } else if (balance >= 15000.00 && balance <= 49999.99) {

        printf("\n*** Maybe you should consider a CD. ***");

    } else if (balance >= 1000.00 && balance <= 14999.99) {

        printf("\n*** Keep up the good work! ***");

    } else if (balance >= 0.00 && balance <= 999.99) {

        printf("\n*** Your balance is getting low! ***");
    } /* end if statement*/


    return 0;

} /*end program*/

