#pragma once

class Matrix {
    int size;
    int** items;
public:
    Matrix(); // Constructor
    ~Matrix(); // Destructor
    void setsize(int s);
    int getsize();
    int *operator[] (int index);
    bool diagdom(); // Diagonal dominance
    Matrix operator+(const Matrix& M);
    Matrix &operator=(const Matrix& M);
};