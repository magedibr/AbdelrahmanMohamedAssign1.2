#include <stdio.h>

#include<stdlib.h>
#include <stdio.h>
#include "validate.h"
#include<time.h>

int main(void)

{



//Test case

    int validArr[9][9] = {{5,3,4,6,7,8,9,1,2}, {6,7,2,1,9,5,3,4,8},{1,9,8,3,4,2,5,6,7},
                     {8,5,9,7,6,1,4,2,3},{4,2,6,8,5,3,7,9,1},{7,1,3,9,2,4,8,5,6},
                     {9,6,1,5,3,7,2,8,4},{2,8,7,4,1,9,6,3,5},{3,4,5,2,8,6,1,7,9}};

    gridPrint(validArr);
    printResult(testGrid(validArr));

//User Input

    for(int i = 0; i < 2; i++)

    {

        printf("Enter row %d of your Sudoku grid\n", i + 1);

        printf("Use Space/Tab/Return key to enter the next values\n");

        printf("and press \'Return\' after entering nine integers.\n");

        printf("Remember, to make a valid row of Sudoku grid,\n");

        printf("all integers should be distinct and range from 1 to 9\n");

        for(int j = 0; j < 9; j++)

            scanf("%d", &validArr[i][j]);

    }

//Create the rest of the rows

    srand(time(0));

    for(int i = 2; i < 9; i++)

        for(int j = 0; j < 9; j++)

        {

            validArr[i][j] = 1 + rand() % 9;



            for(int k = 0; k < j; k++)

                if(validArr[i][j] == validArr[i][k])

                    j--;

        }

    gridPrint(validArr);

    printResult(testGrid(validArr));

}