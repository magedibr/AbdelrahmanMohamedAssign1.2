//
// Created by Abdelrahman Mohamed on 2020-09-29.
//
#include <stdio.h>
#include "validate.h"


int testGrid(int b[9][9])

{

    int i, j, k, l, m, n;

//Invalid if any value is not from 1 to 9

    for(i = 0; i < 9; i++)

        for( j = 0; j < 9; j++)

            if(b[i][j] < 1 || b[i][j] > 9)

                return 0;

//Invalid if any value repeats in the row

    for(i = 0; i < 9; i++)

        for( j = 0; j < 9; j++)

            for(k = 1; k < j; k++)

                if(b[i][j] == b[i][k])

                    return 0;

//Invalid if any value repeats in the column

    for(j = 0; j < 9; j++)

        for(i = 0; i < 9; i++)

            for(k = 1; k < i; k++)

                if(b[i][j] == b[k][j])

                    return 0;

//Invalid if any value repeats in the block

    for(i = 0; i < 9; i++)

        for(j = 0; j < 9; j++)

        {

            m = (int)(i / 3) * 3;

            n = (int)(j / 3) * 3;

            for(k = m; k < m + 3; k++)

                for(l = n; l < n + 3; l++)

                    if((i != k || j != l) && (b[i][j] == b[k][l]))
                        return 0;
        }

    return 1;
}

//Function to print the result accordingly

void printResult(int result)

{

    if(result == 1)

        printf("It is a valid solution.\n");

    else

        printf("It is an invalid solution.\n");

}

//Fucntion to display the grid

void gridPrint(int validArr[9][9])

{

    int i, j;

    printf("\n-------------Sudoku Grid-------------");

    for(i = 0; i < 9; i++)

    {

        printf("\n");

        for(j = 0; j < 9; j++)

            printf(" %d", validArr[i][j]);

    }

    printf("\n\n");

}

