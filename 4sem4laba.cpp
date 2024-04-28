#include <iostream>
#include <limits>
#include <vector>
#include <cstdlib>

using namespace std;

template <typename T>
int findSecondMax(T* arr, int n) {
    
    T max1 = numeric_limits<T>::min();
    T max2 = numeric_limits<T>::min();

    
    int max1_index = -1;
    int max2_index = -1;


    for (int i = 0; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max2_index = max1_index;

            max1 = arr[i];
            max1_index = i;
        }
        else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
            max2_index = i;
        }
    }

    
    return max2_index;
}

template <typename T>
class Matrix {
private:
    
    unsigned int m;
    unsigned int n;

public:
    std::vector<std::vector<T>> data;
    Matrix() {
        m = 3;
        n = 3;
        data = std::vector<std::vector<T>>(m, std::vector<T>(n, 0));
    }

    Matrix(unsigned int m, unsigned int n) : m(m), n(n) {
        data = std::vector<std::vector<T>>(m, std::vector<T>(n, 0));
    }

    ~Matrix() {
        std::cout << "DELETED!!!!" << std::endl;
    }

    void fillRandom() {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] = rand() / 10.0;
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
        for (unsigned int i = 0; i < matrix.m; ++i) {
            for (unsigned int j = 0; j < matrix.n; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    Matrix operator+= (const Matrix<T>& other) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return *this;
    }

    Matrix operator+(const Matrix<T>& other) const {
        Matrix result(*this);
        return result += other;
    }

    Matrix& operator-=(const Matrix<T>& other) {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] -= other.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator-(const Matrix<T>& other) const {
        Matrix result(*this);
        return result -= other;
    }

    Matrix operator*(const Matrix<T>& other) const {
        Matrix result(m, other.n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < other.n; ++j) {
                result.data[i][j] = 0;
                for (unsigned int k = 0; k < n; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    bool operator==(const Matrix<T>& other) const {
        if (m != other.m || n != other.n) {
            return false;
        }
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Matrix<T>& other) const {
        return !(*this == other);
    }
   
};


template <typename T>
class Vector : public Matrix<T> {
public:
    Vector(unsigned int n) : Matrix<T>(1, n) {}

    T dotProduct(const Vector& other) const {
        T sum = 0;
        for (unsigned int i = 0; i < 3; ++i) {
            sum += this->at(0, i) * other.at(0, i);
        }
        return sum;
    }

    Vector crossProduct(const Vector& other) const {
        Vector<T> result;
        for (int i = 0; i < 3; ++i) {
            if (i == 0) {
                result = data.at(1) * other.data.at(2) - data.at(2) * other.data.at(1);
            }
            if (i == 1) {
                result = data.at(2) * other.data.at(0) - data.at(0) * other.data.at(2);
            }
            if (i == 2) {
                result = data.at(0) * other.data.at(1) - data.at(1) * other.data.at(0);
            }
            

            return result;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    //1
    int arr1[] = { 11, 72, 7, 2, 5 };
    float arr2[] = { 3.2, 1.3, 7.4, 4.5, 5.6 };
    double arr3[] = { 11.23, 6.34, 3.45, 9.56, 5.67 };
    char arr4[] = { 'w', 'i', 'z', 'd', 'e' };

    cout << "Индекс второго максимума (int): " << findSecondMax(arr1, 5) << endl;
    cout << "Индекс второго максимума (float): " << findSecondMax(arr2, 5) << endl;
    cout << "Индекс второго максимума (double): " << findSecondMax(arr3, 5) << endl;
    cout << "Индекс второго максимума (char): " << findSecondMax(arr4, 5) << endl;

    //2
    Matrix<double> matrix(3, 3);
    Matrix<double> matrix1(3, 3);
    matrix1.fillRandom();
    matrix.fillRandom();

    std::cout << "Матричный тест (double)" << std::endl;
    std::cout << matrix << std::endl << matrix1 << std::endl;
    Matrix<double> m1 = matrix + matrix1;
    std::cout << m1;

    //3
    Vector<int> vector1(3);
    vector1.fillRandom();

    Vector<int> vector2(3);
    vector2.fillRandom();

    // Вычислить скалярное произведение
    int dotProduct = vector1.dotProduct(vector2);
    std::cout << "Скалярное произведение: " << dotProduct << std::endl;

    // Вычислить векторное произведение
    Vector<int> crossProduct = vector1.crossProduct(vector2);
    std::cout << "Векторное произведение: " << crossProduct << std::endl;


    return 0;
}