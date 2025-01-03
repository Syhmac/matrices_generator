// Created: 2025-01-03 20:51:00
// Ver. 1.0
// Comment lang: EN
// CMD text lang: PL
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct matrix_size { // Defining a structure that will store the size of the matrix
    int row;
    int col;
};

void close_file(FILE* file) {
    // Closes the file
    // Takes a pointer to the file as an argument
    fclose(file);
}

void save_matrix(int** matrix, const struct matrix_size size, const char* file_name) {
    // Saves the matrix to the file
    // Takes the pointer to the matrix and the struct with its size as arguments
    FILE *file = fopen(file_name, "w");
    fprintf(file, "%d %d", size.row, size.col);
    for (int i = 0; i < size.row; i++) {
        fprintf(file, "\n");
        for (int j = 0; j < size.col - 1; j++) {
            fprintf(file, "%d ", matrix[j][i]);
        }
        fprintf(file, "%d", matrix[size.col - 1][i]); // To avoid the space at the end of the line
    }
    close_file(file);
}

int** allocate_matrix(const int col, const int row) {
    // Allocating memory for the matrix
    // Takes the number of columns and rows as arguments
    // Returns a pointer to the matrix
    int **matrix = malloc(col * sizeof(int*));
    for (int i = 0; i < col; i++) {
        matrix[i] = malloc(row * sizeof(int));
    }
    return matrix;
}

void free_matrix(int** matrix, const int col) {
    // Frees the memory allocated for the matrix
    // Takes a pointer to the matrix and the number of columns as arguments
    for (int i = 0; i < col; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void fill_matrix(int** matrix, const struct matrix_size size) {
    // Fills the matrix with random numbers from 0 to 100
    // Takes a pointer to the matrix and a struct describing size as arguments
    for (int i = 0; i < size.row; i++) {
        for (int j = 0; j < size.col; j++) {
            matrix[j][i] = rand() % 101;
        }
    }
}

int main(void) {
    setlocale(LC_ALL, ""); // Setting the locale to the system's default

    // Initializing the structures
    struct matrix_size size_1;
    struct matrix_size size_2;

    // Getting the sizes of matrices from the user
    wprintf(L"Podaj wymiary pierwszej macierzy: ");
    scanf("%d %d", &size_1.row, &size_1.col);

    if (size_1.row <= 0 || size_1.col <= 0) {
        wprintf(L"Podano nieprawidłowe wymiary pierwszej macierzy\n");
        return 1;
    }

    wprintf(L"Podaj wymiary drugiej macierzy: ");
    scanf("%d %d", &size_2.row, &size_2.col);

    if (size_2.row <= 0 || size_2.col <= 0) {
        wprintf(L"Podano nieprawidłowe wymiary drugiej macierzy\n");
        return 2;
    }

    // Allocating memory for the matrices
    int** matrix_1 = allocate_matrix(size_1.col, size_1.row);
    int** matrix_2 = allocate_matrix(size_2.col, size_2.row);

    // Filling the matrices with random numbers
    fill_matrix(matrix_1, size_1);
    fill_matrix(matrix_2, size_2);

    // Saving the matrices to the files
    save_matrix(matrix_1, size_1, "matrix_1.txt");
    save_matrix(matrix_2, size_2, "matrix_2.txt");

    // Cleaning the memory
    free_matrix(matrix_1, size_1.col);
    free_matrix(matrix_2, size_2.col);

    return 0;
}
