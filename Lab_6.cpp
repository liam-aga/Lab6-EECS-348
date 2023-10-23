/* @Author: Liam Aga
 * KU ID: 3050093
 * EECS 348 | Lab 6
 * Date Created: 10/18/23
 * Last Modified: 10/22/23, 9:00pm
 * This lab performs matrix manipulation, functions and equations upon a given .txt input file.
 */

#include <iostream>
#include <fstream>
#include <iomanip>

// Define the maximum matrix size
const int MAX_SIZE = 100;

// Function prototypes
void readMatricesFromFile(const std::string& filename, int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& size); // Reads both A and B matrices
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

int main() {

    std::cout << "Lab #6: Matrix manipulation" << std::endl << std::endl;

    // Define matrices A, B, and a result matrix
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int size;

    // Read the matrices from the input file
    readMatricesFromFile("matrix_input.txt", matrixA, matrixB, size);

    // Print matrix A
    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, size);
    std::cout << std::endl;

    // Print matrix B
    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB, size);
    std::cout << std::endl;

    // Calculate and print matrix: A + B
    addMatrices(matrixA, matrixB, result, size);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(result, size);
    std::cout << std::endl;

    // Calculate and print matrix: A * B
    multiplyMatrices(matrixA, matrixB, result, size);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(result, size);
    std::cout << std::endl;

    // Calculate and print matrix: A - B
    subtractMatrices(matrixA, matrixB, result, size);
    std::cout << "Matrix Difference (A - B):" << std::endl;
    printMatrix(result, size);
    std::cout << std::endl;

    return 0;
}

// Read matrix values from a file into two 2D arrays
void readMatricesFromFile(const std::string& filename, int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& size) {
    std::ifstream input(filename);

    if (!input.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        exit(1);
    }

    input >> size;

    // Read matrix A
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            input >> matrixA[i][j];
        }
    }

    // Read matrix B
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            input >> matrixB[i][j];
        }
    }

    input.close();
}

// Print a matrix in a formatted manner
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Subtract matrix2 from matrix1 and store the result in a third matrix
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

