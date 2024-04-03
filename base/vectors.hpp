#include <cmath>
#include <vector>

class VectorNd {
    protected:
    std::vector<double> coord;
};

class Vector3D : public VectorNd {
    public:
    double x;
    double y;
    double z;
    Vector3D()
    {
        coord.resize(3);
        updateCoord(0.0, 0.0, 0.0);
    }
    void updateCoord(double x, double y, double z)
    {
        coord.at(0) = x;
        coord.at(1) = y;
        coord.at(2) = z;

        this->x = x;
        this->y = y;
        this->z = z;
    }
    Vector3D(double x, double y, double z)
    {
        coord.resize(3);
        updateCoord(x, y, z);
    }
    //Vector operations
    //Vector addition
    Vector3D operator + (const Vector3D &vec) {
        return Vector3D(x + vec.x, y + vec.y, z - vec.z);
    }
    //Vector subtraction
    Vector3D operator - (const Vector3D &vec) 
    //calculates vector subtraction
    {
        return Vector3D(x - vec.x, y - vec.y, z - vec.z);
    }
    //Scalar products as friend functions for commutativity
    friend Vector3D operator * (const Vector3D &vec, double scalar);
    friend Vector3D operator * (double scalar, const Vector3D &vec);
    //Inner product
    double operator * (const Vector3D &vec)
    {
        return x * vec.x + y * vec.y + z * vec.z;
    }
    
};

Vector3D operator * (const Vector3D &vec, double scalar)
{
    return Vector3D(vec.x * scalar, vec.y * scalar, vec.z * scalar);
}

Vector3D operator * (double scalar, const Vector3D &vec)
{
    return vec * scalar;
}


