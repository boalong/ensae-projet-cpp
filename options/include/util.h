#ifndef UTIL_H
#define UTIL_H

class Matrix
{
    private:
        /* The number of rows in the matrix */
        int nrows;
        /* The number of columns */
        int ncols;
        /* The data in the matrix */
        double* data;
        /* Pointer to one after the end of the
        data */
        double* endPointer;

    public:
        Matrix(int nrows, int ncols);
        Matrix(const Matrix& other); // copy constructor
        Matrix& operator=(const Matrix& other); // assignement operator
        ~Matrix() {delete[] data;} // destructor

        // Get functions
        int get_nrows();
        int get_ncols();

        void insert_item(double value, int row, int col);
        double get_item(int row, int col);
        void print_matrix();
};

double covariance(double* X, double* Y, int length);
double regressionBeta(double* Y, double* X, int length); // Simple OLS regression of Y on X
double mean(double* X, int length);

#endif // UTIL_H
