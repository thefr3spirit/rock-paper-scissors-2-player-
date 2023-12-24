/*Rocks, papers, scissors
this program allows 2 users to each choose an item that is compared to one it will randomly generate
and determines who won the duel...  */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*declaring symbolic constants for limits to be used when generating the random
that are going to represent the rock, paper, and scissors*/ 
#define lower_limit 1
#define upper_limit 3

//function to return users' outcome
const char *winner_determiner(int user_choice, int comp_choice);

int main()
{
    //Declare array to store user's choices
    int choice[2];

    //Use for loop to prompt users to enter their choices and store in array
    for (int a = 0; a <= 1; a++)
    {
        printf("User %d: Choose 1 for rock, 2 for paper, and 3 for scissor: ", a + 1);
        scanf("%d", &choice[a]);
    }
    printf("\n");

    //Using another for loop to display users' choice
    for (int b = 0; b <= 1; b++)
    {
        if (choice[b] == 1) { printf("User %d, picked: rock\n", b + 1); }
        else if (choice[b] == 2) { printf("User %d, picked: paper\n", b + 1); }
        else { printf("User %d, picked: scissor\n", b + 1); }
    }

    //Assigning the random number generator with current time as the seed.
    srand(time(NULL));

    //generating a random number and initializing it to the variable result
    int result = lower_limit + rand() % (upper_limit - lower_limit + 1);

    //use if statement to determine counter choice
    if (result == 1) { printf("The computer picked: rock\n\n"); }
    else if (result == 2) { printf("The computer picked: paper\n\n"); }
    else { printf("The computer picked: scissor\n\n"); }

    // Determine the winner using the winner_determiner function
    for (int c = 0; c <= 1; c++)
    {
        const char *final_result = winner_determiner(choice[c], result);
        printf("Result for User %d: %s\n", c + 1, final_result);
    }

    return 0;
}

const char *winner_determiner(int user_choice, int comp_choice)
{
    switch (user_choice)
    {
    case 1:
        if (comp_choice == 1) { return "Draw"; }
        else if (comp_choice == 2) { return "Lost"; }
        else { return "Won"; }
        break;

    case 2:
        if (comp_choice == 1) { return "Won"; }
        else if (comp_choice == 2) { return "Draw"; }
        else { return "Lost"; }
        break;

    case 3:
        if (comp_choice == 1) { return "Lost"; }
        else if (comp_choice == 2) { return "Won"; }
        else { return "Draw"; }
        break;

    default:
        return "Invalid entry!. Enter rock, paper, or scissor. Please observe the case";
    }
}
