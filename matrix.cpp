#include "matrix.h"

Matrix::Matrix(): _data(0), _size(0) {}

Matrix::Matrix(int size): _size(size), _data(0)
{
    _total=_size*_size;
    _data = new int [_total];
    memset(_data, 0, _total*sizeof(int));
}
Matrix::Matrix(const Matrix& other) :
        _size(other.size())
{
    //delete [] _data;
    _total=_size*_size;
    _data = new int [_total];
    memcpy(_data,other._data,_total*sizeof(int));
}

void Matrix::transpon()
{
    Matrix C(*this);
    for (int i=0; i<_size; i++)
        for (int j=0; j<_size; j++)
            *(_data+i*_size+j)=*(C._data+j*_size+i);
}

//http://khpi-iip.mipk.kharkiv.edu/library/datastr/book_sod/kgsu/din_0100.html

/*
void Warren::TransClose()
//¬ычисление матрицы достижимости.
{
  //»нициализаци€ матрицы Path матрицей смежностей Adj.
  for (int i=0;i<MaxNodes;i++)
    for (int j=0;j<MaxNodes;j++)
      Path[i][j] = Adj[i][j];
  //Ќахождение следующих значений матрицы Path.
  for (i=1;i<MaxNodes;i++)
    for (int j=0;j<i;j++)
      if (Path[i][j]==1)
         for (int k=0;k<MaxNodes;k++)
               Path[i][k] = (Path[i][k] || Path[j][k]);
  for (i=0;i<MaxNodes-1;i++)
    for (int j=i+1;j<MaxNodes;j++)
      if (Path[i][j]==1)
         for (int k=0;k<MaxNodes;k++)
               Path[i][k] = (Path[i][k] || Path[j][k]);
}

*/


/*void Matrix::transitiveClosure()
{
    for (int i=1;i<_size;i++)
      for (int j=0;j<i;j++)
        if (*(_data+i*_size+j)==1)
           for (int k=0;k<_size;k++)
                 *(_data+i*_size+k) = (*(_data+i*_size+k) || *(_data+j*_size+k));
    for (int i=0;i<_size-1;i++)
      for (int j=i+1;j<_size;j++)
        if (*(_data+i*_size+j)==1)
           for (int k=0;k<_size;k++)
                 *(_data+i*_size+k) = (*(_data+i*_size+k) || *(_data+j*_size+k));
}*/

void Matrix::transitiveClosure()
{
    for (int k=0;k<_size;k++)
        for (int i=0;i<_size;i++)
          if (*(_data+i*_size+k)==1)
             for (int j=0;j<_size;j++)
                 *(_data+i*_size+j)=(*(_data+i*_size+j)||*(_data+k*_size+j));
}

void Matrix::reflexiveClosure()
{
    for(int i=0;i<_size;i++)
        *(_data+i*_size+i)=1;
}



const Matrix Matrix::operator*(const Matrix& other) const
{
    if(other.size()!=_size) return Matrix();
    Matrix C(_size);
    for (int i=0; i<_size; i++)
        for (int j=0; j<_size; j++)
            for (int k=0; k<_size; k++)
                *(C._data+i*_size+j)+= *(_data+i*_size+k) * *(other._data+k*_size+j);
    return C;
}

Matrix & Matrix::operator= (const Matrix& other)
{
    if (this!=&other)
    {
        if (_data!=0)
            delete [] _data;
        _size = other.size();
        _total=_size*_size;
        _data = new int [_total];

        memcpy(_data,other._data,_total*sizeof(int));

    }
    return *this;
}

void Matrix::toHtml(QString filename, const QStringList *names)
{
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly))
    {
        file.write("<html><head><style type='text/css'>td{border-style:solid;border-width:1px;border-color:black;}</style></head><body><table cellpadding='2' cellspacing='0'><tr><td>&nbsp;</td>");
        for(int i=0;i<names->size();i++)
            file.write("<td><b>"+names->at(i).toAscii()+"</b></td>");
        file.write("</tr>");
        for(int i=0;i<_size;i++)
        {
            file.write("<tr><td><b>"+names->at(i).toAscii()+"</b></td>");
            //QString str;
            for(int j=0;j<_size;j++)
            {
                file.write("<td>"+QString::number(*(_data+i*_size+j)).toAscii()+"</td>");
                //str.append(QString::number(FIRST[i][j]));
            }
            file.write("</tr>");
            //qDebug()<<str;

        }
        file.write("</table></body></html>");
        file.close();
    }
}

Matrix::~Matrix()
{
    if (_data!=0)
        delete [] _data;
}
