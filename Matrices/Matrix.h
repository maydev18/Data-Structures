#include <iostream>
using namespace std;
class Matrix{
    public:
        int ** arr;
        int rows,column;
        Matrix(){}
        Matrix(Matrix & m);
        void getMatrix();
        Matrix operator + (Matrix & m);
        Matrix operator - (Matrix & m);
        void operator - ();
        Matrix operator * (Matrix & m);
        Matrix transpose();
        void operator += (int a);
        void operator -= (int a);
        int operator () (int , int);
        friend ostream & operator << (ostream & out , Matrix & m);
        friend istream & operator >> (istream & in , Matrix & m);
        ~Matrix(){}
};
Matrix::Matrix(Matrix&m){
    rows = m.rows;
    column = m.column;
    for(int i= 1 ; i<=rows ; i++){
        for(int j=1; j<=column  ; j++){
            arr[i][j] = m.arr[i][j];
        }
    }
}
Matrix Matrix :: operator +(Matrix & m){
    Matrix newmatrix;
    newmatrix.rows = rows;
    newmatrix.column = column;
    for(int i=1 ; i<=rows ; i++){
        for(int j=1 ; j<=column ; j++){
            newmatrix.arr[i][j] = arr[i][j]+m.arr[i][j];
        }
    }
    return newmatrix;
}
Matrix Matrix :: operator -(Matrix & m){
    Matrix newmatrix;
    newmatrix.rows = rows;
    newmatrix.column = column;
    for(int i=1 ; i<=rows ; i++){
        for(int j=1 ; j<=column ; j++){
            newmatrix.arr[i][j] = arr[i][j]-m.arr[i][j];
        }
    }
    return newmatrix;
}
void Matrix :: operator-(){
    for(int i = 1 ; i<=rows  ; i++){
        for(int j=1 ; j<=column ; j++){
            arr[i][j] = -arr[i][j];
        }
    }
}
Matrix Matrix :: operator*(Matrix & m){
    Matrix newmatrix;
    newmatrix.rows = this->rows;
    newmatrix.column = m.column;
    for(int i = 1 ; i<= newmatrix.rows ; i++){
        for(int j = 1 ; j<= newmatrix.column ; j++){
            int sum = 0;
            for(int k = 1 ; k <= this->column ; k++){
                sum += (this->arr[i][k] * m.arr[k][j]);
            }
            newmatrix.arr[i][j] = sum;
        }
    }
    return newmatrix;
}
Matrix Matrix :: transpose(){
    Matrix newmatrix;
    newmatrix.rows = this->column;
    newmatrix.column = this->rows;
    for(int i = 1 ; i <= newmatrix.rows  ; i++){
        for(int j=1 ; j<=newmatrix.column ; j++){
            newmatrix.arr[i][j] = this->arr[j][i];
        }
    }
    return newmatrix;
}
void Matrix :: operator+=(int a){
    for(int i=1 ; i<=rows ; i++){
        for(int j=1 ; j<=column ; j++){
            arr[i][j]+=a;
        }
    }
}
void Matrix :: operator-= (int a){
    for(int i=1 ; i<=rows ; i++){
        for(int j=1 ; j<=column ; j++){
            arr[i][j]-=a;
        }
    }
}
int Matrix :: operator()(int a , int b){
    return arr[a][b];
}
ostream & operator << (ostream & out , Matrix & m){
    out << endl;
    for(int i=1 ; i<=m.rows ; i++){
        for(int j=1 ; j<=m.column ; j++){
            out << m.arr[i][j]<<" ";
        }
        out << endl;
    }
    return out;
}
istream & operator >> (istream & in , Matrix & m){
    cout << "enter the number of rows: " ;
    in >> m.rows;
    cout << "enter the number of columns: ";
    in >> m.column;
    m.arr = new int*[m.rows];
    for(int i=1 ; i<=m.rows ; i++){
        m.arr[i] = new int[m.column];
    }
    for(int i = 1 ; i <= m.rows ; i++){
        for(int j = 1 ; j<= m.column ; j++){
            cout << "enter the ( "<< i <<" , "<<j<<" )th entry: ";
            in >> m.arr[i][j];
        }
    }
    return in;
}
