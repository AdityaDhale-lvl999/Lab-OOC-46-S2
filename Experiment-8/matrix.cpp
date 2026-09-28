#include <iostream>
#include <vector>
using namespace std;
 
class Matrix {
private:
    int rows, cols;
    //vector of vectors so we don't deal with raw pointers
    vector<vector<int>> data;
 
public:
    //default gives an empty 0x0 matrix, otherwise a rows x cols matrix full of zeros
    Matrix(int r = 0, int c = 0) : rows(r), cols(c), data(r, vector<int>(c, 0))
    {
    }
 
    //read every element from the user
    void input()
    {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "enter element [" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
        }
    }
 
    //print the matrix row by row
    void display() const
    {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
    }
 
    //addition and subtraction only make sense when both matrices have the same size
    bool sameSize(const Matrix& other) const
    {
        return rows == other.rows && cols == other.cols;
    }
 
    //m1 + m2 -> add element by element
    Matrix operator+(const Matrix& other) const
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }
 
    //m1 - m2 -> subtract element by element
    Matrix operator-(const Matrix& other) const
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }
 
    //m1 == m2 -> true only if size and every element match
    bool operator==(const Matrix& other) const
    {
        if (!sameSize(other))
            return false;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (data[i][j] != other.data[i][j])
                    return false;
        return true;
    }
};
 
int main()
{
    int r1, c1, r2, c2;
 
    cout << "enter rows and columns of matrix 1: ";
    cin >> r1 >> c1;
    Matrix m1(r1, c1);
    m1.input();
 
    cout << "enter rows and columns of matrix 2: ";
    cin >> r2 >> c2;
    Matrix m2(r2, c2);
    m2.input();
 
    cout << "\nmatrix 1:" << endl;
    m1.display();
    cout << "\nmatrix 2:" << endl;
    m2.display();
 
    //only add/subtract if the sizes match, otherwise the result is meaningless
    if (m1.sameSize(m2)) {
        Matrix sum = m1 + m2;
        Matrix diff = m1 - m2;
 
        cout << "\nmatrix 1 + matrix 2:" << endl;
        sum.display();
        cout << "\nmatrix 1 - matrix 2:" << endl;
        diff.display();
    }
    else {
        cout << "\naddition and subtraction not possible, sizes are different" << endl;
    }
 
    //comparison works for any two matrices
    if (m1 == m2)
        cout << "\nthe matrices are equal" << endl;
    else
        cout << "\nthe matrices are not equal" << endl;
 
    return 0;
}
