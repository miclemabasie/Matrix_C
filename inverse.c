#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void set_minors(int x, int y, int **matrix, float **minors_matrix, int matrix_size);
void dynamically_allocate_memory(int **matrix, int matrix_size);
void show_matrix(int **matrix, int matrix_size);
void calculate_cofactors(float **in_matrix, float **out_matrix, int standard_singn_matrix[3][3], int matrix_size);
void calculate_transpose(float **in_matrix, float **transpose_matrix, int matrix_size);


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
    float **cofactors = (float **)malloc(matrix_size * sizeof(float *));
    float **transpose_matrix = (float **)malloc(matrix_size * sizeof(float *));
    float **test = (float **)malloc(matrix_size * sizeof(float *));

    dynamically_allocate_memory(matrix, matrix_size);

    for (int r = 0; r < matrix_size; r++)
    {
        minors_matrix[r] = (float *)malloc(matrix_size * sizeof(float));
    }

    for (int r = 0; r < matrix_size; r++)
    {
        cofactors[r] = (float *)malloc(matrix_size * sizeof(float));
    }
    for (int r = 0; r < matrix_size; r++)
    {
        transpose_matrix[r] = (float *)malloc(matrix_size * sizeof(float));
    }

    int a;
    // Allocate some variables for the matrix
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            printf("Enter the value at mat[%d][%d]", i, j);
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }

    int singed_matrix[3][3] = {
        {1, -1, 1}, {-1, 1, -1}, {1, -1, 1}
    };


    // show created array
    // for (int i = 0; i < matrix_size; i++)
    // {
    //     for(int j = 0; j < matrix_size; j++)
    //     {
    //         printf("%d  ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
     printf("\t -> 2 To find the DETERMINANT of the matrix\n");
        printf("\t -> 3 To find the INVERSE of the matrix\n");
        printf("\t -> 4 To find the MINORS of the matrix\n");
        printf("\t -> 5 To find the COFACTORS of the matrix\n");
        printf("\t -> 6 to find TRANSPOSE of the matrix.\n");
        printf("\t -> 7 Show the current matrix.\n");
        printf("\t -> 0 To Quit the program!\n");
    show_matrix(matrix, matrix_size);

    set_minors(0, 0, matrix, minors_matrix, matrix_size);
    set_minors(0, 1, matrix, minors_matrix, matrix_size);
    set_minors(0, 2, matrix, minors_matrix, matrix_size);

    set_minors(1, 0, matrix, minors_matrix, matrix_size);
    set_minors(1, 1, matrix, minors_matrix, matrix_size);
    set_minors(1, 2, matrix, minors_matrix, matrix_size);

    set_minors(2, 0, matrix, minors_matrix, matrix_size);
    set_minors(2, 1, matrix, minors_matrix, matrix_size);
    system("clear");
    set_minors(2, 2, matrix, minors_matrix, matrix_size);

    calculate_cofactors(minors_matrix, cofactors, singed_matrix, matrix_size);
    calculate_transpose(cofactors, transpose_matrix, matrix_size);
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

void set_minors(int x, int y, int **matrix, float **minors_matrix, int matrix_size)
{
    int valid_data[4];
    int tem_index = 0;
    int is_valid = 0;
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            if(i != x)
            {
                if(j != y)
                {
                    is_valid = 1;
                 valid_data[tem_index] = matrix[i][j];
                    tem_index++;
                }
            }
        }
    }
    // update minors_matrix using tem_selected_data to their respective indexs
    float res = 0;
    res = (valid_data[0] * valid_data[3]) - (valid_data[1] * valid_data[2]);
    minors_matrix[x][y] = res;
}

void show_matrix(int **matrix, int matrix_size)
{
    for (int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }

}

// find the cofactors of a given matrix

void calculate_cofactors(float **in_matrix, float **out_matrix, int standard_singn_matrix[3][3], int matrix_size)
{
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            out_matrix[i][j] = in_matrix[i][j] * standard_singn_matrix[i][j];
        }
    }

     printf("Cofactor matrix is: \n");
     for (int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            printf("%.2f  ", out_matrix[i][j]);
        }
        printf("\n");
    }
}


void calculate_transpose(float **in_matrix, float **transpose_matrix, int matrix_size)
{
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            transpose_matrix[i][j] = in_matrix[j][i];
        }
    }

    printf("Transpose matrix is: \n");
     for (int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            printf("%.2f  ", transpose_matrix[i][j]);
        }
        printf("\n");
    }
}

void set_all_minors(int **matrix, int **minors_matrix, int matrix_size)
{
    set_minors(0, 0, matrix, minors_matrix, matrix_size);
    set_minors(0, 1, matrix, minors_matrix, matrix_size);
    set_minors(0, 2, matrix, minors_matrix, matrix_size);

    set_minors(1, 0, matrix, minors_matrix, matrix_size);
    set_minors(1, 1, matrix, minors_matrix, matrix_size);
    set_minors(1, 2, matrix, minors_matrix, matrix_size);

    set_minors(2, 0, matrix, minors_matrix, matrix_size);
    set_minors(2, 1, matrix, minors_matrix, matrix_size);
    system("clear");
    set_minors(2, 2, matrix, minors_matrix, matrix_size);
}

// void calculate_inverse(float **adjoint_matrix, float **inverse_matrix, double determinant, int matrix_size)
// {
//     for(int i = 0; i < matrix_size; i++)
//     {
//         for(int j = 0; j < matrix_size; j++)
//         {
//             inverse_matrix[i][j] = adjoint_matrix[i][j] * determinant;
//         }
//     }
//     show_matrix_float(inverse_matrix, matrix_size, "INVERSE MATRIX");
// }