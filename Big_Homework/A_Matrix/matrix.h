#ifndef MATRIX
#define MATRIX

//#define MATRIX_SQUARE_MATRIX_IMPLEMENTED
#include <stdexcept>
#include <iostream>
#include <cstdint>
#include <type_traits>

class MatrixIsDegenerateError : public std::runtime_error {
 public:
  MatrixIsDegenerateError() : std::runtime_error("MatrixIsDegenerateError") {
  }
};

class MatrixOutOfRange : public std::out_of_range {
 public:
  MatrixOutOfRange() : std::out_of_range("MatrixOutOfRange") {
  }
};

template<typename T, size_t Rows, size_t Columns>
class Matrix {
 public:
  T data[Rows][Columns];

  [[nodiscard]] size_t RowsNumber() const;
  [[nodiscard]] size_t ColumnsNumber() const;

  T &operator()(size_t r, size_t c);
  const T &operator()(size_t r, size_t c) const;
  T &At(size_t r, size_t c);
  const T &At(size_t r, size_t c) const;

  Matrix<T, Rows, Columns> operator+(const Matrix<T, Rows, Columns> &matrix) const;
  Matrix<T, Rows, Columns> operator-(const Matrix<T, Rows, Columns> &matrix) const;
  template<size_t K>
  Matrix<T, Rows, K> operator*(const Matrix<T, Columns, K> &matrix) const;

  Matrix<T, Rows, Columns> &operator+=(const Matrix<T, Rows, Columns> &matrix);
  Matrix<T, Rows, Columns> &operator-=(const Matrix<T, Rows, Columns> &matrix);
  template<size_t K>
  Matrix<T, Rows, K> &operator*=(const Matrix<T, Columns, K> &matrix);
  Matrix<T, Rows, Columns> &operator*=(const int &delta);
  Matrix<T, Rows, Columns> &operator/=(const int &delta);

  bool operator==(const Matrix<T, Rows, Columns> &matrix) const;
  bool operator!=(const Matrix<T, Rows, Columns> &matrix) const;
};

template<typename T, size_t Rows, size_t Columns>
size_t Matrix<T, Rows, Columns>::RowsNumber() const {
  return Rows;
}

template<typename T, size_t Rows, size_t Columns>
size_t Matrix<T, Rows, Columns>::ColumnsNumber() const {
  return Columns;
}

template<typename T, size_t Rows, size_t Columns>
T &Matrix<T, Rows, Columns>::operator()(size_t r, size_t c) {
  return data[r][c];
}

template<typename T, size_t Rows, size_t Columns>
const T &Matrix<T, Rows, Columns>::operator()(size_t r, size_t c) const {
  return data[r][c];
}

template<typename T, size_t Rows, size_t Columns>
T &Matrix<T, Rows, Columns>::At(size_t r, size_t c) {
  if (r < Rows && c < Columns) {
    return data[r][c];
  }
  throw MatrixOutOfRange();
}

template<typename T, size_t Rows, size_t Columns>
const T &Matrix<T, Rows, Columns>::At(size_t r, size_t c) const {
  if (r < Rows && c < Columns) {
    return data[r][c];
  }
  throw MatrixOutOfRange();
}

template<typename T, size_t Rows, size_t Columns>
Matrix<T, Rows, Columns> Matrix<T, Rows, Columns>::operator+(const Matrix<T, Rows, Columns> &matrix) const {
  Matrix<T, Rows, Columns> result;
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      result.At(i, j) = this->At(i, j) + matrix.At(i, j);
    }
  }
  return result;
}

template<typename T, size_t Rows, size_t Columns>
Matrix<T, Rows, Columns> Matrix<T, Rows, Columns>::operator-(const Matrix<T, Rows, Columns> &matrix) const {
  Matrix<T, Rows, Columns> result;
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      result.At(i, j) = this->At(i, j) - matrix.At(i, j);
    }
  }
  return result;
}

template<typename T, size_t Rows, size_t Columns>
template<size_t K>
Matrix<T, Rows, K> Matrix<T, Rows, Columns>::operator*(const Matrix<T, Columns, K> &matrix) const {
  Matrix<T, Rows, K> result;
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < K; ++j) {
      for (size_t k = 0; k < Columns; ++k) {
        result.At(i, j) += this->At(i, k) * matrix.At(k, j);
      }
    }
  }
  return result;
}

template<typename T, size_t Rows, size_t Columns>
Matrix<T, Rows, Columns> operator*(const Matrix<T, Rows, Columns> &matrix, const int &delta) {
  Matrix<T, Rows, Columns> result;
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      result.At(i, j) = matrix.At(i, j) * delta;
    }
  }
  return result;
}

template<typename T, size_t Rows, size_t Columns>
Matrix<T, Rows, Columns> operator*(const int &delta, const Matrix<T, Rows, Columns> &matrix) {
  Matrix<T, Rows, Columns> result;
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      result.At(i, j) = matrix.At(i, j) * delta;
    }
  }
  return result;
}

template<typename T, size_t Rows, size_t Columns>
Matrix<T, Rows, Columns> operator/(const Matrix<T, Rows, Columns> &matrix, const int &delta) {
  Matrix<T, Rows, Columns> result;
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      result.At(i, j) = matrix.At(i, j) / delta;
    }
  }
  return result;
}

template<typename T, size_t Rows, size_t Columns>
Matrix<T, Rows, Columns> &Matrix<T, Rows, Columns>::operator+=(const Matrix<T, Rows, Columns> &matrix) {
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      this->At(i, j) += matrix.At(i, j);
    }
  }
  return *this;
}

template<typename T, size_t Rows, size_t Columns>
Matrix<T, Rows, Columns> &Matrix<T, Rows, Columns>::operator-=(const Matrix<T, Rows, Columns> &matrix) {
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      this->At(i, j) -= matrix.At(i, j);
    }
  }
  return *this;
}

template<typename T, size_t Rows, size_t Columns>
template<size_t K>
Matrix<T, Rows, K> &Matrix<T, Rows, Columns>::operator*=(const Matrix<T, Columns, K> &matrix) {
  Matrix<T, Rows, K> temp_matrix;
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < K; ++j) {
      temp_matrix.At(i, j) = 0;
      for (size_t k = 0; k < Columns; ++k) {
        temp_matrix(i, j) += this->At(i, k) * matrix.At(k, j);
      }
    }
  }
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < K; ++j) {
      this->At(i, j) = temp_matrix.At(i, j);
    }
  }
  return *this;
}

template<typename T, size_t Rows, size_t Columns>
Matrix<T, Rows, Columns> &Matrix<T, Rows, Columns>::operator*=(const int &delta) {
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      this->At(i, j) *= delta;
    }
  }
  return *this;
}

template<typename T, size_t Rows, size_t Columns>
Matrix<T, Rows, Columns> &Matrix<T, Rows, Columns>::operator/=(const int &delta) {
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      this->At(i, j) /= delta;
    }
  }
  return *this;
}

template<typename T, size_t Rows, size_t Columns>
bool Matrix<T, Rows, Columns>::operator==(const Matrix<T, Rows, Columns> &matrix) const {
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      if (this->At(i, j) != matrix.At(i, j)) {
        return false;
      }
    }
  }
  return true;
}

template<typename T, size_t Rows, size_t Columns>
bool Matrix<T, Rows, Columns>::operator!=(const Matrix<T, Rows, Columns> &matrix) const {
  return !(*this == matrix);
}

template<typename T, size_t Rows, size_t Columns>
std::istream &operator>>(std::istream &in, Matrix<T, Rows, Columns> &matrix) {
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      in >> matrix.At(i, j);
    }
  }
  return in;
}

template<typename T, size_t Rows, size_t Columns>
std::ostream &operator<<(std::ostream &out, const Matrix<T, Rows, Columns> &matrix) {
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      out << matrix.At(i, j);
      if (j == Columns - 1) {
        out << '\n';
      } else {
        out << ' ';
      }
    }
  }
  return out;
}

template<typename T, size_t Rows, size_t Columns>
Matrix<T, Columns, Rows> GetTransposed(Matrix<T, Rows, Columns> matrix) {
  Matrix<T, Columns, Rows> transposed_matrix;
  for (size_t i = 0; i < Rows; ++i) {
    for (size_t j = 0; j < Columns; ++j) {
      transposed_matrix(j, i) = matrix(i, j);
    }
  }
  return transposed_matrix;
}

/*
template<typename T, size_t N>
void Transpose(Matrix<T, N, N> &matrix) {
  for (int i = 0 ; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      std::swap(matrix.At(i, j), matrix.At(j, i));
    }
  }
}

template<typename T, size_t N>
T Trace(const Matrix<T, N, N> &matrix)  {
  T trace = 0;
  for (int i = 0; i < N; ++i) {
    trace += matrix.At(i, i);
  }
  return trace;
}

template<typename T, uint64_t N>
Matrix<T, N - 1, N - 1> GetMinor(Matrix<T, N, N> matrix, int deleted_row, int deleted_column) {
  Matrix<T, N - 1, N - 1> minor;
  int i_minor = 0, j_minor = 0;
  for (int i = 0; i < N; ++i) {
    if (i_minor != deleted_row) {
      for (int j = 0; j < N; ++j) {
        if (j_minor != deleted_column) {
          minor.At(i_minor, j_minor) = matrix(i, j);
        }
      }
      ++i_minor;
    }
  }
  return minor;
}

template<typename T, uint64_t N>
T Determinant(Matrix<T, N, N> matrix)  {
  if (N < 1) {
    throw std::runtime_error("The dimension is less than 1");
  } else if (N == 1) {
    return matrix.At(0, 0);
  } else if (N == 2) {
    return matrix.At(0, 0) * matrix.At(1, 1) - matrix.At(1, 0) * matrix.At(0, 1);
  } else {
    T determinant = 0;
    T sign = -1;
    for (int i = 0; i < N; ++i) {
      if (N >= PTRDIFF_MAX) {
        __builtin_unreachable ();
      }
      Matrix<T, N - 1, N - 1> minor = GetMinor(matrix, 0, i);
      determinant += sign * Determinant(minor);
    }
    return determinant;
  }
}

T determinant = matrix.At(0, 0) * matrix.At(1, 1) * matrix(2, 2);
determinant += matrix.At(0, 1) * matrix.At(1, 2) * matrix(2, 0);
determinant += matrix.At(0, 2) * matrix.At(1, 0) * matrix.At(2, 1);
determinant -= matrix.At(2, 0) * matrix.At(1, 1) * matrix.At(0, 2);
determinant -= matrix.At(2, 1) * matrix.At(1, 2) * matrix.At(0, 0);
determinant -= matrix.At(2, 2) * matrix.At(1, 0) * matrix.At(0, 1);
template<typename T, size_t N>
Matrix<T, N, N> GetInversed(const Matrix<T, N, N> &matrix) {

}

template<typename T, size_t N>
void Inverse(const Matrix<T, N, N> &matrix) {

}
*/

#endif