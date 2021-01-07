//
// Created by igor on 16.12.2020.
//

#ifndef UAVSTABILIZATION_VECTOR3_H
#define UAVSTABILIZATION_VECTOR3_H


class Vector3 {
public:
    double x;
    double y;
    double z;

    Vector3(double x, double y, double z);

    Vector3 operator += (const Vector3& other);

    Vector3 operator-(const  Vector3& other) const;

    Vector3();

    Vector3 operator * (double scalar) const;
};


#endif //UAVSTABILIZATION_VECTOR3_H
