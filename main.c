#include <stdio.h>
#include <stdlib.h>

// GLOBALS
int data1[4];
int data2[4];
int data3[4];
int data4[4];
double determinant = 0;
// Create a variable to check if there is currently a valid matrix
int valid_matrix = 0;
int running = 1;


// FUNCTIONS
void display_intro_text();
int create_matrix_type();
void create_matrix(int **matrix, int matrix_size, int *valide_matrix);
int program_choices();
void show_matrix(int **matrix, int matrix_size, char message[100]);
void show_matrix_float(float **matrix, int matrix_size, char message[100]);
void dynamically_allocate_memory(int **matrix, int matrix_size);
void dynamic_float_memory_allocation(float **matrix, int matrix_size);
void calculate_determinant(int matrix_size, int **matrix, double *res);
int set_determinant_matrix_data(int **matrix, int valid_data[4]);
int calculate_sub_determinant(int **matrix, int index_holder);
void show_about(void);


// Inverse related functions
void set_minors(int x, int y, int **matrix, float **minors_matrix, int matrix_size);
void dynamically_allocate_memory(int **matrix, int matrix_size);
void calculate_cofactors(float **in_matrix, float **out_matrix, int standard_singn_matrix[3][3], int matrix_size);
void calculate_transpose(float **in_matrix, float **transpose_matrix, int matrix_size);
void set_all_minors(int **matrix, float **minors_matrix, int matrix_size);
void calculate_inverse(float **adjoint_matrix, float **inverse_matrix, double determinant, int matrix_size);


int main(void)
{
    /*Explain to the user how the program works*/
    display_intro_text();

    // Creates a matrix of size (matrix_size)
    int matrix_size; 

    // Dynamically create an array of pointers of size (matrix size)
    int **matrix = (int **)malloc(matrix_size * sizeof(int *));
    dynamically_allocate_memory(matrix, matrix_size);

        
    float **minors_matrix = (float **)malloc(matrix_size * sizeof(float *));
    float **cofactors = (float **)malloc(matrix_size * sizeof(float *));
    float **ajoint_matrix = (float **)malloc(matrix_size * sizeof(float *));
    // float **test = (float **)malloc(matrix_size * sizeof(float *));
    
    dynamic_float_memory_allocation(minors_matrix, matrix_size);
    dynamic_float_memory_allocation(cofactors, matrix_size);
    dynamic_float_memory_allocation(ajoint_matrix, matrix_size);
    // dynamic_float_memory_allocation(test, matrix_size);

    // float **inverse_matrix = (float **)malloc(matrix_size * sizeof(float *));
    // dynamic_float_memory_allocation(inverse_matrix, matrix_size);

    int singed_matrix[3][3] = {
        {1, -1, 1}, {-1, 1, -1}, {1, -1, 1}
    };

    while (running)
    {   
        
        int choice = program_choices();
        if (choice == 1)
        {
            if(!valid_matrix)
            {    
            int i;
            matrix_size = create_matrix_type();   
            create_matrix(matrix, matrix_size, &valid_matrix);
            show_matrix(matrix, matrix_size, "Original Matrix");
            printf("Press 1 to continue: ");
            scanf("%d", &i);
            }else {
                printf("There is already an existing matrix\n");
            }
        }else if(choice == 2)
        {   
            int i;
            printf("Finding the determinant of your matrix...\n");
            calculate_determinant(matrix_size, matrix, &determinant);
            printf("Press 1 to continue: ");
            scanf("%d", &i);
        }
        else if(choice == 3)
        {
            if(valid_matrix)
            {
                calculate_determinant(matrix_size, matrix, &determinant);
                set_all_minors(matrix, minors_matrix, matrix_size);
                calculate_cofactors(minors_matrix, cofactors, singed_matrix, matrix_size);
                calculate_transpose(cofactors, ajoint_matrix, matrix_size);
                calculate_inverse(ajoint_matrix, cofactors, determinant, matrix_size);
            }
        }
        else if(choice == 4){
            set_all_minors(matrix, minors_matrix, matrix_size);
        }else if(choice == 5){
            set_all_minors(matrix, minors_matrix, matrix_size);
            calculate_cofactors(minors_matrix, cofactors, singed_matrix, matrix_size);
        }else if(choice == 6){
            set_all_minors(matrix, minors_matrix, matrix_size);
            calculate_cofactors(minors_matrix, cofactors, singed_matrix, matrix_size);
            calculate_transpose(cofactors, ajoint_matrix, matrix_size);
        }
         else if(choice == 0)
        {
            printf("Exiting the program...\n");
            running = 0;
        }else if(choice == 7)
        {
            if(!valid_matrix)
            {
                printf("Can't show matrix, No valid matrix created yet!\n");
            }else {
                show_matrix(matrix, matrix_size, "Original Matrix");
            }
        }else if(choice == 8){
            system("clear");
            show_about();
            printf("\n");
        }
    }
    free(minors_matrix);
    free(cofactors);
    free(ajoint_matrix);

    return 0;
}

int program_choices()
{
    /* 
    This function is used to display the list of options 
    or features available for the user to select at
    every moment in time based on the data we have about the matrix
    */
    int choice;
    printf("Here are the different choices for the prgram\n");
    printf("Enter: \n");
    if(!valid_matrix)
    {
        printf("\t -> 1 Enter a new matrix\n");
        printf("\t -> 8 About the program.\n");
        printf("\t -> 0 To Quit the program!\n");
    }
    else
    {
        printf("\t -> 2 To find the DETERMINANT of the matrix\n");
        printf("\t -> 3 To find the INVERSE of the matrix\n");
        printf("\t -> 4 To find the MINORS of the matrix\n");
        printf("\t -> 5 To find the COFACTORS of the matrix\n");
        printf("\t -> 6 to find TRANSPOSE of the matrix.\n");
        printf("\t -> 7 Show the current matrix.\n");
        printf("\t -> 0 To Quit the program!\n");
    }
    scanf("%d", &choice);

    return choice;
}


int create_matrix_type()
{
    // Ask the user which type of matrix they'll love to analyse (2x2 or 3x3)
    printf("Please enter the type of matrix you wish to analyze\n");
    // Variable to keep the type of matrix
    int type, valid_input_count;
    valid_input_count = 0;
    do{
        // Keep asking for the matrix type 
        // until type = 2 or 3 
        // anything else is not valid
        if (valid_input_count > 0)
        {
            printf("\n%d is an invalid input, input must be 2 or 3!!\n\n", type);
        }
        printf("Enter 2 for (2x2) or Enter 3 for (3x3): ");
        scanf("%i", &type);
        valid_input_count++;
        
    }while (type < 2 || type > 3);
  
    return type;
}


void create_matrix(int **matrix, int matrix_size, int *valid_matrix)
{
    // Fill in the created matrix with values inputed by the user
    int value;
    printf("Creating a %d x %d matrix...\n", matrix_size, matrix_size);
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            printf("Enter value at matrix[%d][%d]: ", i, j);
            scanf("%i", &matrix[i][j]);
        }
    }
    // Update the program to indicate that we now have a valid matrix
    // and can perform operations on them
    *valid_matrix = 1;
}


void show_matrix(int **matrix, int matrix_size, char message[100])
{
    // Display the matrix to the user
    printf("%s\n", message);
    int j;
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
    return;
}


void show_matrix_float(float **matrix, int matrix_size, char message[100])
{
    // Display the matrix to the user
    printf("%s\n", message);
    int j;
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            printf("%.2f  ", matrix[i][j]);
        }
        printf("\n");
    }
    return;
}


void calculate_determinant(int matrix_size, int **matrix, double *res)
{
    // This function calculates the determinant wit the help of other functions
    if(matrix_size == 2)
    {
        double a, b, c;
        a = calculate_sub_determinant(matrix, 1);
        double result = a - b + c;
        printf("Computing result..\n");
        printf("Result is: (%.1f - %.1f + %.1f)\n", a, b, c);
        printf("Determinant = %.1f \n\n", result);
        *res = result;
    }
    else if(matrix_size == 3)
    {
        int data1_index = 0;
        int data2_index = 0;
        int data3_index = 0;
        int data4_index = 0;
        double a, b, c;
        int **matrix_daterminant_data1 = (int **)malloc(2 * sizeof(int *));
        int **matrix_daterminant_data2 = (int **)malloc(2 * sizeof(int *));
        int **matrix_daterminant_data3 = (int **)malloc(2 * sizeof(int *));

        // int **matrix = (int **)malloc(matrix_size * sizeof(int *));

        dynamically_allocate_memory(matrix_daterminant_data1, 2);
        dynamically_allocate_memory(matrix_daterminant_data2, 2);
        dynamically_allocate_memory(matrix_daterminant_data3, 2);

        // Get the data of every individual split of the matrix
        // and save it in a one dimensional array
        for (int i = 0; i < matrix_size; i++)
        {

            for (int j = 0; j < matrix_size; j++)
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
                    data2_index++;
                }
                if(i != 0 && j != 2)
                {
                    data3[data3_index] = matrix[i][j];
                    data3_index++;
                }

            
            }
            
        } 
        system("clear");
        // take the data from data1 and create a 2 x 2 matrix in 
        // matrix_determinant_data1 for example
        set_determinant_matrix_data(matrix_daterminant_data1, data1);
        set_determinant_matrix_data(matrix_daterminant_data2, data2);
        set_determinant_matrix_data(matrix_daterminant_data3, data3);
        printf("################## RSULTS FOR DETERMINANT ##################\n");
        show_matrix(matrix_daterminant_data1, 2, "Sub Determnat Calculation");
        // Perform determnant calculations on each 2 x 2 det that was created above
        a = calculate_sub_determinant(matrix_daterminant_data1, matrix[0][0]);
        show_matrix(matrix_daterminant_data2, 2, "Sub Determnat Calculation");
        b = calculate_sub_determinant(matrix_daterminant_data2, matrix[0][1]);
        show_matrix(matrix_daterminant_data3, 2, "Sub Determnat Calculation");
        c = calculate_sub_determinant(matrix_daterminant_data3, matrix[0][2]);
        // Perform the calculation of the final determinant value
        double result = a - b + c;
        printf("Computing result..\n");
        printf("Result is: (%.1f - %.1f + %.1f)\n", a, b, c);
        printf("Determinant = %.1f \n\n", result);
        *res = result;
    }
   
}


int set_determinant_matrix_data(int **matrix, int valid_data[4])
{
    // Create a 2 x 2 array out of the single dimensional valid_data
    // and save the 2 x 2 array to matrix array
    int start_index = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matrix[i][j] = valid_data[start_index];
            start_index++;      
        }
    }
    return 0;
}


int calculate_sub_determinant(int **matrix, int index_holder)
{   
    /*
        calculating the determinant of each pair in the matrix
        should incase it is a 3 x 3 matrix
        The index_holder tells the function which index in the array
        to be treated as a place holder variable for the calculations
    */
    int result, sub_determinant;
    sub_determinant = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    printf("Calculating the 2x2 determinants\t============>\t");
    printf("%d(%d*%d - %d*%d) = %d\n", index_holder, matrix[0][0], matrix[1][1], matrix[0][1], matrix[1][0], sub_determinant*index_holder);
    result = index_holder * sub_determinant;
    return result;

}


void show_about(void)
{
    // Tell the user about the application and it's features
    printf("\nMiclem's Matrix Solver is a console application written in C language\n that provides a comprehensive and powerful suit of tools to solve problems \nrelated to matrices. With this easy-to-use program, users can quickly perform \nmatrix operation, such as Gaussian elimination, inversion, rank deternations, \nfactorizations, inverses, eigenvalues calculations and many more. Miclem's \nMatrix Solver gives users the power to quickly accurately solve mathematical \nproblems involving matrices. This robust tool is designed for use by \nmathematicians, students or anyone who needs to work with matrices.\n");
}


void display_intro_text()
{
    printf("##################################  INTRODUCTRION  ############################\n");
    printf("This is a simple C program to solve some basic matrix problems.\n");
    printf("We hope that this program helps you accomplish a few things related to matrices\n");
    printf("To learn how to use the program we have provide some help below\n");
    printf("Please contact me at miclemabasie3@gmail.com if you would be so kind to suggest any improvements to the program, thanks!.\n");
    printf("################################################################################\n");
    return;
}


void normal_show(int *matrix)
{
    int j;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("%d  ", matrix[i]);
        }
        printf("\n");
    }
}

void dynamically_allocate_memory(int **matrix, int matrix_size)
{
    for (int r = 0; r < matrix_size; r++)
    {
        matrix[r] = (int *)malloc(matrix_size * sizeof(int));
    }
}

void dynamic_float_memory_allocation(float **matrix, int matrix_size)
{
    for (int r = 0; r < matrix_size; r++)
    {
        matrix[r] = (float *)malloc(matrix_size * sizeof(float));
    }  
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
    show_matrix_float(minors_matrix, matrix_size, "Minors Matrix");
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
    show_matrix_float(out_matrix, matrix_size, "Cofactors");

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
    show_matrix_float(transpose_matrix, matrix_size, "Transpose Matrix");
}

void set_all_minors(int **matrix, float **minors_matrix, int matrix_size)
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


void calculate_inverse(float **adjoint_matrix, float **inverse_matrix, double determinant, int matrix_size)
{
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            inverse_matrix[i][j] = adjoint_matrix[i][j] * (1 / determinant);
        }
    }
    show_matrix_float(inverse_matrix, matrix_size, "INVERSE MATRIX");
}

