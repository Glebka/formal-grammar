#ifndef MATRIX_H
#define MATRIX_H

#include "memory.h"
#include <QString>
#include <QFile>
#include <QStringList>
class Matrix
{
protected:
        int * _data;
        int _size;
        int _total;
public:
        Matrix();
        Matrix(int size);

        Matrix(const Matrix& other);

        void transpon();
        void transitiveClosure();
        void reflexiveClosure();

        const Matrix operator*(const Matrix& other) const;

        Matrix & operator= (const Matrix& other);

        int* operator[](int i) { return _data+i*_size; }
        int& at(int i, int j) { return (_data+i*_size)[j]; }

        const int size() const { return _size; }

        void toHtml(QString filename,const QStringList * names);

        ~Matrix();
};
#endif // MATRIX_H
