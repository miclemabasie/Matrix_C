#include <stdio.h>
int data1[4];
int data2[4];
int data3[4];
int data4[4];

int determ_matrix1[2][2];
int determ_matrix2[2][2];
int determ_matrix3[2][2];

// Functions
int calculate_determinat(int length, int matrix[3][3]);
int set_determinant_matrix_data(int matrix[2][2], int valid_data[4]);
int calculate_sub_determinant(int matrix[2][2], int index_holder);


int main()
{

    int matrix[3][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}
    };
    calculate_determinat(3, matrix);

    return 0;
}

int set_determinant_matrix_data(int matrix[2][2], int valid_data[4])
{
    int set_index = 0;
    for (int i = 0; i < 2; i++)
    {

        for (int j = 0; j < 2; j++)
        {
        
            matrix[i][j] = valid_data[set_index];
            set_index++;
        
        }
    }

    return 0;
}

int calculate_sub_determinant(int matrix[2][2], int index_holder)
{
    int result, sub_determinant;
    sub_determinant = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    printf("============================Calculating the 2x2 determinants==============================");
    printf("%d(%d*%d - %d*%d) = %d\n", index_holder, matrix[0][0], matrix[1][1], matrix[0][1], matrix[1][0], sub_determinant*index_holder);
    result = index_holder * sub_determinant;
    return result;
}


int calculate_determinat(int length, int matrix[3][3])
{
    int data1_index = 0;
    int data2_index = 0;
    int data3_index = 0;
    int data4_index = 0;
    int a, b, c;
    for (int i = 0; i < length; i++)
    {

        for (int j = 0; j < length; j++)
        {

            if (i != 0 && j != 0)
            {
                data1[data1_index] = matrix[i][j];
                // printf("This is I: %d and this is j: %d\n", i, j);
                data1_index++;
            }
            if( i != 0 && j != 1)
            {
                data2[data2_index] = matrix[i][j];
                printf("This is I: %d and this is j: %d\n", i, j);
                data2_index++;
            }
            if(i != 0 && j != 2)
            {
                data3[data3_index] = matrix[i][j];
                data3_index++;
            }

        
        }
        
    }  
   
    
    set_determinant_matrix_data(determ_matrix1, data1);
    set_determinant_matrix_data(determ_matrix2, data2);
    set_determinant_matrix_data(determ_matrix3, data3);

    a = calculate_sub_determinant(determ_matrix1, matrix[0][0]);
    b = calculate_sub_determinant(determ_matrix2, matrix[0][1]);
    c = calculate_sub_determinant(determ_matrix3, matrix[0][2]);

    int result = a - b + c;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d  ", determ_matrix3[i][j]);
        }
        printf("\n");
    }
    printf("Computing result..");
    printf("Result is: (%d - %d + %d", a, b, c);
    printf("Determinant = %d \n", result);

    return result;
}

