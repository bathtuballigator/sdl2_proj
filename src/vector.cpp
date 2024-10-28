#include <cstdlib>
class vec3 {
    public:
        vec3(int, int, int);
        vec3();

    private:
        int x;
        int y;
        int z;
};

vec3::vec3(int x, int y, int z) { x = x; }
