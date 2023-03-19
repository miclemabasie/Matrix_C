#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void set_minors(int x, int y, int **matrix, float **minors_matrix, int matrix_size);
void dynamically_allocate_memory(int **matrix, int matrix_size);
void show_matrix(int **matrix, int matrix_size);



void dynamically_allocate_memory(int **matrix, int matrix_size)
{
    for (int r = 0; r < matrix_size; r++)
    {
        matrix[r] = (int *)malloc(matrix_size * sizeof(int));
    }
}


int main(void)
{
    // Dynamically allocate some space for the matrix
    int matrix_size = 3;
    int **matrix = (int **)malloc(matrix_size * sizeof(int *));
    float **minors_matrix = (float **)malloc(matrix_size * sizeof(float *));
    
    dynamically_allocate_memory(matrix, matrix_size);

    int a;
    // Allocate some variables for the matrix
    // for (int i = 0; i < matrix_size; i++)
    // {
    //     for (int j = 0; j < matrix_size; j++)
    //     {
    //         printf("Enter the value at mat[%d][%d]", i, j);
    //         scanf("%d", &matrix[i][j]);
    //     }
    //     printf("\n");
    // }

    // show created array
    // for (int i = 0; i < matrix_size; i++)
    // {
    //     for(int j = 0; j < matrix_size; j++)
    //     {
    //         printf("%d  ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }

    int singed_matrix[3][3] = {
        {1, -1, 1}, {-1, 1, -1}, {1, -1, 1}
    };

    for (int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            printf("%d  ", singed_matrix[i][j]);
        }
        printf("\n");
    }


   

    // Steps to find the inverse of a matrix
    // 1. Determinant must not be zero!
    // 2. Find the minors of the matrix
    // 3. Find the cofactors of the matrix -> singned minors.
    // 4. Find Transpose of the matrix
    // 5. Find the adjoint of the matrix -> Transpose of the cofacotors
    // 7. Take 1 devided by the det. -> 1 / det
    // 8. Multiply every result of step 7 (1/det) by every entry of the matrix from the result of step 5 (adjoint of matrix)

    // Find the minors of the matrix


        return 0;
}


// find the cofactors of a given matrix

