#ifndef VECTORS_H_
#define VECTORS_H_
#include<glm/glm.hpp>
class Vec2
{
    public: float x, y,z ; //z for depth
            glm::vec3 c; //c for color
            float i; // i for intensity


    public: Vec2(){i = 1;}
            Vec2(float xx, float yy,float zz=0,float ii=1): x(xx) ,y(yy),z(zz),i(ii){}
            Vec2(const Vec2& in):x(in.x),y(in.y),z(in.z),i(in.i){}
            void operator = (const Vec2& in){
                x = in.x;
                y = in.y;
                z = in.z;
                i = in.i;
            }
};



class Matrix
{
    private:
        float* data;
        int row, col;
    public:
        Matrix(int rows,int column) : row(rows), col(column)
        {
            data = new float[row*col];
        }

        Matrix(const Matrix& mat)
        {
            row = mat.row;
            col = mat.col;
            data = new float[row*col];

            for (int i =0;i<row*col;i++)
                (*this)(i) = mat(i);
        }


        void operator=(const Matrix& mat)
        {
            delete[] data;
            row = mat.row;
            col = mat.col;
            data = new float[row*col];

            for (int i =0;i<row*col;i++)
                (*this)(i) = mat(i);
        }


        float& operator() (int r, int c);   //mat(i,j)
        float& operator() (int pos) ;       //mat(pos)


        const float operator() (int r, int c) const;   //mat(i,j)
        const float operator() (int pos) const;       //mat(pos)


        Matrix operator * (Matrix& mat);    // M = T * M
        Matrix operator + (Matrix& mat);    // C = A + B
        Matrix operator - (Matrix& mat);    // C = A - B
        Matrix operator / (float val);      // C[] = C[] / val
        float dot(Matrix& mat);             // A.dot(B) == (A = A DOT B)
        float magnitude();                  //returns the square root of sum of squares of all element

        ~Matrix(){
            delete[] data;
        }
};




#endif //VECTORS_H_
