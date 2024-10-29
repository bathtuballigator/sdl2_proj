
template <typename T> class vec3 {
    public:
        vec3(T, T, T);
        vec3(vec3<T> const &);

        vec3 operator*(T a);
        T operator*(vec3<T> a);
        vec3 operator+(vec3 a);
        vec3 operator-(vec3 a);
        vec3 operator-(T a);
        vec3 operator/(T a);

    private:
        T x;
        T y;
        T z;
};
