#include "util.h"
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;


Matrix::Matrix(int nrows, int ncols): nrows( nrows ), ncols( ncols )
{
    int size = nrows*ncols;
    data = new double[size];
    endPointer = data+size;
    // memset is an optimized low level function
    // that should be faster than looping
    memset( data, 0, sizeof( double )*size );
};

Matrix::Matrix(const Matrix& other): nrows(other.nrows), ncols(other.ncols), data(new double[other.nrows * other.ncols]), endPointer(data + other.nrows * other.ncols)
{
    copy(other.data, other.data + other.nrows * other.ncols, data);
};

Matrix& Matrix::operator=(const Matrix& other) // assignement operator
{
    if (this != &other)
        {
            delete[] data;
            nrows = other.nrows;
            ncols = other.ncols;
            data = new double[nrows * ncols];
            copy(other.data, other.data + (nrows * ncols), data);
            endPointer = data + (nrows * ncols);
        }
    return *this;
}


int Matrix::get_nrows()
{
    return nrows;
}

int Matrix::get_ncols()
{
    return ncols;
}


void Matrix::insert_item(double value, int row, int col)
{
    data[row * ncols + col] = value;
}


double Matrix::get_item(int row, int col)
{
    return data[row * ncols + col];
}


void Matrix::print_matrix()
{
    for (int i=0; i<get_nrows(); i++)
    {
        for (int j=0; j<get_ncols(); j++)
        {
            cout<<get_item(i, j)<<"\t";
        }
        cout<<endl;
    }
}



double covariance(double* X, double* Y, int length)
{
    double sum_XY = 0;
    double sum_X = 0;
    double sum_Y = 0;

    for (int i=0; i<length; i++)
    {
        sum_XY += X[i]*Y[i];
        sum_X += X[i];
        sum_Y += Y[i];
    }

    return (1/static_cast<double>(length)) * sum_XY - (1/static_cast<double>(length)) * sum_X * (1/static_cast<double>(length)) * sum_Y;
}

double regressionBeta(double* Y, double* X, int length)
{
    return covariance(X, Y, length) / covariance(X, X, length);
}

double mean(double* X, int length)
{
    double sum = 0;

    for (int i=0 ; i<length ; i++)
    {
        sum += X[i];
    }

    return sum/length;
}

