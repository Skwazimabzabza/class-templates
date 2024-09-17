#include <iostream>
using namespace std;


template <typename T>
class Matrix {
private:
    T rows;   
    T cols;   
    T** arr;  

public:

    Matrix(int r, int c) {
        rows = r;
        cols = c;
        arr = new T* [rows];
        for (int i{}; i < rows; ++i) {
                arr[i] = new T[cols];
        }
    }

    Matrix(const Matrix& matrix){

        rows = matrix.rows;
        cols = matrix.cols;
        arr = new T * [rows];
        for (int i{}; i < rows; ++i) {
            arr[i] = new T[cols];
            for (int j{}; j < cols; ++j) {
                arr[i][j] = matrix.arr[i][j];
            }
        }
    }

    void gen() {
        for (int i{}; i < rows; ++i) {
            for (int j{}; j < cols; ++j) {
                arr[i][j] = rand() % 101;
            }
        }
    }

    void print() {
        cout << "Матрица:\n";
        for (int i{}; i < rows; ++i) {
            for (int j{}; j < cols; ++j) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Matrix() {
        for (int i{}; i < rows; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    }



     Matrix<T> operator+(const Matrix<T>&  matrix) const {
        Matrix<T> result(rows, cols);
        for (int i{}; i < rows; ++i) {
            for (int j{}; j < cols; ++j) {
                result.arr[i][j] = arr[i][j] + matrix.arr[i][j];
            }
        }
        return result;
     }

     Matrix<T> operator-(const Matrix<T>& matrix) const {
         Matrix<T> result(rows, cols);
         for (int i{}; i < rows; ++i) {
             for (int j{}; j < cols; ++j) {
                 result.arr[i][j] = arr[i][j] - matrix.arr[i][j];
             }
         }
         return result;
     }

     Matrix<T> operator*(const Matrix<T>& matrix) const {
         Matrix<T> result(rows, cols);
         for (int i{}; i < rows; ++i) {
             for (int j{}; j < cols; ++j) {
                 result.arr[i][j] = arr[i][j] * matrix.arr[i][j];
             }
         }
         return result;
     }

     Matrix<T> operator/(const Matrix<T>& matrix) const {
         Matrix<T> result(rows, cols);
         for (int i{}; i < rows; ++i) {
             for (int j{}; j < cols; ++j) {
                 if (matrix.arr[i][j] != 0)
                     result.arr[i][j] = arr[i][j] / matrix.arr[i][j];
                 else
                     result.arr[i][j] = 0;
             }
         }
         return result;
     }


     T maxN()const {
         T max = arr[0][0];

         for (int i{}; i < rows; ++i) {
             for (int j{}; j < cols; ++j) {
                 if (arr[i][j] > max)
                     max = arr[i][j];
             }
         }
         return max;
     }

     T minN()const {
         T min = arr[0][0];

         for (int i{}; i < rows; ++i) {
             for (int j{}; j < cols; ++j) {
                 if (arr[i][j] < min)
                     min = arr[i][j];
             }
         }
         return min;
     }
};

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Ru");
    int rows{}; 
    int cols{};

    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    Matrix <int> matrix(rows, cols);
    Matrix <int> matrix2(rows, cols);

    matrix.gen();
    matrix2.gen();

    matrix.print();
    matrix2.print();

    Matrix <int> sum = matrix + matrix2;
    std::cout << "Результат суммы двух матриц" << std::endl;
    sum.print();

    Matrix <int> sub = matrix - matrix2;
    std::cout << "Результат вычитания двух матриц" << std::endl;
    sub.print();

    Matrix <int> mult = matrix * matrix2;
    std::cout << "Результат умножения двух матриц" << std::endl;
    mult.print();

    Matrix <int> div = matrix / matrix2;
    std::cout << "Результат деления двух матриц" << std::endl;
    div.print();

    int max = matrix.maxN();
    std::cout << "Максимальное число в первой матрице " << max << std::endl;
    max = matrix2.maxN();
    std::cout << "Максимальное число во второй матрице " << max << std::endl;

    int min = matrix.minN();
    std::cout << "Минимальное число в первой матрице " << min << std::endl;
    min = matrix2.minN();
    std::cout << "Минимальное число во второй матрице " << min << std::endl;
}
