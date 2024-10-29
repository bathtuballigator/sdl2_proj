#include "vector.h"
#include <cstdlib>
#include <ctime>

template <typename T> vec3<T>::vec3(T x, T y, T z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

template <typename T> vec3<T>::vec3(vec3<T> const &vec) {
    this->x = vec->x;
    this->y = vec->y;
    this->z = vec->z;
}

template <typename T> vec3<T> vec3<T>::operator*(T a) {
    return vec3<T>(x * a, y * a, z * a);
}
template <typename T> T vec3<T>::operator*(vec3<T> a) {
    return (a->x * this->x) + (this->y * a->y) + (this->z * a->z);
}

template <typename T> vec3<T> vec3<T>::operator+(vec3<T> a) {
    return vec3<T>(this->x + a->x, this->y + a->y, this->z + a->z);
}

template <typename T> vec3<T> vec3<T>::operator-(vec3<T> a) {
    return vec3<T>(this->x - a->x, this->y - a->y, this->z - a->z);
}
