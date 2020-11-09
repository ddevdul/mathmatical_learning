#include <iostream>
#include <vector>
#include <math.h>

class Laff
{
public:
    Laff() = default;
    VectorWrapper<int> laff_copy(const VectorWrapper<int>& x, const VectorWrapper<int>& y);
    VectorWrapper<int> laff_scal(const VectorWrapper<int>& alpha, const VectorWrapper<int>& x);
    VectorWrapper<int> laff_axpy(const VectorWrapper<int>& alpha, const VectorWrapper<int>& x, const VectorWrapper<int>& y);
    int laff_dot(const VectorWrapper<int>& x, const VectorWrapper<int>& y);
    double laff_norm2(const VectorWrapper<int> x); 
    int slicing_dicing(const VectorWrapper<int>& x, const VectorWrapper<int>& y);
    void Axpy_unb(const int& alpha, const VectorWrapper<int>& x, VectorWrapper<int>& y);
};

template <typename T>
struct VectorWrapper
{   
public:
    VectorWrapper() = default;
    VectorWrapper(int vector_type, int scalar=0)
        : vector_type(vector_type), scalar(scalar) {}
    VectorWrapper(const VectorWrapper<T>& other_vector)
        : vector_type(other.vector_type), scalar(other.scalar) {}
    std::vector<T> vec;
    // vector type 0 for a row and 1 for a column
    int vector_type;
    int scalar; // 0 is not a scalar 1 is a scalar
};