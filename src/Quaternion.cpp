//
// Created by igor on 16.12.2020.
//

#include "Quaternion.h"
#include "Vector3.h"
#include <math.h>


Quaternion::Quaternion(double r, double i, double j, double k) : r(r), i(i), j(j), k(k){

}

//Conjugate. For unit quaternions works as inverse
Quaternion Quaternion::operator~() const{
    return Quaternion(r, -i, -j, -k);
}



Quaternion::Quaternion(): r(1), i(0), j(0), k(0) {}

Vector3 Quaternion::toEuler() const {
    Vector3 angles;

    // roll (x-axis rotation)
    double sinr_cosp = 2 * (r * i + j * k);
    double cosr_cosp = 1 - 2 * (r * r + j * j);
    angles.x = atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    double sinp = 2 * (r * i - k * i);
    if (fabs(sinp) >= 1)
        angles.y = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
    else
        angles.y = asin(sinp);

    // yaw (z-axis rotation)
    double siny_cosp = 2 * (r * k + i * j);
    double cosy_cosp = 1 - 2 * (j *j + k * k);
    angles.z = atan2(siny_cosp, cosy_cosp);

    return angles;
}

void Quaternion::normalize() {
    if (r<0) {
        r = -r;
        i = -i;
        j = -j;
        k = -k;
    }
}


Quaternion operator*(const Quaternion &p, const Quaternion &q) {
    return Quaternion(
            p.r*q.r - p.i*q.i - p.j*q.j - p.k*q.k,
            p.r*q.i + p.i*q.r + p.j*q.k - p.k*q.j,
            p.r*q.j - p.i*q.k + p.j*q.r + p.k*q.i,
            p.r*q.k + p.i*q.j - p.j*q.i + p.k*q.r
    );
}

Quaternion operator*(const Quaternion &p, double r) {
    return {p.r * r,
            p.i * r,
            p.j * r,
            p.k * r};
}

Vector3 discreteDerivative(Quaternion &from, Quaternion &to, double dt) {
    Quaternion dq = ~from * to * (1/dt);
    Quaternion result = ~to * dq * 2 * to;
    return {result.i, result.j, result.k};
}


