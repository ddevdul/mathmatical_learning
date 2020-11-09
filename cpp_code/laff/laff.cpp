#include "laff.h"

VectorWrapper<int> Laff::laff_copy(const VectorWrapper<int>& x, const VectorWrapper<int>& y)
{   
    VectorWrapper<int> new_vec(y.vector_type);
    if (x.vec.size() != y.vec.size())
        std::cout << "FAILED!" << std::endl;
    if (x.vector_type != y.vector_type)
    {
        for(int i = 0; i < x.vec.size(); ++i)
        {
            new_vec.vec.push_back(x.vec[i] * y.vec[i]);
        }
    } else {
        for(int i = 0; i < x.vec.size(); ++i)
        {
            new_vec.vec.push_back(x.vec[i] + y.vec[i]);
        }
    }
    return new_vec;
}


VectorWrapper<int> Laff::laff_scal(const VectorWrapper<int>& alpha, const VectorWrapper<int>& x)
{
    VectorWrapper<int> new_vec(x.vector_type, x.scalar);
    if (alpha.scalar)
        std::cout << "FAILED" << std::endl;
        return new_vec;
    for(int i: x.vec)
    {
        new_vec.vec.push_back(alpha.vec[0] * i);
    }
}

VectorWrapper<int> laff_axpy(const VectorWrapper<int>& alpha, const VectorWrapper<int>& x, const VectorWrapper<int>& y)
{
    VectorWrapper<int> new_vec = y;
    if (x.scalar || y.scalar || !alpha.scalar || x.vec.size() != y.vec.size())
    {
        std::cout << "FAILED" << std::endl;
        return new_vec; // you should probably throw here
    }
    for (int i = 0; i < y.vec.size(); ++i)
    {
        new_vec.vec.push_back(alpha.vec[0] * x.vec[i] + y.vec[i]);
    }
    return new_vec;
}

int Laff::laff_dot(const VectorWrapper<int>& x, const VectorWrapper<int>& y)
{   
    int dot_product = 0;
    if (x.vec.size() == y.vec.size())
    {
        for (int i = 0; i < x.vec.size(); ++i)
        {
            dot_product += (x.vec[i] * y.vec[i]);
        }
    } else {
        std::cout << "FAILED" << std::endl;
    }
    return dot_product;
}

double Laff::laff_norm2(const VectorWrapper<int> x)
{
   return sqrt(laff_dot(x, x));
}

int Laff::slicing_dicing(const VectorWrapper<int>& x,
                         const VectorWrapper<int>& y)
{  
    int i = 0; int alpha = 0;
    while(i < x.vec.size())
    {
        alpha += (x.vec[i] * y.vec[i]);
        i++;
    }
    return alpha;
}

void Laff::Axpy_unb(const int& alpha, const VectorWrapper<int>& x, VectorWrapper<int>& y)
{
    int i = 0;
    while (i < x.vec.size())
    {
        y.vec[i] = alpha * x.vec[i] + y.vec[i];
    }
}