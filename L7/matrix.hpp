//
// Created by Tooster on 18.04.2018.
//

#ifndef CPP_MATRIX_HPP
#define CPP_MATRIX_HPP

#include "exceptions/invalid_dimensions_exception.hpp"

namespace Calculations {
    class Matrix {
        int rows, columns;
        double **tab;
    public:
        /// Creates square,diagonal matrix with var on the diagonal
        Matrix(int size, double var) noexcept(false);

        Matrix(int rows, int columns) noexcept(false);

        Matrix(const Matrix &);

        Matrix(Matrix &&) noexcept;

        Matrix &operator=(const Matrix &);

        Matrix &operator=(Matrix &&) noexcept;

        virtual ~Matrix();


        // @formatter:off
        Matrix operator*(double scalar) const noexcept; // scalar multiplication
        Matrix &operator+=(const Matrix &other) noexcept(false);
        Matrix &operator*=(const Matrix &other) noexcept(false); //other multiplied to the right
        Matrix &operator-=(const Matrix &other) noexcept(false);
        friend Matrix operator+(const Matrix &m1, const Matrix &m2) noexcept(false);

        friend Matrix operator-(const Matrix &m1, const Matrix &m2) noexcept(false);

        friend Matrix operator*(double, const Matrix &) noexcept;
        friend Matrix operator*(const Matrix &, const Matrix &) noexcept(false);
        // @formatter:on
        Matrix transposition() noexcept;

        Matrix &rowSwap(int i, int j) noexcept(false);

        Matrix &rowMult(int i, double scalar) noexcept(false);

        Matrix &rowAdd(int to, int from, double scalar) noexcept(false);

        Matrix &colSwap(int i, int j) noexcept(false);

        Matrix &colMult(int i, double scalar) noexcept(false);

        Matrix &colAdd(int to, int from, double scalar) noexcept(false);

        Matrix complement(int row, int column) noexcept(false);

        double det() noexcept(false);

//        std::istream &operator>>(std::istream &we, Matrix &m);
//        std::ostream &operator<<(std::ostream &wy, const Matrix &m);
    };


}


#endif //CPP_MATRIX_HPP
