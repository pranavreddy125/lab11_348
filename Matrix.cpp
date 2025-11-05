#include "Matrix.h" //getting matrix.h

//default construct
Matrix::Matrix() {
    size = 0; //no size yet
    data = nullptr; //no memory yet
}

//constructor with size
Matrix::Matrix(int n) {
    size = n;
    data = new int*[size]; //allocating memeory for rows
    for(int i = 0; i < size; i++) {
        data[i] = new int[size]; //each row
    }
}

//copy constructor as deep copy
Matrix::Matrix(const Matrix& other) {
    size = other.size; //copying size
    if(size == 0) {
        data = nullptr;
    } else {
        //allocate the new memory 
        data = new int*[size];
        for(int i = 0; i < size; i++) {
            data[i] = new int[size];
            //copying each val
            for(int j = 0; j < size; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
}

//copy assignment also deep copy
Matrix& Matrix::operator=(const Matrix& other) {
    if(this == &other) return *this; //if it assigns to itself then dont do anything

    //free old memory
    if(data != nullptr) {
        for(int i = 0; i < size; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
    size = other.size;

    if(size == 0) {
        data = nullptr;
    } else { //if new matrix size not 0 then same thing, allocate new memory and copy value
        data = new int*[size];
        for(int i = 0; i < size; i++) {
            data[i] = new int[size];
            for(int j = 0; j < size; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this; //return obj
}

//destructor
Matrix::~Matrix() {
    if(data != nullptr) { //if memory exists then delete
        for(int i = 0; i < size; i++) {
            delete[] data[i]; //each row
        }
        delete[] data; //delete row ptr
        data = nullptr;
    }
}

//reads 1 matrix from file only values
void Matrix::readMatrix(ifstream &file) {
    //assumes size is already set by Matrix
    //if data not allocated, allocate here
    if(data == nullptr && size > 0) {
        data = new int*[size];
        for(int i = 0; i < size; i++) {
            data[i] = new int[size];
        }
    }

    for(int r = 0; r < size; r++) { //NxN values into matrix
        for(int c = 0; c < size; c++) {
            file >> data[r][c];
        }
    }
}

//prints matrix aligned
void Matrix::printMatrix() const {
    for(int r = 0; r < size; r++) {
        for(int c = 0; c < size; c++) {
            cout<<setw(4)<<data[r][c]; //setw for alligning columns
        }
        cout<<endl;
    }
}

//operator+ (add matrices)
Matrix Matrix::operator+(const Matrix& other) { //operator overloading from slides for addition of matrix
    Matrix result(size);
    for(int r = 0; r < size; r++) {
        for(int c = 0; c < size; c++) {
            result.data[r][c] = data[r][c] + other.data[r][c];
        }
    }
    return result;
}

//operator* (multiply matrices)
Matrix Matrix::operator*(const Matrix& other) { //operator overloading for multiplication
    Matrix result(size); //new matrix for ans
    for(int i = 0; i < size; i++) { //normal multiplication
        for(int j = 0; j < size; j++) {
            result.data[i][j] = 0; //starting at 0
            for(int k = 0; k < size; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

//sum of both diagonals
int Matrix::diagonalSum() const {
    int sum = 0; 
    for(int i = 0; i < size; i++) { //looping through both diagonals
        sum += data[i][i]; //main diag
        sum += data[i][size - 1 - i]; //second diag
    }
    return sum;
}

//swap rows, returns new matrix so original is unchanged
Matrix Matrix::swapRows(int r1, int r2) {
    Matrix temp(*this); //deep copy of matrix
    if(r1 >= 0 && r1 < size && r2 >= 0 && r2 < size) { //only swap if valid
        for(int c = 0; c < size; c++) {
            int t = temp.data[r1][c];
            temp.data[r1][c] = temp.data[r2][c];
            temp.data[r2][c] = t;
        }
    }
    return temp;
}

//swap columns, returns new matrix
Matrix Matrix::swapCols(int c1, int c2) {
    Matrix temp(*this); //deep copy 
    if(c1 >= 0 && c1 < size && c2 >= 0 && c2 < size) { //same thing but for column swap
        for(int r = 0; r < size; r++) {
            int t = temp.data[r][c1];
            temp.data[r][c1] = temp.data[r][c2];
            temp.data[r][c2] = t;
        }
    }
    return temp;
}

//update one value and return new matrix copy
Matrix Matrix::updateValue(int r, int c, int val) {
    Matrix temp(*this); //deep copy 
    if(r >= 0 && r < size && c >= 0 && c < size) { //update if inside valid bounds
        temp.data[r][c] = val;
    }
    return temp;
}