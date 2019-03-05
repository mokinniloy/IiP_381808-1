#pragma once

class Matrix {
    int size;
    int** items;
public:
	// Constructors
    Matrix(int s);
	Matrix(const Matrix& Mat);
    ~Matrix(); // Destructor
    int getsize();
    int *operator[] (int index);
    bool diagdom(); // Diagonal dominance
    Matrix operator+(const Matrix& M);
    Matrix &operator=(const Matrix& M);
};